#ifndef TERRAINPROJECT_AABB_H
#define TERRAINPROJECT_AABB_H

class aabb {
	vec3 min;
	vec3 max;
public:
	void	Clear();
	void	ContainPoint(vec3 v);
	bool	TestVector(vec3 v);
};

#endif