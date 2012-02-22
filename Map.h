#ifndef TERRAINPROJECT_MAP_H
#define TERRAINPROJECT_MAP_H

//This defines how many zones the terrain is broken into
//There are lots of important tradeoffs going on here
//This affects the density of zones, zone textures, the time
//spent compiling terrain, and many other minor details.
#define ZONE_GRID         8
#define ZONES             (ZONE_GRID * ZONE_GRID)

enum {
	LAYER_GRASS,
	LAYER_LOWGRASS,
	LAYER_DIRT,
	LAYER_ROCK,
	LAYER_SAND,
	LAYER_COUNT,
	LAYER_LIGHTING,
	LAYER_SPECIAL,
};

rgba	MapLight( int x, int y );
float	MapDistance( int x, int y );
float	MapDot( int x, int y );
float	MapElevation( float x, float y );
float	MapLayer( int x, int y, int layer );
vec3	MapNormal( int x, int y );
vec3	MapPosition( int x, int y );
float	MapElevation( int x, int y );
void	MapInit( void );
void	MapTerm( void );
void	MapUpdate( void );
int		MapSize( void );

#endif
