#ifndef DEF_SCENETITLE_H
#define DEF_SCENETITLE_H

#ifndef DEF_SCENEBASE_H
#include "sceneBase.h"
#endif

class CSceneTitle : public IScene
{
public:
	CSceneTitle();
	~CSceneTitle();
	IScene* step() override;	// �X�V
	void	draw() override;	// �`��
};


#endif