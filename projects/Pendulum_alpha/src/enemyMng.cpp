
#include "enemyMng.h"
#include "define.h"
#include <algorithm>
#include <functional>
#include <fstream>
#include <sstream>

//---------------------------------
// �G
#include "bird.h"
//---------------------------------


CEnemyMng::CEnemyMng():
	Base("EnemyMng")
{
}




void CEnemyMng::step()
{
	for(auto& enemy : enemies_)
		enemy->step();

	EraseObject(enemies_);
	if(!temp_.empty())
	{
		enemies_.insert(enemies_.end(), temp_.begin(), temp_.end());
		temp_.clear();
	}
}

void CEnemyMng::draw()
{
	for(auto& enemy : enemies_)
		enemy->draw();
}

ObjPtr CEnemyMng::GetPtr()
{
	auto& em = GetObjects("EnemyMng");
	if(em.empty()) return nullptr;
	return em[0];
}

void CEnemyMng::LoadEnemiesInfo(const std::string& fileName)
{
	
	std::stringstream file;
	file << "res/txt/enemy/" << fileName;
	std::ifstream f(file.str());
	if(f.fail())return;
	enemies_.clear();
	temp_.clear();

	// ��
	if(FindChunk(f, "#Bird"))
	{
		std::string label;
		f >> label;
		if(label == "{")
		{
			while(!f.eof())
			{
				float pos[2];	// [0]:x [1]:y
				for(auto& p : pos)
				{
					f >> label;
					// �G���[�`�F�b�N
					if(label == "}" || f.eof())break;
					p = static_cast<float>(std::atof(label.c_str()));
				}
				if(label == "}") break;
				enemies_.push_back(EnemyPtr(new CBird(pos[0], pos[1])));
			}
		}
		f.clear();
		f.seekg(0);
	}

	// �ʓG
	if(FindChunk(f, "#enemyName"))
	{
		std::string label;
		f >> label;
		if(label == "{")
		{
			while(!f.eof())
			{
				f >> label;
			}
		}
	}

}

void CEnemyMng::CreateEnemy(const EnemyPtr& enemy)
{
	temp_.push_back(enemy);
}

std::vector<EnemyPtr> CEnemyMng::GetEnemies()
{
	return enemies_;
}

