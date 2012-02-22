#ifndef TERRAINPROJECT_CAMERA_H
#define TERRAINPROJECT_CAMERA_H

class vec3;

vec3	CameraAngle( void );
void	CameraAngleSet( vec3 new_angle );
float	CameraDistance( void );
void	CameraDistanceSet( float new_distance );
void	CameraInit( void );
vec3	CameraPosition( void );
void	CameraPositionSet( vec3 new_pos );
void	CameraUpdate( void );
void	CameraTerm( void );

void	CameraForward( float delta );
void	CameraSelectionPitch( float delta_y );
void	CameraSelectionYaw( float delta_x );
void	CameraSelectionZoom( float delta_y );
void	CameraPan( float delta_x );
void	CameraPitch( float delta_y );
void	CameraYaw( float delta_x );

#endif
