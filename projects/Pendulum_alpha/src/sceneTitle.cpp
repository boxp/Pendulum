#include "sceneTitle.h"
#include "define.h"

#include "setting.h"

#include "sceneStageSelect.h"

//======================================
// CSceneTitle methods
#pragma region
// �R���X�g���N�^
CSceneTitle::CSceneTitle() :
IScene("bgm_title")
, phase_(Phase::TITLE)
{
	CFade::ChangeColor(-1);
}
CSceneTitle::~CSceneTitle()
{
	
}


// �`��
void CSceneTitle::draw()
{
	//DSound_
	font::Draw_FontTextNC(100, 200, 0.5f, "�^�C�g�����", -1, 0);
	font::Draw_FontTextNC(100, 250, 0.5f, "�{�^��1�ŃV�[���؂�ւ�", -1, 0);
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
bool CSceneTitle::update()
{
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

	// �����A�N�V�������N�����ăV�[�����؂�ւ��Ƃ�
	if (input::CheckPush(input::KEY_BTN0))
	{
		return true;
	}
	return false;
}

IScene* CSceneTitle::NextScene()
{
	return new CSceneStageSelect();
}


#pragma endregion
// CSceneTitle methods

