#ifndef DEF_SCENESTAGESELECT_H
#define DEF_SCENESTAGESELECT_H

#ifndef DEF_SCENEBASE_HPP
#include "sceneBase.hpp"
#endif

class CSceneStageSelect : public IScene
{
private:
	
private:
	
public:
	CSceneStageSelect();
	~CSceneStageSelect();
	IScene* step() override;	// �X�V
	void	draw() override;	// �`��
};

#endif