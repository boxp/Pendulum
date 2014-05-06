//**************************************************************************************//
//
//�@main.cpp
//
//**************************************************************************************//
#include	"define.h"

using namespace std;
using namespace gplib;


#include	"obj.h"
#include	"GameManager.h"
#include	"charbase.h"
#include	"gameover.h"
#include	"common.h"
#include	"setting.h"
#include	"sceneTitle.h"
#include	"fade.h"

#include	<memory>


std::unique_ptr<IScene> scene_;

//3D�J����
Dx_Camera *dxCamera = nullptr;

//���b�V���S�̊Ǘ��N���X
DX3DMESHMANAGER *meshManage = nullptr;


//�Q�[���Ǘ�
CGameManager *gm = nullptr;

//**************************************************************************************//
//���C�u�������ŕK�v�ȕϐ��@
//�K�v�ɉ����ĕύX���邱��
//**************************************************************************************//
namespace gplib{
	namespace system{
		const char USERNAME[] = "Pendulum";
		const int	WINW = 1280;
		const int	WINH = 720;
		//const int	WINW = 1024;
		//const int	WINH = 576;
		//const int	WINW	=	640;
		//const int	WINH	=	480;
		bool		WindowMode = true;
		int			KeyboardMode = 0;	//pad disable:1 pad enable:0
	}
}


void SceneStep()
{
	IScene::UpdateShareResource();
	IScene *next(scene_->step());
	if (next != scene_.get())
	{
		scene_.reset(next);
	}
}

void SceneDisp()
{
	scene_->draw();
	CFade::draw();
	debug::DFPS();
}
//---------------------------------------------------------------------------------------
//�Q�[�����[�v 
//---------------------------------------------------------------------------------------
void system::GameLoop()
{
	SceneStep();
	SceneDisp();
}

//---------------------------------------------------------------------------------------
//�v���O�����S�̂̏�����
//�t�H���g�̍쐬�A���[�f�B���O��ʂŎg�p����摜�̓ǂݍ��݂Ȃ�
//�N�����Ɉ�񂾂��s�������͂����ōs��
//---------------------------------------------------------------------------------------
void InitGame()
{
	//2D�J�����̒����_
	camera::InitCamera(system::WINW / 2, system::WINH / 2, 0.0f, 0.0f);
	//3D�J�����ݒ�@�J�����ʒu�̓f�t�H���g�@�����_��0,0,0
	dxCamera = new Dx_Camera();
	//

	////�Q�[���Ǘ��̏�����
	gm = new CGameManager();
	{
		TempObject t(gm);
	}

	setting::OnCreateSetup();

	// �V�[��������
	scene_.reset(new CSceneTitle());
	IScene::CreateShareResource();

}

void TerminateGame()
{
	// �V�[�����\�[�X�j��
	IScene::DestroyShareResource();

	SAFE_DELETE(meshManage);
	//�J�����̔j��
	SAFE_DELETE(dxCamera);

	//�Q�[���Ǘ�����
	SAFE_DELETE(gm);
}
void system::OnCreate()
{
	font::Draw_CreateFont(0, 30, "MS�@�S�V�b�N");
	font::Draw_CreateFont(1, 20, "MS�@�S�V�b�N");
	font::Draw_CreateFont(2, 10, "MS�@�S�V�b�N");

	//�摜�̃��[�h
	graph::Draw_LoadObject("player", "res/gra/Act_Chara1.png");
	graph::Draw_LoadObject("mapchip", "res/gra/block.png");
	graph::Draw_LoadObject("back", "res/gra/cloud.png");
	graph::Draw_LoadObject("enemy", "res/gra/enemy.png");
	graph::Draw_LoadObject("effect", "res/gra/newEffect.png");
	/*
	graph::Draw_LoadObject("shot", "res/gra/shot.png");
	graph::Draw_LoadObject("effect", "res/gra/effect.png");
	graph::Draw_LoadObject("enemy2", "res/gra/enemy2.png");
	graph::Draw_LoadObject("boss", "res/gra/boss.png");
	graph::Draw_LoadObject("bomb", "res/gra/bomb.png");
	graph::Draw_LoadObject("enemyshot", "res/gra/enemyshot.png");
	*/
	//���ʉ��̃��[�h
	se::DSound_LoadFile("se1", "res/snd/se1.wav");
	//BGM�̃��[�h
	bgm::DShow_LoadFile("bgm1", "res/snd/bgm1.mp3");
	InitGame();
}

//---------------------------------------------------------------------------------------
//�v���O�����S�̂̌�n��
//�I�����Ɉ�񂾂��s�������͂����ōs��
//---------------------------------------------------------------------------------------
void system::OnDestroy()
{
	TerminateGame();
}

//----------------------
//�����\��
void Draw_TextToBmp(int x, int y, const string& msg, int size, int type)
{
	int i;
	//�t�H���g�f�[�^�̉����ѐ�
	const int GRAPHIC_CELL_LENGTH = 16;
	//�t�H���g�f�[�^�̌��T�C�Y
	const int GRAPHIC_SIZEXY = 8;
	int draw_x, draw_y;
	int font_x, font_y;
	//�����`��ʒu�쐬
	draw_x = x; draw_y = y;
	if (size <= 0)	size = 1;
	for (i = 0; i < (int)msg.length(); i++){
		//�`�敶������
		font_x = (int)msg[i] % GRAPHIC_CELL_LENGTH * GRAPHIC_SIZEXY;
		font_y = (int)msg[i] / GRAPHIC_CELL_LENGTH * GRAPHIC_SIZEXY;
		//�����`��
		graph::Draw_Graphics(draw_x, draw_y, 0.5f, "font",
			font_x, font_y, GRAPHIC_SIZEXY, GRAPHIC_SIZEXY,
			0, 0, (float)size, (float)size);
		//�����`��ʒu�X�V
		if (type == WORDBREAK && msg[i] == '\n'){
			draw_y += GRAPHIC_SIZEXY * size;
			draw_x = x;
		}
		else{
			draw_x += GRAPHIC_SIZEXY * size;
		}
	}
}
//======================================================================================//
//WINDOW�@���C��
//======================================================================================//
int WINAPI WinMain (HINSTANCE hInstance,HINSTANCE hPreInst,LPSTR lpszCmdLine,int nCmdShow)
{
	return system::DoWindow(hInstance,hPreInst,lpszCmdLine,nCmdShow);
}