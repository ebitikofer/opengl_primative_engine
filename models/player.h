#ifndef PLAYER_M_H
#define PLAYER_M_H

#include <Angel.h>
#include "human.h"

#define PARTS_PLAYER  13

#define PLAYER_W 2.0
#define PLAYER_H 5.0
#define PLAYER_D 2.0

vec3 character_bounds = { vec3(PLAYER_W, PLAYER_H, PLAYER_D) };

vec3 player_parts_diff[PARTS_PLAYER] = {
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

vec3 player_parts_size[PARTS_PLAYER] = {
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

vec3 player_parts_colors[PARTS_PLAYER] = {
  vec3(AGENCY_R, AGENCY_G, AGENCY_B),
  vec3(SKIN_R, SKIN_G, SKIN_B),
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
