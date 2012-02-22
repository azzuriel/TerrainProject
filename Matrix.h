#ifndef TERRAINPROJECT_MATRIX_H
#define TERRAINPROJECT_MATRIX_H

class mat4 {
public:
	float mat[4][4];
	
		mat4();
		~mat4();

	void Identity();
	void Set(mat4& m);
	void MultiplySelf(mat4& m);
	vec3 TransformPoint(vec3 in);
	void Rotate(float theta, float x, float y, float z);
};

#endif