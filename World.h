#ifndef TERRAIN_PROJECT_H
#define TERRAIN_PROJECT_H

rgba	WorldAmbientColor( void );
float	WorldFade( void );
rgba	WorldFogColor( void );
vec3	WorldLightVector( void );
vec4	WorldLightQuat( void );
rgba	WorldLightColor( void );
void	WorldInit( void );
void	WorldTerm( void );
void	WorldUpdate( void );

#endif
