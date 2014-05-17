#include "sceneTitle.h"
#include "define.h"

#include "setting.h"

#include "sceneStageSelect.h"

//======================================
// CSceneTitle methods
#pragma region
// �R���X�g���N�^
CSceneTitle::CSceneTitle()
{
	
}
CSceneTitle::~CSceneTitle()
{
}

void CSceneTitle::TitleInit()
{
	phaseTime_ = 0.f;
}


void CSceneTitle::TitleStep()
{
	phaseTime_ += system::FrameTime;
	const float demoTime = 2.f;	// �f���v���C�Ɉړ�����܂ł̎���
	if (phaseTime_ >= demoTime)
	{
		DemoInit();
		phase_ = Phase::DEMO;	// �f���v���C��Ԃ�
	}
}

void CSceneTitle::DemoInit()
{
	phaseTime_ = 0.f;
	demo_.pos.x = 100.f;
}
void CSceneTitle::DemoStep()
{
	demo_.pos.x += 100.f * system::FrameTime;
	// �f���v���C�I��
	if (demo_.pos.x >= 200.f)
	{
		TitleInit();
		phase_ = Phase::TITLE;	// �^�C�g����ʂ�
	}
}

// ����
IScene* CSceneTitle::step()
{
	switch (state_)
	{
	case IScene::State::INNING:
		break;
	case IScene::State::MAIN:
		switch (phase_)
		{
		case Phase::TITLE:
			// �^�C�g����ʕ\����
			TitleStep();
			break;
		case Phase::DEMO:
			// �f���v���C�\����
			DemoStep();
			break;
		}
		break;
	case IScene::State::OUTING:
		break;
	default:
		break;
	}

	// �����A�N�V�������N�����ăV�[�����؂�ւ��Ƃ�
	if(input::CheckPush(input::KEY_BTN0))
	{
		return new CSceneStageSelect();
	}
	return this;
}

// �`��
void CSceneTitle::draw()
{
	//DSound_
	font::Draw_FontTextNC(100,200,0.5f,"�^�C�g�����",-1,0);
	font::Draw_FontTextNC(100,250,0.5f,"�{�^��1�ŃV�[���؂�ւ�",-1,0);
}


#pragma endregion
// CSceneTitle methods

