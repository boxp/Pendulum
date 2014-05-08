#include "sceneStageSelect.h"
#include "define.h"

#include "sceneMain.h"
#include "Fade.h"

#include "stageMng.h"

extern CGameManager* gm;

//======================================
// CSceneStageSelect methods
#pragma region CSceneStageSelect methods
// �R���X�g���N�^
CSceneStageSelect::CSceneStageSelect()
{
	state_ = State::MAIN;
	InsertObject(ObjPtr(new CStageMng()));
}
CSceneStageSelect::~CSceneStageSelect()
{
}



// ����
IScene* CSceneStageSelect::step()
{
	if(state_ == State::INNING)
	{
		if(!CFade::FadeIn(255.f/20.f))
		{
			return this;
		}
		else
		{
			state_ = State::MAIN;
		}
	}
	else if(state_ == State::OUTING)
	{
		if(CFade::FadeOut(255.f/20.f))
		{
			const auto& sm = gm->GetObjects("SceneMng");
			if (!sm.empty())
			{
				std::dynamic_pointer_cast<CStageMng>(sm[0])->LoadStage("stage01");
			}
			return new CSceneMain();
		}
		/*
		const float end_time = 0.4f;	// �I���b
		// BGM�t�F�[�h�A�E�g
		bgmVolum_ -= static_cast<int>(100.f / end_time * FrameTime);
		DShow_VolumeControl(BGM::MAIN,bgmVolum_);
		if(bgmVolum_ <= 0)
		{
			bgmVolum_ = 0;
			return new CSceneEnd();
		}
		*/
	}
	else
	{
		// �����A�N�V�������N�����ăV�[�����؂�ւ��Ƃ�
		if(input::CheckPush(input::KEY_BTN0))
		{
			state_ = State::OUTING;
			if(!CFade::IsFadeOuting())
			{
				CFade::ChangeColor(255,255,255);
				CFade::StartFadeOut();
			}
		}
	}


	return this;
}

// �`��
void CSceneStageSelect::draw()
{
	font::Draw_FontTextNC(100,200,0.5f,"�X�e�[�W�Z���N�g���",-1,0);
}


#pragma endregion CSceneStageSelect methods
// CSceneStageSelect methods

