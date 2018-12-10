#ifndef ZOMBIE_M_H
#define ZOMBIE_M_H

#include <Angel.h>
#include "human.h"

#define PARTS_ZOMBIE  13

#define ZOMBIE_W 2.0
#define ZOMBIE_H 2.0
#define ZOMBIE_D 2.0
#define ZOMBIE_R 0.1
#define ZOMBIE_G 0.3
#define ZOMBIE_B 0.1

GLfloat zombie_height[6] = { 0.0 };

vec3 zomb_parts_diff[PARTS_ZOMBIE] = {
  vec3(0.0, 1.15, 0.0),
  vec3(0.0, 0.75, 0.0),
  vec3(30.0, 0.75, -0.4),
  vec3(-30.0, 0.75, -0.4),
  vec3(0.0, 0.875, -0.4),
  vec3(30.0 * 0.99, -0.25 * 0.99, 0.0 * 0.99),
  vec3(90.0, -0.25, 0.25),
  vec3(-90.0, -0.25, 0.25),
  vec3(0.0 * 0.75, -0.025 * 0.75, -0.3 * 0.75),
  vec3(90.0, -0.375, 0.5),
  vec3(-90.0, -0.375, 0.5),
  vec3(90.0, -1.25, 0.25),
  vec3(-90.0, -1.25, 0.25)
};

vec3 zomb_parts_size[PARTS_ZOMBIE] = {
  vec3(HAIR_W, HAIR_H, HAIR_D),
  vec3(FACE_W, FACE_H, FACE_D),
  vec3(LENS_W, LENS_H, LENS_D),
  vec3(LENS_W, LENS_H, LENS_D),
  vec3(BRIDGE_W, BRIDGE_H, BRIDGE_D),
  vec3(SHIRT_W, SHIRT_H, SHIRT_D),
  vec3(SUIT_W, SUIT_H, SUIT_D),
  vec3(SUIT_W, SUIT_H, SUIT_D),
  vec3(TIE_W, TIE_H, TIE_D),
  vec3(APPENDAGE_W, APPENDAGE_H, APPENDAGE_D),
  vec3(APPENDAGE_W, APPENDAGE_H, APPENDAGE_D),
  vec3(APPENDAGE_W, APPENDAGE_H, APPENDAGE_D),
  vec3(APPENDAGE_W, APPENDAGE_H, APPENDAGE_D)
};

vec3 zomb_parts_colors[PARTS_ZOMBIE] = {
  vec3(AGENCY_R, AGENCY_G, AGENCY_B),
  vec3(ZOMBIE_R, ZOMBIE_G, ZOMBIE_B),
  vec3(AGENCY_R, AGENCY_G, AGENCY_B),
  vec3(AGENCY_R, AGENCY_G, AGENCY_B),
  vec3(AGENCY_R, AGENCY_G, AGENCY_B),
  vec3(SHIRT_R, SHIRT_G, SHIRT_B),
  vec3(AGENCY_R, AGENCY_G, AGENCY_B),
  vec3(AGENCY_R, AGENCY_G, AGENCY_B),
  vec3(AGENCY_R, AGENCY_G, AGENCY_B),
  vec3(AGENCY_R, AGENCY_G, AGENCY_B),
  vec3(AGENCY_R, AGENCY_G, AGENCY_B),
  vec3(AGENCY_R, AGENCY_G, AGENCY_B),
  vec3(AGENCY_R, AGENCY_G, AGENCY_B)
};

#endif
