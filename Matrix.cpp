#include "precompiled.h"

mat4::mat4()
{
	Identity();
}

mat4::~mat4()
{

}

void mat4::Identity()
{
	mat[0][0] = 1; mat[0][1] = 0; mat[0][2] = 0; mat[0][3] = 0;
	mat[1][0] = 0; mat[1][1] = 1; mat[1][2] = 0; mat[1][3] = 0;
	mat[2][0] = 0; mat[2][1] = 0; mat[2][2] = 1; mat[2][3] = 0;
	mat[3][0] = 0; mat[3][1] = 0; mat[3][2] = 0; mat[3][3] = 1;
}

void mat4::Set(mat4& m)
{
	mat[0][0] = m.mat[0][0];
	mat[0][1] = m.mat[0][1];
	mat[0][2] = m.mat[0][2];
	mat[0][3] = m.mat[0][3];

	mat[1][0] = m.mat[1][0];
	mat[1][1] = m.mat[1][1];
	mat[1][2] = m.mat[1][2];
	mat[1][3] = m.mat[1][3];

	mat[2][0] = m.mat[2][0];
	mat[2][1] = m.mat[2][1];
	mat[2][2] = m.mat[2][2];
	mat[2][3] = m.mat[2][3];

	mat[3][0] = m.mat[3][0];
	mat[3][1] = m.mat[3][1];
	mat[3][2] = m.mat[3][2];
	mat[3][3] = m.mat[3][3];
}

#define M(e,x,y)                (e.mat[x][y])

void mat4::MultiplySelf(mat4& m)
{

	this->mat[0][0] = this->mat[0][0] * m.mat[0][0] + this->mat[1][0] * m.mat[0][1] + this->mat[2][0] * m.mat[0][2];
	this->mat[1][0] = this->mat[0][0] * m.mat[1][0] + this->mat[1][0] * m.mat[1][1] + this->mat[2][0] * m.mat[1][2];
	this->mat[2][0] = this->mat[0][0] * m.mat[2][0] + this->mat[1][0] * m.mat[2][1] + this->mat[2][0] * m.mat[2][2];
	this->mat[3][0] = this->mat[0][0] * m.mat[3][0] + this->mat[1][0] * m.mat[3][1] + this->mat[2][0] * m.mat[3][2] + mat[3][0];

	this->mat[0][1] = this->mat[0][1] * m.mat[0][0] + this->mat[1][1] * m.mat[0][1] + this->mat[2][1] * m.mat[0][2];
	this->mat[1][1] = this->mat[0][1] * m.mat[1][0] + this->mat[1][1] * m.mat[1][1] + this->mat[2][1] * m.mat[1][2];
	this->mat[2][1] = this->mat[0][1] * m.mat[2][0] + this->mat[1][1] * m.mat[2][1] + this->mat[2][1] * m.mat[2][2];
	this->mat[3][1] = this->mat[0][1] * m.mat[3][0] + this->mat[1][1] * m.mat[3][1] + this->mat[2][1] * m.mat[3][2] + mat[3][1];

	this->mat[0][2] = this->mat[0][2] * m.mat[0][0] + this->mat[1][2] * m.mat[0][1] + this->mat[2][2] * m.mat[0][2];
	this->mat[1][2] = this->mat[0][2] * m.mat[1][0] + this->mat[1][2] * m.mat[1][1] + this->mat[2][2] * m.mat[1][2];
	this->mat[2][2] = this->mat[0][2] * m.mat[2][0] + this->mat[1][2] * m.mat[2][1] + this->mat[2][2] * m.mat[2][2];
	this->mat[3][2] = this->mat[0][2] * m.mat[3][0] + this->mat[1][2] * m.mat[3][1] + this->mat[2][2] * m.mat[3][2] + mat[3][2];
}

vec3 mat4::TransformPoint(vec3 in)
{
	vec3 out;

	out.x = mat[0][0] * in.x + mat[1][0] * in.y + mat[2][0] * in.z + mat[3][0];
	out.y = mat[0][1] * in.x + mat[1][1] * in.y + mat[2][1] * in.z + mat[3][1];
	out.z = mat[0][2] * in.x + mat[1][2] * in.y + mat[2][2] * in.z + mat[3][2];

	return out;
}

void mat4::Rotate(float theta, float x, float y, float z)
{

}