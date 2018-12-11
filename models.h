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
#define ROCKETS       12
#define HEALTHS       13
#define SHIELDS       14
#include "models/supplies.h"
#define NUM_BULLETS  1
#define NUM_ROCKETS  1
#define NUM_HEALTHS  1
#define NUM_SHIELDS  1
Object bullets[NUM_BULLETS][PARTS_BULLET];
Object rockets[NUM_ROCKETS][PARTS_ROCKET];
Object healths[NUM_HEALTHS][PARTS_HEALTH];
Object shields[NUM_SHIELDS][PARTS_SHIELD];

#define NUM_BULLET 100

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
Object gun_hud[NUM_GUNS][PARTS_GUN];

#define KEYS          15
#include "models/key.h"
#define NUM_KEYS      1
Object keys[NUM_KEYS][PARTS_KEY];

#define LASERS          16
#include "models/laser.h"
#define NUM_LASERS      1
Object lasers[NUM_LASERS][PARTS_LASER];

#define LAUNCHERS          17
#include "models/launcher.h"
#define NUM_LAUNCHERS      1
Object launchers[NUM_LAUNCHERS][PARTS_LAUNCHER];

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

bool render_[LAUNCHERS + 1];

// PICKUPS //

vec3 gun_loc[NUM_GUNS] = {
  vec3(50.0, 10.0, 50.0)
};

vec3 launcher_loc[NUM_LAUNCHERS] = {
  vec3(-50.0, 10.0, 50.0)
};

vec3 laser_loc[NUM_LASERS] = {
  vec3(50.0, 10.0, -50.0)
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



vec3 key_loc[NUM_KEYS] = {
  vec3(0.0, -17.5, 0.0)
};


vec3 gun_mult[NUM_GUNS] = {
  vec3(1.0, 1.0, 1.0)
};
vec3 launcher_mult[NUM_LAUNCHERS] = {
  vec3(1.0, 1.0, 1.0)
};
vec3 laser_mult[NUM_LASERS] = {
  vec3(1.0, 1.0, 1.0)
};
vec3 vacuum_mult[NUM_VACCUUMS] = {
  vec3(1.0, 1.0, 1.0)
};
vec3 coffee_mult[NUM_COFFEES] = {
  vec3(1.0, 1.0, 1.0)
};
vec3 bullet_mult[NUM_BULLETS] = {
  vec3(1.0, 1.0, 1.0)
};
vec3 rocket_mult[NUM_ROCKETS] = {
  vec3(1.0, 1.0, 1.0)
};
vec3 health_mult[NUM_HEALTHS] = {
  vec3(1.0, 1.0, 1.0)
};
vec3 shield_mult[NUM_SHIELDS] = {
  vec3(1.0, 1.0, 1.0)
};
vec3 key_mult[NUM_KEYS] = {
  vec3(1.0, 1.0, 1.0)
};

// ENEMIES //

vec3 ghosts_loc[NUM_GHOSTS] = { vec3(0.0, 0.0, 0.0) };
vec3 zombies_loc[NUM_ZOMBIES] = {
  vec3(10.0, zombie_height[0], 25.0),
  vec3(10.0, zombie_height[0], 35.0),
  vec3(15.0, zombie_height[0], 32.5)
};
vec3 werewolves_loc[NUM_WEREWOLFS] = {
  vec3(10.0, 10.0, 25.0),
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

vec3 ghost_mult[NUM_GHOSTS] = {
  vec3(1.0, 1.0, 1.0)
};
vec3 agency_mult[NUM_AGENCIES] = {
  vec3(1.0, 1.0, 1.0)
};
vec3 zombie_mult[NUM_ZOMBIES] = {
  vec3(1.0, 1.0, 1.0)
};
vec3 werewolf_mult[NUM_WEREWOLFS] = {
  vec3(1.0, 1.0, 1.0)
};



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

  for (int i = 0; i < NUM_FLOORS; i++) {
    for (int j = 0; j < PARTS_FLOOR; j++) {
      floors[0][j].create(mv, model_view,
        vec3(-50.0 + FLOOR_SIZE / 2, -2.5, -50.0 + FLOOR_SIZE / 2),
        vec3(50.0, ROOF_H, 50.0),
        vec3(ROOF_R, ROOF_G, ROOF_B),
        vec3(0.0, 0.0, 0.0),
        vec3(0.0, 0.0, 0.0),
        0, 0, 0, Object::wood
      );

      floors[1][j].create(mv, model_view,
        vec3(37.5, -2.5, 0.0),
        vec3(ROOF_W / 4, ROOF_H, 10.0),
        vec3(ROOF_R, ROOF_G, ROOF_B),
        vec3(0, 0, 0),
        vec3(0.0, 0.0, 0.0),
        0, 0, 0, Object::wood);
      floors[2][j].create(mv, model_view,
        vec3(-37.5, -2.5, 0.0),
        vec3(ROOF_W / 4, ROOF_H, 10.0),
        vec3(ROOF_R, ROOF_G, ROOF_B),
        vec3(0, 0, 0),
        vec3(0.0, 0.0, 0.0),
        0, 0, 0, Object::wood);
      floors[3][j].create(mv, model_view,
        vec3(0.0, -2.5, 37.5),
        vec3(10.0, ROOF_H, ROOF_D / 4),
        vec3(ROOF_R, ROOF_G, ROOF_B),
        vec3(0, 0, 0),
        vec3(0.0, 0.0, 0.0),
        0, 0, 0, Object::wood);
      floors[4][j].create(mv, model_view,
        vec3(0.0, -2.5, -37.5),
        vec3(10.0, ROOF_H, ROOF_D / 4),
        vec3(ROOF_R, ROOF_G, ROOF_B),
        vec3(0.0, 0.0, 0.0),
        vec3(0, 0, 0),
        0, 0, 0, Object::wood);

      floors[5][j].create(mv, model_view,
        vec3(50.0, 7.5, 50.0),
        vec3(25.0, ROOF_H, 25.0),
        vec3(ROOF_R, ROOF_G, ROOF_B),
        vec3(0.0, 0.0, 0.0),
        vec3(0, 0, 0),
        0, 0, 0, Object::wood);
      floors[6][j].create(mv, model_view,
        vec3(-50.0, 7.5, 50.0),
        vec3(25.0, ROOF_H, 25.0),
        vec3(ROOF_R, ROOF_G, ROOF_B),
        vec3(0.0, 0.0, 0.0),
        vec3( 0, 0, 0),
        0, 0, 0, Object::wood);
      floors[7][j].create(mv, model_view,
        vec3(-50.0, 7.5, -50.0),
        vec3(25.0, ROOF_H, 25.0),
        vec3(ROOF_R, ROOF_G, ROOF_B),
        vec3(0.0, 0.0, 0.0),
        vec3(0, 0, 0),
        0, 0, 0, Object::wood);
      floors[8][j].create(mv, model_view,
        vec3(50.0, 7.5, -50.0),
        vec3(25.0, ROOF_H, 25.0),
        vec3(ROOF_R, ROOF_G, ROOF_B),
        vec3(0.0, 0.0, 0.0),
        vec3(0, 0, 0),
        0, 0, 0, Object::wood);

      floors[9][j].create(mv, model_view,
        vec3(0.0, -10.0, 75.0),
        vec3(ROOF_W, ROOF_H, 20.0),
        vec3(ROOF_R, ROOF_G, ROOF_B),
        vec3(0.0, 0.0, 0.0),
        vec3(0, 0, 0),
        0, 0, 0, Object::wood);
      floors[10][j].create(mv, model_view,
        vec3(0.0, -10.0, -75.0),
        vec3(ROOF_W, ROOF_H, 20.0),
        vec3(ROOF_R, ROOF_G, ROOF_B),
        vec3(0.0, 0.0, 0.0),
        vec3(0, 0, 0),
        0, 0, 0, Object::wood);
      floors[11][j].create(mv, model_view,
        vec3(75.0, -10.0, 0.0),
        vec3(20.0, ROOF_H, ROOF_D),
        vec3(ROOF_R, ROOF_G, ROOF_B),
        vec3(0.0, 0.0, 0.0),
        vec3(0, 0, 0),
        0, 0, 0, Object::wood);
      floors[12][j].create(mv, model_view,
        vec3(-75.0, -10.0, 0.0),
        vec3(20.0, ROOF_H, ROOF_D),
        vec3(ROOF_R, ROOF_G, ROOF_B),
        vec3(0.0, 0.0, 0.0),
        vec3(0, 0, 0),
        0, 0, 0, Object::wood);

      floors[13][j].create(mv, model_view,
        vec3(42.5, -15.0, 0.0),
        vec3(ROOF_W / 4, ROOF_H, 10.0),
        vec3(ROOF_R, ROOF_G, ROOF_B),
        vec3(0.0, 0.0, 0.0),
        vec3(0, 0, 0),
        0, 0, 0, Object::wood);
      floors[14][j].create(mv, model_view,
        vec3(-42.5, -15.0, 0.0),
        vec3(ROOF_W / 4, ROOF_H, 10.0),
        vec3(ROOF_R, ROOF_G, ROOF_B),
        vec3(0.0, 0.0, 0.0),
        vec3(0, 0, 0),
        0, 0, 0, Object::wood);
      floors[15][j].create(mv, model_view,
        vec3(0.0, -15.0, 42.5),
        vec3(10.0, ROOF_H, ROOF_D / 4),
        vec3(ROOF_R, ROOF_G, ROOF_B),
        vec3(0.0, 0.0, 0.0),
        vec3(0, 0, 0),
        0, 0, 0, Object::wood);
      floors[16][j].create(mv, model_view,
        vec3(0.0, -15.0, -42.5),
        vec3(10.0, ROOF_H, ROOF_D / 4),
        vec3(ROOF_R, ROOF_G, ROOF_B),
        vec3(0.0, 0.0, 0.0),
        vec3(0, 0, 0),
        0, 0, 0, Object::wood);

      floors[17][j].create(mv, model_view,
        vec3(-50.0 + FLOOR_SIZE / 2, -20.0, -50.0 + FLOOR_SIZE / 2),
        vec3(10.0, ROOF_H, 10.0),
        vec3(ROOF_R, ROOF_G, ROOF_B),
        vec3(0.0, 0.0, 0.0),
        vec3(0, 0, 0),
        0, 0, 0, Object::wood);

      floors[18][j].create(mv, model_view,
        vec3(-50.0 + FLOOR_SIZE / 2, 15.0, -50.0 + FLOOR_SIZE / 2),
        vec3(10.0, ROOF_H, 10.0),
        vec3(ROOF_R, ROOF_G, ROOF_B),
        vec3(0.0, 0.0, 0.0),
        vec3(0, 0, 0),
        0, 0, 0, Object::wood);
    }
  }

  // for (int i = 0; i < NUM_MOONS; i++) {
  //   for (int j = 0; j < PARTS_MOON; j++) {
  //     moons[i][j].create(mv, model_view,
  // vec3(-75.0,  40.0, -65.0, MOON_W, MOON_H, MOON_D, MOON_R, MOON_G, MOON_B, 0, 0, 0, 6, 6, 2, Object::wood);
  //   }
  // }

  vec3 ghost_parts_diff[PARTS_GHOST] = {
    vec3(ghosts_loc[0].x, ghost_height[0] + 0.5, ghosts_loc[0].z),
    vec3(ghosts_loc[0].x, ghost_height[1] + 0.0, ghosts_loc[0].z),
    vec3(ghosts_loc[0].x + 0.5 * cos(105 * M_PI/180), ghost_height[2] - 1.0, ghosts_loc[0].z + 0.5 * sin(105 * M_PI/180)),
    vec3(ghosts_loc[0].x + 0.5 * cos(225 * M_PI/180), ghost_height[3] - 1.0, ghosts_loc[0].z + 0.5 * sin(225 * M_PI/180)),
    vec3(ghosts_loc[0].x + 0.5 * cos(345 * M_PI/180), ghost_height[4] - 1.0, ghosts_loc[0].z + 0.5 * sin(345 * M_PI/180))
  };

  vec3 ghost_parts_size[PARTS_GHOST] = {
    vec3(ghosts_size[0].x, ghosts_size[0].y, ghosts_size[0].z),
    vec3(ghosts_size[0].x*1.25, ghosts_size[0].y*1.25, ghosts_size[0].z*1.25),
    vec3(ghosts_size[0].x/2, ghosts_size[0].y/2, ghosts_size[0].z/2),
    vec3(ghosts_size[0].x/2, ghosts_size[0].y/2, ghosts_size[0].z/2),
    vec3(ghosts_size[0].x/2, ghosts_size[0].y/2, ghosts_size[0].z/2),
  };

  for (int i = 0; i < NUM_GUNS; i++) {
    for (int j = 0; j < PARTS_GUN; j++) {
      guns[i][j].create(mv, model_view, gun_loc[i], gun_parts_size[j], gun_parts_colors[j], gun_parts_diff[j], vec3(0, 0, 0), 0, 0, 0, Object::metal);
    }
  }
  for (int i = 0; i < NUM_GUNS; i++) {
    for (int j = 0; j < PARTS_GUN; j++) {
      gun_hud[i][j].create(mv, model_view, vec3(0, 0, -10), gun_parts_size[j], gun_parts_colors[j], gun_parts_diff[j], vec3(0, 0, 0), 0, 0, 0, Object::metal);
    }
  }
  for (int i = 0; i < NUM_LAUNCHERS; i++) {
    for (int j = 0; j < PARTS_LAUNCHER; j++) {
      launchers[i][j].create(mv, model_view, launcher_loc[i], launcher_parts_size[j], launcher_parts_colors[j], launcher_parts_diff[j], vec3(0, 0, 0), 0, 0, 0, Object::metal);
    }
  }
  for (int i = 0; i < NUM_LASERS; i++) {
    for (int j = 0; j < PARTS_LASER; j++) {
      lasers[i][j].create(mv, model_view, laser_loc[i], laser_parts_size[j], laser_parts_colors[j], laser_parts_diff[j], vec3(0, 0, 0), 0, 0, 0, Object::metal);
    }
  }
  for (int i = 0; i < NUM_VACCUUMS; i++) {
    for (int j = 0; j < PARTS_VACCUUM; j++) {
      vaccuums[i][j].create(mv, model_view, vacuum_loc[i], vacuum_parts_size[j], vacuum_parts_colors[j], vacuum_parts_diff[j], vec3(0, 0, 0), 0, 0, 0, Object::metal);
    }
  }
  for (int i = 0; i < NUM_COFFEES; i++) {
    for (int j = 0; j < PARTS_COFFEE; j++) {
      coffees[i][j].create(mv, model_view, coffee_loc[i], coffee_parts_size[j], coffee_parts_colors[j], coffee_parts_diff[j], vec3(0, 0, 0), 0, 0, 0, Object::metal);
    }
  }
  for (int i = 0; i < NUM_BULLETS; i++) {
    for (int j = 0; j < PARTS_BULLET; j++) {
      bullets[i][j].create(mv, model_view, bullet_loc[i], bullet_parts_size[j], bullet_parts_colors[j], bullet_parts_diff[j], vec3(0, 0, 0), 0, 0, 0, Object::metal);
    }
  }
  for (int i = 0; i < NUM_ROCKETS; i++) {
    for (int j = 0; j < PARTS_ROCKET; j++) {
      rockets[i][j].create(mv, model_view, rocket_loc[i], rocket_parts_size[j], rocket_parts_colors[j], rocket_parts_diff[j], vec3(0, 0, 0), 0, 0, 0, Object::metal);
    }
  }
  for (int i = 0; i < NUM_HEALTHS; i++) {
    for (int j = 0; j < PARTS_HEALTH; j++) {
      healths[i][j].create(mv, model_view, health_loc[i], health_parts_size[j], health_parts_colors[j], health_parts_diff[j], vec3(0, 0, 0), 0, 0, 0, Object::metal);
    }
  }
  for (int i = 0; i < NUM_SHIELDS; i++) {
    for (int j = 0; j < PARTS_SHIELD; j++) {
      shields[i][j].create(mv, model_view, shield_loc[i], shield_parts_size[j], shield_parts_colors[j], shield_parts_diff[j], vec3(0, 0, 0), 0, 0, 0, Object::metal);
    }
  }
  for (int i = 0; i < NUM_KEYS; i++) {
    for (int j = 0; j < PARTS_KEY; j++) {
      keys[i][j].create(mv, model_view, key_loc[i], key_parts_size[j], key_parts_colors[j], key_parts_diff[j], vec3(0, 0, 0), 0, 0, 0, Object::metal);
    }
  }
  for (int i = 0; i < NUM_GHOSTS; i++) {
    for (int j = 0; j < PARTS_GHOST; j++) {
      ghosts[i][j].create(mv, model_view, ghosts_loc[i], ghost_parts_size[j], ghost_parts_colors[j], ghost_parts_diff[j], vec3(0, 0, 0), 0, 0, 0, Object::metal);
    }
  }
  for (int i = 0; i < NUM_ZOMBIES; i++) {
    for (int j = 0; j < PARTS_ZOMBIE; j++) {
      zombies[i][j].create(mv, model_view, zombies_loc[i], zomb_parts_size[j], zomb_parts_colors[j], zomb_parts_diff[j], vec3(0, 0, 0), 0, 0, 0, Object::metal);
    }
  }
  for (int i = 0; i < NUM_WEREWOLFS; i++) {
    for (int j = 0; j < PARTS_WEREWOLF; j++) {
      werewolfs[i][j].create(mv, model_view, werewolves_loc[i], wolf_parts_size[j], wolf_parts_colors[j], wolf_parts_diff[j], vec3(0, 0, 0), 0, 0, 0, Object::metal);
    }
  }
  for (int i = 0; i < NUM_AGENCIES; i++) {
    for (int j = 0; j < PARTS_AGENCIE; j++) {
      agencies[i][j].create(mv, model_view, agencies_loc[i], agen_parts_size[j], agen_parts_colors[j], agen_parts_diff[j], vec3(0, 0, 0), 0, 0, 0, Object::metal);
    }
  }
  for (int i = 0; i < NUM_PLAYERS; i++) {
    for (int j = 0; j < PARTS_PLAYER; j++) {
      players[i][j].create(mv, model_view, vec3(0.0, 20.0, 0.0), vec3(PLAYER_W, PLAYER_H, PLAYER_D), agen_parts_colors[j], agen_parts_diff[j], vec3(0, 0, 0), 0, 0, 0, Object::metal);
    }
  }

  // for (int i = 0; i < NUM_PLAYERS; i++) {
  //   // for (int j = 0; j < PARTS_GHOST; j++) {
  //     players[i][0].create(mv, model_view,
  // vec3(0.0 + 0.0 * cos((90.0 - 0) * M_PI/180), 5.0 + 1.15, 0.0 + 0.0, HAIR_W, HAIR_H, HAIR_D, AGENCY_R, AGENCY_G, AGENCY_B, 0, -90.0, 0, 0, 0, 0, Object::wood);
  //     players[i][1].create(mv, model_view,
  // vec3(0.0 + 0.0 * cos((90.0 - 0) * M_PI/180), 5.0 + 0.75, 0.0 + 0.0, FACE_W, FACE_H, FACE_D, SKIN_R, SKIN_G, SKIN_B, 0, -90.0, 0, 0, 0, 0, Object::wood);
  //     players[i][2].create(mv, model_view,
  // vec3(0.0 - 0.4 * cos((90.0 - 30) * M_PI/180), 5.0 + 0.75, 0.0 - 0.4 * sin((90.0 - 30) * M_PI/180), LENS_W, LENS_H, LENS_D, AGENCY_R, AGENCY_G, AGENCY_B, 0, -90.0, 0, 0, 0, 0, Object::wood);
  //     players[i][3].create(mv, model_view,
  // vec3(0.0 - 0.4 * cos((90.0 + 30) * M_PI/180), 5.0 + 0.75, 0.0 - 0.4 * sin((90.0 + 30) * M_PI/180), LENS_W, LENS_H, LENS_D, AGENCY_R, AGENCY_G, AGENCY_B, 0, -90.0, 0, 0, 0, 0, Object::wood);
  //     players[i][4].create(mv, model_view,
  // vec3(0.0 - 0.4 * cos((90.0 - 0) * M_PI/180), 5.0 + 0.875, 0.0 - 0.4 * sin(90.0 * M_PI/180), BRIDGE_W, BRIDGE_H, BRIDGE_D, AGENCY_R, AGENCY_G, AGENCY_B, 0, -90.0, 0, 0, 0, 0, Object::wood);
  //     players[i][5].create(mv, model_view,
  // vec3(0.0 + 0.0 * cos((90.0 - 30) * M_PI/180), 5.0 - 0.25, 0.0 + 0.0, SHIRT_W, SHIRT_H, SHIRT_D, SHIRT_R, SHIRT_G, SHIRT_B, 0, -90.0, 0, 0, 0, 0, Object::wood);
  //     players[i][6].create(mv, model_view,
  // vec3(0.0 + 0.1 * cos(90.0 * M_PI/180), 5.0 - 0.25, 0.0 + 0.1 * sin(90.0 * M_PI/180), SHIRT_W, SHIRT_H, SHIRT_D, AGENCY_R, AGENCY_G, AGENCY_B, 0, -90.0, 0, 0, 0, 0, Object::wood);
  //     players[i][7].create(mv, model_view,
  // vec3(0.0 - 0.25 * cos((90.0 - 0) * M_PI/180), 5.0 - 0.125, 0.0 - 0.25 * sin((90.0 - 0) * M_PI/180), TIE_W, TIE_H, TIE_D, AGENCY_R, AGENCY_G, AGENCY_B, 0, -90.0, 0, 0, 0, 0, Object::wood);
  //     players[i][8].create(mv, model_view,
  // vec3(0.0 + 0.375 * cos((90.0 - 90) * M_PI/180), 5.0 - 0.25, 0.0 + 0.375  * sin((90.0 - 90) * M_PI/180), SUIT_W, SUIT_H, SUIT_D, AGENCY_R, AGENCY_G, AGENCY_B, 0, -90.0, 0, 0, 0, 0, Object::wood);
  //     players[i][9].create(mv, model_view,
  // vec3(0.0 + 0.375 * cos((90.0 + 90) * M_PI/180), 5.0 - 0.25, 0.0 + 0.375 * sin((90.0 + 90) * M_PI/180), SUIT_W, SUIT_H, SUIT_D, AGENCY_R, AGENCY_G, AGENCY_B, 0, -90.0, 0, 0, 0, 0, Object::wood);
  //     players[i][10].create(mv, model_view,
  // vec3(0.0 + 0.5 * cos((90.0 - 90) * M_PI/180), 5.0 - 0.375, 0.0 + 0.5 * sin((90.0 - 90) * M_PI/180), APPENDAGE_W, APPENDAGE_H, APPENDAGE_D, AGENCY_R, AGENCY_G, AGENCY_B, 0, -90.0, 0, 0, 0, 0, Object::wood);
  //     players[i][11].create(mv, model_view,
  // vec3(0.0 + 0.5 * cos((90.0 + 90) * M_PI/180), 5.0 - 0.375, 0.0 + 0.5 * sin((90.0 + 90) * M_PI/180), APPENDAGE_W, APPENDAGE_H, APPENDAGE_D, AGENCY_R, AGENCY_G, AGENCY_B, 0, -90.0, 0, 0, 0, 0, Object::wood);
  //     players[i][12].create(mv, model_view,
  // vec3(0.0 + 0.25 * cos((90.0 - 90) * M_PI/180), 5.0 - 1.5, 0.0 + 0.25 * sin((90.0 - 90) * M_PI/180), APPENDAGE_W, APPENDAGE_H, APPENDAGE_D, AGENCY_R, AGENCY_G, AGENCY_B, 0, -90.0, 0, 0, 0, 0, Object::wood);
  //     players[i][13].create(mv, model_view,
  // vec3(0.0 + 0.25 * cos((90.0 + 90) * M_PI/180), 5.0 - 1.5, 0.0 + 0.25 * sin((90.0 + 90) * M_PI/180), APPENDAGE_W, APPENDAGE_H, APPENDAGE_D, AGENCY_R, AGENCY_G, AGENCY_B, 0, -90.0, 0, 0, 0, 0, Object::wood);
  //   // }
  // }

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



// for (int i = 0; i < NUM_GHOSTS; i++) {
//   // for (int j = 0; j < PARTS_GHOST; j++) {
      // void character() {
      //   object(mv, model_view, mv_pos.x + 0.0, mv_pos.y + 1.15, mv_pos.z + 0.0, HAIR_W, HAIR_H, HAIR_D, AGENCY_R, AGENCY_G, AGENCY_B, 0, -theta, 0, 0, 0, 0); // translate down half of the object
      //   object(mv, model_view, mv_pos.x + 0.0, mv_pos.y + 0.75, mv_pos.z + 0.0, FACE_W, FACE_H, FACE_D, SKIN_R, SKIN_G, SKIN_B, 0, -theta, 0, 0, 0, 0); // translate down half of the object
      //   object(mv, model_view, mv_pos.x - 0.4 * cos((theta - 30) * M_PI/180), mv_pos.y + 0.75, mv_pos.z - 0.4 * sin((theta - 30) * M_PI/180), LENS_W, LENS_H, LENS_D, AGENCY_R, AGENCY_G, AGENCY_B, 0, -theta, 0, 0, 0, 0); // translate down half of the object
      //   object(mv, model_view, mv_pos.x - 0.4 * cos((theta + 30) * M_PI/180), mv_pos.y + 0.75, mv_pos.z - 0.4 * sin((theta + 30) * M_PI/180), LENS_W, LENS_H, LENS_D, AGENCY_R, AGENCY_G, AGENCY_B, 0, -theta, 0, 0, 0, 0); // translate down half of the object
      //   object(mv, model_view, mv_pos.x - 0.4 * cos(theta * M_PI/180), mv_pos.y + 0.875, mv_pos.z - 0.4 * sin(theta * M_PI/180), BRIDGE_W, BRIDGE_H, BRIDGE_D, AGENCY_R, AGENCY_G, AGENCY_B, 0, -theta, 0, 0, 0, 0); // translate down half of the object
      //   object(mv, model_view, mv_pos.x + 0.0, mv_pos.y - 0.25, mv_pos.z + 0.0, SHIRT_W, SHIRT_H, SHIRT_D, SHIRT_R, SHIRT_G, SHIRT_B, 0, -theta, 0, 0, 0, 0); // translate down half of the object
      //   object(mv, model_view, mv_pos.x + 0.1 * cos(theta * M_PI/180), mv_pos.y - 0.25, mv_pos.z + 0.1 * sin(theta * M_PI/180), SHIRT_W, SHIRT_H, SHIRT_D, AGENCY_R, AGENCY_G, AGENCY_B, 0, -theta, 0, 0, 0, 0); // translate down half of the object
      //   object(mv, model_view, mv_pos.x - 0.25 * cos((theta - 0) * M_PI/180), mv_pos.y - 0.125, mv_pos.z - 0.25 * sin((theta - 0) * M_PI/180), TIE_W, TIE_H, TIE_D, AGENCY_R, AGENCY_G, AGENCY_B, 0, -theta, 0, 0, 0, 0); // translate down half of the object
      //   object(mv, model_view, mv_pos.x + 0.375 * cos((theta - 90) * M_PI/180), mv_pos.y - 0.25, mv_pos.z + 0.375  * sin((theta - 90) * M_PI/180), SUIT_W, SUIT_H, SUIT_D, AGENCY_R, AGENCY_G, AGENCY_B, 0, -theta, 0, 0, 0, 0); // translate down half of the object
      //   object(mv, model_view, mv_pos.x + 0.375 * cos((theta + 90) * M_PI/180), mv_pos.y - 0.25, mv_pos.z + 0.375 * sin((theta + 90) * M_PI/180), SUIT_W, SUIT_H, SUIT_D, AGENCY_R, AGENCY_G, AGENCY_B, 0, -theta, 0, 0, 0, 0); // translate down half of the object
      //   object(mv, model_view, mv_pos.x + 0.5 * cos((theta - 90) * M_PI/180), mv_pos.y - 0.375, mv_pos.z + 0.5 * sin((theta - 90) * M_PI/180), APPENDAGE_W, APPENDAGE_H, APPENDAGE_D, AGENCY_R, AGENCY_G, AGENCY_B, 0, -theta, 0, 0, 0, 0); // translate down half of the object
      //   object(mv, model_view, mv_pos.x + 0.5 * cos((theta + 90) * M_PI/180), mv_pos.y - 0.375, mv_pos.z + 0.5 * sin((theta + 90) * M_PI/180), APPENDAGE_W, APPENDAGE_H, APPENDAGE_D, AGENCY_R, AGENCY_G, AGENCY_B, 0, -theta, 0, 0, 0, 0); // translate down half of the object
      //   object(mv, model_view, mv_pos.x + 0.25 * cos((theta - 90) * M_PI/180), mv_pos.y - 1.5, mv_pos.z + 0.25 * sin((theta - 90) * M_PI/180), APPENDAGE_W, APPENDAGE_H, APPENDAGE_D, AGENCY_R, AGENCY_G, AGENCY_B, 0, -theta, 0, 0, 0, 0); // translate down half of the object
      //   object(mv, model_view, mv_pos.x + 0.25 * cos((theta + 90) * M_PI/180), mv_pos.y - 1.5, mv_pos.z + 0.25 * sin((theta + 90) * M_PI/180), APPENDAGE_W, APPENDAGE_H, APPENDAGE_D, AGENCY_R, AGENCY_G, AGENCY_B, 0, -theta, 0, 0, 0, 0); // translate down half of the object
      // }
//   // }
// }

#endif
