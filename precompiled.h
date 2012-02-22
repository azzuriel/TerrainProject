#ifndef TERRAINPROJECT_PRECOMPILED_H
#define TERRAINPROJECT_PRECOMPILED_H

/*
====================
Standard Library headers
====================
*/

#include <cmath>
#include <cstdarg>
#include <cstdint> // for uint16_t and the likes
#include <cstdio>
#include <cstring>
#include <string>
#include <cfloat>
#include <cstdlib>
#include <windows.h>
#include <gl\gl.h>
#include <gl\glu.h>

/*
====================
Constants
====================
*/

const std::string APP_TITLE("TerrainProject");
const std::string APP("terrain");

/*
====================
Project headers
====================
*/
#include "math.h"
#include "vector.h"
#include "rgba.h"
#include "matrix.h"

#include "entity.h"
#include "win.h"
#include "world.h"
#include "ini.h"
#include "render.h"
#include "sky.h"
#include "terrain.h"
#include "texture.h"
#include "time.h"
#include "aabb.h"
#include "bmp.h"
#include "app.h"
#include "bmp.h"
#include "camera.h"
#include "console.h"
#include "glext.h"
#include "macro.h"
#include "map.h"
#include "maptexture.h"
#include "pointer.h"

#endif