#include "effectExplosion.h"
#include "setting.h"

#include "common.h"

#include "define.h"

CEffectExplosion::CEffectExplosion(const mymath::Vec3f& pos, float scale):
	IEffect("EffectExplosion")
	,animCnt_(0.f)
{
	obj_.pos = pos;
	obj_.scale = scale;

	obj_.resname = "img_explosion";
	obj_.size(500, 500);
	

	addAngle_ = math::GetRandom(-3600.f, 3600.f) / 10.f;
	obj_.angle = math::GetRandom(0.f, 3600.f) / 10.f;

	obj_.alpha = 200.f;
	obj_.scale = math::GetRandom(0.9f,1.2f);
	
}

void CEffectExplosion::step()
{
	const float animTime = 0.5f;
	// 0.5秒
	animCnt_ += 12.f / animTime * system::FrameTime;
	
	// 回転
	//obj_.angle += addAngle_ / animTime * system::FrameTime;
	if(obj_.angle >= 360.f)	obj_.angle -= 360.f;
	else if(obj_.angle < 0.f)	obj_.angle += 360.f;

	if(animCnt_ > 14.f)
	{
		kill();
	}
	else
	{
		// アニメーション番号の反映
		obj_.src.x = static_cast<int>(animCnt_) % 3;
		obj_.src.y = static_cast<int>(animCnt_) / 3;
	}
}

void CEffectExplosion::draw()
{
	graph:: Draw_SetRenderMode(ADD);
	for(int i=0; i<2; ++i)
		obj_.draw();
	graph::Draw_EndRenderMode();
}