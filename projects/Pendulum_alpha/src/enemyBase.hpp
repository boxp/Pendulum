#ifndef DEF_ENEMYBASE_HPP
#define DEF_ENEMYBASE_HPP

#ifndef DEF_CHARAOBJBASE_HPP
#include "charaObjBase.hpp"
#endif

#ifndef DEF_ATTACKBASE_HPP
#include "attackBase.hpp"
#endif

#ifndef DEF_MYMATH_HPP
#include "MyMath.hpp
#endif

#ifndef DEF_DEFINE_H
#include "define.h"
#endif

#ifndef DEF_NWAYSHOT_T
#include "nWayShot.h"
#endif

/*
	@brief		�G��{�N���X
	@attention	���O�͕K��"E_"����n�߂邱��
*/
class IEnemy : public ICharacter
{
protected:
	AttackPtr attack_;							// �U����i
public:
	const AttackPtr& attack;
protected:
	
public:
	/*
		@brief	�R���X�g���N�^
		@param	[in]	name	���O("E_"����n�߂�)
		@param	[in]	attack	�U���p�N���X�|�C���^
		@attention	name��"E_"����n�߂邱��
	*/
	IEnemy(const std::string& name):
		ICharacter(name)
		,attack(attack_)
	{}
	virtual ~IEnemy() = 0{}
	virtual void step() = 0{}
	virtual void draw() = 0{}
	/*
		@brief	�_���[�W���Z
		@param	[in]	dam	�_���[�W��
		@return ���S������
		@retval	true	���S
		@retval	false	�c��
	*/
	virtual bool ApplyDamage(int dam) = 0{}

	/*
		@brief	�U���̓����蔻��̈�̎擾
		@return	�U���̓����蔻��̈�
	*/
	virtual Collisions GetAttackCollisions(){return attack_->GetCollisionAreas();}

	/*
		@brief	�U����i���̊i�[
		@attension	ifstream��currentPosition�ɒ���
					if(FindChunk(f,"#Attack"))
						LoadAttack(f);
		@param	[in/out]	f	�I�[�v���ς݃t�@�C��
		@return		EOF��
		@retval		true		EOF
		@retval		false		EOF�łȂ�
	*/
	bool LoadAttack(std::ifstream& f)
	{
		std::string buf;
		f >> buf;
		if(buf == "NWayShot")
		{
			f >> buf;
			if(buf != "{") return f.eof();
			else
			{
				CharBase shot_info;
				f >> buf;	// Img���x���ǂݔ�΂�
				std::string img_path;
				f >> img_path;
				D3DCOLOR transparent;
				f >> std::hex >> transparent;
				shot_info.img = Draw_LoadObject(img_path,transparent);

				f >> buf;	// Width���x���ǂݔ�΂�
				LoadValue(f, obj_, shot_info.src.x);
				f >> buf;	// Height���x���ǂݔ�΂�
				LoadValue(f, obj_, shot_info.src.y);

				CShot shot(shot_info);
				shot.LoadCollisions(f);
				attack_ = AttackPtr(new CNWayShot(shot));
			}
		}
		
		return f.eof();
	}

};
typedef std::shared_ptr<IEnemy> EnemyPtr;

#endif