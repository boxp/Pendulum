#ifndef DEF_PLAYER_H
#define DEF_PLAYER_H

#ifndef DEF_CHARAOBJBASE_HPP
#include "charaObjBase.hpp"
#endif

#ifndef DEF_MYMATH_HPP
#include "MyMath.hpp"
#endif

#ifndef DEF_ACTIONPOINT_H
#include "actionPoint.h"
#endif

#ifndef DEF_CHARBASE_H
#include "charBase.h"
#endif



class CPlayer : public ICharacter
{
public:
	struct LoadInfo
	{
		float MAX_G;			// 最大重力速度
		float GRAVITY_ACC;		// 重力加速度
		float TENSION;			// フックの張力(初速)
		float DOWN_TENSION;		// 張力減速率
		float DOWN_SPEED;		// 移動減速率(1-DOWN_SPEED)
		float MAX_VX;			// 水平方向の最大速度(ゲームとして成り立つバランス調整用)
		float MAX_VY;			// 鉛直方向の最大速度(ゲームとして成り立つバランス調整用)
		float CHAIN_TIME[2];	// Chain猶予時間
	};
private:
	enum MotionType		// モーション番号
	{
		FALL,			// 落下(通常時)
		HANG,			// 立体機動中
		ATTACK,			// 攻撃中
	};
	enum
	{
		MAX_CHAIN = 999,			// 最高Chain数
	};
private:
	/*
	static const float MAX_G;		// 最大重力速度
	static const float GRAVITY_ACC;	// 重力加速度
	static const float TENSION;		// フックの張力(初速)
	static const float DOWN_TENSION;// 張力減速率
	static const float DOWN_SPEED;	// 移動減速率(1-DOWN_SPEED)
	static const float MAX_VX;		// 水平方向の最大速度(ゲームとして成り立つバランス調整用)
	static const float MAX_VY;		// 鉛直方向の最大速度(ゲームとして成り立つバランス調整用)

	static const float CHAIN_TIME[2];	// Chain猶予時間
	//*/
	LoadInfo loadInfo_;			// ファイルから取得する可変値

	float gravity_;				// 重力
	bool gravityF_;				// 重力処理をするか(壁に刺さってる時などの処理用)
	float tensionAcc_;			// 張力の加速度
	float hangAcc_;				// ぶら下がっている時の振り子運動の加速度
	
	bool isHanging_;			// ぶら下がっているか
	mymath::Vec3f hangPoint_;			// ぶら下がっている支点
		
	charabase::CharPtr attackRange_;		// 攻撃範囲
	bool isAttacking_;			// 攻撃中か

	enum class ChainState				// Chain文字画像表示状態
	{
		HIDE,					// 非表示
		APPEARING,				// 出現中
		SHOW,					// 表示
		DISAPPEARING,			// 消失中
	}chainState_;
	
	//--------------------------------------------------
	charabase::CharPtr chainMsg_;			// Chain文字画像
	mymath::Vec3f numberPos_;			// Chain数字座標
	float numberAnimTime_;		// Chain数字アニメーション用カウント1
	mymath::Vec3f chainStaPos_;			// Chain文字初期位置
	float chainAnimTime_;		// Chain文字アニメーション用カウント
	float chainTime_;			// Chain残り時間
	
	//--------------------------------------------------
	int chainCnt_;				// Chain数

	//--------------------------------------------------

public:
	//const bool& isHanging;		// ぶら下がり中(ActionPoint判定するか)
private:
	/*
		@brief	情報の初期化
		@return	なし
	*/
	void init();

	/*
		@brief	キー入力
		@return	なし
	*/
	void key();

	/*
		@brief	キャラの移動
		@return なし
	*/
	void move();
public:
	/*
		@brief	空オブジェクト生成
				DB初期化時に呼ばれる
	
	*/
	CPlayer();
	/*
		@param	[in]	stage	ステージ情報
		@param	[in]	pos		初期座標
	*/
	CPlayer(const mymath::Vec3f& pos);
	/*
		@param	[in]	stage	ステージ情報
		@param	[in]	x		初期座標
		@param	[in]	y		初期座標
		@param	[in]	z		初期座標
	*/
	CPlayer(float x, float y, float z = 0.5f);

	~CPlayer();

	virtual void step() override;
	
	virtual void draw() override;
	
	virtual void hit(const ObjPtr& rival) override;

	/*
		@brief	プレイヤーオブジェクトを取得
		@return	ポインタ
		@retval	nullptr	プレイヤーオブジェクトが作られていない場合
		@retval	プレイヤーのポインタ
	*/
	static ObjPtr GetPtr();

	/*
		@brief	攻撃待機中フラグの取得
		@return	攻撃待機中フラグ
		@retval	true	攻撃待機中
		@retval	false	攻撃待機中でない
	*/
	bool isAttacking() const;

	/*
		@brief	プレイヤー情報初期化
		@param	[in]	info	ロードしてきた情報一覧
		@return	なし
	*/
	void SetInfo(const LoadInfo& info);

	/*
		@brief	フックの支点の設定
		@param	[in]	pos	支点座標
		@return	なし
	*/
	void SetHangPoint(const mymath::Vec3f& pos);

	/*
		@brief	ダメージ加算
		@param	[in]	dam	ダメージ量
		@return 死亡したか
		@retval	true	死亡
		@retval	false	残存
	*/
	bool ApplyDamage(int dam) override;
	
	/*
		@brief	攻撃
		@param	[in]	pos	敵の座標
		@return	なし
	*/
	void ApplyAttack(const mymath::Vec3f& pos);

	/*
		@brief	敵を倒した
		@return	なし
	*/
	void KilledEnemy();
	
	/*
		@brief	当たり判定領域の取得
		@return	当たり判定領域
	*/
	//virtual Collisions GetCollisionAreas() override;


};

#endif