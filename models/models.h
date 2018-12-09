#ifndef MODELS_H
#define MODELS_H

#include <Angel.h>
#include "engine.h"

#define FLOOR_SIZE 100
#define NUM_TILES  50
#define TILE_SIZE  FLOOR_SIZE / NUM_TILES
#define WALL_HEIGHT 15

#define PLAYER_W 2.0
#define PLAYER_H 5.0
#define PLAYER_D 2.0

#define FLOOR_W TILE_SIZE
#define FLOOR_H 1.0
#define FLOOR_D TILE_SIZE
#define FLOOR_R 0.2
#define FLOOR_G 0.1
#define FLOOR_B 0.0

#define COLOR_FLOORS  4
//   vec3(0.6, 0.6, 0.6),

#define LON_WALL_W 0.5
#define LON_WALL_H WALL_HEIGHT
#define LON_WALL_D TILE_SIZE
#define LON_WALL_R 0.7
#define LON_WALL_G 0.6
#define LON_WALL_B 0.5

#define LAT_WALL_W TILE_SIZE
#define LAT_WALL_H WALL_HEIGHT
#define LAT_WALL_D 0.5
#define LAT_WALL_R 0.7
#define LAT_WALL_G 0.6
#define LAT_WALL_B 0.5

#define ROOF_W FLOOR_SIZE
#define ROOF_H 1.0
#define ROOF_D FLOOR_SIZE
#define ROOF_R 0.2
#define ROOF_G 0.1
#define ROOF_B 0.1

#define DOOR_W 5.0
#define DOOR_H 10.0
#define DOOR_D 0.5
#define DOOR_R 0.25
#define DOOR_G 0.15
#define DOOR_B 0.05

#define BULB_W 0.5
#define BULB_H 0.5
#define BULB_D 0.25
#define SHAFT_W 0.25
#define SHAFT_H 0.25
#define SHAFT_D 0.25
#define DOORKNOB_R 0.9
#define DOORKNOB_G 0.7
#define DOORKNOB_B 0.0

#define MOON_W 10.0
#define MOON_H 10.0
#define MOON_D 10.0
#define MOON_R 0.9
#define MOON_G 0.9
#define MOON_B 1.0

#define TOP_W 2.5
#define TOP_H 0.1
#define TOP_D 5.0
#define LEG_W 0.1
#define LEG_H 2.0
#define LEG_D 0.1
#define TABLE_R 0.5
#define TABLE_G 0.3
#define TABLE_B 0.1

#define BODYL_W 4.0
#define BODYL_H 4.0
#define BODYL_D 4.0
#define BODYS_W 3.5
#define BODYS_H 3.5
#define BODYS_D 3.5
#define HOSEL_W 1.0
#define HOSEL_H 6.0
#define HOSEL_D 1.0
#define HOSEM_W 1.0
#define HOSEM_H 2.0
#define HOSEM_D 1.0
#define HOSES_W 1.0
#define HOSES_H 2.0
#define HOSES_D 1.0
#define NOZZLE_W 3.0
#define NOZZLE_H 0.5
#define NOZZLE_D 1.5
#define HOSE_R 0.8
#define HOSE_G 0.8
#define HOSE_B 0.8
#define STRAP_W 1.0
#define STRAP_H 7.0
#define STRAP_D 1.0
#define STRAP_R 0.7
#define STRAP_G 0.5
#define STRAP_B 0.1
#define WHEEL_W 2.0
#define WHEEL_H 2.0
#define WHEEL_D 1.0
#define WHEEL_R 0.8
#define WHEEL_G 0.8
#define WHEEL_B 0.8
#define LIGHT_W 1.0
#define LIGHT_H 1.0
#define LIGHT_D 1.0
#define LIGHT_R 0.4
#define LIGHT_G 0.8
#define LIGHT_B 0.1
#define VACCUUM_R 0.8
#define VACCUUM_G 0.1
#define VACCUUM_B 0.1

#define GHOST_W 2.0
#define GHOST_H 2.0
#define GHOST_D 2.0
#define GHOST_R 0.9
#define GHOST_G 0.9
#define GHOST_B 1.0

#define FRAME_W 28.0
#define FRAME_H 20.0
#define FRAME_D 0.5
#define STRING_W 0.5
#define STRING_H 8.0
#define STRING_D 0.5
#define STRING_R 0.9
#define STRING_G 0.9
#define STRING_B 0.7
#define PICTURE_R 0.9
#define PICTURE_G 0.7
#define PICTURE_B 0.0

#define SWITCH_W 2.0
#define SWITCH_H 2.0
#define SWITCH_D 2.0
#define BASE_W 2.0
#define BASE_H 2.0
#define BASE_D 2.0
// #define LIGHT_R 0.9
// #define LIGHT_G 0.9
// #define LIGHT_B 1.0

#define BOOKCASELZ_W 5.0
#define BOOKCASELZ_H 15.0
#define BOOKCASELZ_D 25.0
#define BOOKCASELX_W 25.0
#define BOOKCASELX_H 15.0
#define BOOKCASELX_D 5.0
#define BOOKCASESZ_W 5.0
#define BOOKCASESZ_H 15.0
#define BOOKCASESZ_D 10.0
#define BOOKCASESX_W 10.0
#define BOOKCASESX_H 15.0
#define BOOKCASESX_D 5.0
#define BOOKCASE_R 0.25
#define BOOKCASE_G 0.15
#define BOOKCASE_B 0.05

#define KEYL_W 1.0
#define KEYL_H 1.0
#define KEYL_D 3.0
#define KEYS_W 1.0
#define KEYS_H 1.0
#define KEYS_D 2.0
#define KEY_R 0.9
#define KEY_G 0.7
#define KEY_B 0.0

#define FIRE_W 1.0
#define FIRE_H 1.0
#define FIRE_D 1.0
#define LOG_W 1.0
#define LOG_H 1.0
#define LOG_D 2.0
#define LOG_R 0.9
#define LOG_G 0.7
#define LOG_B 0.0
#define FIRE_R 0.9
#define FIRE_G 0.7
#define FIRE_B 0.0

#define HAIR_W 0.76
#define HAIR_H 0.15
#define HAIR_D 0.76
#define FACE_W 0.75
#define FACE_H 0.75
#define FACE_D 0.75
#define LENS_W 0.25
#define LENS_H 0.25
#define LENS_D 0.25
#define BRIDGE_W 0.06125
#define BRIDGE_H 0.06125
#define BRIDGE_D 0.5
#define SHIRT_W 0.5
#define SHIRT_H 1.25
#define SHIRT_D 0.5
#define SUIT_W 0.5
#define SUIT_H 1.25
#define SUIT_D 0.25
#define TIE_W 0.25
#define TIE_H 1.0
#define TIE_D 0.25
#define APPENDAGE_W 0.25
#define APPENDAGE_H 1.5
#define APPENDAGE_D 0.25
#define SKIN_R 0.8
#define SKIN_G 0.8
#define SKIN_B 0.6
#define SHIRT_R 1.0
#define SHIRT_G 1.0
#define SHIRT_B 1.0
#define AGENCY_R 0.0
#define AGENCY_G 0.0
#define AGENCY_B 0.0

#define ZOMBIE_W 2.0
#define ZOMBIE_H 2.0
#define ZOMBIE_D 2.0
#define ZOMBIE_R 0.1
#define ZOMBIE_G 0.3
#define ZOMBIE_B 0.1

#define WEREWOLF_W 2.0
#define WEREWOLF_H 2.0
#define WEREWOLF_D 2.0
#define WEREWOLF_R 0.1
#define WEREWOLF_G 0.1
#define WEREWOLF_B 0.1

#define COFFEE_W 1.0
#define COFFEE_H 1.0
#define COFFEE_D 1.0
#define CUP_W 1.25
#define CUP_H 1.25
#define CUP_D 1.25
#define SAUCER_W 2.0
#define SAUCER_H 0.1
#define SAUCER_D 2.0
#define COFFEE_R 0.1
#define COFFEE_G 0.1
#define COFFEE_B 0.0
#define DISH_R 0.9
#define DISH_G 0.9
#define DISH_B 1.0

#define TREE_W 1.0
#define TREE_H 5.0
#define TREE_D 1.0
#define TREE_R 0.5
#define TREE_G 0.3
#define TREE_B 0.1

#define ROCK_W 2.0
#define ROCK_H 2.0
#define ROCK_D 2.0
#define ROCK_R 0.5
#define ROCK_G 0.4
#define ROCK_B 0.3

#define ANIMAL_W 1.0
#define ANIMAL_H 1.0
#define ANIMAL_D 1.0
#define ANIMAL_R 1.0
#define ANIMAL_G 1.0
#define ANIMAL_B 1.0
// vec3 animal_col[NUM_OF_ANIMALS] = { vec3(1.0, 0.0, 0.0), vec3(0.0, 1.0, 0.0), vec3(0.0, 0.0, 1.0) };

#define BARREL_W 3.0
#define BARREL_H 1.0
#define BARREL_D 0.75
#define BARREL_R 0.6
#define BARREL_G 0.6
#define BARREL_B 0.6

#define COLOR_BARREL  5
//   vec3(0.9, 0.6, 0.5),

#define SIGHT_W 2.0
#define SIGHT_H 0.25
#define SIGHT_D 0.25
#define SIGHT_R 0.5
#define SIGHT_G 0.5
#define SIGHT_B 0.5

#define HANDLE_W 0.6
#define HANDLE_H 2.0
#define HANDLE_D 0.5
#define HANDLE_R 0.4
#define HANDLE_G 0.4
#define HANDLE_B 0.4

#define BULLET_W 0.1
#define BULLET_H 0.05
#define BULLET_D 0.05
#define BULLET_R 0.1
#define BULLET_G 0.3
#define BULLET_B 0.1

#define ROCKET_W 0.1
#define ROCKET_H 0.5
#define ROCKET_D 0.5
#define ROCKET_R 0.1
#define ROCKET_G 0.3
#define ROCKET_B 0.1

#define LASER_W 1.0
#define LASER_H 0.05
#define LASER_D 0.05
#define LASER_R 0.1
#define LASER_G 0.3
#define LASER_B 0.1

#define FLOORS        0
#define NUM_FLOORS    7
#define PARTS_FLOOR   1

#define MOONS         1
#define NUM_MOONS     1
#define PARTS_MOON    1

#define GUNS          2
#define NUM_GUNS      1
#define PARTS_GUN     3

#define KEYS          3
#define NUM_KEYS      1
#define PARTS_KEY     6

#define VACCUUMS      4
#define NUM_VACCUUMS  1
#define PARTS_VACCUUM 11

#define COFFEES       5
#define NUM_COFFEES   1
#define PARTS_COFFEE  6

#define PLAYERS       6
#define NUM_PLAYERS   1
#define PARTS_PLAYER  14

#define GHOSTS        7
#define NUM_GHOSTS    1
#define PARTS_GHOST   5

#define ZOMBIES       8
#define NUM_ZOMBIES   3
#define PARTS_ZOMBIE  13

#define WEREWOLFS     9
#define NUM_WEREWOLFS 1
#define PARTS_WEREWOLF 13

#define AGENCIES      10
#define NUM_AGENCIES  1
#define PARTS_AGENCIE 13

Object floors[NUM_FLOORS][PARTS_FLOOR];
Object moons[NUM_MOONS][PARTS_MOON];
Object guns[NUM_GUNS][PARTS_GUN];
Object keys[NUM_KEYS][PARTS_KEY];
Object vaccuums[NUM_VACCUUMS][PARTS_VACCUUM];
Object coffees[NUM_COFFEES][PARTS_COFFEE];
Object ghosts[NUM_GHOSTS][PARTS_GHOST];
Object zombies[NUM_ZOMBIES][PARTS_ZOMBIE];
Object werewolfs[NUM_WEREWOLFS][PARTS_WEREWOLF];
Object agencies[NUM_AGENCIES][PARTS_AGENCIE];
Object players[NUM_PLAYERS][PARTS_PLAYER];

bool render_[AGENCIES + 1];

// PICKUPS //

vec3 gun_loc[NUM_GUNS] = {
  vec3(50.0, 10.0, 50.0)
};
vec3 key_loc[NUM_GUNS] = {
  vec3(50.0, 10.0, -50.0)
};
vec3 vacuum_loc[NUM_GUNS] = {
  vec3(-50.0, 10.0, -50.0)
};
vec3 coffee_loc[NUM_GUNS] = {
  vec3(-50.0, 10.0, 50.0)
};

vec3 gun_parts_diff[PARTS_GUN] = {
  vec3(0.0, 0.0 * 0.2, 0.0 * 0.2),
  vec3(0.0, -0.25 * 0.2, -0.75 * 0.2),
  vec3(0.0, -1.0 * 0.2, -0.025 * 0.2),
};

vec3 gun_parts_size[PARTS_GUN] = {
  vec3(BARREL_W*0.2, BARREL_H*0.2, BARREL_D*0.2),
  vec3(SIGHT_W*0.2, SIGHT_H*0.2, SIGHT_D*0.2),    //////////////////////////////
  vec3(HANDLE_W*0.2, HANDLE_H*0.2, HANDLE_D*0.2), //////////////////////////////
};

vec3 gun_parts_colors[PARTS_GUN] = {
  vec3(BARREL_R, BARREL_G, BARREL_B),
  vec3(SIGHT_R, SIGHT_G, SIGHT_B),
  vec3(HANDLE_R, HANDLE_G, HANDLE_B)
};

vec3 key_parts_diff[PARTS_KEY] = {
  vec3(0, 0.0*0., 1.5*0.2),
  vec3(0, 0.0*0.2, -0.5*0.2),
  vec3(0, 0.0*0.2, -2.5*0.2),
  vec3(0, 1.5*0.2, -1.5*0.2),
  vec3(0, -1.5*0.2, -1.5*0.2),
  vec3(0, -1.0*0.2, 2.0*0.2)
};

vec3 key_parts_size[PARTS_KEY] = {
  vec3(KEYL_D*0.2, KEYL_H*0.2, KEYL_W*0.2), ////////////////////////////////////
  vec3(KEYL_H*0.2, KEYL_D*0.2, KEYL_W*0.2),
  vec3(KEYL_H*0.2, KEYL_D*0.2, KEYL_W*0.2),
  vec3(KEYS_D*0.2, KEYS_H*0.2, KEYS_W*0.2), ////////////////////////////////////
  vec3(KEYS_D*0.2, KEYS_H*0.2, KEYS_W*0.2), ////////////////////////////////////
  vec3(KEYS_H*0.2, KEYS_D*0.2, KEYS_W*0.2)
};

vec3 key_parts_colors[PARTS_KEY] = {
  vec3(KEY_R, KEY_G, KEY_B),
  vec3(KEY_R, KEY_G, KEY_B),
  vec3(KEY_R, KEY_G, KEY_B),
  vec3(KEY_R, KEY_G, KEY_B),
  vec3(KEY_R, KEY_G, KEY_B),
  vec3(KEY_R, KEY_G, KEY_B)
};

vec3 vacuum_parts_diff[PARTS_VACCUUM] = {
  vec3(0, -3.0*0.2, 0.0*0.2),
  vec3(0, 0.5*0.2, -0.5*0.2),
  vec3(-65, 0.5*0.2, 2.75*0.2),
  vec3(0, 2.5*0.2, 1.0*0.2),
  vec3(-50, 3.5*0.2, 1.75*0.2),
  vec3(-65, -2.5*0.2, 2.75*0.2),
  vec3(-25, -1.5*0.2, -2.25*0.2),
  vec3(25, -1.5*0.2, -2.25*0.2),
  vec3(-90, -3.5*0.2, 2.5*0.2),
  vec3(90, -3.5*0.2, 2.5*0.2),
  vec3(0, 0.5*0.2, 1.5*0.2)
};

vec3 vacuum_parts_size[PARTS_VACCUUM] = {
  vec3(BODYL_W*0.2, BODYL_H*0.2, BODYL_D*0.2),
  vec3(BODYS_W*0.2, BODYS_H*0.2, BODYS_D*0.2),
  vec3(HOSEL_W*0.203, HOSEL_H*0.2, HOSEL_D*0.203),
  vec3(HOSEM_W*0.201, HOSEM_H*0.2, HOSEM_D*0.201),
  vec3(HOSES_W*0.202, HOSES_D*0.2, HOSES_H*0.202),
  vec3(NOZZLE_D*0.2, NOZZLE_H*0.2, NOZZLE_W*0.2),
  vec3(STRAP_W*0.2, STRAP_H*0.2, STRAP_D*0.2),
  vec3(STRAP_W*0.2, STRAP_H*0.2, STRAP_D*0.2),
  vec3(WHEEL_W*0.2, WHEEL_H*0.2, WHEEL_D*0.2),
  vec3(WHEEL_W*0.2, WHEEL_H*0.2, WHEEL_D*0.2),
  vec3(LIGHT_W*0.2, LIGHT_H*0.2, LIGHT_D*0.2)
};

vec3 vacuum_parts_colors[PARTS_VACCUUM] = {
  vec3(VACCUUM_R, VACCUUM_G, VACCUUM_B),
  vec3(VACCUUM_R, VACCUUM_G, VACCUUM_B),
  vec3(HOSE_R, HOSE_G, HOSE_B),
  vec3(HOSE_R, HOSE_G, HOSE_B),
  vec3(HOSE_R, HOSE_G, HOSE_B),
  vec3(HOSE_R, HOSE_G, HOSE_B),
  vec3(STRAP_R, STRAP_G, STRAP_B),
  vec3(STRAP_R, STRAP_G, STRAP_B),
  vec3(WHEEL_R, WHEEL_G, WHEEL_B),
  vec3(WHEEL_R, WHEEL_G, WHEEL_B),
  vec3(LIGHT_R, LIGHT_G, LIGHT_B)
};

vec3 coffee_parts_diff[PARTS_COFFEE] = {
  vec3(0.0, -0.8*0.2, 0.0*0.2),
  vec3(0.0, -0.8*0.2, 0.0*0.2),
  vec3(0.0, -1.0*0.2, 0.0*0.2),
  vec3(0.0, -1.0*0.2, 0.0*0.2),
  vec3(0.0, -1.5*0.2, 0.0*0.2),
  vec3(0.0, -1.5*0.2, 0.0*0.2)
};

vec3 coffee_parts_size[PARTS_COFFEE] = {
  vec3(COFFEE_W*0.2, COFFEE_H*0.2, COFFEE_D*0.2),
  vec3(COFFEE_W*0.2, COFFEE_H*0.2, COFFEE_D*0.2),
  vec3(CUP_W*0.2, CUP_H*0.2, CUP_D*0.2),
  vec3(CUP_W*0.2, CUP_H*0.2, CUP_D*0.2),
  vec3(SAUCER_W*0.2, SAUCER_H*0.2, SAUCER_D*0.2),
  vec3(SAUCER_W*0.2, SAUCER_H*0.2, SAUCER_D*0.2)
};

vec3 coffee_parts_colors[PARTS_COFFEE] = {
  vec3(COFFEE_R, COFFEE_G, COFFEE_B),
  vec3(COFFEE_R, COFFEE_G, COFFEE_B),
  vec3(DISH_R, DISH_G, DISH_B),
  vec3(DISH_R, DISH_G, DISH_B),
  vec3(DISH_R, DISH_G, DISH_B),
  vec3(DISH_R, DISH_G, DISH_B)
};

// ENEMIES //

vec3 ghost_parts_colors[PARTS_GHOST] = {
  vec3(GHOST_R, GHOST_G, GHOST_B),
  vec3(GHOST_R, GHOST_G, GHOST_B),
  vec3(GHOST_R, GHOST_G, GHOST_B),
  vec3(GHOST_R, GHOST_G, GHOST_B),
  vec3(GHOST_R, GHOST_G, GHOST_B)
};

vec3 ghost_parts_rot[PARTS_GHOST] = {
  vec3(0.0, 0.0, 0.0),
  vec3(0.0, 0.0, 0.0),
  vec3(45.0, 0.0, 45.0),
  vec3(45.0, 0.0, 45.0),
  vec3(45.0, 0.0, 45.0)
};

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

vec3 wolf_parts_diff[PARTS_WEREWOLF] = {
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

vec3 wolf_parts_size[PARTS_WEREWOLF] = {
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

vec3 wolf_parts_colors[PARTS_WEREWOLF] = {
  vec3(WEREWOLF_R, WEREWOLF_G, WEREWOLF_B),
  vec3(WEREWOLF_R, WEREWOLF_G, WEREWOLF_B),
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

vec3 agen_parts_diff[PARTS_AGENCIE] = {
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

vec3 agen_parts_size[PARTS_AGENCIE] = {
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

vec3 agen_parts_colors[PARTS_AGENCIE] = {
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

// void load() {

//     mat4  m;
//
//     m = RotateY( theta[Torso] );
//     model[Torso] = Object( m, torso, NULL, &model[Head1] );
//
//     m = Translate(0.0, TORSO_HEIGHT+0.5*HEAD_HEIGHT, 0.0) *
//       RotateX(theta[Head1]) *
//       RotateY(theta[Head2]) *
//       Translate(0.0, -0.5*HEAD_HEIGHT, 0.0);
//
//     model[Head1] = Object( m, head, &model[LeftUpperArm], NULL );
//
//     m = Translate(-(TORSO_WIDTH+UPPER_ARM_WIDTH), 0.9*TORSO_HEIGHT, 0.0) *
// 	RotateX(theta[LeftUpperArm]);
//     model[LeftUpperArm] =
// 	Object( m, left_upper_arm, &model[RightUpperArm], &model[LeftLowerArm] );
//
//     m = Translate(TORSO_WIDTH+UPPER_ARM_WIDTH, 0.9*TORSO_HEIGHT, 0.0) *
// 	RotateX(theta[RightUpperArm]);
//     model[RightUpperArm] =
// 	Object( m, right_upper_arm,
// 	      &model[LeftUpperLeg], &model[RightLowerArm] );
//
//     m = Translate(-(TORSO_WIDTH+UPPER_LEG_WIDTH), 0.1*UPPER_LEG_HEIGHT, 0.0) *
// 	RotateX(theta[LeftUpperLeg]);
//     model[LeftUpperLeg] =
// 	Object( m, left_upper_leg, &model[RightUpperLeg], &model[LeftLowerLeg] );
//
//     m = Translate(TORSO_WIDTH+UPPER_LEG_WIDTH, 0.1*UPPER_LEG_HEIGHT, 0.0) *
// 	RotateX(theta[RightUpperLeg]);
//     model[RightUpperLeg] =
// 	Object( m, right_upper_leg, NULL, &model[RightLowerLeg] );
//
//     m = Translate(0.0, UPPER_ARM_HEIGHT, 0.0) * RotateX(theta[LeftLowerArm]);
//     model[LeftLowerArm] = Object( m, left_lower_arm, NULL, NULL );
//
//     m = Translate(0.0, UPPER_ARM_HEIGHT, 0.0) * RotateX(theta[RightLowerArm]);
//     model[RightLowerArm] = Object( m, right_lower_arm, NULL, NULL );
//
//     m = Translate(0.0, UPPER_LEG_HEIGHT, 0.0) * RotateX(theta[LeftLowerLeg]);
//     model[LeftLowerLeg] = Object( m, left_lower_leg, NULL, NULL );
//
//     m = Translate(0.0, UPPER_LEG_HEIGHT, 0.0) * RotateX(theta[RightLowerLeg]);
//     model[RightLowerLeg] = Object( m, right_lower_leg, NULL, NULL );

  // floors[0].create(mv, model_view, -50.0 + FLOOR_SIZE / 2, -2.5, -50.0 + FLOOR_SIZE / 2, 50.0, ROOF_H, 50.0, ROOF_R, ROOF_G, ROOF_B, 0, 0, 0, 0, 0, 0, Object::wood);
  //
  // floors[1].create(mv, model_view, -50.0 + FLOOR_SIZE / 2, -2.5, -50.0 + FLOOR_SIZE / 2, ROOF_W, ROOF_H, 10.0, ROOF_R, ROOF_G, ROOF_B, 0, 0, 0, 0, 0, 0, Object::wood);
  // floors[2].create(mv, model_view, -50.0 + FLOOR_SIZE / 2, -2.5, -50.0 + FLOOR_SIZE / 2, 10.0, ROOF_H, ROOF_D, ROOF_R, ROOF_G, ROOF_B, 0, 0, 0, 0, 0, 0, Object::wood);
  //
  // floors[3].create(mv, model_view, 50.0, 7.5, 50.0, 25.0, ROOF_H, 25.0, ROOF_R, ROOF_G, ROOF_B, 0, 0, 0, 0, 0, 0, Object::wood);
  // floors[4].create(mv, model_view, -50.0, 7.5, 50.0, 25.0, ROOF_H, 25.0, ROOF_R, ROOF_G, ROOF_B, 0, 0, 0, 0, 0, 0, Object::wood);
  // floors[5].create(mv, model_view, -50.0, 7.5, -50.0, 25.0, ROOF_H, 25.0, ROOF_R, ROOF_G, ROOF_B, 0, 0, 0, 0, 0, 0, Object::wood);
  // floors[6].create(mv, model_view, 50.0, 7.5, -50.0, 25.0, ROOF_H, 25.0, ROOF_R, ROOF_G, ROOF_B, 0, 0, 0, 0, 0, 0, Object::wood);

// }

// void traverse( Object node ) {
//   // base case
//   if ( node == NULL ) { return; }
//
//   // Recursive case, first remember the current transform.
//   mvstack.push( model_view );
//
//   mv *= node.transform;
//   node.render(mvstack);
//   traverse( node.child );
//
//   //  if ( node->child != NULL) { traverse( node->child ); }
//
//   mv = mvstack.pop();
//
//   traverse( node.sibling );
//   //  if ( node->sibling != NULL) { traverse( node->sibling ); }
// }

void load (mat4 mv, GLuint model_view) {

  // mat4 matr
  // GLuint unif

  // float x
  // float y
  // float z

  // float ra
  // float yax

  // float w
  // float h
  // float d

  // float r
  // float g
  // float b

  // float pi
  // float ya
  // float ro

  // float rta
  // float rl

  // float sli
  // float sta
  // float typ

  // Object::material mat

  // for (int i = 0; i < NUM_FLOORS; i++) {
    for (int j = 0; j < PARTS_FLOOR; j++) {
      floors[0][j].create(mv, model_view, -50.0 + FLOOR_SIZE / 2, -2.5, -50.0 + FLOOR_SIZE / 2, 50.0, ROOF_H, 50.0, ROOF_R, ROOF_G, ROOF_B, 0, 0, 0, 0, 0, 0, Object::wood);

      floors[1][j].create(mv, model_view, -50.0 + FLOOR_SIZE / 2, -2.5, -50.0 + FLOOR_SIZE / 2, ROOF_W, ROOF_H, 10.0, ROOF_R, ROOF_G, ROOF_B, 0, 0, 0, 0, 0, 0, Object::wood);
      floors[2][j].create(mv, model_view, -50.0 + FLOOR_SIZE / 2, -2.5, -50.0 + FLOOR_SIZE / 2, 10.0, ROOF_H, ROOF_D, ROOF_R, ROOF_G, ROOF_B, 0, 0, 0, 0, 0, 0, Object::wood);

      floors[3][j].create(mv, model_view, 50.0, 7.5, 50.0, 25.0, ROOF_H, 25.0, ROOF_R, ROOF_G, ROOF_B, 0, 0, 0, 0, 0, 0, Object::wood);
      floors[4][j].create(mv, model_view, -50.0, 7.5, 50.0, 25.0, ROOF_H, 25.0, ROOF_R, ROOF_G, ROOF_B, 0, 0, 0, 0, 0, 0, Object::wood);
      floors[5][j].create(mv, model_view, -50.0, 7.5, -50.0, 25.0, ROOF_H, 25.0, ROOF_R, ROOF_G, ROOF_B, 0, 0, 0, 0, 0, 0, Object::wood);
      floors[6][j].create(mv, model_view, 50.0, 7.5, -50.0, 25.0, ROOF_H, 25.0, ROOF_R, ROOF_G, ROOF_B, 0, 0, 0, 0, 0, 0, Object::wood);
    }
  // }

  for (int i = 0; i < NUM_MOONS; i++) {
    for (int j = 0; j < PARTS_MOON; j++) {
      moons[i][j].create(mv, model_view, -75.0,  40.0, -65.0, MOON_W, MOON_H, MOON_D, MOON_R, MOON_G, MOON_B, 0, 0, 0, 6, 6, 2, Object::wood);
    }
  }

  for (int i = 0; i < NUM_GUNS; i++) {
    // for (int j = 0; j < PARTS_GUN; j++) {
      guns[i][0].create(mv, model_view, 50 + 0.0*0.2, 10.0 + 0.0*0.2, 50 + -1.0*0.2, BARREL_W*0.2, BARREL_H*0.2, BARREL_D*0.2, BARREL_R, BARREL_G, BARREL_B, 0, 0, 0, 0, 0, 0, Object::metal);
      guns[i][1].create(mv, model_view, 50 - 0.4*0.2, 10.0 + -0.5*0.2, 50 + -1.75*0.2, SIGHT_W*0.2, SIGHT_H*0.2, SIGHT_D*0.2, SIGHT_R, SIGHT_G, SIGHT_B, 0, 0, 90, 0, 0, 0, Object::metal);
      guns[i][2].create(mv, model_view, 50 + 0.05*0.2, 10.0 + -1.1*0.2, 50 + 0.0*0.2, HANDLE_W*0.2, HANDLE_H*0.2, HANDLE_D*0.2, HANDLE_R, HANDLE_G, HANDLE_B, 0, 90, 0, 0, 0, 0, Object::metal);
    // }
  }

  for (int i = 0; i < NUM_KEYS; i++) {
    // for (int j = 0; j < PARTS_KEY; j++) {
      keys[i][0].create(mv, model_view, 50.0 - 1.5*0.2, 10.0 + 0.0*0.2, -50.0 + 1.5*0.2, KEYL_W*0.2, KEYL_H*0.2, KEYL_D*0.2, KEY_R, KEY_G, KEY_B, 0, 0, 0, 0, 0, 0, Object::metal);
      keys[i][1].create(mv, model_view, 50.0 - 1.5*0.2, 10.0 + 0.0*0.2, -50.0 - 0.5*0.2, KEYL_W*0.2, KEYL_H*0.2, KEYL_D*0.2, KEY_R, KEY_G, KEY_B, 90, 0, 0, 0, 0, 0, Object::metal);
      keys[i][2].create(mv, model_view, 50.0 - 1.5*0.2, 10.0 + 0.0*0.2, -50.0 - 2.5*0.2, KEYL_W*0.2, KEYL_H*0.2, KEYL_D*0.2, KEY_R, KEY_G, KEY_B, 90, 0, 0, 0, 0, 0, Object::metal);
      keys[i][3].create(mv, model_view, 50.0 - 1.5*0.2, 10.0 + 1.5*0.2, -50.0 - 1.5*0.2, KEYS_W*0.2, KEYS_H*0.2, KEYS_D*0.2, KEY_R, KEY_G, KEY_B, 0, 0, 0, 0, 0, 0, Object::metal);
      keys[i][4].create(mv, model_view, 50.0 - 1.5*0.2, 10.0 - 1.5*0.2, -50.0 - 1.5*0.2, KEYS_W*0.2, KEYS_H*0.2, KEYS_D*0.2, KEY_R, KEY_G, KEY_B, 0, 0, 0, 0, 0, 0, Object::metal);
      keys[i][5].create(mv, model_view, 50.0 - 1.5*0.2, 10.0 - 1.0*0.2, -50.0 + 2.0*0.2, KEYS_W*0.2, KEYS_H*0.2, KEYS_D*0.2, KEY_R, KEY_G, KEY_B, 90, 0, 0, 0, 0, 0, Object::metal);
    // }
  }

  for (int i = 0; i < NUM_VACCUUMS; i++) {
    // for (int j = 0; j < PARTS_VACCUUM; j++) {
      vaccuums[i][0].create(mv, model_view, -50.0 + 0.0*0.2, 8.0 - 3.0*0.2, -50.0 + 0.0*0.2, BODYL_W*0.2, BODYL_H*0.2, BODYL_D*0.2, VACCUUM_R, VACCUUM_G, VACCUUM_B, 0, 0, 0, 0, 0, 0, Object::metal);
      vaccuums[i][1].create(mv, model_view, -50.0 + 0.0*0.2, 8.0 + 0.5*0.2, -50.0 - 0.5*0.2, BODYS_W*0.2, BODYS_H*0.2, BODYS_D*0.2, VACCUUM_R, VACCUUM_G, VACCUUM_B, 0, 0, 0, 0, 0, 0, Object::metal);
      vaccuums[i][2].create(mv, model_view, -50.0 + 2.5*0.2, 8.0 + 0.5*0.2, -50.0 + 1.0*0.2, HOSEL_W*0.203, HOSEL_H*0.2, HOSEL_D*0.203, HOSE_R, HOSE_G, HOSE_B, 0, 0, 0, 0, 0, 0, Object::metal);
      vaccuums[i][3].create(mv, model_view, -50.0 + 0.0*0.2, 8.0 + 2.5*0.2, -50.0 + 1.0*0.2, HOSEM_W*0.201, HOSEM_H*0.2, HOSEM_D*0.201, HOSE_R, HOSE_G, HOSE_B, 0, 0, 0, 0, 0, 0, Object::metal);
      vaccuums[i][4].create(mv, model_view, -50.0 + 1.25*0.2, 8.0 + 3.5*0.2, -50.0 + 1.0*0.2, HOSES_W*0.202, HOSES_H*0.2, HOSES_D*0.202, HOSE_R, HOSE_G, HOSE_B, 0, 0, 90, 0, 0, 0, Object::metal);
      vaccuums[i][5].create(mv, model_view, -50.0 + 2.5*0.2, 8.0 - 2.5*0.2, -50.0 + 1.5*0.2, NOZZLE_W*0.2, NOZZLE_H*0.2, NOZZLE_D*0.2, HOSE_R, HOSE_G, HOSE_B, 0, 0, 0, 0, 0, 0, Object::metal);
      vaccuums[i][6].create(mv, model_view, -50.0 - 1.0*0.2, 8.0 - 1.5*0.2, -50.0 - 2.0*0.2, STRAP_W*0.2, STRAP_H*0.2, STRAP_D*0.2, STRAP_R, STRAP_G, STRAP_B, 0, 0, 0, 0, 0, 0, Object::metal);
      vaccuums[i][7].create(mv, model_view, -50.0 + 1.0*0.2, 8.0 - 1.5*0.2, -50.0 - 2.0*0.2, STRAP_W*0.2, STRAP_H*0.2, STRAP_D*0.2, STRAP_R, STRAP_G, STRAP_B, 0, 0, 0, 0, 0, 0, Object::metal);
      vaccuums[i][8].create(mv, model_view, -50.0 - 2.5*0.2, 8.0 - 3.5*0.2, -50.0 - 0.5*0.2, WHEEL_W*0.2, WHEEL_H*0.2, WHEEL_D*0.2, WHEEL_R, WHEEL_G, WHEEL_B, 0, 0, 0, 0, 0, 0, Object::metal);
      vaccuums[i][9].create(mv, model_view, -50.0 + 2.5*0.2, 8.0 - 3.5*0.2, -50.0 - 0.5*0.2, WHEEL_W*0.2, WHEEL_H*0.2, WHEEL_D*0.2, WHEEL_R, WHEEL_G, WHEEL_B, 0, 0, 0, 0, 0, 0, Object::metal);
      vaccuums[i][10].create(mv, model_view, -50.0 + 0.0*0.2, 8.0 + 0.5*0.2, -50.0 + 1.0*0.2, LIGHT_W*0.2, LIGHT_H*0.2, LIGHT_D*0.2, LIGHT_R, LIGHT_G, LIGHT_B, 0, 0, 0, 0, 0, 0, Object::glass);
    // }
  }

  for (int i = 0; i < NUM_COFFEES; i++) {
    // for (int j = 0; j < PARTS_COFFEE; j++) {
      coffees[i][0].create(mv, model_view, -50.0 + 0.0*0.2, 10.0 - 0.8*0.2, 50.0 + 0.0*0.2, COFFEE_W*0.2, COFFEE_H*0.2, COFFEE_D*0.2, COFFEE_R, COFFEE_G, COFFEE_B, 0, 0, 0, 0, 0, 0, Object::ceramic);
      coffees[i][1].create(mv, model_view, -50.0 + 0.0*0.2, 10.0 - 1.0*0.2, 50.0 + 0.0*0.2, CUP_W*0.2, CUP_H*0.2, CUP_D*0.2, DISH_R, DISH_G, DISH_B, 0, 0, 0, 0, 0, 0, Object::ceramic);
      coffees[i][2].create(mv, model_view, -50.0 + 0.0*0.2, 10.0 - 1.5*0.2, 50.0 + 0.0*0.2, SAUCER_W*0.2, SAUCER_H*0.2, SAUCER_D*0.2, DISH_R, DISH_G, DISH_B, 0, 45, 0, 0, 0, 0, Object::ceramic);
      coffees[i][3].create(mv, model_view, -50.0 + 0.0*0.2, 10.0 - 1.5*0.2, 50.0 + 0.0*0.2, SAUCER_W*0.2, SAUCER_H*0.2, SAUCER_D*0.2, DISH_R, DISH_G, DISH_B, 0, 0, 0, 0, 0, 0, Object::ceramic);
    // }
  }

  for (int i = 0; i < NUM_PLAYERS; i++) {
    // for (int j = 0; j < PARTS_GHOST; j++) {
      players[i][0].create(mv, model_view, 0.0 + 0.0 * cos((90.0 - 0) * M_PI/180), 5.0 + 1.15, 0.0 + 0.0, HAIR_W, HAIR_H, HAIR_D, AGENCY_R, AGENCY_G, AGENCY_B, 0, -90.0, 0, 0, 0, 0, Object::wood);
      players[i][1].create(mv, model_view, 0.0 + 0.0 * cos((90.0 - 0) * M_PI/180), 5.0 + 0.75, 0.0 + 0.0, FACE_W, FACE_H, FACE_D, SKIN_R, SKIN_G, SKIN_B, 0, -90.0, 0, 0, 0, 0, Object::wood);
      players[i][2].create(mv, model_view, 0.0 - 0.4 * cos((90.0 - 30) * M_PI/180), 5.0 + 0.75, 0.0 - 0.4 * sin((90.0 - 30) * M_PI/180), LENS_W, LENS_H, LENS_D, AGENCY_R, AGENCY_G, AGENCY_B, 0, -90.0, 0, 0, 0, 0, Object::wood);
      players[i][3].create(mv, model_view, 0.0 - 0.4 * cos((90.0 + 30) * M_PI/180), 5.0 + 0.75, 0.0 - 0.4 * sin((90.0 + 30) * M_PI/180), LENS_W, LENS_H, LENS_D, AGENCY_R, AGENCY_G, AGENCY_B, 0, -90.0, 0, 0, 0, 0, Object::wood);
      players[i][4].create(mv, model_view, 0.0 - 0.4 * cos((90.0 - 0) * M_PI/180), 5.0 + 0.875, 0.0 - 0.4 * sin(90.0 * M_PI/180), BRIDGE_W, BRIDGE_H, BRIDGE_D, AGENCY_R, AGENCY_G, AGENCY_B, 0, -90.0, 0, 0, 0, 0, Object::wood);
      players[i][5].create(mv, model_view, 0.0 + 0.0 * cos((90.0 - 30) * M_PI/180), 5.0 - 0.25, 0.0 + 0.0, SHIRT_W, SHIRT_H, SHIRT_D, SHIRT_R, SHIRT_G, SHIRT_B, 0, -90.0, 0, 0, 0, 0, Object::wood);
      players[i][6].create(mv, model_view, 0.0 + 0.1 * cos(90.0 * M_PI/180), 5.0 - 0.25, 0.0 + 0.1 * sin(90.0 * M_PI/180), SHIRT_W, SHIRT_H, SHIRT_D, AGENCY_R, AGENCY_G, AGENCY_B, 0, -90.0, 0, 0, 0, 0, Object::wood);
      players[i][7].create(mv, model_view, 0.0 - 0.25 * cos((90.0 - 0) * M_PI/180), 5.0 - 0.125, 0.0 - 0.25 * sin((90.0 - 0) * M_PI/180), TIE_W, TIE_H, TIE_D, AGENCY_R, AGENCY_G, AGENCY_B, 0, -90.0, 0, 0, 0, 0, Object::wood);
      players[i][8].create(mv, model_view, 0.0 + 0.375 * cos((90.0 - 90) * M_PI/180), 5.0 - 0.25, 0.0 + 0.375  * sin((90.0 - 90) * M_PI/180), SUIT_W, SUIT_H, SUIT_D, AGENCY_R, AGENCY_G, AGENCY_B, 0, -90.0, 0, 0, 0, 0, Object::wood);
      players[i][9].create(mv, model_view, 0.0 + 0.375 * cos((90.0 + 90) * M_PI/180), 5.0 - 0.25, 0.0 + 0.375 * sin((90.0 + 90) * M_PI/180), SUIT_W, SUIT_H, SUIT_D, AGENCY_R, AGENCY_G, AGENCY_B, 0, -90.0, 0, 0, 0, 0, Object::wood);
      players[i][10].create(mv, model_view, 0.0 + 0.5 * cos((90.0 - 90) * M_PI/180), 5.0 - 0.375, 0.0 + 0.5 * sin((90.0 - 90) * M_PI/180), APPENDAGE_W, APPENDAGE_H, APPENDAGE_D, AGENCY_R, AGENCY_G, AGENCY_B, 0, -90.0, 0, 0, 0, 0, Object::wood);
      players[i][11].create(mv, model_view, 0.0 + 0.5 * cos((90.0 + 90) * M_PI/180), 5.0 - 0.375, 0.0 + 0.5 * sin((90.0 + 90) * M_PI/180), APPENDAGE_W, APPENDAGE_H, APPENDAGE_D, AGENCY_R, AGENCY_G, AGENCY_B, 0, -90.0, 0, 0, 0, 0, Object::wood);
      players[i][12].create(mv, model_view, 0.0 + 0.25 * cos((90.0 - 90) * M_PI/180), 5.0 - 1.5, 0.0 + 0.25 * sin((90.0 - 90) * M_PI/180), APPENDAGE_W, APPENDAGE_H, APPENDAGE_D, AGENCY_R, AGENCY_G, AGENCY_B, 0, -90.0, 0, 0, 0, 0, Object::wood);
      players[i][13].create(mv, model_view, 0.0 + 0.25 * cos((90.0 + 90) * M_PI/180), 5.0 - 1.5, 0.0 + 0.25 * sin((90.0 + 90) * M_PI/180), APPENDAGE_W, APPENDAGE_H, APPENDAGE_D, AGENCY_R, AGENCY_G, AGENCY_B, 0, -90.0, 0, 0, 0, 0, Object::wood);
    // }
  }

  for (int i = 0; i < NUM_GHOSTS; i++) {
    // for (int j = 0; j < PARTS_GHOST; j++) {
      ghosts[i][0].create(mv, model_view, -17.5, 0.0 + 0.5, -5.0, 0.0, 0.0, 0.0, GHOST_R, GHOST_G, GHOST_B, 0, 0, 0, 0, 0, 0, Object::ceramic);
      ghosts[i][1].create(mv, model_view, -17.5, 0.0 + 0.0, -5.0, 0.0*1.25, 0.0*1.25, 0.0*1.25, GHOST_R, GHOST_G, GHOST_B, 0, 0, 0, 0, 0, 0, Object::ceramic);
      ghosts[i][2].create(mv, model_view, -17.5 + 0.5 * cos(105 * M_PI/180), 0.0 - 1.0, -5.0 + 0.5 * sin(105 * M_PI/180), 0.0/2, 0.0/2, 0.0/2, GHOST_R, GHOST_G, GHOST_B, 45, 0, 45, 0, 0, 0, Object::ceramic);
      ghosts[i][3].create(mv, model_view, -17.5 + 0.5 * cos(225 * M_PI/180), 0.0 - 1.0, -5.0 + 0.5 * sin(225 * M_PI/180), 0.0/2, 0.0/2, 0.0/2, GHOST_R, GHOST_G, GHOST_B, 45, 0, 45, 0, 0, 0, Object::ceramic);
      ghosts[i][4].create(mv, model_view, -17.5 + 0.5 * cos(345 * M_PI/180), 0.0 - 1.0, -5.0 + 0.5 * sin(345 * M_PI/180), 0.0/2, 0.0/2, 0.0/2, GHOST_R, GHOST_G, GHOST_B, 45, 0, 45, 0, 0, 0, Object::ceramic);
    // }
  }

  for (int i = 0; i < NUM_ZOMBIES; i++) {
    // for (int j = 0; j < PARTS_ZOMBIE; j++) {
      zombies[i][0].create(mv, model_view, 0.0 + 0.0, 0.0 + 1.15, 0.0 + 0.0, HAIR_W*1.0, HAIR_H*1.0, HAIR_D*1.0, ZOMBIE_R, ZOMBIE_G, ZOMBIE_B, 0, 0, 0, 0, 0, 0, Object::ceramic);
      zombies[i][1].create(mv, model_view, 0.0 + 0.0, 0.0 + 0.75, 0.0 + 0.0, FACE_W*1.0, FACE_H*1.0, FACE_D*1.0, ZOMBIE_R, ZOMBIE_G, ZOMBIE_B, 0, 0, 0, 0, 0, 0, Object::ceramic);
      zombies[i][2].create(mv, model_view, 0.0 + 0.3, 0.0 + 0.75, 0.0 - 0.175, LENS_W*1.0, LENS_H*1.0, LENS_D*1.0, ZOMBIE_R, ZOMBIE_G, ZOMBIE_B, 0, 0, 0, 0, 0, 0, Object::ceramic);
      zombies[i][3].create(mv, model_view, 0.0 + 0.3, 0.0 + 0.75, 0.0 + 0.175, LENS_W*1.0, LENS_H*1.0, LENS_D*1.0, ZOMBIE_R, ZOMBIE_G, ZOMBIE_B, 0, 0, 0, 0, 0, 0, Object::ceramic);
      zombies[i][4].create(mv, model_view, 0.0 + 0.4, 0.0 + 0.875, 0.0 + 0.0, BRIDGE_W*1.0, BRIDGE_H*1.0, BRIDGE_D*1.0, ZOMBIE_R, ZOMBIE_G, ZOMBIE_B, 0, 0, 0, 0, 0, 0, Object::ceramic);
      zombies[i][5].create(mv, model_view, 0.0 + 0.0, 0.0 - 0.25, 0.0 + 0.0, SHIRT_W*1.0, SHIRT_H*1.0, SHIRT_D*1.0, ZOMBIE_R, ZOMBIE_G, ZOMBIE_B, 0, 0, 0, 0, 0, 0, Object::ceramic);
      zombies[i][6].create(mv, model_view, 0.0 + 0.0, 0.0 - 0.25, 0.0 - 0.375, SUIT_W*1.0, SUIT_H*1.0, SUIT_D*1.0, ZOMBIE_R, ZOMBIE_G, ZOMBIE_B, 0, 0, 0, 0, 0, 0, Object::ceramic);
      zombies[i][7].create(mv, model_view, 0.0 + 0.0, 0.0 - 0.25, 0.0 + 0.375, SUIT_W*1.0, SUIT_H*1.0, SUIT_D*1.0, ZOMBIE_R, ZOMBIE_G, ZOMBIE_B, 0, 0, 0, 0, 0, 0, Object::ceramic);
      zombies[i][8].create(mv, model_view, 0.0 + 0.25, 0.0 - 0.125, 0.0 + 0.0, TIE_W*1.0, TIE_H*1.0, TIE_D*1.0, ZOMBIE_R, ZOMBIE_G, ZOMBIE_B, 0, 0, 0, 0, 0, 0, Object::ceramic);
      zombies[i][9].create(mv, model_view, 0.0 + 0.0, 0.0 - 0.375, 0.0 - 0.5, APPENDAGE_W*1.0, APPENDAGE_H*1.0, APPENDAGE_D*1.0, ZOMBIE_R, ZOMBIE_G, ZOMBIE_B, 0, 0, 0, 0, 0, 0, Object::ceramic);
      zombies[i][10].create(mv, model_view, 0.0 + 0.0, 0.0 - 0.375, 0.0 + 0.5, APPENDAGE_W*1.0, APPENDAGE_H*1.0, APPENDAGE_D*1.0, ZOMBIE_R, ZOMBIE_G, ZOMBIE_B, 0, 0, 0, 0, 0, 0, Object::ceramic);
      zombies[i][11].create(mv, model_view, 0.0 + 0.0, 0.0 - 1.5, 0.0 - 0.25, APPENDAGE_W*1.0, APPENDAGE_H*1.0, APPENDAGE_D*1.0, ZOMBIE_R, ZOMBIE_G, ZOMBIE_B, 0, 0, 0, 0, 0, 0, Object::ceramic);
      zombies[i][12].create(mv, model_view, 0.0 + 0.0, 0.0 - 1.5, 0.0 + 0.25, APPENDAGE_W*1.0, APPENDAGE_H*1.0, APPENDAGE_D*1.0, ZOMBIE_R, ZOMBIE_G, ZOMBIE_B, 0, 0, 0, 0, 0, 0, Object::ceramic);
    // }
  }

  for (int i = 0; i < NUM_WEREWOLFS; i++) {
    // for (int j = 0; j < PARTS_WEREWOLF; j++) {
      werewolfs[i][0].create(mv, model_view, 0.0 + 0.0, 0.0 + 1.15, 0.0 + 0.0, HAIR_W*1.0, HAIR_H*1.0, HAIR_D*1.0, WEREWOLF_R, WEREWOLF_G, WEREWOLF_B, 0, 0, 0, 0, 0, 0, Object::ceramic);
      werewolfs[i][1].create(mv, model_view, 0.0 + 0.0, 0.0 + 0.75, 0.0 + 0.0, FACE_W*1.0, FACE_H*1.0, FACE_D*1.0, WEREWOLF_R, WEREWOLF_G, WEREWOLF_B, 0, 0, 0, 0, 0, 0, Object::ceramic);
      werewolfs[i][2].create(mv, model_view, 0.0 + 0.3, 0.0 + 0.75, 0.0 - 0.175, LENS_W*1.0, LENS_H*1.0, LENS_D*1.0, WEREWOLF_R, WEREWOLF_G, WEREWOLF_B, 0, 0, 0, 0, 0, 0, Object::ceramic);
      werewolfs[i][3].create(mv, model_view, 0.0 + 0.3, 0.0 + 0.75, 0.0 + 0.175, LENS_W*1.0, LENS_H*1.0, LENS_D*1.0, WEREWOLF_R, WEREWOLF_G, WEREWOLF_B, 0, 0, 0, 0, 0, 0, Object::ceramic);
      werewolfs[i][4].create(mv, model_view, 0.0 + 0.4, 0.0 + 0.875, 0.0 + 0.0, BRIDGE_W*1.0, BRIDGE_H*1.0, BRIDGE_D*1.0, WEREWOLF_R, WEREWOLF_G, WEREWOLF_B, 0, 0, 0, 0, 0, 0, Object::ceramic);
      werewolfs[i][5].create(mv, model_view, 0.0 + 0.0, 0.0 - 0.25, 0.0 + 0.0, SHIRT_W*1.0, SHIRT_H*1.0, SHIRT_D*1.0, WEREWOLF_R, WEREWOLF_G, WEREWOLF_B, 0, 0, 0, 0, 0, 0, Object::ceramic);
      werewolfs[i][6].create(mv, model_view, 0.0 + 0.0, 0.0 - 0.25, 0.0 - 0.375, SUIT_W*1.0, SUIT_H*1.0, SUIT_D*1.0, WEREWOLF_R, WEREWOLF_G, WEREWOLF_B, 0, 0, 0, 0, 0, 0, Object::ceramic);
      werewolfs[i][7].create(mv, model_view, 0.0 + 0.0, 0.0 - 0.25, 0.0 + 0.375, SUIT_W*1.0, SUIT_H*1.0, SUIT_D*1.0, WEREWOLF_R, WEREWOLF_G, WEREWOLF_B, 0, 0, 0, 0, 0, 0, Object::ceramic);
      werewolfs[i][8].create(mv, model_view, 0.0 + 0.25, 0.0 - 0.125, 0.0 + 0.0, TIE_W*1.0, TIE_H*1.0, TIE_D*1.0, WEREWOLF_R, WEREWOLF_G, WEREWOLF_B, 0, 0, 0, 0, 0, 0, Object::ceramic);
      werewolfs[i][9].create(mv, model_view, 0.0 + 0.0, 0.0 - 0.375, 0.0 - 0.5, APPENDAGE_W*1.0, APPENDAGE_H*1.0, APPENDAGE_D*1.0, WEREWOLF_R, WEREWOLF_G, WEREWOLF_B, 0, 0, 0, 0, 0, 0, Object::ceramic);
      werewolfs[i][10].create(mv, model_view, 0.0 + 0.0, 0.0 - 0.375, 0.0 + 0.5, APPENDAGE_W*1.0, APPENDAGE_H*1.0, APPENDAGE_D*1.0, WEREWOLF_R, WEREWOLF_G, WEREWOLF_B, 0, 0, 0, 0, 0, 0, Object::ceramic);
      werewolfs[i][11].create(mv, model_view, 0.0 + 0.0, 0.0 - 1.5, 0.0 - 0.25, APPENDAGE_W*1.0, APPENDAGE_H*1.0, APPENDAGE_D*1.0, WEREWOLF_R, WEREWOLF_G, WEREWOLF_B, 0, 0, 0, 0, 0, 0, Object::ceramic);
      werewolfs[i][12].create(mv, model_view, 0.0 + 0.0, 0.0 - 1.5, 0.0 + 0.25, APPENDAGE_W*1.0, APPENDAGE_H*1.0, APPENDAGE_D*1.0, WEREWOLF_R, WEREWOLF_G, WEREWOLF_B, 0, 0, 0, 0, 0, 0, Object::ceramic);
    // }
  }

  for (int i = 0; i < NUM_AGENCIES; i++) {
    // for (int j = 0; j < PARTS_AGENCIE; j++) {
      agencies[i][0].create(mv, model_view, 0.0 + 0.0, 0.0 + 1.15, 0.0 + 0.0, HAIR_W*1.0, HAIR_H*1.0, HAIR_D*1.0, AGENCY_R, AGENCY_G, AGENCY_B, 0, 0, 0, 0, 0, 0, Object::ceramic);
      agencies[i][1].create(mv, model_view, 0.0 + 0.0, 0.0 + 0.75, 0.0 + 0.0, FACE_W*1.0, FACE_H*1.0, FACE_D*1.0, SKIN_R, SKIN_G, SKIN_B, 0, 0, 0, 0, 0, 0, Object::ceramic);
      agencies[i][2].create(mv, model_view, 0.0 + 0.3, 0.0 + 0.75, 0.0 - 0.175, LENS_W*1.0, LENS_H*1.0, LENS_D*1.0, AGENCY_R, AGENCY_G, AGENCY_B, 0, 0, 0, 0, 0, 0, Object::ceramic);
      agencies[i][3].create(mv, model_view, 0.0 + 0.3, 0.0 + 0.75, 0.0 + 0.175, LENS_W*1.0, LENS_H*1.0, LENS_D*1.0, AGENCY_R, AGENCY_G, AGENCY_B, 0, 0, 0, 0, 0, 0, Object::ceramic);
      agencies[i][4].create(mv, model_view, 0.0 + 0.4, 0.0 + 0.875, 0.0 + 0.0, BRIDGE_W*1.0, BRIDGE_H*1.0, BRIDGE_D*1.0, AGENCY_R, AGENCY_G, AGENCY_B, 0, 0, 0, 0, 0, 0, Object::ceramic);
      agencies[i][5].create(mv, model_view, 0.0 + 0.0, 0.0 - 0.25, 0.0 + 0.0, SHIRT_W*1.0, SHIRT_H*1.0, SHIRT_D*1.0, SHIRT_R, SHIRT_G, SHIRT_B, 0, 0, 0, 0, 0, 0, Object::ceramic);
      agencies[i][6].create(mv, model_view, 0.0 + 0.0, 0.0 - 0.25, 0.0 - 0.375, SUIT_W*1.0, SUIT_H*1.0, SUIT_D*1.0, AGENCY_R, AGENCY_G, AGENCY_B, 0, 0, 0, 0, 0, 0, Object::ceramic);
      agencies[i][7].create(mv, model_view, 0.0 + 0.0, 0.0 - 0.25, 0.0 + 0.375, SUIT_W*1.0, SUIT_H*1.0, SUIT_D*1.0, AGENCY_R, AGENCY_G, AGENCY_B, 0, 0, 0, 0, 0, 0, Object::ceramic);
      agencies[i][8].create(mv, model_view, 0.0 + 0.25, 0.0 - 0.125, 0.0 + 0.0, TIE_W*1.0, TIE_H*1.0, TIE_D*1.0, AGENCY_R, AGENCY_G, AGENCY_B, 0, 0, 0, 0, 0, 0, Object::ceramic);
      agencies[i][9].create(mv, model_view, 0.0 + 0.0, 0.0 - 0.375, 0.0 - 0.5, APPENDAGE_W*1.0, APPENDAGE_H*1.0, APPENDAGE_D*1.0, AGENCY_R, AGENCY_G, AGENCY_B, 0, 0, 0, 0, 0, 0, Object::ceramic);
      agencies[i][10].create(mv, model_view, 0.0 + 0.0, 0.0 - 0.375, 0.0 + 0.5, APPENDAGE_W*1.0, APPENDAGE_H*1.0, APPENDAGE_D*1.0, AGENCY_R, AGENCY_G, AGENCY_B, 0, 0, 0, 0, 0, 0, Object::ceramic);
      agencies[i][11].create(mv, model_view, 0.0 + 0.0, 0.0 - 1.5, 0.0 - 0.25, APPENDAGE_W*1.0, APPENDAGE_H*1.0, APPENDAGE_D*1.0, AGENCY_R, AGENCY_G, AGENCY_B, 0, 0, 0, 0, 0, 0, Object::ceramic);
      agencies[i][12].create(mv, model_view, 0.0 + 0.0, 0.0 - 1.5, 0.0 + 0.25, APPENDAGE_W*1.0, APPENDAGE_H*1.0, APPENDAGE_D*1.0, AGENCY_R, AGENCY_G, AGENCY_B, 0, 0, 0, 0, 0, 0, Object::ceramic);
    // }
  }

}

// void walls() {
//   for (int i = 0; i < 4; i++) {
//     object(mv, model_view, wall_loc[i].x, wall_loc[i].y+6.5, wall_loc[i].z, wall_size[i].x, wall_size[i].y/8, wall_size[i].z, LON_WALL_R, LON_WALL_G, LON_WALL_B, 0, 0, 0, 0, 0, 0);
//     object(mv, model_view, wall_loc[i].x, wall_loc[i].y-6.5, wall_loc[i].z, wall_size[i].x, wall_size[i].y/8, wall_size[i].z, LON_WALL_R, LON_WALL_G, LON_WALL_B, 0, 0, 0, 0, 0, 0);
//   }
//   for (int i = 4; i < NUM_OBJECTS; i++) {
//     object(mv, model_view, wall_loc[i].x, wall_loc[i].y, wall_loc[i].z, wall_size[i].x, wall_size[i].y, wall_size[i].z, LON_WALL_R, LON_WALL_G, LON_WALL_B, 0, 0, 0, 0, 0, 0);
//   }
//   for (int i = 4; i < NUM_OBJECTS; i++) {
//     object(mv, model_view, wall_loc[i].x, wall_loc[i].y, wall_loc[i].z, wall_size[i].x, wall_size[i].y, wall_size[i].z, LON_WALL_R, LON_WALL_G, LON_WALL_B, 0, 0, 0, 0, 0, 0);
//   }
//   // object(mv, model_view, -50.0,  door_height,  45.0, LON_WALL_W, LON_WALL_H, LON_WALL_D * NUM_TILES - 90.0, LON_WALL_R, LON_WALL_G, LON_WALL_B, 0, 0, 0, 0, 0, 0);
// }

// void roof() {
//   object(mv, model_view, -50.0 + FLOOR_SIZE / 2, 12.5, -50.0 + FLOOR_SIZE / 2, ROOF_W, ROOF_H, ROOF_D, ROOF_R, ROOF_G, ROOF_B, 0, 0, 0, 0, 0, 0);
// }

// void werewolf() {
//   for (int i = 1; i < 4; i++) {
//     object(mv, model_view, werewolves_loc[i].x + 0.0, zombie_height[0] + 0.5, werewolves_loc[i].z + 0.0, ZOMBIE_W*.75, ZOMBIE_H*.75, ZOMBIE_D*.75, ZOMBIE_R, ZOMBIE_G, ZOMBIE_B, 45, 0, 45, 0, 0, 0); // translate down half of the object
//     object(mv, model_view, werewolves_loc[i].x + 0.0, zombie_height[1] + 0.0, werewolves_loc[i].z + 0.0, ZOMBIE_W*1, ZOMBIE_H*1, ZOMBIE_D*1, ZOMBIE_R, ZOMBIE_G, ZOMBIE_B, 0, 0, 0, 0, 0, 0); // translate down half of the object
//     object(mv, model_view, werewolves_loc[i].x + 1.0, zombie_height[2] + 0.0, werewolves_loc[i].z + 0.0, ZOMBIE_W/2, ZOMBIE_H, ZOMBIE_D/2, ZOMBIE_R, ZOMBIE_G, ZOMBIE_B, 0, 0, 0, 0, 0, 0); // translate down half of the object
//     object(mv, model_view, werewolves_loc[i].x - 1.0, zombie_height[3] + 0.0, werewolves_loc[i].z + 0.0, ZOMBIE_W/2, ZOMBIE_H, ZOMBIE_D/2, ZOMBIE_R, ZOMBIE_G, ZOMBIE_B, 0, 0, 0, 0, 0, 0); // translate down half of the object
//     object(mv, model_view, werewolves_loc[i].x + 0.5, zombie_height[4] - 1.0, werewolves_loc[i].z + 0.0, ZOMBIE_W/2, ZOMBIE_H, ZOMBIE_D/2, ZOMBIE_R, ZOMBIE_G, ZOMBIE_B, 0, 0, 0, 0, 0, 0); // translate down half of the object
//     object(mv, model_view, werewolves_loc[i].x - 0.5, zombie_height[5] - 1.0, werewolves_loc[i].z + 0.0, ZOMBIE_W/2, ZOMBIE_H, ZOMBIE_D/2, ZOMBIE_R, ZOMBIE_G, ZOMBIE_B, 0, 0, 0, 0, 0, 0); // translate down half of the object
//   }
// }

// void light() { ;
//   // object(mv, model_view, -50.0,  door_height,  45.0, LON_WALL_W, LON_WALL_H, LON_WALL_D * NUM_TILES - 90.0, LON_WALL_R, LON_WALL_G, LON_WALL_B, 0, 0, 0, 0, 0, 0);
// }

void render_models(/*MatrixStack stack,*/ bool hurt, bool hallucinate, color4 aps[], color4 dps[], color4 sps[], color4 light_ambients[], color4 light_diffuses[], color4 light_speculars[], GLuint ambient_product, GLuint diffuse_product, GLuint specular_product, GLuint ambient_product2, GLuint diffuse_product2, GLuint specular_product2, GLuint enable, float color_a_pink, color4 emissive[], GLuint Material_Emiss, GLuint shiny) {

  if (render_[FLOORS]) {
    for (int i = 0; i < NUM_FLOORS; i++) {
      for (int j = 0; j < PARTS_FLOOR; j++) {
        floors[i][j].render(/*mvstack*/ hurt, hallucinate, aps, dps, sps, light_ambients, light_diffuses, light_speculars, ambient_product, diffuse_product, specular_product, ambient_product2, diffuse_product2, specular_product2, enable, color_a_pink, emissive, Material_Emiss, shiny);
      }
    }
  }

  if (render_[MOONS]) {
    for (int i = 0; i < NUM_MOONS; i++) {
      for (int j = 0; j < PARTS_MOON; j++) {
        moons[i][j].render(/*mvstack*/ hurt, hallucinate, aps, dps, sps, light_ambients, light_diffuses, light_speculars, ambient_product, diffuse_product, specular_product, ambient_product2, diffuse_product2, specular_product2, enable, color_a_pink, emissive, Material_Emiss, shiny);
      }
    }
  }

  if (render_[GUNS]) {
    for (int i = 0; i < NUM_GUNS; i++) {
      for (int j = 0; j < PARTS_GUN; j++) {
        guns[i][j].render(/*mvstack*/ hurt, hallucinate, aps, dps, sps, light_ambients, light_diffuses, light_speculars, ambient_product, diffuse_product, specular_product, ambient_product2, diffuse_product2, specular_product2, enable, color_a_pink, emissive, Material_Emiss, shiny);
      }
    }
  }

  if (render_[KEYS]) {
    for (int i = 0; i < NUM_KEYS; i++) {
      for (int j = 0; j < PARTS_KEY; j++) {
        keys[i][j].render(/*mvstack*/ hurt, hallucinate, aps, dps, sps, light_ambients, light_diffuses, light_speculars, ambient_product, diffuse_product, specular_product, ambient_product2, diffuse_product2, specular_product2, enable, color_a_pink, emissive, Material_Emiss, shiny);
      }
    }
  }

  if (render_[VACCUUMS]) {
    for (int i = 0; i < NUM_VACCUUMS; i++) {
      for (int j = 0; j < PARTS_VACCUUM; j++) {
        vaccuums[i][j].render(/*mvstack*/ hurt, hallucinate, aps, dps, sps, light_ambients, light_diffuses, light_speculars, ambient_product, diffuse_product, specular_product, ambient_product2, diffuse_product2, specular_product2, enable, color_a_pink, emissive, Material_Emiss, shiny);
      }
    }
  }

  if (render_[COFFEES]) {
    for (int i = 0; i < NUM_COFFEES; i++) {
      for (int j = 0; j < PARTS_COFFEE; j++) {
        coffees[i][j].render(/*mvstack*/ hurt, hallucinate, aps, dps, sps, light_ambients, light_diffuses, light_speculars, ambient_product, diffuse_product, specular_product, ambient_product2, diffuse_product2, specular_product2, enable, color_a_pink, emissive, Material_Emiss, shiny);
      }
    }
  }

  if (render_[PLAYERS]) {
    for (int i = 0; i < NUM_PLAYERS; i++) {
      for (int j = 0; j < PARTS_PLAYER; j++) {
        players[i][j].render(/*mvstack*/ hurt, hallucinate, aps, dps, sps, light_ambients, light_diffuses, light_speculars, ambient_product, diffuse_product, specular_product, ambient_product2, diffuse_product2, specular_product2, enable, color_a_pink, emissive, Material_Emiss, shiny);
      }
    }
  }

  if (render_[GHOSTS]) {
    for (int i = 0; i < NUM_GHOSTS; i++) {
      for (int j = 0; j < PARTS_GHOST; j++) {
        ghosts[i][j].render(/*mvstack*/ hurt, hallucinate, aps, dps, sps, light_ambients, light_diffuses, light_speculars, ambient_product, diffuse_product, specular_product, ambient_product2, diffuse_product2, specular_product2, enable, color_a_pink, emissive, Material_Emiss, shiny);
      }
    }
  }

  if (render_[ZOMBIES]) {
    for (int i = 0; i < NUM_ZOMBIES; i++) {
      for (int j = 0; j < PARTS_ZOMBIE; j++) {
        zombies[i][j].render(/*mvstack*/ hurt, hallucinate, aps, dps, sps, light_ambients, light_diffuses, light_speculars, ambient_product, diffuse_product, specular_product, ambient_product2, diffuse_product2, specular_product2, enable, color_a_pink, emissive, Material_Emiss, shiny);
      }
    }
  }

  if (render_[WEREWOLFS]) {
    for (int i = 0; i < NUM_WEREWOLFS; i++) {
      for (int j = 0; j < PARTS_WEREWOLF; j++) {
        werewolfs[i][j].render(/*mvstack*/ hurt, hallucinate, aps, dps, sps, light_ambients, light_diffuses, light_speculars, ambient_product, diffuse_product, specular_product, ambient_product2, diffuse_product2, specular_product2, enable, color_a_pink, emissive, Material_Emiss, shiny);
      }
    }
  }

  if (render_[AGENCIES]) {
    for (int i = 0; i < NUM_AGENCIES; i++) {
      for (int j = 0; j < PARTS_AGENCIE; j++) {
        agencies[i][j].render(/*mvstack*/ hurt, hallucinate, aps, dps, sps, light_ambients, light_diffuses, light_speculars, ambient_product, diffuse_product, specular_product, ambient_product2, diffuse_product2, specular_product2, enable, color_a_pink, emissive, Material_Emiss, shiny);
      }
    }
  }

}

#endif
