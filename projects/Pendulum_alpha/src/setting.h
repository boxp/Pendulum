/*
	�Q�[���ŗL�̐ݒ蓙�O���[�o���ϐ�
*/
#ifndef DEF_SETTING_H
#define DEF_SETTING_H
#include <string>

namespace setting
{

enum Font
{
	MSGOSICK,
	POP30,
	POP25,
	POP12,
	MSG15,
	FONT_NUM,			// �������ɋL�q�Acpp���̔z��ɒǉ�
};

enum ImgTbl
{
	backgroundIMG,
	playerIMG,
	birdIMG,
	shotIMG,
	circleIMG,
	expIMG,
	numberIMG,
	chainIMG,

	IMG_NUM,			// �������ɋL�q�Acpp���̔z��ɒǉ�
};

enum BGM
{
	TITLE,
	STAGESELECT,
	MAIN,
	RESULT,

	BGM_NUM
};


enum SE
{
	EXPLODE,
	SE_NUM
};


extern void OnCreateSetup();

extern int GetFontID(const std::string& resname);

}	// namespace setting

#endif