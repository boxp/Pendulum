#ifndef DEF_SCENESTAGESELECT_H
#define DEF_SCENESTAGESELECT_H

#ifndef DEF_SCENEBASE_HPP
#include "sceneBase.hpp"
#endif

class CSceneStageSelect : public IScene
{
private:
	static mymath::Recti* fieldRect_;		// �X�e�[�W�I���t�B�[���h�T�C�Y
protected:
	/*
		@brief	���C���X�V����
		@return	���C���I����
		@retval	true	���C���I��(�t�F�[�h�C���J�n)
		@retval	false	���C��������
	*/
	bool update() override;

	/*
		@brief	���̃V�[���ɐ؂�ւ��u�ԂɌĂ΂��
		@return	���̃V�[��
	*/
	IScene* NextScene() override;
	
public:
	CSceneStageSelect();
	~CSceneStageSelect();
	void	draw() override;	// �`��
};

#endif