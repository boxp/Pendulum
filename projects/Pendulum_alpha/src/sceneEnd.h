#ifndef DEF_SCENEEND_H
#define DEF_SCENEEND_H

#ifndef DEF_SCENEBASE_H
#include "sceneBase.h"
#endif

class CSceneEnd : public IScene
{
public:
	CSceneEnd();
	~CSceneEnd();
	IScene* step() override;	// �X�V
	void	draw() override;	// �`��
};


#endif