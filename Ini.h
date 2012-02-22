#ifndef TERRAINPROJECT_INI_H
#define TERRAINPROJECT_INI_H

int		IniInt( char* entry );
void	IniIntSet( char* entry, int val );
float	IniFloat( char* entry );
void	IniFloatSet( char* entry, float val );
char*	IniString( char* entry );
void	IniStringSet( char* entry, char* val );
void	IniVectorSet( char* entry, vec3& v );
vec3	IniVector( char* entry );

#endif
