#include "sceneEnd.h"
#include "define.h"

#include "sceneTitle.h"

#include "scoreMng.h"

//======================================
// CSceneEnd methods
#pragma region
// �R���X�g���N�^
CSceneEnd::CSceneEnd():
IScene("img_end", "bgm_end")
{
	// �X�R�A�}�l�[�W���̂݃R�s�[���������Ă���
	auto scoreManager = std::dynamic_pointer_cast<CScoreMng>(gm()->GetObj(typeid(CScoreMng)));
	scoreManager->score(100);
	// ���C���Q�[�����̃I�u�W�F�N�g����
	gm()->init();
	// �ēx�K�v�ȃI�u�W�F�N�g�̒ǉ�
	InsertObject(ObjPtr(new CScoreMng(*scoreManager)));
}
CSceneEnd::~CSceneEnd()
{
}

// �`��
void CSceneEnd::draw()
{
	font::Draw_FontTextNC(100, 200, 0.5f, "�G���h���", -1, 0);

	// �w�i
	//__super::draw();

}

// ����
bool CSceneEnd::update()
{

	// �����A�N�V�������N�����ăV�[�����؂�ւ��Ƃ�
	if (input::CheckPush(input::KEY_BTN0))
	{
		auto& sm = std::dynamic_pointer_cast<CScoreMng>(gm()->GetObj(typeid(CScoreMng)));
		sm->RegisterRanking("MAON");
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
