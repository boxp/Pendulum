#ifndef DEF_SCENESTAGESELECT_H
#define DEF_SCENESTAGESELECT_H

#ifndef DEF_SCENEBASE_H
#include "sceneBase.h"
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