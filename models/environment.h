#ifndef ENVIRONMENT_H
#define ENVIRONMENT_H

#include <Angel.h>

#define PARTS_FLOOR   1

#define PARTS_MOON    1

#define FLOOR_SIZE 100
#define NUM_TILES  50
#define TILE_SIZE  FLOOR_SIZE / NUM_TILES
#define WALL_HEIGHT 15

#define FLOOR_W TILE_SIZE
#define FLOOR_H 1.0
#define FLOOR_D TILE_SIZE
#define FLOOR_R 0.2
#define FLOOR_G 0.1
#define FLOOR_B 0.0

#define COLOR_FLOORS  4
//   vec3(0.6, 0.6, 0.6),

#define ROOF_W FLOOR_SIZE
#define ROOF_H 1.0
#define ROOF_D FLOOR_SIZE
#define ROOF_R 0.2
#define ROOF_G 0.1
#define ROOF_B 0.1

#endif
