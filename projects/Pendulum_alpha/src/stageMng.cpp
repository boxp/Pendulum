#include "stageMng.h"

#include "define.h"

#include "setting.h"
#include "common.h"

#include "player.h"
#include "enemyMng.h"

#include <sstream>
#include <fstream>

using std::ifstream;
using common::FindChunk;

CStageMng::CStageMng():
	Base("StageMng")
	,actionPoints(actionPoints_)
	,rect(stageRect_)
{
}

bool CStageMng::LoadSize(std::ifstream& f)
{
	if(FindChunk(f,"#Left"))
	{
		f >> stageRect_.left;
	}
	if(FindChunk(f,"#Top"))
	{
		f >> stageRect_.top;
	}
	if(FindChunk(f,"#Right"))
	{
		f >> stageRect_.right;
	}
	if(FindChunk(f,"#Bottom"))
	{
		f >> stageRect_.bottom;
	}
	return f.eof();
}

bool CStageMng::LoadPlayer(ifstream& f)
{
	if(FindChunk(f,"#Player"))
	{
		float pos[2];	// [0]:x [1]:y
		for(auto& p : pos)
		{
			std::string label;
			f >> label;
			p = static_cast<float>(std::atof(label.c_str()));
		}
		InsertObject(ObjPtr(new CPlayer(*this, pos[0], pos[1])));
	}

	return f.eof();
}

bool CStageMng::LoadEnemies(ifstream& f)
{
	if(FindChunk(f,"#Enemy"))
	{
		std::string label;
		f >> label;
		auto& ems = GetObjects("EnemyMng");
		ObjPtr em;
		if(ems.empty())
		{
			// EnemyMng���Ȃ��ꍇ�A�V�K�ɒǉ�����
			em = ObjPtr(new CEnemyMng());
			InsertObject(em);
		}
		else
		{
			em = ems[0];
		}
		static_cast<CEnemyMng*>(em.get())->LoadEnemiesInfo(label);
	}
	return f.eof();
}

bool CStageMng::LoadActionCircles(ifstream& f)
{
	if(FindChunk(f,"#ActionCircle"))
	{
		std::string label;
		f >> label;
		if(label != "{" || f.eof()) return f.eof();
		while(!f.eof())
		{
			std::vector<float> info;
			for(int i=0; i<3; ++i)
			{
				f >> label;
				if(label == "}" || f.eof())return f.eof();
				info.push_back(static_cast<float>(std::atof(label.c_str())));
			}
			if(info.size() == 3)
			{
				actionPoints_.push_back(ActPtPtr(
					new CActionCircle(info[0], info[1], info[2])
										));
			}
		}
	}
	return f.eof();
}

bool CStageMng::LoadActionPolygons(ifstream& f)
{
	if(FindChunk(f,"#ActionPolygon"))
	{
		std::string label;
		f >> label;
		if(label != "{" || f.eof()) return f.eof();
		while(!f.eof())
		{
			f >> label;
			if(label == "}")break;
			int num = std::atoi(label.c_str());
			std::vector<mymath::Vec3f> info(num);
			for(int i=0; i<num; ++i)
			{
				mymath::Vec3f pos;
				f >> label;
				if(label == "}" || f.eof()) return f.eof();
				pos.x = static_cast<float>(std::atof(label.c_str()));
				f >> label;
				if(label == "}" || f.eof()) return f.eof();
				pos.y = static_cast<float>(std::atof(label.c_str()));
				pos.z = 0.5f;
				info[i] = pos;
			}
			//info.push_back(info[0]);	// �H�ɂ���
			actionPoints_.push_back(ActPtPtr(
				new CActionPolygon(info)));
			
		}
	}
	return f.eof();
}




void CStageMng::step()
{
	for(auto& ap : actionPoints_)
		ap->step();
	// ���d�X�N���[���Ƃ�

#ifdef _DEBUG
	if(CheckPush(KEY_F1))
	{
		std::stringstream file;
		file << "res/txt/stage/" << stageName_ << ".txt";
		ifstream f(file.str());
		if(f.is_open())
		{
			LoadEnemies(f);
		}
	}
#endif


}

void CStageMng::draw()
{
	for(auto& ap : actionPoints_)
		ap->draw();
	Draw_Graphics(0,0,1.f,
		backgroundIMG_,0,0,1280,800,0,0,
		(rect.right-rect.left)/1280.f,
		(rect.bottom-rect.top)/800.f);
}

void CStageMng::LoadStage(const std::string& stageName)
{
	std::stringstream file;
	file << "res/txt/stage/" << stageName << ".txt";
	ifstream f(file.str());
	if(f.fail())return;
	stageName_ = stageName;
	
	ClearObjects();

	if(LoadSize(f))
	{
		f.clear();
		f.seekg(0);
	}
	if(LoadPlayer(f))
	{
		f.clear();
		f.seekg(0);
	}
	if(LoadEnemies(f))
	{
		f.clear();
		f.seekg(0);
	}
	if(LoadActionCircles(f))
	{
		f.clear();
		f.seekg(0);
	}
	if(LoadActionPolygons(f))
	{
		f.clear();
		f.seekg(0);
	}

	
}