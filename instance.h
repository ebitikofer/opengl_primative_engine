#ifndef INSTANCE_H
#define INSTANCE_H

#include <Angel.h>
#include "engine.h"
#include "utility.h"
#include "game.h"
#include "models.h"

#define SKY_R 0.1
#define SKY_G 0.0
#define SKY_B 0.05
// #define SKY_R 0.05
// #define SKY_G 0.0
// #define SKY_B 0.1
// vec3 sky = vec3(0.8, 1.0, 1.0);

#define COLOR_SKY 1

// Motion rates
#define RATE_PLAYER	  0.5
#define RATE_GUN	    1

// Color vec3s
vec3 sky = vec3(SKY_R, SKY_G, SKY_B);

std::uniform_real_distribution<double> dist_x(-7.0, 7.0);
std::uniform_real_distribution<double> dist_z(-10.0, -6.0);
std::uniform_real_distribution<double> sickness(0.0, 0.005);

// Game object locations
vec3 player = vec3(0.0, 0.0, 6.0);

vec3 ghosts_loc[NUM_GHOSTS] = { vec3(0.0, 0.0, 0.0) };
vec3 zombies_loc[NUM_ZOMBIES] = { vec3(0.0, 0.0, 0.0) };
vec3 werewolves_loc[NUM_WEREWOLFS] = { vec3(0.0, 0.0, 0.0) };
vec3 agencies_loc[NUM_AGENCIES] = { vec3(1.0, 1.0, 1.0) };
vec3 ghosts_size[NUM_GHOSTS] = { vec3(0.0, 0.0, 0.0) };
vec3 zombies_size[NUM_ZOMBIES] = { vec3(0.0, 0.0, 0.0) };
vec3 werewolves_size[NUM_WEREWOLFS] = { vec3(0.0, 0.0, 0.0) };
vec3 agencies_size[NUM_AGENCIES] = { vec3(0.0, 0.0, 0.0) };
vec3 pickup_size[NUM_PICKUPS] = { vec3(0.0, 0.0, 0.0) };

GLfloat ghost_theta[NUM_GHOSTS] = { 0.0 };
GLfloat agency_theta[NUM_AGENCIES] = { 0.0 };
GLfloat werewolf_theta[NUM_WEREWOLFS] = { 0.0 };
GLfloat zombie_theta[NUM_ZOMBIES] = { 0.0 };

GLfloat disp_rot = 0.0;

float display_rot = 0.0;

bool fire_gun = false, reload = true, action = false;
float elevation = 0.0, frame = 3.0;
int score = 0, health = 5, shield = 7, clip = 7;
bool solid_part = true, game_over = false;

GLfloat ghost_height[5] = { 0.0 },
        zombie_height[6] = { 0.0 },
        bullet_dist[NUM_BULLETS];

GLfloat gun_mult = 1.0,
        key_mult = 1.0,
        vacuum_mult = 1.0,
        coffee_mult = 1.0,
        ghost_mult = 1.0,
        agency_mult = 1.0,
        zombie_mult[NUM_ZOMBIES] = { 1.0, 1.0, 1.0 },
        werewolf_mult[NUM_WEREWOLFS] = { 1.0 },
        speed_boost = 1.0;

vec3 zombie_loc[NUM_ZOMBIES] = {
  vec3(10.0, zombie_height[0], 25.0),
  vec3(10.0, zombie_height[0], 35.0),
  vec3(15.0, zombie_height[0], 32.5)
};

vec3 werewolf_loc[NUM_WEREWOLFS] = {
  vec3(10.0, zombie_height[0], 25.0),
};

vec3 bullet[NUM_BULLETS] = { vec3(0.0, 0.0, 0.0) };
vec3 bullet_size = vec3(BULLET_W, BULLET_H, BULLET_D);
vec3 bullet_color = vec3(0.28, 0.26, 0.1);
GLfloat bullet_speed = 1.0;

vec3 agency_loc = vec3(-51.0, 0.0, 10.0),
     ghost_loc = vec3(-17.5, ghost_height[0], -5.0),
     picture_loc = vec3(12.5, 0.0, -1.0);

int  bullet_ang[NUM_BULLETS] = { 0 };

bool debug = false,
     view_toggle = true,
     debug_toggle = true,
     werewolf_chase = false,
     ghost_chase = false,
     agency_chase = false,
     zombie_chase = false,
     get_gun = false,
     get_vaccuum = false,
     get_coffee = false,
     get_key = false,
     kill_ghost = false,
     active[NUM_BULLETS] = { false },
     sweep_ghost = false;

bool rooms[NUM_ROOMS] = { false };
bool displayed[NUM_ROOMS] = { false };
vec4 bounds[NUM_ROOMS] = {
  vec4(0.0, -25.0, 0.0, -25.0),
  vec4(0.0, -25.0, 25.0, 0.0),
  vec4(25.0, 0.0, 0.0, -25.0),
  vec4(25.0, 0.0, 25.0, 0.0),
  // vec4(-25.0, -50.0, 40.0, 0.0),
  // vec4(-25.0, -50.0, 0.0, -50.0),
  // vec4(0.0, -25.0, 0.0, -50.0),
  // vec4(25.0, 0.0, 0.0, -25.0),
  vec4(25.0, 0.0, -25.0, -50.0),
  vec4(50.0, 25.0, -25.0, -50.0),
  vec4(50.0, 25.0, 20.0, -25.0),
  vec4(25.0, -12.5, 40.0, 0.0),
  vec4(50.0, 25.0, 40.0, 25.0),
  vec4(50.0, -50.0, 50.0, 40.0)
};

void set_room(GLfloat x, GLfloat y, GLfloat z, GLfloat w, GLfloat h, GLfloat d){
  for (int i = 0; i < NUM_ROOMS; i++) {
    if (x - w / 2 < bounds[i].x &&
        x + w / 2 > bounds[i].y &&
        z - d / 2 < bounds[i].z &&
        z + d / 2 > bounds[i].w ) {
      if (!displayed[i]) {
        std::cout << "ROOM" << (i + 1) << std::endl;
        displayed[i] = true;
      } else {
      }
      rooms[i] = true;
    } else {
      displayed[i] = false;
      rooms[i] = false;
    }
  }
}

void check_keys() {

  for (int i = 0; i < 256; i++) {
    if (key_buffer[i]){
      switch (i) {
        case 033: { } break; // Escape Key
        case 'Q': exit(EXIT_SUCCESS); break; // Quit
        case 'w': { mv_vel.z -= speed_boost * sin(theta*M_PI/180)/2; mv_vel.x -= speed_boost * cos(theta*M_PI/180)/2; } break;
        case 's': { mv_vel.z += speed_boost * sin(theta*M_PI/180)/2; mv_vel.x += speed_boost * cos(theta*M_PI/180)/2; } break;
        case 'a': { mv_vel.x -= speed_boost * sin(theta*M_PI/180)/2; mv_vel.z += speed_boost * cos(theta*M_PI/180)/2; } break;
        case 'd': { mv_vel.x += speed_boost * sin(theta*M_PI/180)/2; mv_vel.z -= speed_boost * cos(theta*M_PI/180)/2; } break;
        case ' ': { if (!fall) jump = true; } break; // Action
        case 'f': { action = true; } break; // Action
        case '/': { if (reload) { fire_gun = true; reload = false; } } break; // Shoot
        case '1': { if (get_gun) { bullet_size = vec3(BULLET_W, BULLET_H, BULLET_D); bullet_color = vec3(0.28, 0.26, 0.1); bullet_speed = 1.0; } } break; // Weapon 1
        case '2': { if (get_gun) { bullet_size = vec3(ROCKET_W, ROCKET_H, ROCKET_D); bullet_color = vec3(0.27, 0.32, 0.17); bullet_speed = 0.5; } } break; // Weapon 2
        case '3': { if (get_gun) { bullet_size = vec3(LASER_W, LASER_H, LASER_D); bullet_color = vec3(1.0, 0.25, 0.75); bullet_speed = 2.5; } } break; // Weapon 3
        case 'c': if (view_toggle) { perspective = !perspective; view_toggle = false; } break; //fire
        // Utility
        case '-': /* lights[0] = !lights[0]; glUniform1i(Lights[0], lights[0]); */ health -= 1; break;
        case '=': /* lights[1] = !lights[1]; glUniform1i(Lights[1], lights[1]); */ health += 1; break;
        case 'W': { solid_part = !solid_part; } break; //wire
        case 'z': zNear *= 1.1; zFar /= 1.1; break;
        case 'Z': zNear /= 1.1; zFar *= 1.1; break;
        case 'r': radius *= 1.5; break;
        case 'R': radius /= 1.5; break;
        case 'v': fovy -= 5; if (fovy < 0) { fovy = 1; } break;
        case 'V': fovy += 5; /* break; */ if (fovy > 179) { fovy = 179; } break;
        case '~': zNear = 0.1; zFar = 300.0; radius = 3.0; theta = 0.0; phi = 0.0; break; // reset
        case '`': if (debug_toggle) { debug = !debug; debug_toggle = false; } break;
        default: { } break; // Default

      }
    } else {
      switch (i) {
        case '/': fire_gun = false; break; // Stop firing, not the same as bullet landing
        case ' ': { jump = false; } break; //wire
        case 'f': { action = false; } break; //wire
        case 'c': { view_toggle = true; } break; //fire
        case '`': { debug_toggle = true; } break; //fire
      }
    }

    if (spec_buffer[i]) {
      switch (i) {
        case GLUT_KEY_RIGHT: theta += dr; break; // Look angle right
        case GLUT_KEY_LEFT:  theta -= dr; break; // Look angle left
        case GLUT_KEY_DOWN:  phi += dr;   break; // Look angle down
        case GLUT_KEY_UP:    phi -= dr;   break; // Look angle up
      }
    }
  }

}

void chase(vec3 &chaser, vec3 chasee, float &chaser_theta, float speed) {

  float x_len = 0, y_len = 0;

  if (chaser.x != chasee.x) {
    if (chaser.x - chasee.x < 0) { chaser.x += speed; }
    if (chaser.x - chasee.x > 0) { chaser.x -= speed; }
  }
  if (chaser.z != chasee.z) {
    if (chaser.z - chasee.z < 0) { chaser.z += speed; }
    if (chaser.z - chasee.z > 0) { chaser.z -= speed; }
  }

  x_len = chaser.x - chasee.x;
  y_len = chaser.z - chasee.z;

  chaser_theta = -(atan(x_len/(y_len + 0.01)) * 180 / M_PI) + 90;

}

void move_and_face(Object &actor, vec3 loc, vec3 size, vec3 growth, vec3 color, vec3 center_loc, vec3 rot) {
  actor.update(
    vec3(loc.x + center_loc.z * cos((rot.y + center_loc.x) * M_PI/180), loc.y + center_loc.y, loc.z + center_loc.z * sin((rot.y + center_loc.x) * M_PI/180)),
    vec3(size.x * growth.x, size.y * growth.y, size.z * growth.z),
    vec3(color.x, color.y, color.z),
    vec3(rot.x, -rot.y, rot.z)
  );
}

void update_everything() {

  pickup_size[4] = vec3(1.0, 1.0, 1.0);
  pickup_size[5] = vec3(2.5, 1.0, 2.5);
  pickup_size[6] = vec3(2.5, 1.0, 2.5);
  pickup_size[7] = vec3(2.5, 1.0, 2.5);

  for (int i = 0; i < NUM_GUNS; i++) {
    for (int j = 0; j < PARTS_GUN; j++) {
      move_and_face(
        guns[i][j],
        gun_loc[i],
        gun_parts_size[j],
        vec3(gun_mult, gun_mult, gun_mult),
        gun_parts_colors[j],
        gun_parts_diff[j],
        vec3(0, display_rot, 0)
      );
    }
  }

  for (int i = 0; i < NUM_KEYS; i++) {
    for (int j = 0; j < PARTS_KEY; j++) {
      move_and_face(
        keys[i][j],
        key_loc[i],
        key_parts_size[j],
        vec3(key_mult, key_mult, key_mult),
        key_parts_colors[j],
        key_parts_diff[j],
        vec3(0, display_rot, 0)
      );
    }
  }

  for (int i = 0; i < NUM_VACCUUMS; i++) {
    for (int j = 0; j < PARTS_VACCUUM; j++) {
      move_and_face(
        vaccuums[i][j],
        vacuum_loc[i],
        vacuum_parts_size[j],
        vec3(vacuum_mult, vacuum_mult, vacuum_mult),
        vacuum_parts_colors[j],
        vacuum_parts_diff[j],
        vec3(0, display_rot, 0)
      );
    }
  }

  vec3 coffee_parts_rot[PARTS_COFFEE] = {
    vec3(0.0, display_rot - 45.0, 0.0),
    vec3(0.0, display_rot, 0.0),
    vec3(0.0, display_rot - 45.0, 0.0),
    vec3(0.0, display_rot, 0.0),
    vec3(0.0, display_rot - 45.0, 0.0),
    vec3(0.0, display_rot, 0.0)
  };

  for (int i = 0; i < NUM_COFFEES; i++) {
    for (int j = 0; j < PARTS_COFFEE; j++) {
      move_and_face(
        coffees[i][j],
        coffee_loc[i],
        coffee_parts_size[j],
        vec3(coffee_mult, coffee_mult, coffee_mult),
        coffee_parts_colors[j],
        coffee_parts_diff[j],
        coffee_parts_rot[j]
      );
    }
  }

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

  ghosts_loc[0] = vec3(ghost_loc.x*ghost_mult, ghost_height[0]*ghost_mult, ghost_loc.z*ghost_mult);
  ghosts_size[0] = vec3(GHOST_W*ghost_mult, GHOST_H*ghost_mult, GHOST_D*ghost_mult);

  for (int i = 0; i < NUM_GHOSTS; i++) {
    for (int j = 0; j < PARTS_GHOST; j++) {
      move_and_face(
        ghosts[i][j],
        ghost_loc[i],
        ghost_parts_size[j],
        vec3(ghost_mult, ghost_mult, ghost_mult),
        ghost_parts_colors[j],
        ghost_parts_diff[j],
        vec3(ghost_parts_rot[j].x, ghost_theta[i], ghost_parts_rot[j].z)
      );
    }
  }

  zombies_loc[0] = vec3(zombie_loc[0].x*zombie_mult[0], zombie_height[0]*zombie_mult[0], zombie_loc[0].z*zombie_mult[0]);
  zombies_loc[1] = vec3(zombie_loc[1].x*zombie_mult[1], zombie_height[0]*zombie_mult[1], zombie_loc[1].z*zombie_mult[1]);
  zombies_loc[2] = vec3(zombie_loc[2].x*zombie_mult[2], zombie_height[0]*zombie_mult[2], zombie_loc[2].z*zombie_mult[2]);

  for(int i = 0; i < NUM_ZOMBIES; i++) {
    zombies_size[i] = vec3(ZOMBIE_W*zombie_mult[i], ZOMBIE_H*zombie_mult[i], ZOMBIE_D*zombie_mult[i]);
  }

  for (int i = 0; i < NUM_ZOMBIES; i++) {
    for (int j = 0; j < PARTS_ZOMBIE; j++) {
      move_and_face(
        zombies[i][j],
        zombies_loc[i],
        zomb_parts_size[j],
        vec3(zombie_mult[i], zombie_mult[i], zombie_mult[i]),
        zomb_parts_colors[j],
        zomb_parts_diff[j],
        vec3(0, zombie_theta[i], 0)
      );
    }
  }

  werewolves_loc[0] = vec3(werewolf_loc[0].x*werewolf_mult[0], werewolf_loc[0].y*werewolf_mult[0], werewolf_loc[0].z*werewolf_mult[0]);
  // werewolfs_size[2] = vec3(ZOMBIE_W*werewolf_mult[2], ZOMBIE_H*werewolf_mult[2], ZOMBIE_D*werewolf_mult[2]);

  for (int i = 0; i < NUM_WEREWOLFS; i++) {
    for (int j = 0; j < PARTS_WEREWOLF; j++) {
      move_and_face(
        werewolfs[i][j],
        werewolves_loc[i],
        wolf_parts_size[j],
        vec3(werewolf_mult[i], werewolf_mult[i], werewolf_mult[i]),
        wolf_parts_colors[j],
        wolf_parts_diff[j],
        vec3(0, werewolf_theta[i], 0)
      );
    }
  }

  agencies_loc[0] = vec3(agency_loc.x, agency_loc.y, agency_loc.z);

  for (int i = 0; i < NUM_AGENCIES; i++) {
    for (int j = 0; j < PARTS_AGENCIE; j++) {
      move_and_face(
        agencies[i][j],
        agencies_loc[i],
        agen_parts_size[j],
        vec3(agency_mult, agency_mult, agency_mult),
        agen_parts_colors[j],
        agen_parts_diff[j],
        vec3(0, agency_theta[i], 0)
      );
    }
  }

}

// animation function, runs the updating of the variables
void animation(void) {

  static GLint lasttime = glutGet(GLUT_ELAPSED_TIME);
  GLint time = glutGet(GLUT_ELAPSED_TIME);

  // mv_vel = vec3(0.0, 0.0, 0.0);
  mv_vel.x = 0.0;
  mv_vel.z = 0.0;

  set_room(mv_pos.x, 0.0, mv_pos.z, PLAYER_W, PLAYER_H, PLAYER_D);

  check_keys();

  // if (rotatep) move_angle += 20.0 / 1000.0 * (time - lasttime);

  // doorAngle += doorAngleIncr / 1000.0 * (time - lasttime);

  // if (doorAngle > 60.0) doorAngleIncr *= -1.0;

  // if (doorAngle < 0.0) { doorAngle = 0.0; doorAngleIncr *= -1.0; }

  // // Do the animation code here in idle, not in display. Code for moving 2nd cube

  // trans += transinc / 1000.0 * ( time - lasttime );

  // if (trans > 1.5) { trans = 1.5; transinc *= -1; }

  // if (trans < -1.5) { trans = -1.5; transinc *= -1; }

  static int step;

  if (pickup[0]) { get_gun = true; }
  if (pickup[1]) { get_vaccuum = true; }
  if (pickup[2]) { get_key = true; }
  if (pickup[3]) { get_coffee = true; }

  if (rooms[0]) { agency_chase = true; }
  else { agency_chase = false; }

  if (rooms[1]) { werewolf_chase = true; }
  else { werewolf_chase = false; }

  if (rooms[2]) { ghost_chase = true; }
  else { ghost_chase = false; }

  if (rooms[3]) { zombie_chase = true; }
  else { zombie_chase = false; }

  if (frame >= 0.0 && frame <= 360.0) {
    if (step == 0 || step == 2) {

      if (frame == 0.0) frame = 1.0;
      if (frame == 360) step++;
      if (frame < 360) frame = frame + 1.0;
      for (int i = 0; i < 5; i++){
        ghost_height[i] = sin((frame - i)*M_PI/30);
      }

      display_rot = frame;
      // display_rot += 0.1;
      // if (display_rot > 359.9) {
      //   display_rot = 0.0;
      // }

    } else if (step == 1 || step == 3) {

      if (frame == 0.0) step++;
      if (frame > 0) frame = frame - 1.0;
      for (int i = 0; i < 5; i++){
        ghost_height[i] = -sin((frame - i)*M_PI/30);
      }

      display_rot = -frame;

    }

  }

  if (step == 4) step = 0;

  if (health == 0) death = true;

  if (ghost_chase) { chase(ghost_loc, mv_pos, ghost_theta[0], 0.1); }

  if (agency_chase) { chase(agency_loc, mv_pos, agency_theta[0], 0.1); }

  if (werewolf_chase) { chase(werewolf_loc[0], mv_pos, werewolf_theta[0], 0.05); }

  if (zombie_chase) {
    for (int i = 0; i < NUM_ZOMBIES; i++) {
        chase(zombie_loc[i], mv_pos, zombie_theta[i], (i + 1) * 0.05);
    }
  }

  if (get_vaccuum) {
    if (g_die[0]) kill_ghost = true;
  } else {
    if (g_die[0]) {
      health--;
      hurt = true;
    } // exit(EXIT_FAILURE);
  }

  if (kill_ghost) {
    if (ghost_mult >= 0.0) {
      ghost_mult -= 0.01;
    }
  }

  if (get_key) { exit(EXIT_SUCCESS); }

  if (get_gun) {
    for (int i = 0; i < NUM_ZOMBIES; i++) {
      if (z_die[i]) {
        if (zombie_mult[i] >= 0.0) {
          zombie_mult[i] -= 0.01;
        }
      }
    }
    for (int i = 0; i < NUM_WEREWOLFS; i++) {
      if (w_die[i]) {
        if (werewolf_mult[i] >= 0.0) {
          werewolf_mult[i] -= 0.01;
        }
      }
    }
    for (int i = 0; i < NUM_AGENCIES; i++) {
      if (a_die[i]) {
        if (agency_mult >= 0.0) {
          agency_mult -= 0.01;
        }
      }
    }
    if (fire_gun) {
      // reload = false;
      for (int i = 0; i < NUM_BULLETS; i++) {
        if (!active[i]) {
          active[i] = true;
          bullet[i] = vec3(mv_pos.x, mv_pos.y, mv_pos.z);
          bullet_ang[i] = theta;
          bullet_dist[i] = 0.0;
          break;
        }
      }
    } else {
      reload = true;
    }
  }

  if (p_die) {
    health--;
    hurt = true;
  }// exit(EXIT_FAILURE);

  if(hurt) {
    mv_vel.z += 20.0 * sin(theta*M_PI/180)/2;
    mv_vel.x += 20.0 * cos(theta*M_PI/180)/2;
  }

  if (get_coffee) { speed_boost = 2.0; }

  title_bar = " X: " + std::to_string(mv_pos.x)
            + " Y: " + std::to_string(mv_pos.y)
            + " Z: " + std::to_string(mv_pos.z);
            // 0.01 * (time - lasttime)); // + " l:" + std::to_string(l) + " r:" + std::to_string(r) + " f:" + std::to_string(f) + " b:" + std::to_string(b);

  if (mouse_button == 3 && changed) { fovy -= 5.0; changed = false; } else if (mouse_button == 4 && changed) { fovy += 5.0; changed = false; }

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

  update_everything();

  if (!fall) { mv_vel.y = 0.0; }

  if (jump) {
    mv_vel.y += 0.75;
    jump = false;
    fall = true;
  }

  mv_vel.y -= 0.015;

  if (mv_pos.y < -300.0) { exit(EXIT_SUCCESS); }

  for (int i = 0; i < NUM_FLOORS; i++) {
    for (int j = 0; j < PARTS_FLOOR; j++) {
      collision(mv_pos.x, mv_pos.y, mv_pos.z, PLAYER_W, PLAYER_H, PLAYER_D, vec3(floors[i][j].x, floors[i][j].y, floors[i][j].z), vec3(floors[i][j].w, floors[i][j].h, floors[i][j].d), collide[i]);
    }
  }

  if(!debug) {
    // for (int i = 0; i < NUM_OBJECTS; i++) {
      // collision(mv_pos.x, mv_pos.y, mv_pos.z, PLAYER_W, PLAYER_H, PLAYER_D, wall_loc[i], wall_size[i], collide[i]);
    // }
    for (int i = 0; i < NUM_GHOSTS; i++) {
      collision(mv_pos.x, mv_pos.y, mv_pos.z, PLAYER_W, PLAYER_H, PLAYER_D, ghosts_loc[0], ghosts_size[0], g_die[0]);
    }
    for (int i = 0; i < NUM_ZOMBIES; i++) {
      collision(mv_pos.x, mv_pos.y, mv_pos.z, PLAYER_W, PLAYER_H, PLAYER_D, zombies_loc[i], zombies_size[i], p_die);
    }
    for (int i = 0; i < NUM_BULLETS; i++) {
      if (active[i]) {
        for (int j = 0; j < NUM_ZOMBIES; j++) {
          proximity(bullet[i].x - bullet_dist[i] * cos((bullet_ang[i]) * M_PI/180), bullet[i].y - 0.0, bullet[i].z - bullet_dist[i] * sin((bullet_ang[i]) * M_PI/180), bullet_size.x, bullet_size.y, bullet_size.z, zombies_loc[j], zombies_size[j], z_die[j]);
        }
        for (int j = 0; j < NUM_WEREWOLFS; j++) {
          proximity(bullet[i].x - bullet_dist[i] * cos((bullet_ang[i]) * M_PI/180), bullet[i].y - 0.0, bullet[i].z - bullet_dist[i] * sin((bullet_ang[i]) * M_PI/180), bullet_size.x, bullet_size.y, bullet_size.z, werewolves_loc[j], werewolves_size[j], w_die[j]);
        }
        for (int j = 0; j < NUM_AGENCIES; j++) {
          proximity(bullet[i].x - bullet_dist[i] * cos((bullet_ang[i]) * M_PI/180), bullet[i].y - 0.0, bullet[i].z - bullet_dist[i] * sin((bullet_ang[i]) * M_PI/180), bullet_size.x, bullet_size.y, bullet_size.z, agencies_loc[j], agencies_size[j], a_die[j]);
        }
      }
    }
  }

  // for (int i = 0; i < NUM_ZOMBIES; i++) {
  //   for (int j = 0; j < NUM_OBJECTS; j++) {
  //     collision(zombies_loc[i].x, mv_pos.y, zombies_loc[i].z, PLAYER_W * 2, PLAYER_H * 2, PLAYER_D * 2, wall_loc[j], wall_size[j], collide[j]);
  //   }
  // }

  // for (int i = 0; i < NUM_ZOMBIES; i++) {
  //   for (int j = 0; j < NUM_OBJECTS; j++) {
  //     collision(zombies_loc[i].x, mv_pos.y, zombies_loc[i].z, PLAYER_W * 2, PLAYER_H * 2, PLAYER_D * 2, wall_loc[j], wall_size[j], collide[j]);
  //   }
  // }

  // object(pv, model_view, mv_pos.x - 5.0 * cos((theta - 0) * M_PI/180), mv_pos.y - 0.25, mv_pos.z - 5.0 * sin((theta - 0) * M_PI/180), 3.0, 3.0, 10.0, BARREL_R, BARREL_G, BARREL_B, 0, -theta + 90, 0, 0, 0, 0);


  // for (int i = 0; i < NUM_DOORS; i++) {
  //   proximity(mv_pos.x, mv_pos.y, mv_pos.z, PLAYER_W, PLAYER_H, PLAYER_D, door_loc[i], door_size[i], doors[i]);
  // }

  // for (int i = 0; i < NUM_INTERACTABLES; i++) {
  //   proximity(mv_pos.x, mv_pos.y, mv_pos.z, PLAYER_W, PLAYER_H, PLAYER_D, inter_loc[i], inter_size[i], proximal[i]);
  // }

  for (int i = 0; i < NUM_GUNS; i++) {
    proximity(mv_pos.x, mv_pos.y, mv_pos.z, PLAYER_W, PLAYER_H, PLAYER_D, gun_loc[i], pickup_size[0], pickup[0]);
  }

  for (int i = 0; i < NUM_VACCUUMS; i++) {
    proximity(mv_pos.x, mv_pos.y, mv_pos.z, PLAYER_W, PLAYER_H, PLAYER_D, vacuum_loc[i], pickup_size[1], pickup[1]);
  }

  for (int i = 0; i < NUM_KEYS; i++) {
    proximity(mv_pos.x, mv_pos.y, mv_pos.z, PLAYER_W, PLAYER_H, PLAYER_D, key_loc[i], pickup_size[2], pickup[2]);
  }

  for (int i = 0; i < NUM_COFFEES; i++) {
    proximity(mv_pos.x, mv_pos.y, mv_pos.z, PLAYER_W, PLAYER_H, PLAYER_D, coffee_loc[i], pickup_size[3], pickup[3]);
  }

  // collision(&enemy_loc[0].x, mv_pos.y, &enemy_loc[0].z, GHOST_W, GHOST_H, GHOST_D, wall_loc, wall_size, collide, NUM_OBJECTS);

  if (!collider[1]) { fall = true; } else { fall = false; }

  for (int i = 0; i < 6; i++) { collider[i] = false; }

  mv_pos.x += mv_vel.x;
  mv_pos.y += mv_vel.y;
  mv_pos.z += mv_vel.z;

  lasttime = time;

  // ENVIRONMENT
  disp_rot = display_rot;

  glutPostRedisplay();

}

#endif
