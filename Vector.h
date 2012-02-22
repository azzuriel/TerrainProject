#ifndef VECTOR_H
#define VECTOR_H

class vec2;
class vec3;
class vec4;

#define VECTOR_EPSILON		0.001f

extern vec2 vec2_origin;
#define vec2_zero vec2_origin

extern vec3 vec3_origin;
#define vec3_zero vec3_origin

extern vec4 vec4_origin;
#define vec4_zero vec4_origin

class vec2
{
public:
	float x, y;

	vec2();	// Creates zero vector
	explicit vec2( const float a, const float b );

	vec2&	operator=( const vec2& v );
	vec2	operator-() const;

	vec2	operator+( const vec2& v ) const;
	vec2	operator-( const vec2& v ) const;
	vec2	operator*( const float f ) const;
	vec2	operator/( const float f ) const;

	vec2&	operator+=( const vec2& v );
	vec2&	operator-=( const vec2& v );
	vec2&	operator*=( const float f );
	vec2&	operator/=( const float f );

	bool	operator==( const vec2& v ) const;
	bool	operator!=( const vec2& v ) const;

	friend	vec2 operator*( const float f, const vec2 v );

	void	Set( const float x, const float y );
	void	Zero( void );

	float	Length( void ) const;
	float	LengthSqr( void ) const;
	float	Normalize( void );	// Returns length
	vec2&	Truncate( float length );

	void	Lerp( const vec2& v, const vec2& w, const float l );
};

// Creates zero vector
inline vec2::vec2():x( 0.0f ), y( 0.0f )
{}

inline vec2::vec2( const float a, const float b ):x( a ), y( b )
{}

inline vec2& vec2::operator=( const vec2& v )
{
	x = v.x;
	y = v.y;

	return *this;
}

inline vec2 vec2::operator-() const
{
	return vec2( -x, -y );
}

inline vec2 vec2::operator+( const vec2& v ) const
{
	return vec2(
		this->x + v.x,
		this->y + v.y );
}

inline vec2 vec2::operator-( const vec2& v ) const
{
	return vec2(
		x - v.x,
		y - v.y );
}

inline vec2 vec2::operator*( const float f ) const
{
	return vec2(
		x * f,
		y * f );
}

inline vec2 vec2::operator/( const float f ) const
{
	float invf = 1.0f / f;

	return vec2(
		x * invf,
		y * invf );
}

inline vec2& vec2::operator+=( const vec2& v )
{
	x += v.x;
	y += v.y;

	return *this;
}

inline vec2& vec2::operator-=( const vec2& v )
{
	x -= v.x;
	y -= v.y;

	return *this;
}

inline vec2& vec2::operator*=( const float f )
{
	x *= f;
	y *= f;

	return *this;
}

inline vec2& vec2::operator/=( const float f )
{
	float invf = 1.0f / f;

	x *= invf;
	y *= invf;

	return *this;
}

inline bool vec2::operator==( const vec2& v ) const
{
	if( x == v.x && y == v.y )
		return true;
	else
		return false;
}

inline bool vec2::operator!=( const vec2& v ) const
{
	if( x != v.x && y != v.y )
		return true;
	else
		return false;
}

// friend operator overload
inline vec2 operator*( const float f, const vec2 v )
{
	return vec2(
		f * v.x,
		f * v.y );
}

inline void vec2::Set( const float x, const float y )
{
	this->x = x;
	this->y = y;
}

inline void vec2::Zero( void )
{
	x = y = 0.0f;
}

inline float vec2::Length( void ) const
{
	return sqrt( x * x + y * y );
}

inline float vec2::LengthSqr( void ) const
{
	return x * x + y * y;
}

// 17:42 2011-12-07: Check if this practically works as it should.
inline float vec2::Normalize( void )
{
	float	lengthsqr;	// length squared
	float	lengthinv;	// inverse length

	lengthsqr = LengthSqr();
	lengthinv = math::InvSqrt( lengthsqr );

	x *= lengthinv;
	y *= lengthinv;

	return lengthinv * lengthsqr;
}

// 17:42 2011-12-07: Check if this practically works as it should.
inline vec2& vec2::Truncate( float length )
{
	float	lengthsqr;	// length squared
	float	lengthinv;	// inverse length (

	if( length == 0.0f )
	{
		Zero();
	}
	else
	{
		lengthsqr = LengthSqr();

		if( lengthsqr > ( length * length ) )
		{
			lengthinv = length * math::InvSqrt( lengthsqr );

			x *= lengthinv;
			y *= lengthinv;
		}
	}

	return *this;
}

// Dot product; returns the cosine of the vngle wetween the two vectors
inline float Dot( const vec2& v, const vec2& w )
{
	return ( v.x * w.x + v.y * w.y );
}

/*
====================
vec3
====================
*/
class vec3
{
public:
	float x, y, z;

	vec3();	// Creates zero vector
	explicit vec3( const float a, const float b, const float c );

	vec3&	operator=( const vec3& v );
	vec3	operator-() const;

	vec3	operator+( const vec3& v ) const;
	vec3	operator-( const vec3& v ) const;
	vec3	operator*( const float f ) const;
	vec3	operator/( const float f ) const;

	vec3&	operator+=( const vec3& v );
	vec3&	operator-=( const vec3& v );
	vec3&	operator*=( const float f );
	vec3&	operator/=( const float f );

	bool	operator==( const vec3& v ) const;
	bool	operator!=( const vec3& v ) const;

	friend vec3 operator*( const float f, const vec3 v );

	void	Set( const float x, const float y, const float z );
	void	Zero( void );

	float	Length( void ) const;
	float	LengthSqr( void ) const;
	float	Normalize( void );	// Returns length
	vec3&	Truncate( float length );

	void	Lerp( const vec3& v, const vec3& w, const float l );
	void	SLerp( const vec3& v, const vec3& w, const float l );
};

// Creates zero vector
inline vec3::vec3(): x( 0.0f ), y( 0.0f ), z( 0.0f )
{}

inline vec3::vec3( const float a, const float b, const float c ): x( a ), y( b ), z( c )
{}

inline vec3& vec3::operator=( const vec3& v )
{
	x = v.x;
	y = v.y;
	z = v.z;

	return *this;
}

inline vec3 vec3::operator-() const
{
	return vec3( -x, -y, -z );
}

inline vec3 vec3::operator+( const vec3& v ) const
{
	return vec3(
		this->x + v.x,
		this->y + v.y,
		this->z + v.z );
}

inline vec3 vec3::operator-( const vec3& v ) const
{
	return vec3(
		x - v.x,
		y - v.y,
		z - v.z );
}

inline vec3 vec3::operator*( const float f ) const
{
	return vec3(
		x * f,
		y * f,
		z * f );
}

inline vec3 vec3::operator/( const float f ) const
{
	float invf = 1.0f / f;

	return vec3(
		x * invf,
		y * invf,
		z * invf );
}

inline vec3& vec3::operator+=( const vec3& v )
{
	x += v.x;
	y += v.y;
	z += v.z;

	return *this;
}

inline vec3& vec3::operator-=( const vec3& v )
{
	x -= v.x;
	y -= v.y;
	z -= v.z;

	return *this;
}

inline vec3& vec3::operator*=( const float f )
{
	x *= f;
	y *= f;
	z *= f;

	return *this;
}

inline vec3& vec3::operator/=( const float f )
{
	float invf = 1.0f / f;

	x *= invf;
	y *= invf;
	z *= invf;

	return *this;
}

// maybe insert an epsilon somewhere here?
inline bool vec3::operator==( const vec3& v ) const
{
	if( abs(x - v.x) < VECTOR_EPSILON &&
		abs(y - v.y) < VECTOR_EPSILON &&
		abs(z - v.z) < VECTOR_EPSILON )
		return true;
	else
		return false;
}

inline bool vec3::operator!=( const vec3& v ) const
{
	if( abs(x - v.x) > VECTOR_EPSILON &&
		abs(y - v.y) > VECTOR_EPSILON &&
		abs(z - v.z) > VECTOR_EPSILON )
		return true;
	else
		return false;
}

// friend operator overload
inline vec3 operator*( const float f, const vec3 v )
{
	return vec3(
		f * v.x,
		f * v.y,
		f * v.z );
}

inline void vec3::Set( const float x, const float y, const float z )
{
	this->x = x;
	this->y = y;
	this->z = z;
}

inline void vec3::Zero( void )
{
	x = y = z = 0.0f;
}

inline float vec3::Length( void ) const
{
	return sqrt( x * x + y * y + z * z );
}

inline float vec3::LengthSqr( void ) const
{
	return x * x + y * y + z * z;
}

// 17:42 2011-12-07: Check if this practically works as it should.
inline float vec3::Normalize( void )
{
	float	lengthsqr;	// length squared
	float	lengthinv;	// inverse length

	lengthsqr = LengthSqr();
	lengthinv = math::InvSqrt( lengthsqr );

	x *= lengthinv;
	y *= lengthinv;
	z *= lengthinv;

	return lengthinv * lengthsqr;
}

// 17:42 2011-12-07: Check if this practically works as it should.
inline vec3& vec3::Truncate( float length )
{
	float	lengthsqr;	// length squared
	float	lengthinv;	// inverse length (

	if( length == 0.0f )
	{
		Zero();
	}
	else
	{
		lengthsqr = LengthSqr();

		if( lengthsqr > ( length * length ) )
		{
			lengthinv = length * math::InvSqrt( lengthsqr );

			x *= lengthinv;
			y *= lengthinv;
			z *= lengthinv;
		}
	}

	return *this;
}

// Dot product; returns the cosine of the vngle wetween the two vectors
inline float Dot( const vec3& v, const vec3& w )
{
	return ( v.x * w.x + v.y * w.y + v.z * w.z );
}

// Cross product: returns v vector; perpendiculvr to the 2 input vectors
inline vec3 Cross( const vec3& v, const vec3& w )
{
	return vec3(
		v.y * w.z - w.z * v.y,
		v.z * w.x - w.x * v.z,
		v.x * w.y - w.y * v.z );
}

inline vec3 Reflect( vec3 ray, vec3 normal )
{
	float dot = Dot( ray, normal );
	return (ray - ( normal * ( 2.0f * dot ) ) );
}


/*
====================
vec4
====================
*/
class vec4
{
public:
	float x, y, z, w;

	vec4();	// Creates zero vector
	explicit vec4( const float a, const float b, const float c, const float d );

	vec4&	operator=( const vec4& v );
	vec4	operator-() const;

	vec4	operator+( const vec4& v ) const;
	vec4	operator-( const vec4& v ) const;
	vec4	operator*( const float f ) const;
	vec4	operator/( const float f ) const;

	vec4&	operator+=( const vec4& v );
	vec4&	operator-=( const vec4& v );
	vec4&	operator*=( const float f );
	vec4&	operator/=( const float f );

	bool	operator==( const vec4& v ) const;
	bool	operator!=( const vec4& v ) const;

	friend vec4 operator*( const float f, const vec4 v );

	void	Set( const float x, const float y, const float z, const float w );
	void	Zero( void );

	float	Length( void ) const;
	float	LengthSqr( void ) const;
	float	Normalize( void );	// Returns length
	vec4&	Truncate( float length );

	void	Lerp( const vec4& v, const vec4& w, const float l );
	void	SLerp( const vec4& v, const vec4& w, const float l );
};

// Creates zero vector
inline vec4::vec4(): x( 0.0f ), y( 0.0f ), z( 0.0f ), w( 0.0f )
{}

inline vec4::vec4( const float a, const float b, const float c, const float d): x( a ), y( b ), z( c ), w( d )
{}

inline vec4& vec4::operator=( const vec4& v )
{
	x = v.x;
	y = v.y;
	z = v.z;
	w = v.w;

	return *this;
}

inline vec4 vec4::operator-() const
{
	return vec4( -x, -y, -z, -w);
}

inline vec4 vec4::operator+( const vec4& v ) const
{
	return vec4(
		this->x + v.x,
		this->y + v.y,
		this->z + v.z,
		this->w + v.w );
}

inline vec4 vec4::operator-( const vec4& v ) const
{
	return vec4(
		x - v.x,
		y - v.y,
		z - v.z,
		w - v.w);
}

inline vec4 vec4::operator*( const float f ) const
{
	return vec4(
		x * f,
		y * f,
		z * f,
		w * f );
}

inline vec4 vec4::operator/( const float f ) const
{
	float invf = 1.0f / f;

	return vec4(
		x * invf,
		y * invf,
		z * invf,
		w * invf );
}

inline vec4& vec4::operator+=( const vec4& v )
{
	x += v.x;
	y += v.y;
	z += v.z;
	w += v.w;

	return *this;
}

inline vec4& vec4::operator-=( const vec4& v )
{
	x -= v.x;
	y -= v.y;
	z -= v.z;
	w -= v.w;

	return *this;
}

inline vec4& vec4::operator*=( const float f )
{
	x *= f;
	y *= f;
	z *= f;
	w *= f;

	return *this;
}

inline vec4& vec4::operator/=( const float f )
{
	float invf = 1.0f / f;

	x *= invf;
	y *= invf;
	z *= invf;
	w *= invf;

	return *this;
}

// maybe insert an epsilon somewhere here?
inline bool vec4::operator==( const vec4& v ) const
{
	if( abs(x - v.x) < VECTOR_EPSILON &&
		abs(y - v.y) < VECTOR_EPSILON &&
		abs(z - v.z) < VECTOR_EPSILON &&
		abs(w - v.w) < VECTOR_EPSILON )
		return true;
	else
		return false;
}

inline bool vec4::operator!=( const vec4& v ) const
{
	if( abs(x - v.x) > VECTOR_EPSILON &&
		abs(y - v.y) > VECTOR_EPSILON &&
		abs(z - v.z) > VECTOR_EPSILON &&
		abs(w - v.w) > VECTOR_EPSILON )
		return true;
	else
		return false;
}

// friend operator overload
inline vec4 operator*( const float f, const vec4 v )
{
	return vec4(
		f * v.x,
		f * v.y,
		f * v.z,
		f * v.w );
}

inline void vec4::Set( const float x, const float y, const float z, const float w )
{
	this->x = x;
	this->y = y;
	this->z = z;
	this->w = w;
}

inline void vec4::Zero( void )
{
	x = y = z = w = 0.0f;
}

inline float vec4::Length( void ) const
{
	return sqrt( x * x + y * y + z * z + w * w );
}

inline float vec4::LengthSqr( void ) const
{
	return x * x + y * y + z * z + w * w;
}

// 17:42 2011-12-07: Check if this practically works as it should.
inline float vec4::Normalize( void )
{
	float	lengthsqr;	// length squared
	float	lengthinv;	// inverse length

	lengthsqr = LengthSqr();
	lengthinv = math::InvSqrt( lengthsqr );

	x *= lengthinv;
	y *= lengthinv;
	z *= lengthinv;
	w *= lengthinv;

	return lengthinv * lengthsqr;
}

// 17:42 2011-12-07: Check if this practically works as it should.
inline vec4& vec4::Truncate( float length )
{
	float	lengthsqr;	// length squared
	float	lengthinv;	// inverse length (

	if( length == 0.0f )
	{
		Zero();
	}
	else
	{
		lengthsqr = LengthSqr();

		if( lengthsqr > ( length * length ) )
		{
			lengthinv = length * math::InvSqrt( lengthsqr );

			x *= lengthinv;
			y *= lengthinv;
			z *= lengthinv;
			w *= lengthinv;
		}
	}

	return *this;
}

#endif
