#ifndef MODELS_H
#define MODELS_H

#include <Angel.h>
#include "engine.h"

#define FLOORS        0
#define MOONS         1
#include "models/environment.h"
#define NUM_FLOORS    19
Object floors[NUM_FLOORS][PARTS_FLOOR];
#define NUM_MOONS     1
Object moons[NUM_MOONS][PARTS_MOON];


#define PLAYERS       6
#include "models/player.h"
#define NUM_PLAYERS   1
Object players[NUM_PLAYERS][PARTS_PLAYER];


#define BULLETS       11
#define ROCKETS         12
#define HEALTHS        13
#define SHIELDS         14
#include "models/supplies.h"
#define NUM_BULLETS  1
#define NUM_ROCKETS  1
#define NUM_HEALTHS  1
#define NUM_SHIELDS  1
Object bullets[NUM_BULLETS][PARTS_BULLET];
Object rockets[NUM_ROCKETS][PARTS_ROCKET];
Object healths[NUM_HEALTHS][PARTS_HEALTH];
Object shields[NUM_SHIELDS][PARTS_SHIELD];

// #include "models/human.h"



#define AGENCIES      10
#include "models/agency.h"
#define NUM_AGENCIES  1
Object agencies[NUM_AGENCIES][PARTS_AGENCIE];

#define COFFEES       5
#include "models/coffee.h"
#define NUM_COFFEES   1
Object coffees[NUM_COFFEES][PARTS_COFFEE];

#define GHOSTS        7
#include "models/ghost.h"
#define NUM_GHOSTS    1
Object ghosts[NUM_GHOSTS][PARTS_GHOST];

#define GUNS          2
#include "models/gun.h"
#define NUM_GUNS      1
Object guns[NUM_GUNS][PARTS_GUN];

#define KEYS          3
#include "models/key.h"
#define NUM_KEYS      1
Object keys[NUM_KEYS][PARTS_KEY];

#define WEREWOLFS     9
#include "models/robot.h"
#define NUM_WEREWOLFS 1
Object werewolfs[NUM_WEREWOLFS][PARTS_WEREWOLF];

#define VACCUUMS      4
#include "models/vacuum.h"
#define NUM_VACCUUMS  1
Object vaccuums[NUM_VACCUUMS][PARTS_VACCUUM];

#define ZOMBIES       8
#include "models/zombie.h"
#define NUM_ZOMBIES   3
Object zombies[NUM_ZOMBIES][PARTS_ZOMBIE];



bool render_[SHIELDS + 1];



// PICKUPS //

vec3 gun_loc[NUM_GUNS] = {
  vec3(50.0, 10.0, 50.0)
};

vec3 key_loc[NUM_KEYS] = {
  vec3(0.0, -17.5, 0.0)
};

vec3 vacuum_loc[NUM_VACCUUMS] = {
  vec3(-50.0, 10.0, -50.0)
};

vec3 coffee_loc[NUM_COFFEES] = {
  vec3(0.0, 0.0, 0.0)
};

vec3 bullet_loc[NUM_BULLETS] = {
  vec3(0.0, 0.0, 55.0)
};

vec3 rocket_loc[NUM_ROCKETS] = {
  vec3(0.0, 0.0, -55.0)
};

vec3 health_loc[NUM_HEALTHS] = {
  vec3(55.0, 0.0, 0.0)
};

vec3 shield_loc[NUM_SHIELDS] = {
  vec3(-55.0, 0.0, 0.0)
};


GLfloat gun_mult[NUM_GUNS] = { 1.0 },
        key_mult[NUM_KEYS] = { 1.0 },
        vacuum_mult[NUM_VACCUUMS] = { 1.0 },
        coffee_mult[NUM_COFFEES] = { 1.0 },
        bullet_mult[NUM_BULLETS] = { 1.0 },
        rocket_mult[NUM_ROCKETS] = { 1.0 },
        health_mult[NUM_HEALTHS] = { 1.0 },
        shield_mult[NUM_SHIELDS] = { 1.0 };

// ENEMIES //

vec3 ghosts_loc[NUM_GHOSTS] = { vec3(0.0, 0.0, 0.0) };
vec3 zombies_loc[NUM_ZOMBIES] = {
  vec3(10.0, zombie_height[0], 25.0),
  vec3(10.0, zombie_height[0], 35.0),
  vec3(15.0, zombie_height[0], 32.5)
};
vec3 werewolves_loc[NUM_WEREWOLFS] = {
  vec3(10.0, zombie_height[0], 25.0),
};
vec3 agencies_loc[NUM_AGENCIES] = {
  vec3(-51.0, 0.0, 10.0)
};
vec3 ghosts_size[NUM_GHOSTS] = {
  vec3(-17.5, ghost_height[0], -5.0)
};
vec3 zombies_size[NUM_ZOMBIES] = { vec3(0.0, 0.0, 0.0) };
vec3 werewolves_size[NUM_WEREWOLFS] = { vec3(0.0, 0.0, 0.0) };
vec3 agencies_size[NUM_AGENCIES] = { vec3(0.0, 0.0, 0.0) };

GLfloat ghost_theta[NUM_GHOSTS] = { 0.0 };
GLfloat agency_theta[NUM_AGENCIES] = { 0.0 };
GLfloat werewolf_theta[NUM_WEREWOLFS] = { 0.0 };
GLfloat zombie_theta[NUM_ZOMBIES] = { 0.0 };

GLfloat ghost_mult[NUM_GHOSTS] = { 1.0 },
        agency_mult[NUM_AGENCIES] = { 1.0 },
        zombie_mult[NUM_ZOMBIES] = { 1.0, 1.0, 1.0 },
        werewolf_mult[NUM_WEREWOLFS] = { 1.0 };

// void load() {
//     mat4  m;
//     m = RotateY( theta[Torso] );
//     model[Torso] = Object( m, torso, NULL, &model[Head1] );
//     m = Translate(0.0, TORSO_HEIGHT+0.5*HEAD_HEIGHT, 0.0) *
//       RotateX(theta[Head1]) *
//       RotateY(theta[Head2]) *
//       Translate(0.0, -0.5*HEAD_HEIGHT, 0.0);
//     model[Head1] = Object( m, head, &model[LeftUpperArm], NULL );
//     m = Translate(-(TORSO_WIDTH+UPPER_ARM_WIDTH), 0.9*TORSO_HEIGHT, 0.0) *
//       RotateX(theta[LeftUpperArm]);
//     model[LeftUpperArm] = Object( m, left_upper_arm, &model[RightUpperArm], &model[LeftLowerArm] );
//     m = Translate(TORSO_WIDTH+UPPER_ARM_WIDTH, 0.9*TORSO_HEIGHT, 0.0) *
// 	     RotateX(theta[RightUpperArm]);
//     model[RightUpperArm] = Object( m, right_upper_arm, &model[LeftUpperLeg], &model[RightLowerArm] );
//     m = Translate(-(TORSO_WIDTH+UPPER_LEG_WIDTH), 0.1*UPPER_LEG_HEIGHT, 0.0) *
//       RotateX(theta[LeftUpperLeg]);
//     model[LeftUpperLeg] = Object( m, left_upper_leg, &model[RightUpperLeg], &model[LeftLowerLeg] );
//     m = Translate(TORSO_WIDTH+UPPER_LEG_WIDTH, 0.1*UPPER_LEG_HEIGHT, 0.0) *
//       RotateX(theta[RightUpperLeg]);
//     model[RightUpperLeg] = Object( m, right_upper_leg, NULL, &model[RightLowerLeg] );
//     m = Translate(0.0, UPPER_ARM_HEIGHT, 0.0) * RotateX(theta[LeftLowerArm]);
//     model[LeftLowerArm] = Object( m, left_lower_arm, NULL, NULL );
//     m = Translate(0.0, UPPER_ARM_HEIGHT, 0.0) * RotateX(theta[RightLowerArm]);
//     model[RightLowerArm] = Object( m, right_lower_arm, NULL, NULL );
//     m = Translate(0.0, UPPER_LEG_HEIGHT, 0.0) * RotateX(theta[LeftLowerLeg]);
//     model[LeftLowerLeg] = Object( m, left_lower_leg, NULL, NULL );
//     m = Translate(0.0, UPPER_LEG_HEIGHT, 0.0) * RotateX(theta[RightLowerLeg]);
//     model[RightLowerLeg] = Object( m, right_lower_leg, NULL, NULL );
// }

// void traverse( Object node ) {
//   // base case
//   if ( node == NULL ) { return; }
//   // Recursive case, first remember the current transform.
//   mvstack.push( model_view );
//   mv *= node.transform;
//   node.render(mvstack);
//   traverse( node.child );
//   //  if ( node->child != NULL) { traverse( node->child ); }
//   mv = mvstack.pop();
//   traverse( node.sibling );
//   //  if ( node->sibling != NULL) { traverse( node->sibling ); }
// }

void load (mat4 mv, GLuint model_view) {

  // mat4 matr
  // GLuint unif

  // float x // float y // float z
  // float ra // float yax
  // float w // float h // float d
  // float r // float g // float b
  // float pi // float ya // float ro
  // float rta // float rl
  // float sli // float sta // float typ

  // Object::material mat

  // for (int i = 0; i < NUM_FLOORS; i++) {
    for (int j = 0; j < PARTS_FLOOR; j++) {
      floors[0][j].create(mv, model_view, -50.0 + FLOOR_SIZE / 2, -2.5, -50.0 + FLOOR_SIZE / 2, 50.0, ROOF_H, 50.0, ROOF_R, ROOF_G, ROOF_B, 0, 0, 0, 0, 0, 0, Object::wood);

      floors[1][j].create(mv, model_view, 37.5, -2.5, 0.0, ROOF_W / 4, ROOF_H, 10.0, ROOF_R, ROOF_G, ROOF_B, 0, 0, 0, 0, 0, 0, Object::wood);
      floors[2][j].create(mv, model_view, -37.5, -2.5, 0.0, ROOF_W / 4, ROOF_H, 10.0, ROOF_R, ROOF_G, ROOF_B, 0, 0, 0, 0, 0, 0, Object::wood);
      floors[3][j].create(mv, model_view, 0.0, -2.5, 37.5, 10.0, ROOF_H, ROOF_D / 4, ROOF_R, ROOF_G, ROOF_B, 0, 0, 0, 0, 0, 0, Object::wood);
      floors[4][j].create(mv, model_view, 0.0, -2.5, -37.5, 10.0, ROOF_H, ROOF_D / 4, ROOF_R, ROOF_G, ROOF_B, 0, 0, 0, 0, 0, 0, Object::wood);

      floors[5][j].create(mv, model_view, 50.0, 7.5, 50.0, 25.0, ROOF_H, 25.0, ROOF_R, ROOF_G, ROOF_B, 0, 0, 0, 0, 0, 0, Object::wood);
      floors[6][j].create(mv, model_view, -50.0, 7.5, 50.0, 25.0, ROOF_H, 25.0, ROOF_R, ROOF_G, ROOF_B, 0, 0, 0, 0, 0, 0, Object::wood);
      floors[7][j].create(mv, model_view, -50.0, 7.5, -50.0, 25.0, ROOF_H, 25.0, ROOF_R, ROOF_G, ROOF_B, 0, 0, 0, 0, 0, 0, Object::wood);
      floors[8][j].create(mv, model_view, 50.0, 7.5, -50.0, 25.0, ROOF_H, 25.0, ROOF_R, ROOF_G, ROOF_B, 0, 0, 0, 0, 0, 0, Object::wood);

      floors[9][j].create(mv, model_view, 0.0, -10.0, 75.0, ROOF_W, ROOF_H, 20.0, ROOF_R, ROOF_G, ROOF_B, 0, 0, 0, 0, 0, 0, Object::wood);
      floors[10][j].create(mv, model_view, 0.0, -10.0, -75.0, ROOF_W, ROOF_H, 20.0, ROOF_R, ROOF_G, ROOF_B, 0, 0, 0, 0, 0, 0, Object::wood);
      floors[11][j].create(mv, model_view, 75.0, -10.0, 0.0, 20.0, ROOF_H, ROOF_D, ROOF_R, ROOF_G, ROOF_B, 0, 0, 0, 0, 0, 0, Object::wood);
      floors[12][j].create(mv, model_view, -75.0, -10.0, 0.0, 20.0, ROOF_H, ROOF_D, ROOF_R, ROOF_G, ROOF_B, 0, 0, 0, 0, 0, 0, Object::wood);

      floors[13][j].create(mv, model_view, 42.5, -15.0, 0.0, ROOF_W / 4, ROOF_H, 10.0, ROOF_R, ROOF_G, ROOF_B, 0, 0, 0, 0, 0, 0, Object::wood);
      floors[14][j].create(mv, model_view, -42.5, -15.0, 0.0, ROOF_W / 4, ROOF_H, 10.0, ROOF_R, ROOF_G, ROOF_B, 0, 0, 0, 0, 0, 0, Object::wood);
      floors[15][j].create(mv, model_view, 0.0, -15.0, 42.5, 10.0, ROOF_H, ROOF_D / 4, ROOF_R, ROOF_G, ROOF_B, 0, 0, 0, 0, 0, 0, Object::wood);
      floors[16][j].create(mv, model_view, 0.0, -15.0, -42.5, 10.0, ROOF_H, ROOF_D / 4, ROOF_R, ROOF_G, ROOF_B, 0, 0, 0, 0, 0, 0, Object::wood);

      floors[17][j].create(mv, model_view, -50.0 + FLOOR_SIZE / 2, -20.0, -50.0 + FLOOR_SIZE / 2, 10.0, ROOF_H, 10.0, ROOF_R, ROOF_G, ROOF_B, 0, 0, 0, 0, 0, 0, Object::wood);

      floors[18][j].create(mv, model_view, -50.0 + FLOOR_SIZE / 2, 15.0, -50.0 + FLOOR_SIZE / 2, 10.0, ROOF_H, 10.0, ROOF_R, ROOF_G, ROOF_B, 0, 0, 0, 0, 0, 0, Object::wood);
    }
  // }

  // for (int i = 0; i < NUM_MOONS; i++) {
  //   for (int j = 0; j < PARTS_MOON; j++) {
  //     moons[i][j].create(mv, model_view, -75.0,  40.0, -65.0, MOON_W, MOON_H, MOON_D, MOON_R, MOON_G, MOON_B, 0, 0, 0, 6, 6, 2, Object::wood);
  //   }
  // }

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

  for (int i = 0; i < NUM_BULLETS; i++) {
    for (int j = 0; j < PARTS_BULLET; j++) {
  //     guns[i][0].create(mv, model_view, 50 + 0.0*0.2, 10.0 + 0.0*0.2, 50 + -1.0*0.2, BARREL_W*0.2, BARREL_H*0.2, BARREL_D*0.2, BARREL_R, BARREL_G, BARREL_B, 0, 0, 0, 0, 0, 0, Object::metal);
      bullets[i][j].create(mv, model_view, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0, 0, 0, 0, 0, 0, Object::metal);
    }
  }

  for (int i = 0; i < NUM_ROCKETS; i++) {
    for (int j = 0; j < PARTS_ROCKET; j++) {
      rockets[i][j].create(mv, model_view, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0, 0, 0, 0, 0, 0, Object::metal);
    }
  }

  for (int i = 0; i < NUM_HEALTHS; i++) {
    for (int j = 0; j < PARTS_HEALTH; j++) {
      healths[i][j].create(mv, model_view, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0, 0, 0, 0, 0, 0, Object::metal);
    }
  }

  for (int i = 0; i < NUM_SHIELDS; i++) {
    for (int j = 0; j < PARTS_SHIELD; j++) {
      shields[i][j].create(mv, model_view, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0, 0, 0, 0, 0, 0, Object::metal);
    }
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

#endif
