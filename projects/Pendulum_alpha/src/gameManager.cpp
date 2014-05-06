
#include "GameManager.h"
#include "gameover.h"

#include	<algorithm>
#include	<functional>
#include	<sstream>
#include	<fstream>

mymath::Recti* CGameManager::winRect_ = nullptr;

CGameManager::CGameManager()
{
	objs_.clear();
	addObjs_.clear();
}

CGameManager::~CGameManager()
{
	objs_.clear();
	addObjs_.clear();
}

void CGameManager::MargeObjects()
{
	objs_.erase(
		std::remove_if(objs_.begin(), objs_.end(),
		std::mem_fn(&Base::isDestroy)),
		objs_.end());

	if (!addObjs_.empty())
	{
		objs_.insert(objs_.end(), addObjs_.begin(), addObjs_.end());
		addObjs_.clear();
	}

}

void CGameManager::init()
{
	objs_.clear();
	addObjs_.clear();
	clear_ = false;
}

void CGameManager::step()
{
	//�Q�[���I�[�o�[���A�N���A���ɔ��菈���͍s��Ȃ��B
	if (gameover::isGameOver()) return;

	ClearToChangeScreen(CLEARSCREEN);
	if (getClear()) return;

	//�e��X�V
	for (const auto& s : objs_)
	{
		s->step();
	}

	MargeObjects();


}

void CGameManager::draw()
{
	for (const auto& obj : objs_)
	{
		obj->draw();
	}
}

void CGameManager::AddObject(const ObjPtr& obj)
{
	addObjs_.push_back(obj);
}

void CGameManager::AddObject2(const ObjPtr& obj)
{
	addObjs_.push_back(obj);
	//�ǉ��v�f�z�񂩂�Ǘ��z��֒ǉ�����B
	objs_.insert(objs_.end(), addObjs_.begin(), addObjs_.end());
	//�ǉ��z����N���A
	addObjs_.clear();
}



//�w��̃N���X�������o���ĕԂ�
ObjPtr CGameManager::GetObj(const type_info& objinfo)
{
	for (auto& obj : objs_)
	{
		const type_info& info = typeid(*obj);
		if (info == objinfo)
		{
			return obj;
		}
	}
	//�ǉ��O�̂��̂��`�F�b�N
	for (auto& obj : addObjs_)
	{
		const type_info& info = typeid(*obj);
		if (info == objinfo)
		{
			return obj;
		}
	}
	return nullptr;
}

std::vector<ObjPtr>& CGameManager::GetObjects()
{
	return objs_;
}

std::vector<ObjPtr> CGameManager::GetObjects(const std::string& taskName)
{
	std::vector<ObjPtr> ret;
	for (const auto& obj : objs_)
	{
		if (!obj->FindName(taskName)) continue;
		ret.push_back(obj);
	}
	// �ǉ��\��̃I�u�W�F�N�g���T��
	for (const auto& obj : addObjs_)
	{
		if (!obj->FindName(taskName)) continue;
		ret.push_back(obj);
	}
	return ret;
}

std::vector<ObjPtr> CGameManager::GetObjects(const std::string& taskName, const char delim)
{
	std::vector<ObjPtr> ret;
	std::vector<std::string> taskNames;
	// taskNames�̍쐬
	{
		std::stringstream ss(taskName);
		std::string temp;
		while (std::getline(ss, temp, delim))
		{
			taskNames.push_back(temp);
		}
	}
	for (const auto& obj : objs_)
	{
		for (const auto& taskName : taskNames)
		{
			if (!obj->FindName(taskName)) continue;
			ret.push_back(obj);
		}
	}
	// �ǉ��\��̃I�u�W�F�N�g���T��
	for (const auto& obj : addObjs_)
	{
		for (const auto& taskName : taskNames)
		{
			if (!obj->FindName(taskName)) continue;
			ret.push_back(obj);
		}
	}
	return ret;
}
void CGameManager::setClear(bool clear)
{
	clear_ = clear; 
}
bool CGameManager::getClear() const
{
	return clear_; 
}


void CGameManager::StartClear()
{
	setClear(true);
	count_ = 3.f;
}

void CGameManager::ClearToChangeScreen(int next)
{
	if (getClear())
	{
		count_ -= system::ONEFRAME_TIME;
		debug::SToMNC(0, 100, "GameClearCount:%0.2f", count_);
		if (count_ <= 0)
		{
			stage::ChangeStage(next);
		}
	}
}


const mymath::Recti* CGameManager::winRect() const
{
	return winRect_;
}

void CGameManager::winRect(const mymath::Recti& newRect)
{
	*winRect_ = newRect;
}

void CGameManager::winRect(mymath::Recti* newRect)
{
	winRect_ = newRect;
}


extern CGameManager* gm;

void InsertObject(const ObjPtr& obj)
{
	gm->AddObject(obj);
}