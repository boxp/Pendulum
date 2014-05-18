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
CSceneStageSelect::CSceneStageSelect() :
IScene("bgm_stageSelect")
{
	InsertObject(ObjPtr(new CStageMng()));
}
CSceneStageSelect::~CSceneStageSelect()
{
}

// �`��
void CSceneStageSelect::draw()
{
	font::Draw_FontTextNC(100, 200, 0.5f, "�X�e�[�W�Z���N�g���", -1, 0);
}


// ����
bool CSceneStageSelect::update()
{
	// �����A�N�V�������N�����ăV�[�����؂�ւ��Ƃ�
	if (input::CheckPush(input::KEY_BTN0))
	{
		CFade::ChangeColor(255, 255, 255);
		return true;
	}
	return false;
}

IScene* CSceneStageSelect::NextScene()
{
	const auto& sm = gm->GetObjects("StageMng");
	if (!sm.empty())
	{
		std::dynamic_pointer_cast<CStageMng>(sm[0])->LoadStage("stage01");
	}
	else
	{
		ObjPtr stage(new CStageMng());
		InsertObject(stage);
		std::dynamic_pointer_cast<CStageMng>(stage)->LoadStage("stage01");
	}
	return new CSceneMain();
}



#pragma endregion CSceneStageSelect methods
// CSceneStageSelect methods

