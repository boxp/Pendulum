#ifndef DEF_NWAYSHOT_H
#define DEF_NWAYSHOT_H

#ifndef DEF_ATTACKBASE_HPP
#include "attackBase.hpp"
#endif

#ifndef DEF_MYMATH_HPP
#include "MyMath.hpp"
#endif

#include <vector>

/*
	@brief	�V���b�g
*/
class CShot : public IAttack
{
private:
	int cnt_;
	Vec3f	acceleration_;	// �����x

private:
	void init()
	{
		cnt_ = 0;
	}
public:
	/*
		@brief	������
		@param	[in]	shot			�e�̏��
	*/
	CShot(const CharBase& shot):
		IAttack("Atk_Shot")
	{
		obj_ = shot;
	}
	/*
		@brief	������
		@param	[in]	shot			�e�̏��
		@param	[in]	acceleration	�����x
	*/
	CShot(const CShot& shot, const Vec3f& acceleration):
		IAttack("Atk_Shot")
		,cnt_(0)
		,acceleration_(acceleration)
	{
		obj_ = shot.obj();
	}
	virtual void step() override
	{
		obj_.Move();
		obj_.velocity += acceleration_;
		if(++cnt_ > 1200)
		{
			kill();
		}
	}
	virtual void draw() override
	{
		obj_.draw();
	}
	virtual void hit(const ObjPtr& rival) override
	{
		if(rival->findName("Player"))
		{
			kill();
		}
	}
};
/*
	@brief	NWay�e
*/
class CNWayShot : public IAttack
{
private:
	const CShot shot_;			// �e�̏��
public:
	/*
		@brief	NWay�e�̐���
		@param	[in]	base		�e�̏��(�摜���,�����蔻��)
	*/
	CNWayShot(const CShot& base);

	virtual void step() override;
	virtual void draw() override;

	/*
		@brief	NWay�e�̔���
			�ǂ̈ʒu���� ���� �ǂ̊p�x�� �ǂꂭ�炢�̊Ԋu�� �ǂꂭ�炢�̑����� �����x�͂ǂꂭ�炢�� �ǂ̂悤�ɎU�点�邩
		@param	[in]	pos			�e�̏������W
		@param	[in]	n			�e��
		@param	[in]	angle		�e�̔��ˊp�x(�P��:Degree)
		@param	[in]	interval	�e�̊Ԋu�p�x(�P��:Degree)
		@param	[in]	speed		�e�̑���(�����x)
		@param	[in]	acc			�e�̉����x
		@param	[in]	centerFlag	�e�����E�ɂӂ邩(�f�t�H���g:true)
		@return	�Ȃ�
	*/
	void CreateAttack(const Vec3f& pos, int n, float angle, float interval, float speed, float acc, bool centerFlag = true);
	

};

#endif