#ifndef TERRAINPROJECT_MACRO_H
#define TERRAINPROJECT_MACRO_H

#define DEGREES_TO_RADIANS      .017453292f
#define RADIANS_TO_DEGREES      57.29577951f
#define PI                      ((double)3.1415926535f)
#define PI2                     PI*PI
#define GRAVITY                 9.5f

#define CLAMP(a,b,c)            (a < b ? b : (a > c ? c : a))
#define WRAP(x,y)               ((unsigned)x % y)
#define SIGN(x)                 ((x) > 0 ? 1 : (x) < 0 ? -1 : 0)
#define ABS(x)                  (((x) < 0 ? (-x) : (x)))
#define SMALLEST(x,y)           (ABS(x) < ABS(y) ? 0 : x)                
#define MIN(x,y)                ((x) < (y) ? x : y)                
#define MAX(x,y)                ((x) > (y) ? x : y)                

#define POW(x,y)                (float)pow(x,y)
#define SWAP(a,b)               {int temp = a;a = b; b = temp;}

#endif
