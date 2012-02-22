#include "precompiled.h"

const float MAX_VALUE = 999999999999999.9f;

/*
====================
Clear

Invalidates the aabb
====================
*/
void aabb::Clear()
{
	max = vec3( -MAX_VALUE, -MAX_VALUE, -MAX_VALUE );
	min = vec3( MAX_VALUE,  MAX_VALUE,  MAX_VALUE );
}

/*
====================
ContainPoint

Expand Bbox (if needed) to contain given point
====================
*/
void aabb::ContainPoint(vec3 v)
{
	min.x = MIN( min.x, v.x );
	min.y = MIN( min.y, v.y );
	min.z = MIN( min.z, v.z );
	max.x = MAX( max.x, v.x );
	max.y = MAX( max.y, v.y );
	max.z = MAX( max.z, v.z );
}

/*
====================
TestVector

return true of v is inside this aabb
====================
*/
bool aabb::TestVector(vec3 v)
{
	if( v.x > max.x || v.x < min.x )
		return false;
	if( v.y > max.y || v.y < min.y )
		return false;
	if( v.z > max.z || v.z < min.z )
		return false;
	return true;
}
