#ifndef DEF_SCENEBASE_HPP
#define DEF_SCENEBASE_HPP

#ifndef DEF_FADE_H
#include "fade.h"
#endif

#ifndef DEF_DEFINE_H
#include "define.h"
#endif

#include <string>

#include <memory>

class IScene
{
private:
	const float FADE_IN_TIME;			// �t�F�[�h�C���ɂ����鎞��
	const float FADE_OUT_TIME;			// �t�F�[�h�A�E�g�ɂ����鎞��
protected:

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
		@param	[in]	bgm			BGM�Ǘ���
		@param	[in]	fadeInTime	�t�F�[�h�C���ɂ����鎞��(�f�t�H���g0.3�b)
		@param	[in]	fadeOutTime	�t�F�[�h�A�E�g�ɂ����鎞��(�f�t�H���g0.3�b)
	*/
	IScene(const std::string& bgm, float fadeInTime = 0.3f, float fadeOutTime = 0.3f) :
		BGM_RESNAME(bgm)
		, FADE_IN_TIME(fadeInTime)
		, FADE_OUT_TIME(fadeOutTime)
		, state_(IScene::State::INNING)
		, bgmVolum_(100)
	{
		bgm::DShow_Play(BGM_RESNAME);
		CFade::StartFadeIn();
	}
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
	virtual void draw() =0 {}
	
};

#endif