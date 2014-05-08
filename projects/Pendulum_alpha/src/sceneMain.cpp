#include "sceneMain.h"
#include "define.h"

#include "Collision.h"		// Collision���o�p
#include "enemyMng.h"
#include "setting.h"

#include "Fade.h"

#include "sceneEnd.h"		// �V�[���J��

extern CGameManager* gm;


//======================================
// CSceneMain methods
#pragma region
// �R���X�g���N�^
CSceneMain::CSceneMain()
{
	InsertObject(ObjPtr(new CCollision()));
	CFade::StartFadeIn();
	bgm::DShow_Play("bgm_main");
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
		// �����A�N�V�������N�����ăV�[�����؂�ւ��Ƃ�
		if(input::CheckPush(input::KEY_BTN0))
		{
			state_ = State::OUTING;
		}
		break;
	case State::OUTING:
		const float end_time = 0.4f;	// �I���b
		// BGM�t�F�[�h�A�E�g
		bgmVolum_ -= static_cast<int>(100.f / end_time * system::FrameTime);
		bgm::DShow_VolumeControl("bgm_main", bgmVolum_);
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
}


#pragma endregion
// CSceneMain methods

