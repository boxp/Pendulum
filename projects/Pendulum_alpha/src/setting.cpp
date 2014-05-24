#include "setting.h"
#include "../../../lib/gplib.h"
#include "common.h"

#include <unordered_map>		// Font�e�[�u���p

#include <fstream>

namespace setting
{
	using std::ifstream;

struct ResData
{
	std::string resname;
	std::string path;
	
};

// �t�H���g�p
std::unordered_map<std::string, int> fontTable_;



void LoadImg(ifstream& f);
void LoadBGM(ifstream& f);
void LoadSE(ifstream& f);
void LoadFont(ifstream& f);

// OnCreate���Ă΂��setting����
void OnCreateSetup()
{
	ifstream f("res/dat/resdata.txt");
	if (f.fail())
	{
		gplib::debug::Dbg_BoxToMessage("huh?OnCreateSetup");
		return;
	}
	if (common::FindChunk(f, "#Img"))
	{
		LoadImg(f);
	}
	common::SeekSet(f);
	if (common::FindChunk(f, "#Bgm"))
	{
		LoadBGM(f);
	}
	common::SeekSet(f);
	if (common::FindChunk(f, "#Se"))
	{
		LoadSE(f);
	}
	common::SeekSet(f);
	if (common::FindChunk(f, "#Font"))
	{
		LoadFont(f);
	}
	common::SeekSet(f);
}

void LoadImg(ifstream& f)
{
	/*
	struct ImgInfo
	{
		char* fileName;
		D3DCOLOR transparent;
	};
	// ImgTbl�̑Ή����ɋL�q���邱��
	ImgInfo iInfo[] = 
	{
		{"res/gra/bg.jpg"},
		{"res/gra/player.png",ARGB(255,0,255,0)},
		{"res/gra/bird.png"},
		{"res/gra/lazer.png"},
		{"res/gra/circle_x96.png"},
		{"res/gra/Explosion.png"},
		{"res/gra/number.png"},
		{"res/gra/chain.png"},
	};
	*/
	std::string buf;
	f >> buf;
	if (buf != "{") return;
	while (!f.eof())
	{
		f >> buf;
		if (buf == "}") return;
		ResData data;
		D3DCOLOR transparent;
		data.resname = buf;
		f >> data.path >> std::hex >> transparent;

		graph::Draw_LoadObject(data.resname, data.path, transparent);
	}
}


// BGM���[�h
void LoadBGM(ifstream& f)
{
	/*
	char* bgm[] =
	{
		"res/snd/bgm/uzumaki.mp3",
		"res/snd/bgm/uzumaki.mp3",
		"res/snd/bgm/uzumaki.mp3",
		"res/snd/bgm/uzumaki.mp3",
	};
	for(const auto& b : bgm)
	{
		DShow_LoadFile(b);
	}
	*/
	std::string buf;
	f >> buf;
	if (buf != "{") return;
	while (!f.eof())
	{
		f >> buf;
		if (buf == "}") return;
		ResData data;
		data.resname = buf;
		f >> data.path;
		bgm::DShow_LoadFile(data.resname, data.path);
	}
}

// SE���[�h
void LoadSE(ifstream& f)
{
	/*
	char* se[] =
	{
		"res/snd/se/explode.wav",
	};
	for(const auto& s : se)
	{
		DSound_LoadFile(s);
	}
	*/
	std::string buf;
	f >> buf;
	if (buf != "{") return;
	while (!f.eof())
	{
		f >> buf;
		if (buf == "}") return;
		ResData data;
		data.resname = buf;
		f >> data.path;
		se::DSound_LoadFile(data.resname, data.path);
	}
}


void LoadFont(ifstream& f)
{
	/*
	struct FontInfo
	{
		int size;
		char* fontName;
	};
	FontInfo fInfo[] =
	{
		{ 30, "MS�@�S�V�b�N" },
		{ 30, "HG�n�p�p�߯�ߑ�" },
		{ 25, "HG�n�p�p�߯�ߑ�" },
		{ 12, "HG�n�p�p�߯�ߑ�" },
		{ 15, "MS�@�S�V�b�N" },
	};
	*/
	std::string buf;
	f >> buf;
	if (buf != "{") return;
	int i = 0;
	while (!f.eof())
	{
		f >> buf;
		if (buf == "}") return;
		ResData data;
		int size;
		data.resname = buf;
		f >> data.path >> std::dec >> size;
		data.path = common::StrReplace(data.path, "�Q", "");
		font::Draw_CreateFont(i, size, data.path.c_str());
		fontTable_.insert(std::unordered_map<std::string, int>::value_type(data.resname, i));
		i++;
	}
}

int GetFontID(const std::string& resname)
{
	return fontTable_[resname];
}

}	// namespace setting