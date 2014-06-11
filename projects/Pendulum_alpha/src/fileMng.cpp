#include "fileMng.h"

#include "fileLoader.h"

#include "player.h"
#include "enemyBase.hpp"


#include <fstream>

CFileMng::CFileMng()
{
	fontTable_.clear();
	dataTable_.clear();
}

void CFileMng::Load(const std::string& iniFile)
{
	//fontTable_.clear
	CFileLoader fl(iniFile, fontTable_);

	// �v���C���[
	std::shared_ptr<CPlayer> player;
	fl.LoadPlayerData(*player);
	
	// �G
	std::vector<EnemyPtr> enemies;
	fl.LoadEnemiesData(enemies);

	//=====================================
	// �z����
	// push_back�p�ɃT�C�Y���g��(player + size())
	dataTable_.reserve(1 + enemies.size());
	// �v���C���[
	dataTable_.push_back(player);

	// �G
	for (auto& enemy : enemies)
		dataTable_.push_back(enemy);
}