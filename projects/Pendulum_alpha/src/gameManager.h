#ifndef DEF_GAMEMANAGER_H
#define DEF_GAMEMANAGER_H

//���C�u����
#ifndef DEF_DEFINE_H
#include "define.h"
#endif
using namespace gplib;

#ifndef DEF_OBJ_H
#include "obj.h"
#endif

#include	<vector>
#include	<typeinfo>

//-------------------------------------------------
//�Q�[���̊Ǘ����s���B
//Object���p�����Ă���N���X�͑S�ĊǗ������B
class CGameManager
{
private:
	//�o�����̃I�u�W�F�N�g���Ǘ�
	std::vector<ObjPtr>	objs_;
	//�ǉ��\��̃I�u�W�F�N�g���Ǘ�
	std::vector<ObjPtr>	addObjs_;
	//�Q�[���N���A��Ԃ𔭓�����B
	bool clear_;
	float count_;

	static mymath::Recti* winRect_;		// �E�B���h�E�T�C�Y


private:

	/*
		@brief	�I�u�W�F�N�g�̒ǉ��A�폜���s��
		@return	�Ȃ�
	*/
	void MargeObjects();

public:

	CGameManager();
	~CGameManager();
	/*
		@brief	������	
		@return	�Ȃ�
	*/
	void init();
	/*
		@brief	�S�I�u�W�F�N�g�̍X�V����
		@return	�Ȃ�
	*/
	void step();
	/*
		@brief	�S�I�u�W�F�N�g�̕`��
		@return	�Ȃ�
	*/
	void draw();

	/*
		@brief		�I�u�W�F�N�g�̒ǉ�
		@attention	�I�u�W�F�N�g�����ۂɒǉ������̂�1�t���[����
		@parama		[in]	obj	�ǉ�����I�u�W�F�N�g
		@return		�Ȃ�
	*/
	void AddObject(const ObjPtr& obj);
	/*
		@brief		�I�u�W�F�N�g�̑����ǉ�
		@parama		[in]	obj	�ǉ�����I�u�W�F�N�g
		@return		�Ȃ�
	*/
	void AddObject2(const ObjPtr& obj);

	//�w��̃N���X�������o���ĕԂ�
	ObjPtr GetObj(const type_info& objinfo);

	/*
		@brief	�ǉ�����Ă���S�I�u�W�F�N�g���擾
		@return	�I�u�W�F�N�g�Q
	*/
	std::vector<ObjPtr>& GetObjects();

	/*
		@brief	�^����ꂽ���O���܂ރI�u�W�F�N�g���擾
				GetObjects("Collision");
		@param	[in] taskName	�T���I�u�W�F�N�g��
		@return	�I�u�W�F�N�g�Q
	*/
	std::vector<ObjPtr> GetObjects(const std::string& taskName);
	/*
		@brief	�^����ꂽ���O���܂ރI�u�W�F�N�g���擾
				GetObjects("Player,Enemy", ",");
		@param	[in] taskName	�T���I�u�W�F�N�g��
		@param	[in] delim		��؂蕶��
		@return	�I�u�W�F�N�g�Q
	*/
	std::vector<ObjPtr> GetObjects(const std::string& taskName, const char delim);
	
	/*
		@brief	�I�u�W�F�N�g�̑S����
		@return	�Ȃ�
	*/
	void ClearObjects();



	void setClear(bool clear);
	bool getClear() const;
	void StartClear();
	void ClearToChangeScreen(int next);

	/*
		@brief	�E�B���h�E�T�C�Y�̎擾
		@return	�E�B���h�E�T�C�Y
	*/
	const mymath::Recti* winRect() const;
	/*
		@brief	�V�����E�B���h�E�T�C�Y�̑��
		@param	[in]	newRect	�V�����E�B���h�E�T�C�Y
		@return	�Ȃ�
	*/
	void winRect(const mymath::Recti& newRect);
	/*
		@brief	�E�B���h�E�T�C�Y�̎Q�Ɛ��ύX
		@param	[in]	newRect	�V�����E�B���h�E�T�C�Y�Q�Ɛ�
		@return	�Ȃ�
	*/
	void winRect(mymath::Recti* newRect);

	/*
		@brief	�v���C���[���W�̎擾
		@return	�v���C���[�I�u�W�F�N�g�̍��W
	*/
	mymath::Vec3f GetPlayerPos() const;

};

extern void InsertObject(const ObjPtr& obj);


#endif

