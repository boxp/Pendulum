#ifndef DEF_FILEMNG_H
#define DEF_FILEMNG_H

#ifndef DEF_OBJ_H
#include "obj.h"
#endif

#ifndef DEF_FILELOADER_H
#include "fileLoader.h"
#endif

#include <vector>

/*
	@brief	�t�@�C���Ǘ��N���X(�f�[�^�x�[�X)
			�Q�[���}�l�[�W���ɕێ������
*/
class CFileMng
{
private:
	const std::string iniFile_;			// path.ini�t�@�C���p�X

	CFileLoader fileLoader_;			// �t�@�C�����[�_�[

	// �t�H���g�p
	CFileLoader::FontTable fontTable_;

	// �f�[�^�ꗗ
	std::vector<ObjPtr> dataTable_;

private:

public:

	/*
		@brief	���ǂݍ���
		@param	[in]	iniFile		�ݒ�t�@�C���p�X
	*/
	CFileMng(const std::string& iniFile);

	/*
		@brief	���ǂݍ���
		@return	�Ȃ�
	*/
	void Load();

	/*
		@brief	�t�@�C���p�X�擾
			GetFile("#File")
		@param	[in]	tag	�擾�t�@�C�����ʖ�(#�^�O)
		@return �t�@�C���p�X
	*/
	std::string GetFile(const std::string& tag) const;

	/*
		@brief	���̎擾
			GetData(this);
		@param	[in/out]	obj	�i�[����N���X�I�u�W�F�N�g
								�^���ŃL���X�g���s��
		@return	����ݒ�ł�����
		@retval	true	�ݒ萬��
		@retval	false	�ݒ莸�s
	*/
	template<class OBJ>	bool GetData(OBJ* obj) const
	{
		bool successed = false;
		const std::string& name = obj->getName();
		for (auto& data : dataTable_)
		{
			if (name == data->getName())
			{
				*obj = *(std::dynamic_pointer_cast<OBJ>(data));
				//return true;
				successed = true;
				break;
			}
		}
		return successed;
	}
	/*
		@brief	���̎擾
			GetData(*this);
		@param	[in/out]	obj	�i�[����N���X�I�u�W�F�N�g
							�^���ŃL���X�g���s��
		@return	����ݒ�ł�����
		@retval	true	�ݒ萬��
		@retval	false	�ݒ莸�s
	*/
	template<class OBJ>	bool GetData(OBJ& obj) const
	{
		bool successed = false;
		const std::string& name = obj.getName();
		for (auto& data : dataTable_)
		{
			if (name == data->getName())
			{
				obj = *(std::dynamic_pointer_cast<OBJ>(data));
				//return true;
				successed = true;
				break;
			}
		}
		return successed;
	}

};

#endif