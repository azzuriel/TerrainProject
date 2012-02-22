#ifndef TERRAINPROJECT_MATH_H
#define TERRAINPROJECT_MATH_H

namespace math {
	float InvSqrt( float n );
};

float MathAngle( float x1, float y1, float x2, float y2 );
float MathAngleDifference( float a1, float a2 );
float MathAverage( float n1, float n2 );
float MathInterpolate( float n1, float n2, float delta );
float MathLine_distance( float x1, float y1, float x2, float y2, float px, float py );
float MathDistance( float x1, float y1, float x2, float y2 );
float MathDistance2( float x1, float y1, float x2, float y2 );
float MathSmoothStep( float val, float a, float b );

#endif
