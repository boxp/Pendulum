#ifndef DEF_FILEMNG_H
#define DEF_FILEMNG_H

#ifndef DEF_ENEMYBASE_HPP
#include "enemyBase.hpp"
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

	// �G�f�[�^
	std::vector<EnemyPtr> enemiesData_;

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
		@brief	�G���̐ݒ�
		@param	[in/out]	enemy	�i�[����G�N���X�I�u�W�F�N�g
		@return	�G����ݒ�ł�����
		@retval	true	�ݒ萬��
		@retval	false	�ݒ莸�s
	*/
	template<class ENEMY>	void GetEnemyData(ENEMY& enemy) const
	{
		if (enemiesData_.empty())	LoadEnemiesData();
		bool ret = false;
		const std::string& name = enemy.getName();
		for (const auto& data : enemiesData_)
		{
			if (name == data->getName())
			{
				enemy = *data;
				//return true;
				ret = true;
				break;
			}
		}
		return ret;
	}

};


#endif