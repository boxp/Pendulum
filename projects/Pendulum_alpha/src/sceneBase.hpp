#ifndef DEF_SCENEBASE_HPP
#define DEF_SCENEBASE_HPP


#include <memory>
class IScene
{
protected:
	enum class State		// �V�[���������
	{
		INNING,		// �V�[���ڂ�n��(IN����define����Ă���̂ŋ��)
		MAIN,		// �V�[���̃��C������
		OUTING,		// �V�[���ڂ�I���(OUT����define����Ă���̂ŋ��)
	};
	State state_;
	int bgmVolum_;		// BGM����
	//std::string name_;
public:
	IScene():state_(IScene::State::INNING),bgmVolum_(100){}
	//IScene(const std::string& name):name_(name){}
	
	virtual ~IScene() =0 {}

	virtual IScene* step() =0 {return this;}
	virtual void draw() =0 {}
	
};

#endif