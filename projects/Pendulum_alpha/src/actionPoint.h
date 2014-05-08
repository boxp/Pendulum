#ifndef DEF_ACTIONPOINT_H
#define DEF_ACTIONPOINT_H

#ifndef DEF_OBJ_H
#include "Obj.h"
#endif

#ifndef DEF_MYMATH_HPP
#include "MyMath.hpp"
#endif

#include <vector>	// Polygon�p

#pragma region class IActionPoint
class IActionPoint : public IObject
{
public:
	IActionPoint(const std::string& name, float x=0.f, float y=0.f);
	virtual ~IActionPoint() = 0 {}
	virtual void step() override {}
	virtual void draw() override {}
	/*
		@brief	�_�Ɖ~�̏Փˌ��m + �Փˎ��̈�ԋ߂��~����̓_�̎擾
			if(Contains(out, point))
				point = out;
		@param	[out]	out		��ԋ߂��~����̓_
		@param	[in]	point	�Փ˂��Ă��邩���m����_
		@return	�Փ˂��Ă��邩
		@retval	true	�Փ˂��Ă���
		@retval	false	�Փ˂��Ă��Ȃ�
	*/
	virtual bool Contains(mymath::Vec3f& out, const mymath::Vec3f& point)const{return false;}
	/*
		@brief	�����Ɖ~�̏Փˌ��m + �Փˎ��n�_�ɋ߂����̌�_�̎擾
			if(Contains(out, pos, next))
				next = out;
		@param	[out]	out				�n�_�ɋ߂����̌�_
		@param	[in]	line(sta,end)	�Փˌ��m����
		@return	�Փ˂��Ă��邩
		@retval	true	�Փ˂��Ă���
		@retval	false	�Փ˂��Ă��Ȃ�
	*/
	virtual bool Contains(mymath::Vec3f& out, const mymath::Linef& line)const{return false;}
	/*
		@brief	�����Ɖ~�̏Փˌ��m + �Փˎ��n�_�ɋ߂����̌�_�̎擾
			if(Contains(out, pos, next))
				next = out;
		@param	[out]	out				�n�_�ɋ߂����̌�_
		@param	[in]	line(sta,end)	�Փˌ��m����
		@return	�Փ˂��Ă��邩
		@retval	true	�Փ˂��Ă���
		@retval	false	�Փ˂��Ă��Ȃ�
	*/
	virtual bool Contains(mymath::Vec3f& out, const mymath::Vec3f& sta, const mymath::Vec3f& end)const{return false;}
	
	/*
		@brief	�����Ƃ̏Փˌ��m + �Փˎ��̌�_�̎擾
			if(Contains(out, line))
				next = out;
		@param	[out]	out		��_
		@param	[in]	line	�Փˌ��m����
		@return	�Փ˂��Ă��邩
		@retval	true	�Փ˂��Ă���
		@retval	false	�Փ˂��Ă��Ȃ�
	*/
	virtual bool Contains(std::vector<mymath::Vec3f>& out, const mymath::Linef& line)const{return false;}
	/*
		@brief	�����Ƃ̏Փˌ��m + �Փˎ��̌�_�̎擾
			if(Contains(out, pos, next))
				next = out;
		@param	[out]	out		��_
		@param	[in]	sta,end	�Փˌ��m����
		@return	�Փ˂��Ă��邩
		@retval	true	�Փ˂��Ă���
		@retval	false	�Փ˂��Ă��Ȃ�
	*/
	virtual bool Contains(std::vector<mymath::Vec3f>& out, const mymath::Vec3f& sta, const mymath::Vec3f& end)const{return false;}

	virtual bool Contains(const mymath::ShapefPtr& shape) const { return false; }
	
};
typedef std::shared_ptr<IActionPoint> ActPtPtr;

#pragma endregion  // class IActionPoint

#pragma region class CActionCircle
class CActionCircle : public IActionPoint
{
	mymath::Circlef circle_;
public:
	CActionCircle(float x, float y, float r);
	virtual void step() override;
	virtual void draw() override;
	/*
		@brief	�_�Ɖ~�̏Փˌ��m + �Փˎ��̈�ԋ߂��~����̓_�̎擾
			if(Contains(out, point))
				point = out;
		@param	[out]	out		��ԋ߂��~����̓_
		@param	[in]	point	�Փ˂��Ă��邩���m����_
		@return	�Փ˂��Ă��邩
		@retval	true	�Փ˂��Ă���
		@retval	false	�Փ˂��Ă��Ȃ�
	*/
	bool Contains(mymath::Vec3f& out, const mymath::Vec3f& point) const override;
	/*
		@brief	�����Ɖ~�̏Փˌ��m + �Փˎ��n�_�ɋ߂����̌�_�̎擾
			if(Contains(out, pos, next))
				next = out;
		@param	[out]	out				�n�_�ɋ߂����̌�_
		@param	[in]	line(sta,end)	�Փˌ��m����
		@return	�Փ˂��Ă��邩
		@retval	true	�Փ˂��Ă���
		@retval	false	�Փ˂��Ă��Ȃ�
	*/
	bool Contains(mymath::Vec3f& out, const mymath::Linef& line) const override;
	/*
		@brief	�����Ɖ~�̏Փˌ��m + �Փˎ��n�_�ɋ߂����̌�_�̎擾
			if(Contains(out, pos, next))
				next = out;
		@param	[out]	out				�n�_�ɋ߂����̌�_
		@param	[in]	line(sta,end)	�Փˌ��m����
		@return	�Փ˂��Ă��邩
		@retval	true	�Փ˂��Ă���
		@retval	false	�Փ˂��Ă��Ȃ�
	*/
	bool Contains(mymath::Vec3f& out, const mymath::Vec3f& sta, const mymath::Vec3f& end) const override;
	
	/*
		@brief	�����Ƃ̏Փˌ��m + �Փˎ��̌�_�̎擾
			if(Contains(out, line))
				next = out;
		@param	[out]	out		��_
		@param	[in]	line	�Փˌ��m����
		@return	�Փ˂��Ă��邩
		@retval	true	�Փ˂��Ă���
		@retval	false	�Փ˂��Ă��Ȃ�
	*/
	bool Contains(std::vector<mymath::Vec3f>& out, const mymath::Linef& line) const override;
	/*
		@brief	�����Ƃ̏Փˌ��m + �Փˎ��̌�_�̎擾
			if(Contains(out, pos, next))
				next = out;
		@param	[out]	out		��_
		@param	[in]	sta,end	�Փˌ��m����
		@return	�Փ˂��Ă��邩
		@retval	true	�Փ˂��Ă���
		@retval	false	�Փ˂��Ă��Ȃ�
	*/
	bool Contains(std::vector<mymath::Vec3f>& out, const mymath::Vec3f& sta, const mymath::Vec3f& end) const override;
	
};

#pragma endregion // class CActionCircle

#pragma region class CActionPolygon
class CActionPolygon : public IActionPoint
{
private:
	std::vector<mymath::Vec3f> vertexes_;	// �|���S���𐬌`���钸�_
public:
	const std::vector<mymath::Vec3f>& vertexes;
private:
	/*
		@brief	vertexes_�̏������Ƀ|���S��(�H)�𐬌`
		@return	�|���S���̘g
	*/
	std::vector<mymath::Linef> MakeLines() const;
	/*
		@brief	vertexes_�̏������ɎO�p�`�|���S���𐬌`
				vertexes_[0]����e���_�ɐL�т�
		@return	�O�p�`�|���S���Q
	*/
	std::vector<mymath::Trif> MakeTriangles() const;
public:
	CActionPolygon(const std::vector<mymath::Vec3f>& points);
	virtual void step() override;
	virtual void draw() override;
	
	//================================================================================
#pragma region Contains
	/*
		@brief	�����Ƃ̏Փˌ��m + �Փˎ��n�_�ɋ߂����̌�_�̎擾
			if(Contains(out, line))
				next = out;
		@param	[out]	out		�n�_�ɋ߂����̌�_
		@param	[in]	line	�Փˌ��m����
		@return	�Փ˂��Ă��邩
		@retval	true	�Փ˂��Ă���
		@retval	false	�Փ˂��Ă��Ȃ�
	*/
	bool Contains(mymath::Vec3f& out, const mymath::Linef& line) const override;
	/*
		@brief	�����Ƃ̏Փˌ��m + �Փˎ��n�_�ɋ߂����̌�_�̎擾
			if(Contains(out, pos, next))
				next = out;
		@param	[out]	out		�n�_�ɋ߂����̌�_
		@param	[in]	sta,end	�Փˌ��m����
		@return	�Փ˂��Ă��邩
		@retval	true	�Փ˂��Ă���
		@retval	false	�Փ˂��Ă��Ȃ�
	*/
	bool Contains(mymath::Vec3f& out, const mymath::Vec3f& sta, const mymath::Vec3f& end) const override;
	
	/*
		@brief	�����Ƃ̏Փˌ��m + �Փˎ��̌�_�̎擾
			if(Contains(out, line))
				next = out;
		@param	[out]	out		��_
		@param	[in]	line	�Փˌ��m����
		@return	�Փ˂��Ă��邩
		@retval	true	�Փ˂��Ă���
		@retval	false	�Փ˂��Ă��Ȃ�
	*/
	bool Contains(std::vector<mymath::Vec3f>& out, const mymath::Linef& line) const override;
	/*
		@brief	�����Ƃ̏Փˌ��m + �Փˎ��̌�_�̎擾
			if(Contains(out, pos, next))
				next = out;
		@param	[out]	out		��_
		@param	[in]	sta,end	�Փˌ��m����
		@return	�Փ˂��Ă��邩
		@retval	true	�Փ˂��Ă���
		@retval	false	�Փ˂��Ă��Ȃ�
	*/
	bool Contains(std::vector<mymath::Vec3f>& out, const mymath::Vec3f& sta, const mymath::Vec3f& end) const override;
	

	bool Contains(const mymath::ShapefPtr& shape) const override;

#pragma endregion // Contains
	//================================================================================
	
	//================================================================================
#pragma region Intersection
	/*
		@brief	�����Ƃ̌�_�̂����A�n�_�ɋ߂��_���擾
			if(Contains(line))
				point = IntersectionPoint2Nearest(line);
		@attention	�������Ă��邱�Ƃ��O��
		@param	[in]	line(sta,end)	��r����
		@return	�n�_�ɋ߂���_
	*/
	mymath::Vec3f IntersectionPoint2Nearest(const mymath::Linef& line) const;
	/*
		@brief	�����Ƃ̌�_�̂����A�n�_�ɋ߂��_���擾
			if(Contains(pos,next))
				point = IntersectionPoint2Nearest(pos,next);
		@attention	�������Ă��邱�Ƃ��O��
		@param	[in]	sta	��r�����̎n�_
		@param	[in]	end	��r�����̏I�_
		@return	�n�_�ɋ߂���_
	*/
	mymath::Vec3f IntersectionPoint2Nearest(const mymath::Vec3f& sta, const mymath::Vec3f& end) const;

	#pragma endregion // Intersection
	//================================================================================
	
};

#pragma endregion // class CActionPolygon


#endif