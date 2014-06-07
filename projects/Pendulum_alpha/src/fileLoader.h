#ifndef DEF_FILELOADER_H
#define DEF_FILELOADER_H

#ifndef DEF_ENEMYBASE_HPP
#include "enemyBase.hpp"
#endif

#include <vector>

/*
	@brief	�t�@�C���ǂݍ��݃N���X
			CFileMng���Ăяo�����
*/
class CFileLoader
{
	typedef std::unordered_map<std::string, int> FontTable;
	// ���\�[�X�t�@�C���p
	struct ResData
	{
		std::string resname;
		std::string path;
	};

	const std::string iniFile_;
private:
	//---------------------------------
#pragma region ���\�[�X�t�@�C���ǂݍ��݊֘A
	/*
		@brief	���\�[�X�t�@�C���ǂݍ��ݏ���
		@param	[in/out]	resFile		���\�[�X�t�@�C���ꗗ�t�@�C���p�X
		@param	[out]		fontTablle	�t�H���g�Ǘ��e�[�u��
		@return	�Ȃ�
	*/
	void LoadRes(const std::string& resFile, FontTable& fontTable);
	/*
		@brief	�摜�t�@�C���ǂݍ���
		@param	[in/out]	resF	���\�[�X�t�@�C���ꗗ�t�@�C��
		@return	�Ȃ�
	*/
	void LoadImg(std::ifstream& resF);
	/*
		@brief	BGM�ǂݍ���
		@param	[in/out]	resF	���\�[�X�t�@�C���ꗗ�t�@�C��
		@return	�Ȃ�
	*/
	void LoadBGM(std::ifstream& resF);
	/*
		@brief	SE�ǂݍ���
		@param	[in/out]	resF	���\�[�X�t�@�C���ꗗ�t�@�C��
		@return	�Ȃ�
	*/
	void LoadSE(std::ifstream& resF);
	/*
		@brief	�t�H���g�ǂݍ���
		@param	[in/out]	resF		���\�[�X�t�@�C���ꗗ�t�@�C��
		@param	[out]		fontTable	�t�H���g�Ǘ��e�[�u��
		@return	�Ȃ�
	*/
	void LoadFont(std::ifstream& resF, FontTable& fontTable);
#pragma endregion	// ���\�[�X�t�@�C���ǂݍ��݊֘A
	//---------------------------------
public:
	/*
		@brief	�e�t�@�C���ǂݍ���
		@param	[in]	iniFile	�ݒ�t�@�C���p�X
	*/
	CFileLoader(const std::string& iniFile);

	/*
		@brief	�e�t�@�C���ǂݍ���
		@param	[in]	iniFile		�ݒ�t�@�C���p�X
		@param	[out]	fontTable	�t�H���g�Ǘ��e�[�u��
	*/
	CFileLoader(const std::string& iniFile, FontTable& fontTable);


	/*
		@brief	�G�����t�@�C�����烍�[�h����
		@param	[in]	enemyFile	�G���ꗗ�t�@�C����
		@param	[out]	enemies		���[�h�����G�����i�[����z��
		@return	�Ȃ�
	*/
	void LoadEnemiesData(const std::string& enemyFile, std::vector<EnemyPtr>& enemies);
};


#endif