#include "fileLoader.h"

#include "../../../lib/gplib.h"
using namespace gplib;
#include "common.h"

#include "bird.h"

#include "player.h"

#include <string>
#include <fstream>

CFileLoader::CFileLoader(const std::string& iniFile) :
iniFile_(iniFile)
{
	std::ifstream iniF(iniFile);
	if (iniF.fail())
	{
		gplib::debug::BToM("CFileLoader::CFileLoader iniFpath:%s", iniFile.c_str());
	}
	else
	{
		if (common::FindChunk(iniF, "#ResourceFile"))
		{
			std::string resFile;
			iniF >> resFile;
			LoadRes(resFile, FontTable());
		}
	}
}
CFileLoader::CFileLoader(const std::string& iniFile, FontTable& fontTable) :
iniFile_(iniFile)
{
	std::ifstream iniF(iniFile);
	if (iniF.fail())
	{
		gplib::debug::BToM("CFileLoader::CFileLoader iniFpath:%s", iniFile.c_str());
	}
	else
	{
		if (common::FindChunk(iniF, "#ResourceFile"))
		{
			std::string resFile;
			iniF >> resFile;
			LoadRes(resFile, fontTable);
		}
	}
}

//=======================================================
#pragma region ���\�[�X�t�@�C���ǂݍ���
void CFileLoader::LoadRes(const std::string& resFile, FontTable& fontTable)
{
	//====================================
	// ���\�[�X�t�@�C���ǂݍ���
	ifstream resF(resFile);
	if (resF.fail())
	{
		gplib::debug::BToM("CFileLoader::LoadRes path:%s", resFile.c_str());
		return;
	}

	//--------------------------
	if (common::FindChunk(resF, "#Img"))
	{
		LoadImg(resF);
	}
	common::SeekSet(resF);
	if (common::FindChunk(resF, "#Bgm"))
	{
		LoadBGM(resF);
	}
	common::SeekSet(resF);
	if (common::FindChunk(resF, "#Se"))
	{
		LoadSE(resF);
	}
	common::SeekSet(resF);
	if (common::FindChunk(resF, "#Font"))
	{
		LoadFont(resF, fontTable);
	}
	common::SeekSet(resF);
}

// �摜���[�h
void CFileLoader::LoadImg(ifstream& resF)
{
	std::string buf;
	resF >> buf;
	if (buf != "{") return;
	while (!resF.eof())
	{
		resF >> buf;
		if (buf == "}") return;
		ResData data;
		D3DCOLOR transparent;
		data.resname = buf;
		resF >> data.path >> std::hex >> transparent;

		graph::Draw_LoadObject(data.resname, data.path, transparent);
	}
}

// BGM���[�h
void CFileLoader::LoadBGM(ifstream& resF)
{
	std::string buf;
	resF >> buf;
	if (buf != "{") return;
	while (!resF.eof())
	{
		resF >> buf;
		if (buf == "}") return;
		ResData data;
		data.resname = buf;
		resF >> data.path;
		bgm::DShow_LoadFile(data.resname, data.path);
	}
}

// SE���[�h
void CFileLoader::LoadSE(ifstream& resF)
{
	std::string buf;
	resF >> buf;
	if (buf != "{") return;
	while (!resF.eof())
	{
		resF >> buf;
		if (buf == "}") return;
		ResData data;
		data.resname = buf;
		resF >> data.path;
		se::DSound_LoadFile(data.resname, data.path);
	}
}

// �t�H���g���[�h
void CFileLoader::LoadFont(ifstream& resF, FontTable& fontTable)
{
	fontTable.clear();
	std::string buf;
	resF >> buf;
	if (buf != "{") return;
	int i = 0;
	while (!resF.eof())
	{
		resF >> buf;
		if (buf == "}") return;
		ResData data;
		int size;
		data.resname = buf;
		resF >> data.path >> std::dec >> size;
		data.path = common::StrReplace(data.path, "�Q", "");
		font::Draw_CreateFont(i, size, data.path.c_str());
		fontTable.insert(std::unordered_map<std::string, int>::value_type(data.resname, i));
		i++;
	}
}

#pragma endregion // ���\�[�X�t�@�C���ǂݍ���
//=======================================================

//=======================================================
#pragma region �G�e�[�u���ǂݍ���
bool CFileLoader::LoadBird(const std::string& fileName, std::vector<EnemyPtr>& enemies)
{
	using common::FindChunk;
	using common::SeekSet;
	std::ifstream eneF(fileName);
	if (eneF.fail())
	{
		debug::BToM("CFileLoader::LoadBird path:%s", fileName.c_str());
		return false;
	}
	// ��񃍁[�h�p
	CBird tmp;
	charabase::CharBase cb;
	// �t�@�C��������𔲂����ۂ̃^�O�����p
	bool success;
	// success ����x�ł�false�ɂȂ����瑼�����X�L�b�v
	// if (success){
	// 	���[�h
	// }
	// else {
	// 	return;
	// }�݂����Ȋ���

	//-----------------------------------------------
	// �摜�Ǘ���
	if (success = FindChunk(SeekSet(eneF), "#Img"))
	{
		eneF >> cb.resname;
	}
	// �摜�T�C�Y
	if (success && (success = FindChunk(SeekSet(eneF), "#Size")))
	{
		eneF >> cb.size.x;
		eneF >> cb.size.y;
	}
	// �����蔻��
	if (success && (success = FindChunk(SeekSet(eneF), "#Collision")))
	{
		tmp.LoadCollisions(eneF);
	}
	// �U��
	if (success && (success = FindChunk(SeekSet(eneF), "#Attack")))
	{
		tmp.LoadAttack(eneF);
	}

	if (success)
	{
		//-----------------------------------------------
		// �S�Ă̏�񂪐������ǂݍ��߂��ۂ݂̂����ɓ���
		// �摜���ݒ�
		tmp.obj(cb);
		// �R�s�[�R���X�g���N�^��p���I���W�i���쐬
		enemies.push_back(EnemyPtr(new CBird(tmp)));
	}

	return success;
}

#pragma endregion	// �G�e�[�u���ǂݍ���
//=======================================================




//=======================================================
bool CFileLoader::LoadPlayerData(CPlayer& player)
{
	using common::FindChunk;
	using common::SeekSet;
	//========================================================
	// �p�X�t�@�C������GDB�t�@�C���p�X�̓ǂݍ���
	std::ifstream iniF(iniFile_);
	std::string playerFile;
	if (iniF.fail() || (!FindChunk(iniF, "#PlayerFile")))
	{
		debug::BToM("CFileLoader::LoadPlayerData [iniF]Error path:%s", iniFile_.c_str());
		return false;
	}
	iniF >> playerFile;
	//========================================================
	// DB�t�@�C�����J��
	std::ifstream f(playerFile);
	if (f.fail())
	{
		debug::BToM("CFileLoader::LoadPlayerData [f]Error path:%s", playerFile.c_str());
		return false;
	}

	// ��񃍁[�h�p
	CPlayer tmp;
	charabase::CharBase cb;
	CPlayer::LoadInfo info;
	// �t�@�C��������𔲂����ۂ̃^�O�����p
	bool success;
	// success ����x�ł�false�ɂȂ����瑼�����X�L�b�v
	// if (success){
	// 	���[�h
	// }
	// else {
	// 	return;
	// }�݂����Ȋ���

	//-----------------------------------------------
	// �摜�Ǘ���
	if (success = FindChunk(SeekSet(f), "#Img"))
	{
		f >> cb.resname;
	}
	// �摜�T�C�Y
	if (success && (success = FindChunk(SeekSet(f), "#Size")))
	{
		f >> cb.size.x;
		f >> cb.size.y;
	}
	// �����蔻��
	if (success && (success = FindChunk(SeekSet(f), "#Collision")))
	{
		tmp.LoadCollisions(f);
	}

	if (success)
	{
		//-----------------------------------------------
		// �S�Ă̏�񂪐������ǂݍ��߂��ۂ݂̂����ɓ���
		// �摜���ݒ�
		tmp.obj(cb);
		// �p�����[�^
		tmp.SetInfo(info);
		// �����p���I���W�i������
		player = tmp;
	}
	return success;
}
//=======================================================



void CFileLoader::LoadEnemiesData(std::vector<EnemyPtr>& enemies)
{
	using common::FindChunk;
	using common::SeekSet;
	//========================================================
	// �p�X�t�@�C������GDB�t�@�C���p�X�̓ǂݍ���
	std::ifstream iniF(iniFile_);
	std::string enemyFile;
	if (iniF.fail() || (!FindChunk(iniF, "#EnemyFile")))
	{
		debug::BToM("CFileLoader::LoadEnemiesData [iniF]Error path:%s", iniFile_.c_str());
		return;
	}
	iniF >> enemyFile;
	//========================================================
	// DB�t�@�C�����J��
	std::ifstream f(enemyFile);
	if (f.fail())
	{
		debug::BToM("CFileLoader::LoadEnemiesData [f]Error path:%s", enemyFile.c_str());
		return;
	}

	// �G�e�[�u��������
	enemies.clear();

	//========================================================
	// �G���ǂݍ��݊J�n
	if (FindChunk(SeekSet(f),"#Bird"))
	{
		std::string buf;
		f >> buf;
		LoadBird(buf, enemies);
	}
	//========================================================

}