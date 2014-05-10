#ifndef DEF_SCENEBASE_H
#define DEF_SCENEBASE_H

#ifndef DEF_STAGEMNG_H
#include "stageMng.h"
#endif

#ifndef DEF_GAMEMANAGER_H
#include "gameManager.h"
#endif

#include <memory>
class IScene
{
public:
	class ShareResource
	{
	public:
		CStageMng* stage;
		ShareResource(){}
		~ShareResource()
		{
			if(stage != nullptr)
			{
				delete stage;
				stage = nullptr;
			}
		}
		void Create()
		{
			stage = new CStageMng();
		}
		void Destroy()
		{
			if(stage != nullptr)
			{
				delete stage;
				stage = nullptr;
			}
		}
		void Update()
		{
			stage->step();
		}

		void Draw()
		{
			stage->draw();
		}

	};
	typedef std::unique_ptr<ShareResource> ShareResPtr; 
protected:
	enum class State		// �V�[���������
	{
		INNING,		// �V�[���ڂ�n��(IN����define����Ă���̂ŋ��)
		MAIN,		// �V�[���̃��C������
		OUTING,		// �V�[���ڂ�I���(OUT����define����Ă���̂ŋ��)
	};
	State state_;
	static ShareResPtr shareRes_;
	int bgmVolum_;		// BGM����
	//std::string name_;
public:
	IScene():state_(IScene::State::INNING),bgmVolum_(100){}
	//IScene(const std::string& name):name_(name){}
	
	virtual ~IScene() =0 {}

	virtual IScene* step() =0 {return this;}
	virtual void draw() =0 {}
	
	static void CreateShareResource(){ shareRes_->Create(); }
	static void DestroyShareResource(){ shareRes_->Destroy(); }
	static void UpdateShareResource(){ shareRes_->Update(); }

};

#endif