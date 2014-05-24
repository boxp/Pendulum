#include "scoreMng.h"

#include <fstream>

#include <algorithm>	// sort
#include <functional>	// greater


const std::string CScoreMng::RANKING_FILE = "res/dat/rank.dat";

CScoreMng::CScoreMng():
Base("ScoreMng")
, score_(0)
{
	// �����L���O���ǂݍ���
	ranking_.clear();
	ranking_.reserve(RANK_NUM + 1);
	std::ifstream f(RANKING_FILE);
	if (f.is_open())
	{
		while (!f.eof())
		{
			Ranking tmp;
			f >> tmp.name >> tmp.score;
			if (f.eof())break;
			ranking_.push_back(tmp);
		}
	}

	ranking_.resize(RANK_NUM, Ranking::empty());
}

void CScoreMng::init()
{
	ranking_.clear();
}

void CScoreMng::step()
{

}

void CScoreMng::draw()
{

}


void CScoreMng::score(int s)
{
	score_ = s;
}

int CScoreMng::score() const
{
	return score_;
}

void CScoreMng::RegisterRanking(const std::string& name)
{
	Ranking tmp = { name, score_ };
	ranking_.push_back(tmp);

	// �X�R�A�~���\�[�g
	std::sort(ranking_.begin(), ranking_.end(), std::greater<Ranking>());

	// �����L���O��������
	ranking_.resize(RANK_NUM, Ranking::empty());
	//ranking_.pop_back();

	// �����L���O�t�@�C���㏑��
	std::ofstream f(RANKING_FILE);
	for (const auto& rank : ranking_)
	{
		f << rank.name << "\t" << rank.score << std::endl;
	}


	
}