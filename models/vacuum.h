#ifndef VACUUM_M_H
#define VACUUM_M_H

#include <Angel.h>

#define PARTS_VACCUUM 11

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

#endif
