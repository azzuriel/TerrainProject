#ifndef TERRAINPROJECT_WIN_H
#define TERRAINPROJECT_WIN_H

HWND	WinHwnd( void );
void	WinPopup( char* message, ... );
void	WinTerm( void );
bool	WinInit( void );
int		WinWidth( void );
int		WinHeight( void );
void	WinMousePosition( vec2& v );

#endif
