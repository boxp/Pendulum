#include "sceneEnd.h"
#include "lib\gplib.h"

#include "sceneTitle.h"

//======================================
// CSceneEnd methods
#pragma region
// �R���X�g���N�^
CSceneEnd::CSceneEnd()
{
}
CSceneEnd::~CSceneEnd()
{
}


// ����
IScene* CSceneEnd::step()
{
	// �����A�N�V�������N�����ăV�[�����؂�ւ��Ƃ�
	if(CheckPush(KEY_BTN0))
	{
		return new CSceneTitle();
	}
	return this;
}


// �`��
void CSceneEnd::draw()
{
	Draw_FontText(100,200,0.5f,"�G���h���",-1,0);
}

#pragma endregion
// CSceneEnd methods
