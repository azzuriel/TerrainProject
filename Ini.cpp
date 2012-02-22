/*-----------------------------------------------------------------------------

Ini.cpp

2006 Shamus Young


-------------------------------------------------------------------------------

This takes various types of data and dumps them into a predefined ini file.

-----------------------------------------------------------------------------*/
#include "precompiled.h"

const std::string	FORMAT_VECTOR("%f %f %f");
const int			MAX_RESULT(256);
const std::string	FORMAT_FLOAT("%1.2f");
const std::string	INI_FILE(".\\" + APP + ".ini");
const std::string	SECTION("Settings");

static char                 result[MAX_RESULT];

int IniInt( char* entry )
{
	return GetPrivateProfileInt( SECTION.c_str(), entry, -1, INI_FILE.c_str() );
}

void IniIntSet( char* entry, int val )
{
	char	buf[20];
	
	sprintf_s( buf, "%d", val );
	WritePrivateProfileString( SECTION.c_str(), entry, buf, INI_FILE.c_str() );
}

float IniFloat( char* entry )
{
	float	f;
	
	GetPrivateProfileString( SECTION.c_str(), entry, "", result, MAX_RESULT, INI_FILE.c_str() );
	f = ( float )atof( result );

	return f;
}

void IniFloatSet( char* entry, float val )
{
	char	buf[20];
	
	sprintf_s( buf, FORMAT_FLOAT.c_str(), val );
	WritePrivateProfileString( SECTION.c_str(), entry, buf, INI_FILE.c_str() );
}

char* IniString( char* entry )
{
	GetPrivateProfileString( SECTION.c_str(), entry, "", result, MAX_RESULT, INI_FILE.c_str() );

	return result;
}

void IniStringSet( char* entry, char* val )
{
	WritePrivateProfileString( SECTION.c_str(), entry, val, INI_FILE.c_str() );
}

void IniVectorSet( char* entry, vec3& v )
{
	sprintf_s( result, FORMAT_VECTOR.c_str(), v.x, v.y, v.z );
	WritePrivateProfileString( SECTION.c_str(), entry, result, INI_FILE.c_str() );
}

vec3 IniVector( char* entry )
{
	vec3	v;
	
	GetPrivateProfileString( SECTION.c_str(), entry, "0 0 0", result, MAX_RESULT, INI_FILE.c_str() );
	sscanf_s( result, FORMAT_VECTOR.c_str(), &v.x, &v.y, &v.z );

	return v;
}
