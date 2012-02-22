/*-----------------------------------------------------------------------------

Sky.cpp

2006 Shamus Young

-------------------------------------------------------------------------------

Cheapo gradiant sky.  This is really lame. Seriously.

-----------------------------------------------------------------------------*/

#include "precompiled.h"

void CSky::Render()
{
	vec3	angle;
	vec3	top, bottom, left, right, front, back;
	rgba	horizon, sky;
	int		x, y;
	
	glDepthMask( false );
	glPushAttrib( GL_POLYGON_BIT | GL_LIGHTING_BIT | GL_FOG_BIT );
	glPolygonMode( GL_FRONT_AND_BACK, GL_FILL );
	glDisable( GL_LIGHTING );
	glDisable( GL_FOG );
	glDisable( GL_CULL_FACE );
	glDisable( GL_TEXTURE_2D );
	glPushMatrix();
	glLoadIdentity();
	angle = CameraAngle();
	glRotatef( angle.x, 1.0f, 0.0f, 0.0f );
	glRotatef( angle.y, 0.0f, 1.0f, 0.0f );
	glRotatef( angle.z, 0.0f, 0.0f, 1.0f );
	top = vec3( 0.0f, 0.8f, 0.0f );
	bottom = vec3( 0.0f, -3.0f, 0.0f );
	left = vec3( 10.0f, 0.0f, 0.0f );
	right = vec3( -10.0f, 0.0f, 0.0f );
	front = vec3( 0.0f, 0.0f, 10.0f );
	back = vec3( 0.0f, 0.0f, -10.0f );
	horizon = WorldFogColor();;
	sky = rgba( 0.6f, 0.7f, 0.9f );
	sky = WorldFogColor();
	glClearColor( sky.red, sky.green, sky.blue, 1.0f );
	glClear( GL_COLOR_BUFFER_BIT );
	for( y = 0; y < SKY_GRID - 1; y++ ) {
		glBegin( GL_QUAD_STRIP );
		for( x = 0; x < SKY_GRID; x++ ) {
			glColor3fv( &m_grid[x][y].color.red );
			glVertex3fv( &m_grid[x][y].position.x );
			glColor3fv( &m_grid[x][y + 1].color.red );
			glVertex3fv( &m_grid[x][y + 1].position.x );
		}
		glEnd();
	}
	
	
	
	glPopMatrix();
	glPopAttrib();
	glDepthMask( true );
	
}

/*-----------------------------------------------------------------------------

-----------------------------------------------------------------------------*/

void CSky::Update()
{

}

/*-----------------------------------------------------------------------------

-----------------------------------------------------------------------------*/

CSky::CSky()
{

	int		x, y;
	rgba	top( 0.0f, 0.0f, 1.0f);
	rgba	edge( 0.0f, 1.0f, 1.0f);
	rgba	fog;
	float	scale;
	float	dist;
	float	fade;
	
	fog = WorldFogColor();
	for( y = 0; y < SKY_GRID; y++ ) {
		for( x = 0; x < SKY_GRID; x++ ) {
			dist = MathDistance(( float )x, ( float )y, ( float )SKY_HALF, ( float )SKY_HALF );
			scale = CLAMP(( dist / SKY_HALF ), 0.0f, 1.0f );
			m_grid[x][y].position.x = ( float )( x - SKY_HALF );
			m_grid[x][y].position.y = 1.0f - scale * 1.5f;
			m_grid[x][y].position.z = ( float )( y - SKY_HALF );
			m_grid[x][y].color = top;
			fade = MathSmoothStep( scale, 0.0f, 0.6f );
			m_grid[x][y].color.Lerp( m_grid[x][y].color, edge, fade );
			fade = MathSmoothStep( scale, 0.5f, 0.99f );
			m_grid[x][y].color.Lerp( m_grid[x][y].color, fog, fade );
		}
	}
	
	
}
