#ifndef DEF_SCENETITLE_H
#define DEF_SCENETITLE_H

#ifndef DEF_SCENEBASE_HPP
#include "sceneBase.hpp"
#endif

class CSceneTitle : public IScene
{
private:
	enum class Phase
	{
		TITLE,			// ���C���^�C�g�����
		DEMO,			// �f���v���C
	}phase_;			// �t�F�[�Y

	float phaseTime_;	// �e�t�F�[�Y�\������

	//-------------------------------------
	// �f���v���C�ŕK�v�ȕϐ���
	class CDemo
	{
	public:
		mymath::Vec3f pos;
	}demo_;
	//-------------------------------------

private:
	/*
		@brief	�^�C�g����ʕ\������������
		@return	�Ȃ�
	*/
	void TitleInit();
	/*
		@brief	�^�C�g����ʎ��̍X�V����
		@return	�Ȃ�
	*/
	void TitleStep();
	/*
		@brief	�f���v���C����������
		@return �Ȃ�
	*/
	void DemoInit();
	/*
		@brief	�f���v���C�\�����̍X�V����
		@return	�Ȃ�
	*/
	void DemoStep();
public:
	CSceneTitle();
	~CSceneTitle();
	IScene* step() override;	// �X�V
	void	draw() override;	// �`��
};


#endif