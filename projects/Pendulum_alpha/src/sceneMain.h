#ifndef DEF_SCENEMAIN_H
#define DEF_SCENEMAIN_H

#ifndef DEF_SCENEBASE_HPP
#include "sceneBase.hpp"
#endif


class CSceneMain : public IScene
{
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
	CSceneMain();
	~CSceneMain();
	void	draw() override;	// �`��
};


#endif 