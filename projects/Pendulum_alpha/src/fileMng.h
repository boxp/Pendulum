#ifndef DEF_FILEMNG_H
#define DEF_FILEMNG_H

#ifndef DEF_OBJ_H
#include "obj.h"
#endif

#include <vector>

/*
	@brief	�t�@�C���Ǘ��N���X(�f�[�^�x�[�X)
			�Q�[���}�l�[�W���ɕێ������
*/
class CFileMng
{
private:
	// �t�H���g�p
	std::unordered_map<std::string, int> fontTable_;

	// �f�[�^�ꗗ
	std::vector<ObjPtr> dataTable_;

private:

public:

	CFileMng();

	/*
		@brief	���ǂݍ���
		@param	[in]	iniFile		�ݒ�t�@�C���p�X
		@return	�Ȃ�
	*/
	void Load(const std::string& iniFile);

	/*
		@brief	���̎擾
		@param	[in/out]	obj	�i�[����N���X�I�u�W�F�N�g
								�^���ŃL���X�g���s��
		@return	����ݒ�ł�����
		@retval	true	�ݒ萬��
		@retval	false	�ݒ莸�s
	*/
	template<class OBJ>	bool GetData(OBJ& obj) const
	{
		bool ret = false;
		const std::string& name = obj.getName();
		for (auto& data : dataTable_)
		{
			if (name == data->getName())
			{
				obj = *(std::dynamic_pointer_cast<OBJ>(data));
				//return true;
				ret = true;
				break;
			}
		}
		return ret;
	}

};


#endif