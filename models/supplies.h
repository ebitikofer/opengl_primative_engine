#ifndef AMMO_M_H
#define AMMO_M_H

#include <Angel.h>

#define PARTS_BULLET 1
#define PARTS_ROCKET 1
#define PARTS_HEALTH 1
#define PARTS_SHIELD 1

#define BULLET_W 0.15
#define BULLET_H 0.1
#define BULLET_D 0.1
#define BULLET_R 0.28
#define BULLET_G 0.26
#define BULLET_B 0.1

#define ROCKET_W 0.5
#define ROCKET_H 0.15
#define ROCKET_D 0.15
#define ROCKET_R 0.27
#define ROCKET_G 0.32
#define ROCKET_B 0.17

#define LASER_W 1.0
#define LASER_H 0.05
#define LASER_D 0.05
#define LASER_R 1.0
#define LASER_G 0.25
#define LASER_B 0.75

#define HEALTH_W 1.0
#define HEALTH_H 1.0
#define HEALTH_D 1.0
#define HEALTH_R 0.25
#define HEALTH_G 0.0
#define HEALTH_B 0.0

#define SHIELD_W 1.0
#define SHIELD_H 1.0
#define SHIELD_D 1.0
#define SHIELD_R 0.0
#define SHIELD_G 1.0
#define SHIELD_B 1.0

vec3 bullet_parts_diff[PARTS_BULLET] = {
  vec3(0.0, 0.0, 0.0)
};

vec3 bullet_parts_size[PARTS_BULLET] = {
  vec3(BULLET_W * 5.0, BULLET_H * 5.0, BULLET_D * 5.0),
};

vec3 bullet_parts_colors[PARTS_BULLET] = {
  vec3(BULLET_R, BULLET_G, BULLET_B),
};

vec3 bullet_parts_rot[PARTS_BULLET] = {
  vec3(0.0, 0.0, 0.0)
};

vec3 rocket_parts_diff[PARTS_ROCKET] = {
  vec3(0.0, 0.0, 0.0)
};

vec3 rocket_parts_size[PARTS_ROCKET] = {
  vec3(ROCKET_W * 4.0, ROCKET_H * 4.0, ROCKET_D * 4.0),
};

vec3 rocket_parts_colors[PARTS_ROCKET] = {
  vec3(ROCKET_R, ROCKET_G, ROCKET_B),
};

vec3 rocket_parts_rot[PARTS_ROCKET] = {
  vec3(0.0, 0.0, 0.0)
};

vec3 health_parts_diff[PARTS_HEALTH] = {
  vec3(0.0, 0.0, 0.0)
};

vec3 health_parts_size[PARTS_HEALTH] = {
  vec3(HEALTH_W, HEALTH_H, HEALTH_D),
};

vec3 health_parts_colors[PARTS_HEALTH] = {
  vec3(HEALTH_R, HEALTH_G, HEALTH_B),
};

vec3 health_parts_rot[PARTS_HEALTH] = {
  vec3(0.0, 0.0, 0.0)
};

vec3 shield_parts_diff[PARTS_SHIELD] = {
  vec3(0.0, 0.0, 0.0)
};

vec3 shield_parts_size[PARTS_SHIELD] = {
  vec3(SHIELD_W, SHIELD_H, SHIELD_D),
};

vec3 shield_parts_colors[PARTS_SHIELD] = {
  vec3(SHIELD_R, SHIELD_G, SHIELD_B),
};

vec3 shield_parts_rot[PARTS_SHIELD] = {
  vec3(0.0, 0.0, 0.0)
};

#endif
