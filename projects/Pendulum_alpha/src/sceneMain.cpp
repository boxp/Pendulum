#include "sceneMain.h"
#include "lib\gplib.h"

#include "Obj.h"			// InsertObject,MargeObjects
#include "Collision.h"		// Collision���o�p
#include "player.h"
#include "enemyMng.h"
#include "setting.h"

#include "Fade.h"

#include "sceneEnd.h"		// �V�[���J��


//======================================
// CSceneMain methods
#pragma region
// �R���X�g���N�^
CSceneMain::CSceneMain()
{
	InsertObject(ObjPtr(new CCollision(*(shareRes_->stage))));
	InsertObject(ObjPtr(new CEnemyMng()));
	CFade::StartFadeIn();
	DShow_Play(BGM::MAIN);
}
CSceneMain::~CSceneMain()
{
}

// ����
IScene* CSceneMain::step()
{
	switch(state_)
	{
	case State::INNING:
		if(CFade::FadeIn(255.f/20.f))
		{
			state_ = State::MAIN;
		}
		break;
	case State::MAIN:
		for(auto& obj : objs)
		{
			obj->step();
		}

		MargeObjects();
	
		shareRes_->Update();

		// �����A�N�V�������N�����ăV�[�����؂�ւ��Ƃ�
		if(CheckPush(KEY_BTN0))
		{
			state_ = State::OUTING;
		}
		break;
	case State::OUTING:
		const float end_time = 0.4f;	// �I���b
		// BGM�t�F�[�h�A�E�g
		bgmVolum_ -= static_cast<int>(100.f / end_time * FrameTime);
		DShow_VolumeControl(BGM::MAIN,bgmVolum_);
		if(bgmVolum_ <= 0)
		{
			bgmVolum_ = 0;
			return new CSceneEnd();
		}
		break;
	}
	

	return this;
}

// �`��
void CSceneMain::draw()
{
	//Draw_FontText(100,200,0.5f,"���C�����",-1,0);
	// ObjectBase�`��
	shareRes_->Draw();
	for(auto& obj : objs)
	{
		obj->draw();
	}
}


#pragma endregion
// CSceneMain methods

