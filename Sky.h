#ifndef TERRAINPROJECT_SKY_H
#define TERRAINPROJECT_SKY_H

#define SKY_GRID	21
#define SKY_HALF	(SKY_GRID / 2)

class sky_point {
public:
	rgba	color;
	vec3	position;
};

class CSky : public CEntity
{
private:
	sky_point	m_grid[SKY_GRID][SKY_GRID];
public:
			CSky();
	void	Render( void );
	void	Update( void );
};

#endif
