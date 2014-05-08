#ifndef DEF_BIRD_H
#define DEF_BIRD_H

#ifndef DEF_ENEMYBASE_HPP
#include "enemyBase.hpp"
#endif

class CBird : public IEnemy
{
	typedef IEnemy super;
	enum class State
	{
		WAIT,				// �ҋ@
		CHASE,				// �ǐ�
		RETURN,				// �A��
		ATTACK,				// �U��
		DESTROY,			// ���S�A�j��

	};

private:
	static const float SEARCH_RANGE;		// ���G�͈�(���ݍ��W����ǂꂾ�����G���邩)
	static const float CHASE_RANGE;			// �ǐՔ͈�(�������W����ǂꂾ���ǐՂ��邩)
	static const float ATTACK_RANGE;		// �U���͈�(���ݍ��W���炱�͈̔͂ɂ���ƍU������)
	static const float RETURN_RANGE;		// �A�Ҏ��ŏ��͈�(���͈͓̔��Ȃ珉���ʒu�ɖ߂����Ƃ݂Ȃ�)
	
	static const float MOVE_SPEED;			// �ړ����x

	static void (CBird::*StateStep_[])();	// ��Ԃɂ��step����
	
	State state_;					// �s�����

	float elapsedTime_;				// �o�ߎ���
	float nextActTime_;				// ���ɍs�����N��������

	const mymath::Vec3f* pPlPos_;			// �v���C���[���W
	
	const mymath::Vec3f startPos_;			// �������W(�ǐՌ㌳�ɖ߂�ꏊ)

private:

	/*
		@brief	���̏�����
		@return	�Ȃ�
	*/
	void init();

	/*
		@brief	�ҋ@
		@return	�Ȃ�
	*/
	void WaitStep();
	/*
		@brief	�ǐ�
		@return	�Ȃ�
	*/
	void ChaseStep();
	/*
		@brief	�A��
		@return	�Ȃ�
	*/
	void ReturnStep();
	/*
		@brief	�U��
		@return	�Ȃ�
	*/
	void AttackStep();
	/*
		@brief	���S
		@return	�Ȃ�
	*/
	void DestroyStep();



	/*
		@brief	�v���C���[���W���擾
		@return �擾����������
		@retval	true	�擾����
		@retval	false	���s(nullptr���i�[����Ă���)
	*/
	bool SetPlayerPos();

	/*
		@brief	�s���^�C�v�̌���
		@return	�Ȃ�
	*/
	void DecideState();

	/*
		@brief	�U���̔�������
		@return	�Ȃ�
	*/
	void CreateAttack();
	
public:
	CBird(const mymath::Vec3f& pos);
	CBird(float x, float y, float z = 0.5f);
	~CBird();
	virtual void step() override;
	virtual void draw() override;
	
	virtual void hit(const ObjPtr& rival) override;

	/*
		@brief	�_���[�W���Z
		@param	[in]	dam	�_���[�W��
		@return ���S������
		@retval	true	���S
		@retval	false	�c��
	*/
	virtual bool ApplyDamage(int dam) override;
	
	/*
		@brief	�����蔻��̈�̎擾
		@return	�����蔻��̈�
	*/
	virtual Collisions GetCollisionAreas() override;
		
};

#endif