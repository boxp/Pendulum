#ifndef DEF_MYMATH_HPP
#define DEF_MYMATH_HPP
#include <cmath>
#include <vector>
#include <memory>

#include <wtypes.h>	//  RECT�p

namespace mymath
{
	const float PI = 3.14159265358979323846f;
	const double PI_D = 3.14159265358979323846;
/*
#ifndef PI
#define PI   3.14159265358979323846f
#endif
#ifndef PI_D
#define PI_D 3.14159265358979323846
#endif
*/




// 2��
//#define POW2(x)		( (x)*(x) )
// �s�^�S���X�̒藝�̃��[�g�Ȃ�
//#define PYTHA(x,y)	( POW2((x)) + POW2((y)) )

// 2��
template <typename T> inline T POW2(const T& x)
{
	return x * x; 
}
// �s�^�S���X�̒藝�̃��[�g�Ȃ�
template <typename T1, typename T2>	inline T1 PYTHA(const T1& x, const T2& y)
{ 
	return (x * x) + (y * y); 
}

// �l�̌ܓ�
template<typename T> inline T	round(T a)
{
	return T(int(a + .5 - (a<0.0)));
}


#ifndef max
#define max(a,b)            (((a) > (b)) ? (a) : (b))
//template<class T>
//inline T max(const T a, const T b)
//{
//	return ((a > b) ? a : b);
//}
#endif

#ifndef min
#define min(a,b)            (((a) < (b)) ? (a) : (b))
//template<class T>
//inline T min(const T a, const T b)
//{
//	return ((a < b) ?  a : b);
//}
#endif

#ifndef clamp
#define clamp(x,minVal,maxVal)		( min(max( (minVal), (x)), (maxVal)) )
//template<class T>
//inline clamp(const T x, const T minVal, const T maxVal)
//{
//	return ( min(max( minVal, x), maxVal) );
//}
#endif

// �~�̕⏕�@�\���g���ۂ̓R�����g�A�E�g���O�����O����`����
//#define USE_CIRCLE_EXT

//=================================================================================================
//=================================================================================================
//=================================================================================================
#pragma region Vec3

template<typename T> 
class Vec3 
{ 
public:
	T x,y,z;

	Vec3(T xx = 0, T yy = 0 , T zz = 0):
		x(xx), y(yy), z(zz)
	{}
	Vec3(const T p[3]):
		x(p[0]), y(p[1]), z(p[2])
	{}

	//Vec3(const Vec3<T>& v){ *this = v; }

	// ����A�������n
	Vec3<T>&	operator=(T v){ x=v;y=v;z=v; return *this; } 
	Vec3<T>&	operator()(T xx, T yy = 0 , T zz = 0){ x=xx; y=yy; z=zz; return *this; }

	// �P��
	Vec3<T>		operator-() const { return Vec3<T>(-x,-y,-z); }

	// ��r 
	bool		operator==(const Vec3<T>& v) const { return (x==v.x && y==v.y && z==v.z); } 
	bool		operator!=(const Vec3<T>& v) const { return (x!=v.x || y!=v.y || z!=v.z); } 

	// �x�N�g������(�x�N�g���΃x�N�g��)
	Vec3<T>		operator+(const Vec3<T>& v) const { return Vec3<T>(x+v.x, y+v.y, z+v.z); } 
	Vec3<T>		operator-(const Vec3<T>& v) const { return Vec3<T>(x-v.x, y-v.y, z-v.z); } 
	Vec3<T>		operator*(const Vec3<T>& v) const { return Vec3<T>(x*v.x, y*v.y, z*v.z); } 
	Vec3<T>		operator/(const Vec3<T>& v) const { return Vec3<T>(x/v.x, y/v.y, z/v.z); } 
	Vec3<T>&	operator+=(const Vec3<T>& v){ x+=v.x; y+=v.y; z+=v.z; return *this; } 
	Vec3<T>&	operator-=(const Vec3<T>& v){ x-=v.x; y-=v.y; z-=v.z; return *this; } 
	Vec3<T>&	operator*=(const Vec3<T>& v){ x*=v.x; y*=v.y; z*=v.z; return *this; } 
	Vec3<T>&	operator/=(const Vec3<T>& v){ x/=v.x; y/=v.y; z/=v.z; return *this; } 

	// ���ꉉ�Z
	T			operator|( const Vec3<T>& v )	{ return Dot( *this, v ); }
	Vec3<T>		operator&( const Vec3<T>& v )	{ return Cross( *this, v ); }

	// �x�N�g������2(�x�N�g���Β萔)
	Vec3<T>		operator+(T v) const { return Vec3<T>(x+v,y+v,z+v); } 
	Vec3<T>		operator-(T v) const { return Vec3<T>(x-v,y-v,z-v); } 
	Vec3<T>		operator*(T v) const { return Vec3<T>(x*v,y*v,z*v); } 
	Vec3<T>		operator/(T v) const { return Vec3<T>(x/v,y/v,z/v); } 
	Vec3<T>&	operator+=(T v){ x+=v; y+=v; z+=v; return *this; }
	Vec3<T>&	operator-=(T v){ x-=v; y-=v; z-=v; return *this; }
	Vec3<T>&	operator*=(T v){ x*=v; y*=v; z*=v; return *this; }
	Vec3<T>&	operator/=(T v){ x/=v; y/=v; z/=v; return *this; }

	// friend�֐��ɂ��x�N�g������(�萔�΃x�N�g��)
	friend Vec3<T>	operator+(T v, const Vec3<T>& obj){ return Vec3<T>(obj.x+v, obj.y+v, obj.z+v); } 
	friend Vec3<T>	operator-(T v, const Vec3<T>& obj){ return Vec3<T>(obj.x-v, obj.y-v, obj.z-v); } 
	friend Vec3<T>	operator*(T v, const Vec3<T>& obj){ return Vec3<T>(obj.x*v, obj.y*v, obj.z*v); } 
	friend Vec3<T>	operator/(T v, const Vec3<T>& obj){ return Vec3<T>(obj.x/v, obj.y/v, obj.z/v); } 
	  
	// friend�֐��ɂ���r
	friend bool		operator==(T v, Vec3<T>& obj){ return (obj.x==v && obj.y==v && obj.z==v); } 
	friend bool		operator!=(T v, Vec3<T>& obj){ return (obj.x!=v || obj.y!=v || obj.z!=v); } 
	
	// �L���X�g
	template<class T1>
	Vec3<T>& operator = (const Vec3<T1>& v)
	{
		x = static_cast<T>(v.x);
		y = static_cast<T>(v.y);
		z = static_cast<T>(v.z);
		return *this;
	}
	template<class T1>
	operator Vec3<T1>()
	{
		return Vec3<T1>(static_cast<T>(x),
						static_cast<T>(y),
						static_cast<T>(z));
	}

#pragma region member methods

	static enum eTmpReplace { X=0x01, Y=0x02, Z=0x04 };
	/*
		@brief	�ꎞ�I�ɒl��u���������x�N�g����Ԃ�
		@param	[in]	flag	�u��������x�N�g���̗v�f(X,Y,Z�Ŏw��A|�ŕ����w���)
		@param	[in]	v		���x�N�g��
		@return	�u���������x�N�g��
	*/
	Vec3<T>		TmpReplace( int flag, const Vec3<T>& v )
	{
		return Vec3<T>( (flag&X)?v.x:x, (flag&Y)?v.y:y, (flag&Z)?v.z:z );
	}

	/*
		@brief	�x�N�g���̒������擾(3D)
		@return 3�����x�N�g���̒��� sqrt(x*x + y*y + z*z)
	*/
	float Length() const
	{
		return std::sqrtf(static_cast<float>(x*x + y*y + z*z));
		//return std::sqrtf(std::powf(x,2.f) + std::powf(y,2.f) + std::powf(z,2.f));
	}
	/*
		@brief	�x�N�g���̒������擾(2D)
		@return XY���ʂ�2�����x�N�g���̒��� sqrt(x*x+y*y)
	*/
	float Length2() const
	{
		return std::sqrtf(static_cast<float>(x*x + y*y));
		//return std::sqrtf(std::powf(x,2.f) + std::powf(y,2.f));
	}

	/*
		@brief	3�����x�N�g���𐳋K������
		@return	���K�������x�N�g��
	*/
	Vec3<T>& Normalize()
	{
		float mag = 1.f / Length();
		x = static_cast<T>(static_cast<float>(x) * mag);
		y = static_cast<T>(static_cast<float>(y) * mag);
		z = static_cast<T>(static_cast<float>(z) * mag);
		return *this;
	}
	/*
		@brief	XY���ʂ�2�����x�N�g���𐳋K������
		@return	���K�������x�N�g��
	*/
	Vec3<T>& Normalize2()
	{
		float mag = 1.f / Length2();
		x = static_cast<T>(static_cast<float>(x) * mag);
		y = static_cast<T>(static_cast<float>(y) * mag);
		return *this;
	}


#pragma endregion // member methods
	
#pragma region static methods
	static Vec3<T> Right(){		return Vec3<T>( 1, 0, 0); }
	static Vec3<T> Left(){		return Vec3<T>(-1, 0, 0); }
	static Vec3<T> Top(){		return Vec3<T>( 0, 1, 0); }
	static Vec3<T> Bottom(){	return Vec3<T>( 0,-1, 0); }
	static Vec3<T> Front(){		return Vec3<T>( 0, 0, 1); }
	static Vec3<T> Back(){		return Vec3<T>( 0, 0,-1); }

	/*
		@brief �x�N�g��v1��v2�̂Ȃ��p
		@param	[in]	v1	�x�N�g��
		@param	[in]	v2	�x�N�g��
		@return	�Ȃ��p
	*/
	static float Angle(const Vec3<T>& v1, const Vec3<T>& v2)
	{
		float l1 = v1.Length();
		float l2 = v2.Length();
		if( l1 == 0.0f || l2 == 0.0f ) return 0.0f;
		return std::acosf( Dot(v1 , v2) / (l1 * l2) );
	}

	/*
		@brief	�����̃x�N�g���Ƃ̓���(v1�Ev2)
		@param	[in]	v1	�x�N�g��
		@param	[in]	v2	�x�N�g��
		@return	����
	*/
	static T Dot(const Vec3<T>& v1, const Vec3<T>& v2)
	{
		return v1.x*v2.x + v1.y*v2.y + v1.z*v2.z;
	}
	/*
		@brief	�����̃x�N�g���Ƃ�XY���ʂɂ��������(v1�Ev2)
		@param	[in]	v1	�x�N�g��
		@param	[in]	v2	�x�N�g��
		@return	����
	*/
	static T Dot2(const Vec3<T>& v1, const Vec3<T>& v2)
	{
		return v1.x*v2.x + v1.y*v2.y;
	}
	/*
		@brief	�����̃x�N�g���Ƃ̊O��(v1�~v2)
		@param	[in]	v1	�x�N�g��
		@param	[in]	v2	�x�N�g��
		@return	�O��
	*/
	static Vec3<T> Cross(const Vec3<T>& v1, const Vec3<T>& v2)
	{
		return Vec3<T>( (v1.y*v2.z)-(v1.z*v2.y), (v1.z*v2.x)-(v1.x*v2.z), (v1.x*v2.y)-(v1.y*v2.x) );
	}
	/*
		@brief	�����̃x�N�g���Ƃ�XY���ʂɂ�����O��(v1�~v2)
		@param	[in]	v1	�x�N�g��
		@param	[in]	v2	�x�N�g��
		@return	�O��
	*/
	static T Cross2(const Vec3<T>& v1, const Vec3<T>& v2)
	{
		return (v1.y*v2.x) - (v1.y * v2.x);
	}
	
	/*
		@brief	��]�P�ʃx�N�g���̏K��
		@param	[in]	angle	�p�x(unit:radian)
		@return ��]��̒P�ʃx�N�g��
	*/
	static Vec3<T> Rotate(float angle)
	{
		return Vec3<T>( std::cosf(angle), std::sinf(angle) );
	}

#pragma endregion // static methods

};
typedef Vec3<int>	Vec3i;
typedef Vec3<float>	Vec3f;

#pragma endregion // Vec3

//=================================================================================================
//=================================================================================================
//=================================================================================================
#pragma region Line

template <typename T>
class Line
{
public:
	Vec3<T> sta;
	Vec3<T> end;
public:
	Line():
		sta(0), end(0)
	{}
	Line(const Vec3<T>& s, const Vec3<T>& e):
		sta(s), end(e)
	{}
	Line(T sx, T sy, T sz, T ex, T ey, T ez):
		sta(Vec3<T>(sx,sy,sz)), end(Vec3<T>(ex,ey,ez))
	{}
	Line(const T s[3], const T e[3]):
		sta(Vec3<T>(s[0],s[1],s[2])), end(Vec3<T>(e[0],e[1],e[2]))
	{}

	/*
		@brief	��������
		@param	[in]	line	�Ώې���
		@return	�������Ă��邩
		@retval	true	�������Ă���
		@retval	false	�������Ă��Ȃ�
	*/
	bool Intersect(const Line<T>& line) const
	{
		Vec3<T> v1 = end - sta;
		Vec3<T> v2 = line.end - line.sta;
		return ( (v1 & (line.sta-sta)) | (v1 & (line.end-sta)) ) < 0.f
			&& ( (v2 & (sta-line.sta)) | (v2 & (end-line.sta)) ) < 0.f;
	}
	/*
		@brief	��������
		@param	[in]	_sta	�n�_
		@param	[in]	_end	�I�_
		@return	�������Ă��邩
		@retval	true	�������Ă���
		@retval	false	�������Ă��Ȃ�
	*/
	bool Intersect(const Vec3<T>& _sta, const Vec3<T>& _end) const
	{
		Vec3<T> v1 = end - sta;
		Vec3<T> v2 = _end - _sta;
		return ( (v1 & (_sta-sta)) | (v1 & (_end-sta)) ) < 0.f
			&& ( (v2 & (sta-_sta)) | (v2 & (end-_sta)) ) < 0.f;
	}

	/*
		@brief	��_�̎擾
			if(Intersect(line))
				point = IntersectionPoint2(line);
		@attention	�������Ă��邱�Ƃ��O��
		@param	[in]	line	����
		@return	��_
	*/
	Vec3<T> IntersectionPoint2(const Line<T>& line) const
	{
		/*
		//Vec3<T> v = line.end - line.sta;
		double d1 = std::fabs( ((line.end-line.sta) & (sta-line.sta)).Length() );
		double d2 = std::fabs( ((line.end-line.sta) & (end-line.sta)).Length() );
		double t = d1 / (d1 + d2);
		return sta + ((end - sta) * t);
		*/
		/*
		double r, s;
		double denominator = (end.x - sta.x) * (line.end.y - line.sta.y) - (end.y - sta.y) * (line.end.x - line.sta.x);
		double numeratorR = (sta.y - line.sta.y) * (line.end.x - line.sta.x) - (sta.x - line.sta.x) * (line.end.y - line.sta.y);
		r = numeratorR / denominator;
		double numeratorS = (sta.y - line.sta.y) * (end.x - sta.x) - (sta.x - line.sta.x) * (end.y - sta.y);
		s = numeratorS / denominator;
		return sta + ((end-sta) * r);
		*/
		
		double ksi = (line.end.y - line.sta.y) * (line.end.x - sta.x) - (line.end.x - line.sta.x) * (line.end.y - sta.y);
		double delta = (end.x - sta.x) * (line.end.y - line.sta.y) - (end.y - sta.y) * (line.end.x - line.sta.x);
		double ramda = ksi / delta;
		return sta + (end-sta) * static_cast<T>(ramda);
		
		/*
		double s1 = ( (line.end.x - line.sta.x) * (sta.y - line.sta.y) - (line.end.y - line.sta.y) * (sta.x - line.sta.x)) / 2.0;
		double s2 = ( (line.end.x - line.sta.x) * (line.sta.y - end.y) - (line.end.y - line.sta.y) * (line.sta.x - end.x)) / 2.0;

		return sta + (end-sta) * s1 / (s1+s2);
		*/
	}
	/*
		@brief	��_�̎擾
			if(Intersect(p1,p2))
				point = IntersectionPoint2(p1,p2);
		@attention	�������Ă��邱�Ƃ��O��
		@param	[in]	_sta	�n�_
		@param	[in]	_end	�I�_
		@return	��_
	*/
	Vec3<T> IntersectionPoint2(const Vec3<T>& _sta, const Vec3<T>& _end) const
	{
		double ksi = (_end.y - _sta.y) * (_end.x - sta.x) - (_end.x - _sta.x) * (_end.y - sta.y);
		double delta = (end.x - sta.x) * (_end.y - _sta.y) - (end.y - sta.y) * (_end.x - _sta.x);
		double ramda = ksi / delta;
		return sta + (end-sta) * static_cast<T>(ramda);
	}
};
typedef Line<float> Linef;
typedef Line<int>	Linei;

#pragma endregion // Line

//=================================================================================================
//=================================================================================================
//=================================================================================================
#pragma region Shape
template<typename Tri>
class Triangle;
template<typename Rec>
class Rect;
template<typename Cir, typename Rad>
class Circle;
/*
	@brief	�}�`�̊��N���X
*/
template<typename T> class Shape
{
private:
public:
	virtual ~Shape() = 0{}
	/*
		@brief	�}�`��l�����炷
		@param	[in]	offset	���炷��
		@return	�������g
	*/
	virtual Shape<T>& Offset(const Vec3<T>& offset) = 0{return *this;}

	/*
		@brief	�_�̓����
		@param	[in]	point	���肷��_
		@return	����Ă��邩
		@retval true	���Ă���
		@retval false	���Ă��Ȃ�
	*/
	virtual bool Contains(const Vec3<T>& point)	const{return false;}

	/*
		@brief	�����̌����A�����
		@param	[in]	line(sta,end)	���肷�����
		@param	[in]	fullContain		���S����Ƃ��邩(�f�t�H���g�Ffalse)
		@return	�����A����Ă��邩
		@retval	true	���Ă���
		@retval	false	���Ă��Ȃ�
	*/
	virtual bool Contains(const Line<T>& line, bool fullContain=false)	const{return false;}
	
	/*
		@brief	�����̌����A�����
		@param	[in]	sta				���肷������̎n�_
		@param	[in]	end				���肷������̏I�_
		@param	[in]	fullContain		���S����Ƃ��邩(�f�t�H���g�Ffalse)
		@return	�����A����Ă��邩
		@retval	true	���Ă���
		@retval	false	���Ă��Ȃ�
	*/
	virtual bool Contains(const Vec3<T>& sta, const Vec3<T>& end, bool fullContain=false)	const{return false;}
	
	/*
		@brief	�O�p�`�̌����A�����
		@param	[in]	tri				���肷��O�p�`
		@param	[in]	fullContain		���S����Ƃ��邩(�f�t�H���g�Ffalse)
		@return	�����A����Ă��邩
		@retval	true	���Ă���
		@retval	false	���Ă��Ȃ�
	*/
	virtual bool Contains(const Triangle<T>& tri, bool fullContain=false)	const{return false;}
	
	/*
		@brief	��`�̌����A�����
		@param	[in]	rect			���肷���`
		@param	[in]	fullContain		���S����Ƃ��邩(�f�t�H���g�Ffalse)
		@return	�����A����Ă��邩
		@retval	true	���Ă���
		@retval	false	���Ă��Ȃ�
	*/
	virtual bool Contains(const Rect<T>& rect, bool fullContain=false)		const{return false;}
	//virtual bool Contains(const Circle<T,T>& c, bool fullContain=false)	const{return false;}
	
	/*
		@brief	����Ă���_�����ԋ߂���_�̎擾
			if(Contains(p))
				point = IntersectionPoint2(p);
		@attention	�������Ă��邱�Ƃ��O��
		@param	[in]	point	����Ă���_
		@return	��_
	*/
	virtual Vec3<T> IntersectionPoint2(const Vec3<T>& point)	const{return Vec3<T>();}
	
	/*
		@brief	�����Ƃ̌�_�̎擾
			if(Contains(line))
				points = IntersectionPoint2(line);
		@attention	�������Ă��邱�Ƃ��O��
		@param	[in]	line(sta,end)	��r����
		@return	�S��_
	*/
	virtual std::vector<Vec3<T>> IntersectionPoint2(const Line<T>& line)	const{return std::vector<Vec3<T>>();}
	
	/*
		@brief	�����Ƃ̌�_�̎擾
			if(Contains(pos,next))
				points = IntersectionPoint2(pos,next);
		@attention	�������Ă��邱�Ƃ��O��
		@param	[in]	sta	��r�����̎n�_
		@param	[in]	end	��r�����̏I�_
		@return	�S��_
	*/
	virtual std::vector<Vec3<T>> IntersectionPoint2(const Vec3<T>& sta, const Vec3<T>& end)	const{return std::vector<Vec3<T>>();}
	
	/*
		@brief	�����Ƃ̌�_�̂����A�n�_�ɋ߂��_���擾
			if(Contains(line))
				point = IntersectionPoint2Nearest(line);
		@attention	�������Ă��邱�Ƃ��O��
		@param	[in]	line(sta,end)	��r����
		@return	�n�_�ɋ߂���_
	*/
	virtual Vec3<T> IntersectionPoint2Nearest(const Line<T>& line)	const {return Vec3<T>();}
	
	/*
		@brief	�����Ƃ̌�_�̂����A�n�_�ɋ߂��_���擾
			if(Contains(pos,next))
				point = IntersectionPoint2Nearest(pos,next);
		@attention	�������Ă��邱�Ƃ��O��
		@param	[in]	sta	��r�����̎n�_
		@param	[in]	end	��r�����̏I�_
		@return	�n�_�ɋ߂���_
	*/
	virtual Vec3<T> IntersectionPoint2Nearest(const Vec3<T>& sta, const Vec3<T>& end)	const {return Vec3<T>();}
	
};
typedef	Shape<int>		Shapei;
typedef Shape<float>	Shapef;
typedef std::shared_ptr<Shapef> ShapefPtr;

#pragma endregion // Shape


//=================================================================================================
//=================================================================================================
//=================================================================================================

#pragma region Triangle
/*
	@brief	�O�p�`
*/
template <typename T> class Triangle : public Shape<T>
{
private:

public:
	Vec3<T> points[3];	// �|���S���𐮌`���钸�_
	Triangle()
	{
		points[0] = 0;
		points[1] = 0;
		points[2] = 0;
	}
	Triangle(const Vec3<T>& aa, const Vec3<T>& bb, const Vec3<T>& cc)
	{
		points[0] = aa;
		points[1] = bb;
		points[2] = cc;
	}
	Triangle(T ax, T ay, T az, T bx, T by, T bz, T cx, T cy, T cz):
		points[0](Vec3<T>(ax, ay, az)),
		points[1](Vec3<T>(bx, by, bz)),
		points[2](Vec3<T>(cx, cy, cz))
	{}
	Triangle(T a[3], T b[3], T c[3]):
		points[0](Vec3<T>(a[0], a[1], a[2])),
		points[1](Vec3<T>(b[0], b[1], b[2])),
		points[2](Vec3<T>(c[0], c[1], c[2]))
	{}
	
	/*
		@brief	�}�`��l�����炷
		@param	[in]	offset	���炷��
		@return	�������g
	*/
	virtual Shape<T>& Offset(const Vec3<T>& offset) override
	{
		for(auto& point : points)
		{
			point += offset;
		}
		return *this;
	}

	//================================================================================
#pragma region Contains
	/*
		@brief	�_�̓����
		@param	[in]	point	���肷��_
		@return	����Ă��邩
		@retval true	���Ă���
		@retval false	���Ă��Ȃ�
	*/
	bool Contains(const Vec3<T>& point) const override
	{
		int cnt = 0;
		for(int i=0; i<3; ++i)
		{
			int j = (i+1) % 3;
			Vec3<T> vec(points[j] - points[i]);	// ab,bc,ca
			Vec3<T> p_p(point - points[i]);		// ap,bp,cp 
			// �O�ς̌�������
			cnt += (Vec3<T>::Dot2(vec,p_p) > static_cast<T>(0)) ? 1 : -1;
		}
		return (cnt == 3 || cnt == -3);
	}
	/*
		@brief	�����̌����A�����
		@param	[in]	line(sta,end)	���肷�����
		@param	[in]	fullContain		���S����Ƃ��邩(�f�t�H���g�Ffalse)
		@return	�����A����Ă��邩
		@retval	true	���Ă���
		@retval	false	���Ă��Ȃ�
	*/
	bool Contains(const Line<T>& line, bool fullContain = false) const override
	{
		// ���S����
		if(fullContain)
		{
			return ( Contains(line.sta) && Contains(line.end) );
		}
		// �O���Ƃ̌�������
		std::vector<Vec3<T>> intersections;
		for(int i = 0; i < 3; ++i)
		{
			int j = (i+1) % 3;
			if(line.Intersect(points[i], points[j]))
			{
				intersections.push_back(line.IntersectionPoint2(points[i],points[j]));
			}
		}
		// ��_����������
		if(intersections.empty())
		{
			// ���S����`�F�b�N(�n�_�܂��͏I�_�������Ă���Ί��S����Ƃ�����)
			return Contains(line.sta);
		}
		return true;
	}
	/*
		@brief	�����̌����A�����
		@param	[in]	sta				���肷������̎n�_
		@param	[in]	end				���肷������̏I�_
		@param	[in]	fullContain		���S����Ƃ��邩(�f�t�H���g�Ffalse)
		@return	�����A����Ă��邩
		@retval	true	���Ă���
		@retval	false	���Ă��Ȃ�
	*/
	bool Contains(const Vec3<T>& sta, const Vec3<T>& end, bool fullContain = false) const override
	{
		// ���S����
		if(fullContain)
		{
			return ( Contains(sta) && Contains(end) );
		}
		// �O���Ƃ̌�������
		std::vector<Vec3<T>> intersections;
		Line<T> line(sta, end);
		for(int i = 0; i < 3; ++i)
		{
			int j = (i+1) % 3;
			if(line.Intersect(points[i],points[j]))
				intersections.push_back(line.IntersectionPoint2(points[i],points[j]));
		}
		// ��_����������
		if(intersections.empty())
		{
			// ���S����`�F�b�N(�n�_�܂��͏I�_�������Ă���Ί��S����Ƃ�����)
			return Contains(sta);
		}
		return true;
	}
	/*
		@brief	�O�p�`�̌����A�����
		@param	[in]	tri				���肷��O�p�`
		@param	[in]	fullContain		���S����Ƃ��邩(�f�t�H���g�Ffalse)
		@return	�����A����Ă��邩
		@retval	true	���Ă���
		@retval	false	���Ă��Ȃ�
	*/
	bool Contains(const Triangle<T>& tri, bool fullContain = false) const override
	{
		bool vertextes[3]={false,false,false};	// ���_�̓���
		// ���_����
		for(int i=0; i<3; ++i)
		{
			vertextes[i] = Contains(tri.points[i]);
			if(!fullContain && vertextes[i])
				return true;
		}
		if(fullContain)
			return vertextes[0] && vertextes[1] && vertextes[2];
		
		// �ӌ���
		for(int i=0; i<3; ++i)
		{
			int j = (i+1) % 3;
			Line<T> line(points[i],points[j]);
			for(int k = 0; k < 3; ++k)
			{
				int l = (k+1) % 3;
				if(line.Intersect(tri.points[k], tri.points[l]))
					return true;
			}
		}
		return false;
	}
	/*
		@brief	��`�̌����A�����
		@param	[in]	rect			���肷���`
		@param	[in]	fullContain		���S����Ƃ��邩(�f�t�H���g�Ffalse)
		@return	�����A����Ă��邩
		@retval	true	���Ă���
		@retval	false	���Ă��Ȃ�
	*/
	bool Contains(const Rect<T>& rect, bool fullContain = false) const override
	{
		bool vertextes[4]={false,false,false,false};	// ���_�̓���
		// ���_����
		Vec3<T> rp[4] = {
			Vec3<T>(rect.left,	rect.top,	points[0].z),
			Vec3<T>(rect.right,	rect.top,	points[0].z),
			Vec3<T>(rect.left,	rect.bottom,points[0].z),
			Vec3<T>(rect.right,	rect.bottom,points[0].z)
		};
		for(int i=0; i<4; ++i)
		{
			vertextes[i] = Contains(rp[i]);
			if(!fullContain && vertextes[i])
				return true;
		}
		if(fullContain)
			return vertextes[0] && vertextes[1] && vertextes[2] && vertextes[3];
		
		// �ӌ���
		for(int i=0; i<3; ++i)
		{
			int j = (i+1) % 3;
			Line<T> line(points[i],points[j]);
			for(int k = 0; k < 4; ++k)
			{
				int l = (k+1) % 4;
				if(line.Intersect(rp[k], rp[l]))
					return true;
			}
		}
		return false;
	}
#pragma endregion // Contains
	//================================================================================

	//================================================================================
#pragma region Intersection
	/*
		@brief	����Ă���_�����ԋ߂���_�̎擾
			if(Contains(p))
				point = IntersectionPoint2(p);
		@attention	�������Ă��邱�Ƃ��O��
		@param	[in]	point	����Ă���_
		@return	��_
	*/
	Vec3<T> IntersectionPoint2(const Vec3<T>& point) const override
	{
		Vec3<T> ab(points[1] - points[0]);	// p0 -> p1
		Vec3<T> bp(point - points[1]);		// p1 -> point

		Vec3<T> bc(points[2] - points[1]);	// p1 -> p2
		Vec3<T> cp(point - points[2]);		// p2 -> point

		Vec3<T> ca(points[0] - points[2]);	// p2 -> p0
		Vec3<T> ap(point - points[0]);		// p0 -> point

		// z�����݂̂̊O��
		T c1((ab.x * bp.y) - (ab.y * bp.x));
		T c2((bc.x * cp.y) - (bc.y * cp.x));
		T c3((ca.x * ap.y) - (ca.y * ap.x));
		
		Vec3<T> d_ab((Vec3<T>::Dot(ab.Normalize2(),bp) * ab.Normalize2()) - bp);			
		Vec3<T> d_bc((Vec3<T>::Dot(bc.Normalize2(),cp) * bc.Normalize2()) - cp);
		Vec3<T> d_ca((Vec3<T>::Dot(ca.Normalize2(),ap) * ca.Normalize2()) - ap);
		Vec3<T> work;	// �ł��߂������x�N�g���i�[�p
		// min( min(ab, bc), ca )
		work = (PYTHA(d_ab.x,d_ab.y) < PYTHA(d_bc.x,d_bc.y))? d_ab : d_bc;
		work = (PYTHA(work.x,work.y) < PYTHA(d_ca.x,d_ca.y))? work : d_ca;
		return (work + point);

	}

	/*
		@brief	�����Ƃ̌�_�̎擾
			if(Contains(line))
				points = IntersectionPoint2(line);
		@attention	�������Ă��邱�Ƃ��O��
		@param	[in]	line(sta,end)	��r����
		@return	�S��_
	*/
	std::vector<Vec3<T>> IntersectionPoint2(const Line<T>& line) const override
	{
		std::vector<Vec3<T>> intersections;
		for(int i=0; i<3; ++i)
		{
			int j = (i+1) % 3;
			if(line.Intersect(points[i],points[j]))
				intersections.push_back(line.IntersectionPoint2(points[i],points[j]));
		}
		return intersections;
	}
	/*
		@brief	�����Ƃ̌�_�̎擾
			if(Contains(pos,next))
				points = IntersectionPoint2(pos,next);
		@attention	�������Ă��邱�Ƃ��O��
		@param	[in]	sta	��r�����̎n�_
		@param	[in]	end	��r�����̏I�_
		@return	�S��_
	*/
	std::vector<Vec3<T>> IntersectionPoint2(const Vec3<T>& sta, const Vec3<T>& end) const override
	{
		std::vector<Vec3<T>> intersections;
		Line<T> line(sta,end);
		for(int i=0; i<3; ++i)
		{
			int j = (i+1) % 3;
			if(line.Intersect(points[i],points[j]))
				intersections.push_back(line.IntersectionPoint2(points[i],points[j]));
		}
		return intersections;
	}


	/*
		@brief	�����Ƃ̌�_�̂����A�n�_�ɋ߂��_���擾
			if(Contains(line))
				point = IntersectionPoint2Nearest(line);
		@attention	�������Ă��邱�Ƃ��O��
		@param	[in]	line(sta,end)	��r����
		@return	�n�_�ɋ߂���_
	*/
	Vec3<T> IntersectionPoint2Nearest(const Line<T>& line) const override
	{
		std::vector<Vec3<T>> intersections;
		for(int i=0; i<3; ++i)
		{
			int j = (i+1) % 3;
			if(line.Intersect(points[i],points[j]))
				intersections.push_back(line.IntersectionPoint2(points[i],points[j]));
		}
		// �n�_�Ɉ�ԋ߂���_�̎Z�o
		Vec3<T> min = intersections[0];
		for(size_t i = 1; i < intersections.size(); ++i)
		{
			Vec3<T> d1 = min - line.sta;
			Vec3<T> d2 = intersections[i] - line.sta;
			if(PYTHA(d1.x, d1.y) > PYTHA(d2.x, d2.y))
				min = intersections[i];
		}
		return min;
	}
	/*
		@brief	�����Ƃ̌�_�̂����A�n�_�ɋ߂��_���擾
			if(Contains(pos,next))
				point = IntersectionPoint2Nearest(pos,next);
		@attention	�������Ă��邱�Ƃ��O��
		@param	[in]	sta	��r�����̎n�_
		@param	[in]	end	��r�����̏I�_
		@return	�n�_�ɋ߂���_
	*/
	Vec3<T> IntersectionPoint2Nearest(const Vec3<T>& sta, const Vec3<T>& end) const override
	{
		std::vector<Vec3<T>> intersections;
		Line<T> line(sta,end);
		for(int i=0; i<3; ++i)
		{
			int j = (i+1) % 3;
			if(line.Intersect(points[i],points[j]))
				intersections.push_back(line.IntersectionPoint2(points[i],points[j]));
		}
		// �n�_�Ɉ�ԋ߂���_�̎Z�o
		Vec3<T> min = intersections[0];
		for(size_t i = 1; i < intersections.size(); ++i)
		{
			Vec3<T> d1 = min - sta;
			Vec3<T> d2 = intersections[i] - sta;
			if(PYTHA(d1.x, d1.y) > PYTHA(d2.x, d2.y))
				min = intersections[i];
		}
		return min;
	}
#pragma endregion // Intersection
	//================================================================================
	
};
typedef Triangle<float> Trif;
typedef Triangle<int> Trii;

#pragma endregion // Triangle

//=================================================================================================
//=================================================================================================
//=================================================================================================
#pragma region Rect
/*
	@brief	��`
*/
template<typename T> class Rect : public Shape<T>
{
public:
	T left, top, right, bottom;
	Rect(T l=0, T t=0, T r=0, T b=0):
		left(l),top(t),
		right(r),bottom(b)
	{}
	Rect(const Vec3<T>& leftTop, const Vec3<T>& rightBottom):
		left(leftTop.x), top(leftTop.y),
		right(rightBottom.x), bottom(rightBottom.y)
	{}
	Rect(const RECT& rect):
		left((T)rect.left), top((T)rect.top),
		right((T)rect.right), bottom((T)rect.bottom)
	{}
	
	/*
		@brief	�}�`��l�����炷
		@param	[in]	offset	���炷��
		@return	�������g
	*/
	virtual Shape<T>& Offset(const Vec3<T>& offset) override
	{
		left += offset.x;
		right += offset.x;
		top += offset.y;
		bottom += offset.y;
		return *this;
	}

	//================================================================================
#pragma region Contains
	/*
		@brief	�_�̓����
		@param	[in]	point	���肷��_
		@return	����Ă��邩
		@retval true	���Ă���
		@retval false	���Ă��Ȃ�
	*/
	bool Contains(const Vec3<T>& point) const override
	{
		return left <= point.x && point.x <= right
			&& top	<= point.y && point.y <= bottom;
	}
	/*
		@brief	�����̌����A�����
		@param	[in]	line(sta,end)	���肷�����
		@param	[in]	fullContain		���S����Ƃ��邩(�f�t�H���g�Ffalse)
		@return	�����A����Ă��邩
		@retval	true	���Ă���
		@retval	false	���Ă��Ȃ�
	*/
	bool Contains(const Line<T>& line, bool fullContain = false) const override
	{
		// ���S����
		if(fullContain)
		{
			return ( Contains(line.sta) && Contains(line.end) );
		}
		// �O���Ƃ̌�������
		bool intersection = false;
		Vec3<T> points[4] = {
			Vec3<T>(left,	top,	line.sta.z),
			Vec3<T>(right,	top,	line.sta.z),
			Vec3<T>(left,	bottom,	line.sta.z),
			Vec3<T>(right,	bottom,	line.sta.z)
		};
		for(int i = 0; i < 4; ++i)
		{
			int j = (i+1) % 4;
			if(line.Intersect(points[i],points[j]))
			{
				intersection = true;
				break;
			}
		}
		// ��_����������
		if(!intersection)
		{
			// ���S����`�F�b�N(�n�_�܂��͏I�_�������Ă���Ί��S����Ƃ�����)
			return Contains(line.sta);
		}
		return true;
	}
	/*
		@brief	�����̌����A�����
		@param	[in]	sta				���肷������̎n�_
		@param	[in]	end				���肷������̏I�_
		@param	[in]	fullContain		���S����Ƃ��邩(�f�t�H���g�Ffalse)
		@return	�����A����Ă��邩
		@retval	true	���Ă���
		@retval	false	���Ă��Ȃ�
	*/
	bool Contains(const Vec3<T>& sta, const Vec3<T>& end, bool fullContain = false) const override
	{
		// ���S����
		if(fullContain)
		{
			return ( Contains(sta) && Contains(end) );
		}
		// �O���Ƃ̌�������
		bool intersection = false;
		Line<T> line(sta,end);
		Vec3<T> points[4] = {
			Vec3<T>(left,	top,	line.sta.z),
			Vec3<T>(right,	top,	line.sta.z),
			Vec3<T>(left,	bottom,	line.sta.z),
			Vec3<T>(right,	bottom,	line.sta.z)
		};
		for(int i = 0; i < 4; ++i)
		{
			int j = (i+1) % 4;
			if(line.Intersect(points[i],points[j]))
			{
				intersection = true;
				break;
			}
		}
		// ��_����������
		if(!intersection)
		{
			// ���S����`�F�b�N(�n�_�܂��͏I�_�������Ă���Ί��S����Ƃ�����)
			return Contains(sta);
		}
		return true;
	}
	/*
		@brief	�O�p�`�̌����A�����
		@param	[in]	tri				���肷��O�p�`
		@param	[in]	fullContain		���S����Ƃ��邩(�f�t�H���g�Ffalse)
		@return	�����A����Ă��邩
		@retval	true	���Ă���
		@retval	false	���Ă��Ȃ�
	*/
	bool Contains(const Triangle<T>& tri, bool fullContain = false) const override
	{
		bool vertextes[3]={false,false,false};	// ���_�̓���
		Vec3<T> points[4] = {
			Vec3<T>(left,	top,	tri.points[0].z),
			Vec3<T>(right,	top,	tri.points[0].z),
			Vec3<T>(left,	bottom,	tri.points[0].z),
			Vec3<T>(right,	bottom,	tri.points[0].z)
		};
		// ���_����
		for(int i=0; i<3; ++i)
		{
			vertextes[i] = Contains(tri.points[i]);
			if(!fullContain && vertextes[i])
				return true;
		}
		if(fullContain)
			return vertextes[0] && vertextes[1] && vertextes[2];
		
		// �ӌ���
		for(int i=0; i<4; ++i)
		{
			int j = (i+1) % 4;
			Line<T> line(points[i],points[j]);
			for(int k = 0; k < 3; ++k)
			{
				int l = (k+1) % 3;
				if(line.Intersect(tri.points[k], tri.points[l]))
					return true;
			}
		}
		return false;
	}
	/*
		@brief	��`�̌����A�����
		@param	[in]	rect			���肷���`
		@param	[in]	fullContain		���S����Ƃ��邩(�f�t�H���g�Ffalse)
		@return	�����A����Ă��邩
		@retval	true	���Ă���
		@retval	false	���Ă��Ȃ�
	*/
	bool Contains(const Rect<T>& rect, bool fullContain = false) const override
	{
		if(fullContain)
		{
			bool vertextes[4]={false,false,false,false};	// ���_�̓���
			Vec3<T> rp[4] = {
				Vec3<T>(rect.left,rect.top,0),
				Vec3<T>(rect.right,rect.top,0),
				Vec3<T>(rect.left,rect.bottom,0),
				Vec3<T>(rect.right,rect.bottom,0)
			};
			// ���_����
			for(int i=0; i<4; ++i)
			{
				if(Contains(rp[i])) continue;
				return false;
			}
			return true;
		}
		else
		{
			if(left > rect.right) return false;
			if(rect.left > right) return false;
			if(top > rect.bottom) return false;
			if(rect.top > bottom) return false;
			return true;
		}
		/*
		bool vertextes[4]={false,false,false,false};	// ���_�̓���
		Vec3<T> points[4] = {
			Vec3<T>(left,top,0),
			Vec3<T>(right,top,0),
			Vec3<T>(left,bottom,0),
			Vec3<T>(right,bottom,0)
		};
		Vec3<T> rp[4] = {
			Vec3<T>(rect.left,rect.top,0),
			Vec3<T>(rect.right,rect.top,0),
			Vec3<T>(rect.left,rect.bottom,0),
			Vec3<T>(rect.right,rect.bottom,0)
		};
		// ���_����
		for(int i=0; i<4; ++i)
		{
			vertextes[i] = Contains(rp[i]);
			if(!fullContain && vertextes[i])
				return true;
		}
		if(fullContain)
			return vertextes[0] && vertextes[1] && vertextes[2] && vertextes[3];
		
		// �ӌ���
		for(int i=0; i<4; ++i)
		{
			int j = (i+1) % 4;
			Line<T> line(points[i],points[j]);
			for(int k = 0; k < 4; ++k)
			{
				int l = (k+1) % 4;
				if(line.Intersect(rp[k], rp[l]))
					return true;
			}
		}
		*/
	}
#pragma endregion // Contains
	//================================================================================
	
	//================================================================================
#pragma region Intersection
	/*
		@brief	����Ă���_�����ԋ߂���_�̎擾
			if(Contains(p))
				point = IntersectionPoint2(p);
		@attention	�������Ă��邱�Ƃ��O��
		@param	[in]	point	����Ă���_
		@return	��_
	*/
	Vec3<T> IntersectionPoint2(const Vec3<T>& point) const override
	{
		Vec3<T> points[4] = {
			Vec3<T>(left,	top,	point.z),
			Vec3<T>(right,	top,	point.z),
			Vec3<T>(left,	bottom,	point.z),
			Vec3<T>(right,	bottom,	point.z)
		};
		Vec3<T> ab(points[1] - points[0]);	// p0 -> p1
		Vec3<T> bp(point - points[1]);		// p1 -> point

		Vec3<T> bc(points[2] - points[1]);	// p1 -> p2
		Vec3<T> cp(point - points[2]);		// p2 -> point

		Vec3<T> cd(points[3] - points[2]);	// p2 -> p3
		Vec3<T> dp(point - points[3]);		// p3 -> point

		Vec3<T> da(points[0] - points[3]);	// p3 -> p0
		Vec3<T> ap(point - points[0]);		// p0 -> point


		// z�����݂̂̊O��
		T c1 = Vec3<T>::Cross2(ab, bp);
		T c2 = Vec3<T>::Cross2(bc, cp);
		T c3 = Vec3<T>::Cross2(cd, dp);
		T c4 = Vec3<T>::Cross2(da, ap);
		
		Vec3<T> d_ab((Vec3<T>::Dot(ab.Normalize2(),bp) * ab.Normalize2()) - bp);			
		Vec3<T> d_bc((Vec3<T>::Dot(bc.Normalize2(),cp) * bc.Normalize2()) - cp);
		Vec3<T> d_cd((Vec3<T>::Dot(cd.Normalize2(),dp) * cd.Normalize2()) - dp);
		Vec3<T> d_da((Vec3<T>::Dot(da.Normalize2(),ap) * da.Normalize2()) - ap);
		Vec3<T> work;	// �ł��߂������x�N�g���i�[�p
		// min( min( min(ab, bc), cd ) , da)
		work = (PYTHA(d_ab.x,d_ab.y) < PYTHA(d_bc.x,d_bc.y))? d_ab : d_bc;
		work = (PYTHA(work.x,work.y) < PYTHA(d_cd.x,d_cd.y))? work : d_cd;
		work = (PYTHA(work.x,work.y) < PYTHA(d_da.x,d_da.y))? work : d_da;
		return (work + point);

	}

	/*
		@brief	�����Ƃ̌�_�̎擾
			if(Contains(line))
				points = IntersectionPoint2(line);
		@attention	�������Ă��邱�Ƃ��O��
		@param	[in]	line(sta,end)	��r����
		@return	�S��_
	*/
	std::vector<Vec3<T>> IntersectionPoint2(const Line<T>& line) const override
	{
		std::vector<Vec3<T>> intersections;
		Vec3<T> points[4] = {
			Vec3<T>(left,	top,	line.sta.z),
			Vec3<T>(right,	top,	line.sta.z),
			Vec3<T>(left,	bottom,	line.sta.z),
			Vec3<T>(right,	bottom,	line.sta.z)
		};
		for(int i=0; i<4; ++i)
		{
			int j = (i+1) % 4;
			if(line.Intersect(points[i],points[j]))
				intersections.push_back(line.IntersectionPoint2(points[i],points[j]));
		}
		return intersections;
	}
	/*
		@brief	�����Ƃ̌�_�̎擾
			if(Contains(pos,next))
				points = IntersectionPoint2(pos,next);
		@attention	�������Ă��邱�Ƃ��O��
		@param	[in]	sta	��r�����̎n�_
		@param	[in]	end	��r�����̏I�_
		@return	�S��_
	*/
	std::vector<Vec3<T>> IntersectionPoint2(const Vec3<T>& sta, const Vec3<T>& end) const override
	{
		std::vector<Vec3<T>> intersections;
		Line<T> line(sta,end);
		Vec3<T> points[4] = {
			Vec3<T>(left,	top,	line.sta.z),
			Vec3<T>(right,	top,	line.sta.z),
			Vec3<T>(left,	bottom,	line.sta.z),
			Vec3<T>(right,	bottom,	line.sta.z)
		};
		for(int i=0; i<4; ++i)
		{
			int j = (i+1) % 4;
			if(line.Intersect(points[i],points[j]))
				intersections.push_back(line.IntersectionPoint2(points[i],points[j]));
		}
		return intersections;
	}


	/*
		@brief	�����Ƃ̌�_�̂����A�n�_�ɋ߂��_���擾
			if(Contains(line))
				point = IntersectionPoint2Nearest(line);
		@attention	�������Ă��邱�Ƃ��O��
		@param	[in]	line(sta,end)	��r����
		@return	�n�_�ɋ߂���_
	*/
	Vec3<T> IntersectionPoint2Nearest(const Line<T>& line) const override
	{
		std::vector<Vec3<T>> intersections;
		Vec3<T> points[4] = {
			Vec3<T>(left,	top,	line.sta.z),
			Vec3<T>(right,	top,	line.sta.z),
			Vec3<T>(left,	bottom,	line.sta.z),
			Vec3<T>(right,	bottom,	line.sta.z)
		};
		for(int i=0; i<4; ++i)
		{
			int j = (i+1) % 4;
			if(line.Intersect(points[i],points[j]))
				intersections.push_back(line.IntersectionPoint2(points[i],points[j]));
		}
		// �n�_�Ɉ�ԋ߂���_�̎Z�o
		Vec3<T> min = intersections[0];
		for(size_t i = 1; i < intersections.size(); ++i)
		{
			Vec3<T> d1 = min - line.sta;
			Vec3<T> d2 = intersections[i] - line.sta;
			if(PYTHA(d1.x, d1.y) > PYTHA(d2.x, d2.y))
				min = intersections[i];
		}
		return min;
	}
	/*
		@brief	�����Ƃ̌�_�̂����A�n�_�ɋ߂��_���擾
			if(Contains(pos,next))
				point = IntersectionPoint2Nearest(pos,next);
		@attention	�������Ă��邱�Ƃ��O��
		@param	[in]	sta	��r�����̎n�_
		@param	[in]	end	��r�����̏I�_
		@return	�n�_�ɋ߂���_
	*/
	Vec3<T> IntersectionPoint2Nearest(const Vec3<T>& sta, const Vec3<T>& end) const override
	{
		std::vector<Vec3<T>> intersections;
		Line<T> line(sta,end);
		Vec3<T> points[4] = {
			Vec3<T>(left,	top,	line.sta.z),
			Vec3<T>(right,	top,	line.sta.z),
			Vec3<T>(left,	bottom,	line.sta.z),
			Vec3<T>(right,	bottom,	line.sta.z)
		};
		for(int i=0; i<4; ++i)
		{
			int j = (i+1) % 4;
			if(line.Intersect(points[i],points[j]))
				intersections.push_back(line.IntersectionPoint2(points[i],points[j]));
		}
		// �n�_�Ɉ�ԋ߂���_�̎Z�o
		Vec3<T> min = intersections[0];
		for(size_t i = 1; i < intersections.size(); ++i)
		{
			Vec3<T> d1 = min - sta;
			Vec3<T> d2 = intersections[i] - sta;
			if(PYTHA(d1.x, d1.y) > PYTHA(d2.x, d2.y))
				min = intersections[i];
		}
		return min;
	}
#pragma endregion // Intersection
	//================================================================================
	
	template<class T1>
	Rect<T>& operator = (const Rect<T1>& rt)
	{
		left	= static_cast<T>(rt.left);
		top		= static_cast<T>(rt.top);
		right	= static_cast<T>(rt.right);
		bottom	= static_cast<T>(rt.bottom);
		return *this;
	}
	template<class T1>
	operator Rect<T1>()
	{
		Rect<T1> rt(	static_cast<T1>(left),
						static_cast<T1>(top),
						static_cast<T1>(right),
						static_cast<T1>(bottom));

		return rt;
	}

	/*
		@brief�@��`�����炷
		@param	[in]	ofs_x	���������ɂ��ꂼ��ɉ��Z�����
		@param	[in]	ofs_y	���������ɂ��ꂼ��ɉ��Z�����
		return ���炵�����Ƃ̎��g(�A�����ď�����悤��)
	
	Rect<T>& offset(T ofs_x, T ofs_y)
	{
		left	+= ofs_x;
		right	+= ofs_x;
		top		+= ofs_y;
		bottom	+= ofs_y;
		return *this;
	}*/
};
typedef Rect<int>	Recti;
typedef Rect<float>	Rectf;

#pragma endregion // Rect

//=================================================================================================
//=================================================================================================
//=================================================================================================
#pragma region Circle

#ifdef USE_CIRCLE_EXT
#include "../../../lib/gplib.h"
#endif
/*
	@brief	�~
		Vec3<T1> center
		T2	radius
*/
template<typename T1, typename T2> class Circle : public Shape<T1>
{
public:
	Vec3<T1> center;
	T2 radius;		// �傫��(���a)
public:
	Circle():center(Vec3<T1>()),radius(0)
	{}
	Circle(T1 x, T1 y, T1 z, T2 r):
		center(Vec3<T1>(x,y,z)),radius(r)
	{}
	Circle(const Vec3<T1>& c, T2 r):
		center(c), radius(r)
	{}

	/*
		@brief	�}�`��l�����炷
		@param	[in]	offset	���炷��
		@return	�������g
	*/
	virtual Shape<T1>& Offset(const Vec3<T1>& offset) override
	{
		center += offset;
		return *this;
	}
	//================================================================================
#pragma region Contains
	/*
		@brief	�_�̓����
		@param	[in]	point	���肷��_
		@return	����Ă��邩
		@retval	true	����Ă���
		@retval	false	����Ă��Ȃ�
	*/
	bool Contains(const Vec3<T1>& point) const override
	{
		const Vec3<T1>& c = center;
		const Vec3<T1>& p = point;
		return (PYTHA(p.x-c.x, p.y-c.y) <= POW2(radius) );
	}

	/*
		@brief	�����̌����A�����
		@param	[in]	line(sta,end)	���肷�����
		@param	[in]	fullContain		���S����Ƃ��邩(�f�t�H���g�Ffalse)
		@return	�����A����Ă��邩
		@retval	true	���Ă���
		@retval	false	���Ă��Ȃ�
	*/
	bool Contains(const Line<T1>& line, bool fullContain = false) const override
	{
		Vec3<T1> sp(center - line.sta); // �����n�_����~���S�ւ̃x�N�g��(start->pos)
		Vec3<T1> ep(center - line.end); // �����I�_����~���S�ւ̃x�N�g��(end->pos)
		bool isInner = (PYTHA(sp.x,sp.y) < POW2(radius))
					&& (PYTHA(ep.x,ep.y) < POW2(radius));
		// ���S����(�~�̓���)
		if(fullContain)
		{
			return isInner;
		}
		if(isInner)
		{
			return false;
		}
		Vec3<T1> nv((line.end - line.sta).Normalize2());	// �����̒P�ʃx�N�g��(normalize-vector)
		// �~���S��������ւ̐��� d=((n�Ep)*n)-p
		Vec3<T1> dist((Vec3<T1>::Dot(nv,sp) * nv) - sp);
		
		if(PYTHA(dist.x,dist.y) > POW2(radius))
		{
			// ��������(�~�̊O��)
			return false;
		}
		else if((PYTHA(sp.x,sp.y) > POW2(radius) && PYTHA(ep.x,ep.y) > POW2(radius))
			&&	(((sp.x > 0.f)? 1.f : -1.f) == ((ep.x > 0.f)? 1.f : -1.f))
			&&	(((sp.y > 0.f)? 1.f : -1.f) == ((ep.y > 0.f)? 1.f : -1.f)))
		{
			// ��������(���S�_���܂����Ȃ�)
			return false;
		}
		return true;
	}
	/*
		@brief	�����̌����A�����
		@param	[in]	sta				���肷������̎n�_
		@param	[in]	end				���肷������̏I�_
		@param	[in]	fullContain		���S����Ƃ��邩(�f�t�H���g�Ffalse)
		@return	�����A����Ă��邩
		@retval	true	���Ă���
		@retval	false	���Ă��Ȃ�
	*/
	bool Contains(const Vec3<T1>& sta, const Vec3<T1>& end, bool fullContain = false) const override
	{
		Vec3<T1> sp(center - sta); // �����n�_����~���S�ւ̃x�N�g��
		Vec3<T1> ep(center - end); // �����I�_����~���S�ւ̃x�N�g��
		bool isInner = (PYTHA(sp.x,sp.y) < POW2(radius))
					&& (PYTHA(ep.x,ep.y) < POW2(radius));
		// ���S����(�~�̓���)
		if(fullContain)
		{
			return isInner;
		}
		if(isInner)
		{
			return false;
		}
		Vec3<T1> nv((end - sta).Normalize2());	// �����̒P�ʃx�N�g��
		// �~���S��������ւ̐��� d=((n�Ep)n)-p
		Vec3<T1> dist((Vec3<T1>::Dot(nv,sp) * nv) - sp);
		if(PYTHA(dist.x,dist.y) > POW2(radius))
		{
			// ��������(�~�̊O��)
			return false;
		}
		else if((PYTHA(sp.x,sp.y) > POW2(radius) && PYTHA(ep.x,ep.y) > POW2(radius))
			&&	(((sp.x > 0.f)? 1.f : -1.f) == ((ep.x > 0.f)? 1.f : -1.f))
			&&	(((sp.y > 0.f)? 1.f : -1.f) == ((ep.y > 0.f)? 1.f : -1.f)))
		{
			// ��������(���S�_���܂����Ȃ�)
			return false;
		}
		return true;
	}
	

	/*
		@brief	�����̓����
		@attension	�����̗��[���~�̒��ɂ���ꍇ�͑�3�����ɂ��ς��
					���S����Ɖ~�������͓���D�悳��� 
		@param	[in]	line(sta,end)	���肷�����(�n�_�A�I�_)
		@param	[in]	fullContain		���S����Ƃ��邩
		@param	[in]	intersectOnly	�~���Ƃ̌����݂̂ɂ��邩
		@return	����Ă��邩
		@retval	true	���Ă���
		@retval	false	���Ă��Ȃ�
	*/
	bool Contains(const Line<T1>& line, bool fullContain, bool intersectOnly) const
	{
		Vec3<T1> sp(center - line.sta); // �����n�_����~���S�ւ̃x�N�g��(start->pos)
		Vec3<T1> ep(center - line.end); // �����I�_����~���S�ւ̃x�N�g��(end->pos)
		bool isInner = (PYTHA(sp.x,sp.y) < POW2(radius))
					&& (PYTHA(ep.x,ep.y) < POW2(radius));
		// ���S����(�~�̓���)
		if(fullContain)
		{
			return isInner;
		}
		if(isInner)
		{
			return !intersectOnly;
		}
		Vec3<T1> nv((line.end - line.sta).Normalize2());	// �����̒P�ʃx�N�g��(normalize-vector)
		// �~���S��������ւ̐��� d=((n�Ep)*n)-p
		Vec3<T1> dist((Vec3<T1>::Dot(nv,sp) * nv) - sp);
		
		if(PYTHA(dist.x,dist.y) > POW2(radius))
		{
			// ��������(�~�̊O��)
			return false;
		}
		else if((PYTHA(sp.x,sp.y) > POW2(radius) && PYTHA(ep.x,ep.y) > POW2(radius))
			&&	(((sp.x > 0.f)? 1.f : -1.f) == ((ep.x > 0.f)? 1.f : -1.f))
			&&	(((sp.y > 0.f)? 1.f : -1.f) == ((ep.y > 0.f)? 1.f : -1.f)))
		{
			// ��������(���S�_���܂����Ȃ�)
			return false;
		}
		return true;
	}
	/*
		@brief	�����̓����
		@attension	�����̗��[���~�̒��ɂ���ꍇ�͑�4�����ɂ��ς��
					���S����Ɖ~�������͓���D�悳���
		@param	[in]	sta	���肷������̎n�_
		@param	[in]	end	���肷������̏I�_
		@param	[in]	fullContain		���S����Ƃ��邩
		@param	[in]	intersectOnly	�~���Ƃ̌����݂̂ɂ��邩
		@return	����Ă��邩
		@retval	true	���Ă���
		@retval	false	���Ă��Ȃ�
	*/
	bool Contains(const Vec3<T1>& sta, const Vec3<T1>& end, bool fullContain, bool intersectOnly) const
	{
		Vec3<T1> sp(center - sta); // �����n�_����~���S�ւ̃x�N�g��
		Vec3<T1> ep(center - end); // �����I�_����~���S�ւ̃x�N�g��
		bool isInner = (PYTHA(sp.x,sp.y) < POW2(radius))
					&& (PYTHA(ep.x,ep.y) < POW2(radius));
		// ���S����(�~�̓���)
		if(fullContain)
		{
			return isInner;
		}
		if(isInner)
		{
			return !intersectOnly;
		}
		Vec3<T1> nv((end - sta).Normalize2());	// �����̒P�ʃx�N�g��
		// �~���S��������ւ̐��� d=((n�Ep)n)-p
		Vec3<T1> dist((Vec3<T1>::Dot(nv,sp) * nv) - sp);
		if(PYTHA(dist.x,dist.y) > POW2(radius))
		{
			// ��������(�~�̊O��)
			return false;
		}
		else if((PYTHA(sp.x,sp.y) > POW2(radius) && PYTHA(ep.x,ep.y) > POW2(radius))
			&&	(((sp.x > 0.f)? 1.f : -1.f) == ((ep.x > 0.f)? 1.f : -1.f))
			&&	(((sp.y > 0.f)? 1.f : -1.f) == ((ep.y > 0.f)? 1.f : -1.f)))
		{
			// ��������(���S�_���܂����Ȃ�)
			return false;
		}
		return true;
	}


	
	/*
		@brief	�O�p�`�̌����A�����
		@param	[in]	tri				���肷��O�p�`
		@param	[in]	fullContain		���S����Ƃ��邩(�f�t�H���g�Ffalse)
		@return	�����A����Ă��邩
		@retval	true	���Ă���
		@retval	false	���Ă��Ȃ�
	*/
	bool Contains(const Triangle<T1>& tri, bool fullContain = false) const override
	{
		bool vertextes[3]={false,false,false};	// ���_�̓���
		// ���_����
		for(int i=0; i<3; ++i)
		{
			vertextes[i] = Contains(tri.points[i]);
			if(!fullContain && vertextes[i])
				return true;
		}
		if(fullContain)
			return vertextes[0] && vertextes[1] && vertextes[2];
		
		// �ӌ���
		for(int i = 0; i < 3; ++i)
		{
			int j = (i+1) % 3;
			if(Contains(tri.points[i], tri.points[j]))
				return true;
		}
		return false;
	}
	/*
		@brief	��`�̌����A�����
		@param	[in]	rect			���肷���`
		@param	[in]	fullContain		���S����Ƃ��邩(�f�t�H���g�Ffalse)
		@return	�����A����Ă��邩
		@retval	true	���Ă���
		@retval	false	���Ă��Ȃ�
	*/
	bool Contains(const Rect<T1>& rect, bool fullContain = false) const override
	{
		bool vertextes[4]={false,false,false,false};	// ���_�̓���
		Vec3<T1> rp[4] = {
			Vec3<T1>(rect.left,rect.top,0),
			Vec3<T1>(rect.right,rect.top,0),
			Vec3<T1>(rect.left,rect.bottom,0),
			Vec3<T1>(rect.right,rect.bottom,0)
		};
		// ���_����
		for(int i=0; i<4; ++i)
		{
			vertextes[i] = Contains(rp[i]);
			if(!fullContain && vertextes[i])
				return true;
		}
		if(fullContain)
			return vertextes[0] && vertextes[1] && vertextes[2] && vertextes[3];
		
		// �ӌ���
		for(int i = 0; i < 4; ++i)
		{
			int j = (i+1) % 4;
			if(Contains(rp[i], rp[j]))
				return true;
		}
		return false;
	}
#pragma endregion // Contains
	//================================================================================
	
	//================================================================================
#pragma region Intersection
	/*
		@brief	����Ă���_�����ԋ߂���_�̎擾
			if(Contains(p))
				point = IntersectionPoint2(p);
		@attention	�������Ă��邱�Ƃ��O��
		@param	[in]	point	����Ă���_
		@return	��_
	*/
	Vec3<T1> IntersectionPoint2(const Vec3<T1>& point) const override
	{
		// ����
		Vec3<T1> dist = point - center;
		// �_�ւ̃x�N�g���𐳋K�����ĉ~���S����r���a�{�̈ʒu�ɐL�΂�
		return  (center + (dist.Normalize2() * radius) );
	}

	/*
		@brief	�����Ƃ̌�_�̎擾
			if(Contains(line))
				points = IntersectionPoint2(line);
		@attention	�������Ă��邱�Ƃ��O��
		@param	[in]	line(sta,end)	��r����
		@return	�S��_
	*/
	std::vector<Vec3<T1>> IntersectionPoint2(const Line<T1>& line) const override
	{
		std::vector<Vec3<T1>> intersections; // ��_�i�[�p
		Vec3<T1> sp(center - line.sta); // �����n�_����~���S�ւ̃x�N�g��(start->pos)
		Vec3<T1> ep(center - line.end); // �����I�_����~���S�ւ̃x�N�g��(end->pos)
		Vec3<T1> nv((line.end - line.sta).Normalize2());	// �����̒P�ʃx�N�g��(normalize-vector)
		// �~���S��������ւ̐��� d=((n�Ep)*n)-p
		Vec3<T1> dist((Vec3<T1>::Dot(nv,sp) * nv) - sp);
		
		if(PYTHA(dist.x,dist.y) == POW2(radius))
		{
			intersections.push_back(dist + center);	// ��ړ_
		}
		else
		{
			float d_rad;	// �����̊p�x
			float i_rad;	// ���������_�̊p�x
			if(PYTHA(dist.x,dist.y) > 0.0f)
			{
				d_rad = atan2f(dist.y,dist.x);
				i_rad = acosf(dist.Length2() / radius);
			}
			else
			{
				// �������~���S��ʂ�ꍇ
				d_rad = atan2f(line.end.y,line.end.x);
				i_rad = PI/2.0f;
			}

			Vec3<T1> temp[] =
			{
				// �����Ɩ��������𒆐S�����T���ƍl�����Ƃ�,���ꂼ������̉E,���̌�_
				Vec3<T1>(	static_cast<T1>(static_cast<float>(radius) * std::cosf(d_rad + i_rad)),
							static_cast<T1>(static_cast<float>(radius) * std::sinf(d_rad + i_rad))),
				Vec3<T1>(	static_cast<T1>(static_cast<float>(radius) * std::cosf(d_rad - i_rad)),
							static_cast<T1>(static_cast<float>(radius) * std::sinf(d_rad - i_rad))),
			};

			if(PYTHA(sp.x,sp.y) >= POW2(radius) && PYTHA(ep.x,ep.y) >= POW2(radius))
			{
				for(const auto& t : temp)
				{
					intersections.push_back(t + center);	// ���_
				}
			}
			else
			{
				// ���_
				if(PYTHA(sp.x,sp.y) >= POW2(radius))
				{
					// �~�O�̍��W�����_�܂ł̋���
					Vec3<T1> a(temp[0] - sp);
					Vec3<T1> b(temp[1] - sp);
					intersections.push_back(((PYTHA(a.x,a.y) > PYTHA(b.x,b.y))? temp[0] : temp[1]) + center);
				}
				else
				{
					// �~�O�̍��W�����_�܂ł̋���
					Vec3<T1> a(temp[0] - ep);
					Vec3<T1> b(temp[1] - ep);
					intersections.push_back(((PYTHA(a.x,a.y) > PYTHA(b.x,b.y))? temp[0] : temp[1]) + center);
				}
			}
		}
		return intersections;
	}
	/*
		@brief	�����Ƃ̌�_�̎擾
			if(Contains(pos,next))
				points = IntersectionPoint2(pos,next);
		@attention	�������Ă��邱�Ƃ��O��
		@param	[in]	sta	��r�����̎n�_
		@param	[in]	end	��r�����̏I�_
		@return	�S��_
	*/
	std::vector<Vec3<T1>> IntersectionPoint2(const Vec3<T1>& sta, const Vec3<T1>& end) const override
	{
		std::vector<Vec3<T1>> intersections; // ��_�i�[�p
		Vec3<T1> sp(center - sta); // �����n�_����~���S�ւ̃x�N�g��(start->pos)
		Vec3<T1> ep(center - end); // �����I�_����~���S�ւ̃x�N�g��(end->pos)
		Vec3<T1> nv((end - sta).Normalize2());	// �����̒P�ʃx�N�g��(normalize-vector)
		// �~���S��������ւ̐��� d=((n�Ep)*n)-p
		Vec3<T1> dist((Vec3<T1>::Dot(nv,sp) * nv) - sp);
		
		if(PYTHA(dist.x,dist.y) == POW2(radius))
		{
			intersections.push_back(dist + center);	// ��ړ_
		}
		else
		{
			float d_rad;	// �����̊p�x
			float i_rad;	// ���������_�̊p�x
			if(PYTHA(dist.x,dist.y) > 0.0f)
			{
				d_rad = atan2f(dist.y,dist.x);
				i_rad = acosf(dist.Length2() / radius);
			}
			else
			{
				// �������~���S��ʂ�ꍇ
				d_rad = atan2f(end.y,end.x);
				i_rad = PI/2.0f;
			}

			Vec3<T1> temp[] =
			{
				// �����Ɩ��������𒆐S�����T���ƍl�����Ƃ�,���ꂼ������̉E,���̌�_
				Vec3<T1>(	static_cast<T1>(static_cast<float>(radius) * std::cosf(d_rad + i_rad)),
							static_cast<T1>(static_cast<float>(radius) * std::sinf(d_rad + i_rad))),
				Vec3<T1>(	static_cast<T1>(static_cast<float>(radius) * std::cosf(d_rad - i_rad)),
							static_cast<T1>(static_cast<float>(radius) * std::sinf(d_rad - i_rad))),
			};

			if(PYTHA(sp.x,sp.y) >= POW2(radius) && PYTHA(ep.x,ep.y) >= POW2(radius))
			{
				for(const auto& t : temp)
				{
					intersections.push_back(t + center);	// ���_
				}
			}
			else
			{
				// ���_
				if(PYTHA(sp.x,sp.y) >= POW2(radius))
				{
					// �~�O�̍��W�����_�܂ł̋���
					Vec3<T1> a(temp[0] - sp);
					Vec3<T1> b(temp[1] - sp);
					intersections.push_back(((PYTHA(a.x,a.y) > PYTHA(b.x,b.y))? temp[0] : temp[1]) + center);
				}
				else
				{
					// �~�O�̍��W�����_�܂ł̋���
					Vec3<T1> a(temp[0] - ep);
					Vec3<T1> b(temp[1] - ep);
					intersections.push_back(((PYTHA(a.x,a.y) > PYTHA(b.x,b.y))? temp[0] : temp[1]) + center);
				}
			}
		}
		return intersections;
	}


	/*
		@brief	�����Ƃ̌�_�̂����A�n�_�ɋ߂��_���擾
			if(Contains(line))
				point = IntersectionPoint2Nearest(line);
		@attention	�������Ă��邱�Ƃ��O��
		@param	[in]	line(sta,end)	��r����
		@return	�n�_�ɋ߂���_
	*/
	Vec3<T1> IntersectionPoint2Nearest(const Line<T1>& line) const override
	{
		std::vector<Vec3<T1>> intersections; // ��_�i�[�p
		Vec3<T1> sp(center - line.sta); // �����n�_����~���S�ւ̃x�N�g��(start->pos)
		Vec3<T1> ep(center - line.end); // �����I�_����~���S�ւ̃x�N�g��(end->pos)
		Vec3<T1> nv((line.end - line.sta).Normalize2());	// �����̒P�ʃx�N�g��(normalize-vector)
		// �~���S��������ւ̐��� d=((n�Ep)*n)-p
		Vec3<T1> dist((Vec3<T1>::Dot(nv,sp) * nv) - sp);
		
		if(PYTHA(dist.x,dist.y) == POW2(radius))
		{
			intersections.push_back(dist + center);	// ��ړ_
		}
		else
		{
			float d_rad;	// �����̊p�x
			float i_rad;	// ���������_�̊p�x
			if(PYTHA(dist.x,dist.y) > 0.0f)
			{
				d_rad = atan2f(dist.y,dist.x);
				i_rad = acosf(dist.Length2() / radius);
			}
			else
			{
				// �������~���S��ʂ�ꍇ
				d_rad = atan2f(line.end.y,line.end.x);
				i_rad = PI/2.0f;
			}

			Vec3<T1> temp[] =
			{
				// �����Ɩ��������𒆐S�����T���ƍl�����Ƃ�,���ꂼ������̉E,���̌�_
				Vec3<T1>(	static_cast<T1>(static_cast<float>(radius) * std::cosf(d_rad + i_rad)),
							static_cast<T1>(static_cast<float>(radius) * std::sinf(d_rad + i_rad))),
				Vec3<T1>(	static_cast<T1>(static_cast<float>(radius) * std::cosf(d_rad - i_rad)),
							static_cast<T1>(static_cast<float>(radius) * std::sinf(d_rad - i_rad))),
			};

			if(PYTHA(sp.x,sp.y) >= POW2(radius) && PYTHA(ep.x,ep.y) >= POW2(radius))
			{
				for(const auto& t : temp)
				{
					intersections.push_back(t + center);	// ���_
				}
			}
			else
			{
				// ���_
				if(PYTHA(sp.x,sp.y) >= POW2(radius))
				{
					// �~�O�̍��W�����_�܂ł̋���
					Vec3<T1> a(temp[0] - sp);
					Vec3<T1> b(temp[1] - sp);
					intersections.push_back(((PYTHA(a.x,a.y) > PYTHA(b.x,b.y))? temp[0] : temp[1]) + center);
				}
				else
				{
					// �~�O�̍��W�����_�܂ł̋���
					Vec3<T1> a(temp[0] - ep);
					Vec3<T1> b(temp[1] - ep);
					intersections.push_back(((PYTHA(a.x,a.y) > PYTHA(b.x,b.y))? temp[0] : temp[1]) + center);
				}
			}
		}
		// �n�_�Ɉ�ԋ߂���_�̎Z�o
		Vec3<T1> min = intersections[0];
		for(size_t i = 1; i < intersections.size(); ++i)
		{
			Vec3<T1> d1 = min - line.sta;
			Vec3<T1> d2 = intersections[i] - line.sta;
			if(PYTHA(d1.x, d1.y) > PYTHA(d2.x, d2.y))
				min = intersections[i];
		}
		return min;
	}
	/*
		@brief	�����Ƃ̌�_�̂����A�n�_�ɋ߂��_���擾
			if(Contains(pos,next))
				point = IntersectionPoint2Nearest(pos,next);
		@attention	�������Ă��邱�Ƃ��O��
		@param	[in]	sta	��r�����̎n�_
		@param	[in]	end	��r�����̏I�_
		@return	�n�_�ɋ߂���_
	*/
	Vec3<T1> IntersectionPoint2Nearest(const Vec3<T1>& sta, const Vec3<T1>& end) const override
	{
		std::vector<Vec3<T1>> intersections; // ��_�i�[�p
		Vec3<T1> sp(center - sta); // �����n�_����~���S�ւ̃x�N�g��(start->pos)
		Vec3<T1> ep(center - end); // �����I�_����~���S�ւ̃x�N�g��(end->pos)
		Vec3<T1> nv((end - sta).Normalize2());	// �����̒P�ʃx�N�g��(normalize-vector)
		// �~���S��������ւ̐��� d=((n�Ep)*n)-p
		Vec3<T1> dist((Vec3<T1>::Dot(nv,sp) * nv) - sp);
		
		if(PYTHA(dist.x,dist.y) == POW2(radius))
		{
			intersections.push_back(dist + center);	// ��ړ_
		}
		else
		{
			float d_rad;	// �����̊p�x
			float i_rad;	// ���������_�̊p�x
			if(PYTHA(dist.x,dist.y) > 0.0f)
			{
				d_rad = atan2f(dist.y,dist.x);
				i_rad = acosf(dist.Length2() / radius);
			}
			else
			{
				// �������~���S��ʂ�ꍇ
				d_rad = atan2f(end.y,end.x);
				i_rad = PI/2.0f;
			}

			Vec3<T1> temp[] =
			{
				// �����Ɩ��������𒆐S�����T���ƍl�����Ƃ�,���ꂼ������̉E,���̌�_
				Vec3<T1>(	static_cast<T1>(static_cast<float>(radius) * std::cosf(d_rad + i_rad)),
							static_cast<T1>(static_cast<float>(radius) * std::sinf(d_rad + i_rad))),
				Vec3<T1>(	static_cast<T1>(static_cast<float>(radius) * std::cosf(d_rad - i_rad)),
							static_cast<T1>(static_cast<float>(radius) * std::sinf(d_rad - i_rad))),
			};

			if(PYTHA(sp.x,sp.y) >= POW2(radius) && PYTHA(ep.x,ep.y) >= POW2(radius))
			{
				for(const auto& t : temp)
				{
					intersections.push_back(t + center);	// ���_
				}
			}
			else
			{
				// ���_
				if(PYTHA(sp.x,sp.y) >= POW2(radius))
				{
					// �~�O�̍��W�����_�܂ł̋���
					Vec3<T1> a(temp[0] - sp);
					Vec3<T1> b(temp[1] - sp);
					intersections.push_back(((PYTHA(a.x,a.y) > PYTHA(b.x,b.y))? temp[0] : temp[1]) + center);
				}
				else
				{
					// �~�O�̍��W�����_�܂ł̋���
					Vec3<T1> a(temp[0] - ep);
					Vec3<T1> b(temp[1] - ep);
					intersections.push_back(((PYTHA(a.x,a.y) > PYTHA(b.x,b.y))? temp[0] : temp[1]) + center);
				}
			}
		}
		// �n�_�Ɉ�ԋ߂���_�̎Z�o
		Vec3<T1> min = intersections[0];
		for(size_t i = 1; i < intersections.size(); ++i)
		{
			Vec3<T1> d1 = min - sta;
			Vec3<T1> d2 = intersections[i] - sta;
			if(PYTHA(d1.x, d1.y) > PYTHA(d2.x, d2.y))
				min = intersections[i];
		}
		return min;
	}
#pragma endregion // Intersection
	//================================================================================
	
#ifdef USE_CIRCLE_EXT
	void draw(D3DCOLOR color = 0xffffffff)
	{
		for(int i=0; i<360; ++i)
		{
			float rad = static_cast<float>(i)	* 2.0f * PI / 360.0f;
			float ra2 = static_cast<float>(i+1)	* 2.0f * PI / 360.0f;
			POINT sta = { LONG(std::cosf(rad) * radius + center.x), LONG(-std::sinf(rad) * radius + center.y) };
			POINT end = { LONG(std::cosf(ra2) * radius + center.x), LONG(-std::sinf(ra2) * radius + center.y) };
			Draw_Line(	(int)sta.x,
						(int)sta.y,
						(int)end.x,
						(int)end.y,
						0.f,
						color,1);
		}
	}

	static void draw(T1 center_x, T1 center_y, T1 center_z, T2 radius, D3DCOLOR color = 0xffffffff)
	{
		for(int i=0; i<360; ++i)
		{
			float rad = static_cast<float>(i)	* 2.0f * PI / 360.0f;
			float ra2 = static_cast<float>(i+1)	* 2.0f * PI / 360.0f;
			POINT sta = { LONG(std::cosf(rad) * radius + center_x), LONG(-std::sinf(rad) * radius + center_y) };
			POINT end = { LONG(std::cosf(ra2) * radius + center_x), LONG(-std::sinf(ra2) * radius + center_y) };
			Draw_Line(	(int)sta.x,
						(int)sta.y,
						(int)end.x,
						(int)end.y,
						center_z,
						color,1);
		}
	}
//#else
//	void draw(unsigned long color = 0xffffffff)
//	{
//	}
#endif

};
typedef Circle<int,int> Circlei;
typedef Circle<float,float> Circlef;
#pragma endregion // Circle


}
#endif
/*
template<class T>
strict Matrix
{
	T m[4][4];
};
template<class T>
struct Quaternion
{
	T w, x, y, z;

	Quaternion(){}
	Quaternion( float sx, float sy, float sz, float sw ) : x(sx), y(sy), z(sz), w(sw) {}

	//	�P�ʃN�H�[�^�j�I������
	void Identity(){ x = y = z = 0; w = 1; }
	
	
	//�N�H�[�^�j�I���̌v�Z
	Quaternion operator*(Quaternion qua);

	//��]�N�H�[�^�j�I��
	Quaternion CreateRotationQuaternion(double radian, Vector3f Axis);

	//�ʒu�N�H�[�^�j�I��
	Quaternion CreateXYZToQuaternion(double PosX, double PosY, double PosZ);

	//�N�H�[�^�j�I�������]�s���
	MATRIX QuaternionToMatrix();
};
*/
