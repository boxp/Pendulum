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

#ifndef DEF_STAGE_H
#include "stage.h"
#endif



class CPlayer : public ICharacter
{
private:
	enum MotionType		// ���[�V�����ԍ�
	{
		FALL,			// ����(�ʏ펞)
		HANG,			// ���̋@����
		ATTACK,			// �U����
	};
private:
	static const float MAX_G;		// �ő�d�͑��x
	static const float GRAVITY_ACC;	// �d�͉����x
	static const float TENSION;		// �t�b�N�̒���(����)
	static const float DOWN_TENSION;// ���͌�����
	static const float DOWNSP;		// �ړ�������(1-DOWNSP)
	static const float MAX_VX;		// ���������̍ő呬�x(�Q�[���Ƃ��Đ��藧�o�����X�����p)
	static const float MAX_VY;		// ���������̍ő呬�x(�Q�[���Ƃ��Đ��藧�o�����X�����p)

	static const float CHAIN_TIME[2];	// Chain�P�\����
	static const int MAX_CHAIN;			// �ō�Chain��
	

	float gravity_;				// �d��
	bool gravityF_;				// �d�͏��������邩(�ǂɎh�����Ă鎞�Ȃǂ̏����p)
	float tensionAcc_;			// ���͂̉����x
	float hangAcc_;				// �Ԃ牺�����Ă��鎞�̐U��q�^���̉����x
	
	bool isHanging_;			// �Ԃ牺�����Ă��邩
	mymath::Vec3f hangPoint_;			// �Ԃ牺�����Ă���x�_
		
	CharPtr attackRange_;		// �U���͈�
	bool isAttacking_;			// �U������

	enum class ChainState				// Chain�����摜�\�����
	{
		HIDE,					// ��\��
		APPEARING,				// �o����
		SHOW,					// �\��
		DISAPPEARING,			// ������
	}chainState_;
	
	//--------------------------------------------------
	CharPtr chainMsg_;			// Chain�����摜
	mymath::Vec3f numberPos_;			// Chain�������W
	float numberAnimTime_;		// Chain�����A�j���[�V�����p�J�E���g1
	mymath::Vec3f chainStaPos_;			// Chain���������ʒu
	float chainAnimTime_;		// Chain�����A�j���[�V�����p�J�E���g
	float chainTime_;			// Chain�c�莞��
	
	//--------------------------------------------------
	int chainCnt_;				// Chain��

	//--------------------------------------------------

public:
	//const bool& isHanging;		// �Ԃ牺���蒆(ActionPoint���肷�邩)
	const bool& isAttacking;	// �U����
	const int& power;			// �U����
private:
	/*
		@brief	���̏�����
		@return	�Ȃ�
	*/
	void init();

	/*
		@brief	�L�[����
		@return	�Ȃ�
	*/
	void key();

	/*
		@brief	�L�����̈ړ�
		@return �Ȃ�
	*/
	void move();
public:
	/*
		@param	[in]	stage	�X�e�[�W���
		@param	[in]	pos		�������W
	*/
	CPlayer(const CStage& stage, const mymath::Vec3f& pos);
	/*
		@param	[in]	stage	�X�e�[�W���
		@param	[in]	x		�������W
		@param	[in]	y		�������W
		@param	[in]	z		�������W
	*/
	CPlayer(const CStage& stage, float x, float y, float z = 0.5f);

	~CPlayer();

	virtual void step() override;
	
	virtual void draw() override;
	
	virtual void hit(const ObjPtr& rival) override;

	/*
		@brief	�v���C���[�I�u�W�F�N�g���擾
		@return	�|�C���^
		@retval	nullptr	�v���C���[�I�u�W�F�N�g������Ă��Ȃ��ꍇ
		@retval	�v���C���[�̃|�C���^
	*/
	static ObjPtr GetPtr();

	/*
		@brief	�t�b�N�̎x�_�̐ݒ�
		@param	[in]	pos	�x�_���W
		@return	�Ȃ�
	*/
	void SetHangPoint(const mymath::Vec3f& pos);

	/*
		@brief	�_���[�W���Z
		@param	[in]	dam	�_���[�W��
		@return �Ȃ�
	*/
	void ApplyDamage(int dam);
	
	/*
		@brief	�U��
		@param	[in]	pos	�G�̍��W
		@return	�Ȃ�
	*/
	void ApplyAttack(const mymath::Vec3f& pos);

	/*
		@brief	�G��|����
		@return	�Ȃ�
	*/
	void KilledEnemy();
	
	/*
		@brief	�����蔻��̈�̎擾
		@return	�����蔻��̈�
	*/
	//virtual Collisions GetCollisionAreas() override;

};

#endif