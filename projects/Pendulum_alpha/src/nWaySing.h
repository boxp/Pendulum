#ifndef DEF_NWAYSING_H
#define DEF_NWAYSING_H

#ifndef DEF_ATTACKBASE_HPP
#include "attackBase.hpp"
#endif

#ifndef DEF_MYMATH_HPP
#include "MyMath.hpp"
#endif

#include <vector>

/*
	@brief	ショット
*/
class CShot : public IAttack
{
private:
	int cnt_;
	mymath::Vec3f	acceleration_;	// 加速度

private:
	void init()
	{
		cnt_ = 0;
		collisions_.push_back(mymath::ShapefPtr(new mymath::Circlef(0.f, 0.f, obj_.pos.z, obj_.HalfHeight())));
	}
public:
	/*
	@brief	初期化
	@param	[in]	shot			弾の情報
	@param	[in]	acceleration	加速度
	*/
	CShot(const CShot& shot, const mymath::Vec3f& acceleration = mymath::Vec3f()) :
		IAttack("Atk_Shot")
		, acceleration_(acceleration)
	{
		obj_ = shot.obj();
		init();
	}
	/*
	@brief	初期化
	@param	[in]	shot			弾の情報
	*/
	CShot(const charabase::CharBase& shot) :
		IAttack("Atk_Shot")
	{
		obj_ = shot;
		init();
	}
	virtual void step() override
	{
		obj_.Move();
		obj_.add += acceleration_;
		if (++cnt_ > 300)
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
		if (rival->FindName("Player"))
		{
			kill();
		}
	}
};
/*
@brief	NWay弾
*/
class CNWaySing : public IAttack
{
private:
	const CShot shot_;			// 弾の情報
public:
	/*
	@brief	NWay弾の生成
	@param	[in]	base		弾の情報(画像情報,当たり判定)
	*/
	CNWaySing(const CShot& base);

	virtual void step() override;
	virtual void draw() override;

	/*
	@brief	NWay弾の発射
	どの位置から 何個 どの角度に どれくらいの間隔で どれくらいの速さで 加速度はどれくらいで どのように散らせるか
	@param	[in]	pos			弾の初期座標
	@param	[in]	n			弾数
	@param	[in]	angle		弾の発射角度(単位:Degree)
	@param	[in]	speed		弾の速さ(初速度)
	@param	[in]	acc			弾の加速度
	@param	[in]	centerFlag	弾を左右にふるか(デフォルト:true)
	@return	なし
	*/
	void CreateAttack(const mymath::Vec3f& pos, int n, float angle, float speed, float acc, bool centerFlag = true);


};

#endif