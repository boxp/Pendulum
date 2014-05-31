#ifndef DEF_STAGEMNG_H
#define DEF_STAGEMNG_H

#ifndef DEF_OBJ_H
#include "obj.h"
#endif

#ifndef DEF_ACTIONPOINT_H
#include "actionPoint.h"
#endif

#ifndef DEF_MYMATH_HPP
#include "MyMath.hpp"
#endif


class CStageMng : public Base
{
private:
	mymath::Recti stageRect_;			// �X�e�[�W�̑傫��
	std::vector<std::string> backgroundIMG_;			// �w�i�摜
	std::vector<ActPtPtr> actionPoints_;
	std::string stageName_;		// �X�e�[�W��
public:
	const std::vector<ActPtPtr>& actionPoints;
	const mymath::Recti& rect;

	static std::string stageFile;		// �X�e�[�W�t�@�C���p�X

private:
	/*
		@brief		�X�e�[�W�T�C�Y�̓ǂݍ���
		@attension	f�̓I�[�v���ς�
		@param	[in/out]	f	�t�@�C��
		@return	EOF��
		@retval	true	EOF
		@retval	false	EOF�łȂ�
	*/
	bool LoadSize(std::ifstream& f);
	/*
		@brief		�v���C���[�̓ǂݍ���
		@attension	f�̓I�[�v���ς�
		@param	[in/out]	f	�t�@�C��
		@return	EOF��
		@retval	true	EOF
		@retval	false	EOF�łȂ�
	*/
	bool LoadPlayer(std::ifstream& f);
	/*
		@brief		�G���̓ǂݍ���
		@attension	f�̓I�[�v���ς�
		@param	[in/out]	f	�t�@�C��
		@return	EOF��
		@retval	true	EOF
		@retval	false	EOF�łȂ�
	*/
	bool LoadEnemies(std::ifstream& f);

	/*
		@brief		ActionCircle�̓ǂݍ���
		@attension	f�̓I�[�v���ς�
		@param	[in/out]	f	�t�@�C��
		@return	EOF��
		@retval	true	EOF
		@retval	false	EOF�łȂ�
	*/
	bool LoadActionCircles(std::ifstream& f);
	/*
		@brief		ActionPolygon�̓ǂݍ���
		@attension	f�̓I�[�v���ς�
		@param	[in/out]	f	�t�@�C��
		@return	EOF��
		@retval	true	EOF
		@retval	false	EOF�łȂ�
	*/
	bool LoadActionPolygons(std::ifstream& f);

public:
	CStageMng();
	virtual void step() override;
	virtual void draw() override;

	/*
		@brief	�X�e�[�W�̃��[�h
		@param	[in]	stageName	�X�e�[�W��(�t�@�C����)
		@return	�Ȃ�
	*/
	void LoadStage(const std::string& stageName);

	static const std::shared_ptr<CStageMng> GetPtr();
};

#endif