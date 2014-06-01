#ifndef DEF_SCENEBASE_HPP
#define DEF_SCENEBASE_HPP

#ifndef DEF_FADE_H
#include "fade.h"
#endif

#ifndef DEF_DEFINE_H
#include "define.h"
#endif

#ifndef DEF_GAMEMANAGER_H
#include "gameManager.h"
#endif

#include <string>

#include <memory>

class IScene
{
private:
	static CGameManager* gm_;			// �Q�[���}�l�[�W�����������߂̃N���X

	const float FADE_IN_TIME;			// �t�F�[�h�C���ɂ����鎞��
	const float FADE_OUT_TIME;			// �t�F�[�h�A�E�g�ɂ����鎞��

protected:

	const std::string BACK_RESNAME;		// �w�i
	const std::string BGM_RESNAME;		// BGM����

	enum class State		// �V�[���������
	{
		INNING,		// �V�[���ڂ�n��(IN����define����Ă���̂ŋ��)
		MAIN,		// �V�[���̃��C������
		OUTING,		// �V�[���ڂ�I���(OUT����define����Ă���̂ŋ��)
	};
	State state_;

	int bgmVolum_;		// BGM����
	//std::string name_;

protected:
	/*
		@brief	�Q�[���}�l�[�W���̎擾
		@return	�Q�[���}�l�[�W��
	*/
	CGameManager* gm() const
	{
		return gm_;
	}
	/*
		@brief	�Q�[���}�l�[�W���̐ݒ�
		@return	�Ȃ�
	*/
	void gm(CGameManager* gm)
	{
		gm_ = gm;
	}



	/*
		@brief	���C���X�V����
		@return	���C���I����
		@retval	true	���C���I��(�t�F�[�h�C���J�n)
		@retval	false	���C��������
	*/
	virtual bool update() = 0{ return false; }

	/*
		@brief	���̃V�[���ɐ؂�ւ��u�ԂɌĂ΂��
		@return	���̃V�[��
	*/
	virtual IScene* NextScene() = 0{ return this; }

public:
	/*
		@param	[in]	back		�w�i�摜�Ǘ���
		@param	[in]	bgm			BGM�Ǘ���
		@param	[in]	fadeInTime	�t�F�[�h�C���ɂ����鎞��(�f�t�H���g0.3�b)
		@param	[in]	fadeOutTime	�t�F�[�h�A�E�g�ɂ����鎞��(�f�t�H���g0.3�b)
	*/
	IScene(const std::string& back, const std::string& bgm, float fadeInTime = 0.3f, float fadeOutTime = 0.3f) :
		BACK_RESNAME(back)
		, BGM_RESNAME(bgm)
		, FADE_IN_TIME(fadeInTime)
		, FADE_OUT_TIME(fadeOutTime)
		, state_(IScene::State::INNING)
		, bgmVolum_(100)
	{
		bgm::DShow_SetStartPos(BGM_RESNAME);
		bgm::DShow_VolumeControl(BGM_RESNAME, bgmVolum_);
		bgm::DShow_Play(BGM_RESNAME);
		CFade::StartFadeIn();
	}
	IScene() :
		BACK_RESNAME("")
		, BGM_RESNAME("")
		, FADE_IN_TIME(0.3f)
		, FADE_OUT_TIME(0.3f)
	{}
	//IScene(const std::string& name):name_(name){}
	
	virtual ~IScene() =0 {}

	virtual IScene* step()
	{
		switch (state_)
		{
		case IScene::State::INNING:
			if (CFade::FadeIn(255.f / FADE_IN_TIME*system::FrameTime))
			{
				state_ = State::MAIN;
			}
			break;
		case IScene::State::MAIN:
			if (update())
			{
				// �t�F�[�h�A�E�g�J�n
				CFade::StartFadeOut();
				state_ = State::OUTING;
			}
			break;
		case IScene::State::OUTING:
			//--------------------------------------
			// BGM�t�F�[�h�A�E�g
			bgmVolum_ -= static_cast<int>(100.f / FADE_OUT_TIME * system::FrameTime);
			if (bgmVolum_ <= 0)
				bgmVolum_ = 0;
			bgm::DShow_VolumeControl(BGM_RESNAME, bgmVolum_);
			//--------------------------------------
			if (CFade::FadeOut(255.f / FADE_OUT_TIME * system::FrameTime))
			{
				return NextScene();
			}
			break;
		}
		return this;
	}

	virtual void draw()
	{
		SIZE size = graph::Draw_GetImageSize2(BACK_RESNAME);
		graph::Draw_GraphicsLeftTopNC(
			0, 0, 1.f,
			BACK_RESNAME,
			0, 0,
			size.cx, size.cy,
			0, nullptr,
			static_cast<float>(system::WINW) / size.cx,
			static_cast<float>(system::WINH) / size.cy);
	}
	
};


class TempScene : public IScene
{
protected:
	virtual bool update() override{ return false; }
	virtual IScene* NextScene() override{ return this; }
public:
	TempScene(CGameManager *game) :
		IScene()
	{
		gm(game);
	}
	~TempScene(){}
};


#endif