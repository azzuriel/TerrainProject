#ifndef TERRAINPROJECT_POINTER_H
#define TERRAINPROJECT_POINTER_H

class CPointer : public CEntity
{
private:
	vec3	m_position;
	vec2	m_last_mouse;
	vec2	m_last_cell;
	int		m_texture;
	float	m_pulse;
	
public:
			CPointer();
	
	void	RenderFade( void );
	void	Render( void );
	void	Update( void );
	vec2	Selected( void );
};

#endif
