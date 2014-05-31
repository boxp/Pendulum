#ifndef DEF_SCENEEND_H
#define DEF_SCENEEND_H

#ifndef DEF_SCENEBASE_HPP
#include "sceneBase.hpp"
#endif

class CSceneEnd : public IScene
{
private:
	enum class State
	{
		NAME,					// ���O�I��
		REGISTER_ANIM,			// �o�^����A�j���[�V������
		ANIM_END,				// �A�j���[�V�����I��
	};
	State state_;

	int selectChar_;			// �I�𕶎��ԍ�

	float registerAnimTime_;	// �o�^�A�j���[�V�����J�E���g


private:
	/*
		@brief	���O�I������
		@return	�Ȃ�
	*/
	void DecideName();

	/*
		@brief	�o�^����A�j���[�V��������
		@return	�Ȃ�
	*/
	void RegisterAnimation();

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
	CSceneEnd();
	~CSceneEnd();
	void	draw() override;	// �`��
};


#endif