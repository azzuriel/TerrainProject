#include "precompiled.h"

vec2 vec2_origin( 0.0f, 0.0f );
vec3 vec3_origin( 0.0f, 0.0f, 0.0f );

/*
====================
Lerp

Linearly interpolates one vector to another.
l has a range of 0.0f to 1.0f
====================
*/
void vec2::Lerp( const vec2& v, const vec2& w, const float scalar )
{
	if( scalar <= 0.0f )
		( *this ) = v;
	else if( scalar >= 1.0f )
		( *this ) = w;
	else
		( *this ) = v + scalar * ( w - v );
}

/*
====================
Lerp

Linearly interpolates one vector to another.
scalar has a range of 0.0f to 1.0f
====================
*/
void vec3::Lerp( const vec3& v, const vec3& w, const float scalar )
{
	if( scalar <= 0.0f )
		( *this ) = v;
	else if( scalar >= 1.0f )
		( *this ) = w;
	else
		( *this ) = v + scalar * ( w - v );
}

/*
====================
Slerp

Spherical linear interpolation from v to w.
Vectors are expected to be normalized.
l has a range of 0.0f to 1.0f
====================
*/
#define LERP_DELTA 1e-6

void vec3::SLerp( const vec3& v, const vec3& w, const float t )
{
	float omega, cosom, sinom, scale0, scale1;

	if( t <= 0.0f )
	{
		( *this ) = v;
		return;
	}
	else if( t >= 1.0f )
	{
		( *this ) = w;
		return;
	}

	cosom = Dot( v, w );

	if(( 1.0f - cosom ) > LERP_DELTA )
	{
		omega = acos( cosom );
		sinom = sin( omega );
		scale0 = sin(( 1.0f - t ) * omega ) / sinom;
		scale1 = sin( t * omega ) / sinom;
	}
	else
	{
		scale0 = 1.0f - t;
		scale1 = t;
	}

	( *this ) = ( v * scale0 + w * scale1 );
}
