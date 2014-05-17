#ifndef DEF_CHARAOBJBASE_HPP
#define DEF_CHARAOBJBASE_HPP

#ifndef DEF_OBJ_H
#include "Obj.h"
#endif

/*
	@brief	�L�����N�^�[�I�u�W�F�N�g���N���X(�v���C���[�A�G�ANPC?)
	@attension	step����ICharacter::step���Ăяo��
*/
class ICharacter : public IColObject
{

protected:
	int health_;				// �̗�
	int power_;					// �U����

	mymath::Vec3f prePos_;				// 1�t���[���O�̍��W
public:
	const mymath::Vec3f& prePos;		// 1�t���[���O���W
public:
	ICharacter(const std::string& name):
		IColObject(name)
		,health_(1)
		,power_(0)
		,prePos_(obj_.pos)
		,prePos(prePos_)
	{}
	~ICharacter() = 0{}
	/*
		@brief		�h���㋤�ʏ���
					1�t���[���O�̍��W�Ɍ��ݍ��W���i�[
		@attension	�h�����step���ŌĂяo������
		@return		�Ȃ�
	*/
	virtual void step() = 0{prePos_ = obj_.pos;}
	virtual void draw() = 0{}
	virtual void hit(const ObjPtr& rival){__super::hit(rival);}
	/*
		@brief	�����蔻��̈�̎擾
		@return	�����蔻��̈�
	*/
	virtual Collisions GetCollisionAreas(){return __super::GetCollisionAreas();}

	/*
		@brief	�U���͂̎擾
		@return	�␳��̍U����
	*/
	virtual int getPower() const {return power_;}
};

#endif