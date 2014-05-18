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
CSceneMain::CSceneMain():
IScene("bgm_main")
{
	InsertObject(ObjPtr(new CCollision()));
}
CSceneMain::~CSceneMain()
{
}

// �`��
void CSceneMain::draw()
{
	//Draw_FontText(100,200,0.5f,"���C�����",-1,0);
}

// ����
bool CSceneMain::update()
{
	// �����A�N�V�������N�����ăV�[�����؂�ւ��Ƃ�
	if (input::CheckPush(input::KEY_BTN0))
	{
		return true;
	}
	return false;
}

IScene* CSceneMain::NextScene()
{
	return new CSceneEnd();
}



#pragma endregion
// CSceneMain methods

