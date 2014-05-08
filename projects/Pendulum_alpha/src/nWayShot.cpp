#include "nWayShot.h"
#include "lib\gplib.h"

#include "MyMath.hpp"


CNWayShot::CNWayShot(const CShot& base):
	IAttack("Atk_NWayShot")
	,shot_(base)
{
	force_ = 3;
}

void CNWayShot::step()
{
}
void CNWayShot::draw()
{
}


void CNWayShot::CreateAttack(const Vec3f& pos, int n, float angle, float interval, float speed, float acc, bool centerFlag)
{
	for(int i=0; i<n; ++i)
	{
		CharBase shot(shot_.obj());	// ���W�A�p�x�A�摜�A�����x
		// ���W
		shot.pos = pos;
		// ���ˊp
		shot.angle = angle + (interval * ((centerFlag) ?  static_cast<float>(i - n/2) : static_cast<float>(i)));
		if(shot.angle >= 360.f)
			shot.angle -= 360.f;
		else if(shot.angle < 0.f)
			shot.angle += 360.f;
		// ���ˊp�ɍ��킹�ď����x������x�̌�����ς���
		const float rad = Calc_DegreeToRad(shot.angle);
		const float c = std::cosf(rad);
		const float s = std::sinf(rad);
		shot.velocity.x = speed *  c;
		shot.velocity.y = speed * -s;
		shot.velocity.z = 0.f;
		
		Vec3f a(acc *  c,
				acc * -s);	// �����x
		CShot shot_info(shot,a);	// �ǉ��p
		// �����蔻��̈�̃R�s�[
		shot_info.SetCollisionAreas(shot_.collisions);

		// �o�^
		InsertObject(ObjPtr(new CShot(shot_info)));
	}

}

