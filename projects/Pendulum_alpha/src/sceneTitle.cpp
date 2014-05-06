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



// ����
IScene* CSceneTitle::step()
{
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

