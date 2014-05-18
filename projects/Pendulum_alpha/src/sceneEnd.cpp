#include "sceneEnd.h"
#include "define.h"

#include "sceneTitle.h"

//======================================
// CSceneEnd methods
#pragma region
// �R���X�g���N�^
CSceneEnd::CSceneEnd():
IScene("bgm_end")
{
}
CSceneEnd::~CSceneEnd()
{
}

// �`��
void CSceneEnd::draw()
{
	font::Draw_FontText(100, 200, 0.5f, "�G���h���", -1, 0);
}


// ����
bool CSceneEnd::update()
{

	// �����A�N�V�������N�����ăV�[�����؂�ւ��Ƃ�
	if (input::CheckPush(input::KEY_BTN0))
	{
		return true;
	}
	return false;
}

IScene* CSceneEnd::NextScene()
{
	return new CSceneTitle();
}




#pragma endregion
// CSceneEnd methods
