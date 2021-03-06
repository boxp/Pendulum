#include "fileMng.h"


#include "player.h"
#include "enemyBase.hpp"


#include <fstream>

CFileMng::CFileMng(const std::string& iniFile):
iniFile_(iniFile)
, fileLoader_(iniFile_)
{
	fontTable_.clear();
	dataTable_.clear();
	fileLoader_.Load(fontTable_);
}

void CFileMng::Load()
{
	//fontTable_.clear

	// プレイヤー
	auto player = std::shared_ptr<CPlayer>(new CPlayer());
	fileLoader_.LoadPlayerData(*player);
	
	// 敵
	std::vector<EnemyPtr> enemies;
	fileLoader_.LoadEnemiesData(enemies);

	//=====================================
	// 配列代入
	// push_back用にサイズを拡張(player + size())
	dataTable_.reserve(1 + enemies.size());
	// プレイヤー
	dataTable_.push_back(player);

	// 敵
	for (auto& enemy : enemies)
		dataTable_.push_back(enemy);
}


std::string CFileMng::GetFile(const std::string& tag) const
{
	return fileLoader_.GetFile(tag);
}