#ifndef INSTANCE_H
#define INSTANCE_H

#include <Angel.h>
#include "engine.h"
#include "utility.h"
#include "game.h"
#include "models.h"

// Motion rates
#define RATE_PLAYER	  0.5
#define RATE_GUN	    1

std::uniform_real_distribution<double> dist_x(-7.0, 7.0);
std::uniform_real_distribution<double> dist_z(-10.0, -6.0);
std::uniform_real_distribution<double> sickness(0.0, 0.005);

// Game object locations
vec3 player = vec3(0.0, 0.0, 6.0);

// Color vec3s
vec3 sky = vec3(0.8, 1.0, 1.0);
vec3 feather = vec3(FEATHER_RE, FEATHER_GR, FEATHER_BL);

float display_rot = 0.0;

float dart_x = 0.0, dart_z = 0.0;
bool fire_gun = false, reload = true, action = false;
float elevation = 0.0, frame = 3.0;
int score = 0;
int health = 5;
bool solid_part = true, game_over = false;

GLfloat ghost_height[5] = { 0.0 },
        bookcase_x[2] = { 20.0, 30.0 },
        zombie_height[6] = { 0.0 },
        bullet_dist[NUM_BULLETS];

GLfloat wall_height = 5.0,
        door_vert = 2.5,
        ghost_mult = 1.0,
        bookcase_z = -45.0,
        dizziness = 0.0,
        nausea = 0.0,
        zombie_mult[NUM_ZOMBIES] = { 1.0, 1.0, 1.0 },
        werewolf_mult[NUM_ZOMBIES] = { 1.0, 1.0, 1.0 },
        door_height = 27.5,
        speed_boost = 1.0;

vec3 zombie_loc[NUM_ZOMBIES] = {
  vec3(10.0, zombie_height[0], 25.0),
  vec3(10.0, zombie_height[0], 35.0),
  vec3(15.0, zombie_height[0], 32.5)
};

vec3 werewolf_loc[NUM_ZOMBIES] = {
  vec3(10.0, zombie_height[0], 25.0),
  vec3(10.0, zombie_height[0], 35.0),
  vec3(15.0, zombie_height[0], 32.5)
};

vec3 bullet[NUM_BULLETS] = { vec3(0.0, 0.0, 0.0) };

vec3 agency_loc = vec3(-51.0, 0.0, 10.0),
     ghost_loc = vec3(-17.5, ghost_height[0], -5.0),
     picture_loc = vec3(12.5, 0.0, -1.0),
     door_color = vec3(0.7, 0.6, 0.5);

int picture_rot = 225, flicker = 0, door_open[NUM_DOORS] = { 0 }, bullet_ang[NUM_BULLETS] = { 0 };

bool debug = false,
     toggle = true,
     draw_table = false,
     door_collide = true,
     open_door[NUM_DOORS] = { false },
     werewolf_chase = false,
     ghost_chase = false,
     get_sweeper = false,
     kill_ghost = false,
     sweep_ghost = false,
     fix_picture = false,
     lose_power = false,
     bookcase_open = false,
     //light_fire = false,
     get_key = false,
     agency_chase = false,
     zombie_chase = false,
     get_gun = false,
     kill_zombie[3] = { false },
     //hit_glass = false,
     get_coffee = false,
     shut_door = false,
     active[NUM_BULLETS] = { false };

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

// animation function, runs the updating of the variables
void animation(void) {

  static GLint lasttime = glutGet(GLUT_ELAPSED_TIME);
  GLint time = glutGet(GLUT_ELAPSED_TIME);

  // mv_vel = vec3(0.0, 0.0, 0.0);
  mv_vel.x = 0.0;
  mv_vel.z = 0.0;

  set_room(mv_pos.x, 0.0, mv_pos.z, PLAYER_W, PLAYER_H, PLAYER_D);

  // if (rotatep) move_angle += 20.0 / 1000.0 * (time - lasttime);

  // doorAngle += doorAngleIncr / 1000.0 * (time - lasttime);

  // if (doorAngle > 60.0) doorAngleIncr *= -1.0;

  // if (doorAngle < 0.0) { doorAngle = 0.0; doorAngleIncr *= -1.0; }





  // // Do the animation code here in idle, not in display. Code for moving 2nd cube

  // trans += transinc / 1000.0 * ( time - lasttime );

  // if (trans > 1.5) { trans = 1.5; transinc *= -1; }

  // if (trans < -1.5) { trans = -1.5; transinc *= -1; }

  static int step;

  if (pickup[0]){
    get_sweeper = true;
  }
  if (pickup[1]){
    get_key = true;
  }
  if (pickup[2]){
    get_gun = true;
  }
  if (pickup[3]){
    get_coffee = true;
  }

  if (rooms[0]) {
    agency_chase = true;
    // if (doors[0]){
    //   if (action) {
    //     open_door[0] = true;
    //   }
    // }
    // if (doors[8]){
    //   if (action) {
    //     open_door[8] = true;
    //   }
    // }
  } else { agency_chase = false; }

  if (rooms[1]) {
    werewolf_chase = true;
    // if (doors[1]){
    //   if (action) {
    //     open_door[1] = true;
    //   }
    // }
  } else { werewolf_chase = false; }

  if (rooms[2]) {
    ghost_chase = true;
    // if (doors[2]){
    //   if (action) {
    //     open_door[2] = true;
    //   }
    // }
    // if (doors[9]){
    //   if (action) {
    //     open_door[9] = true;
    //   }
    // }
  }
  else { ghost_chase = false; }

  if (rooms[3]) {
    zombie_chase = true;
    // if (proximal[2]){
    //   if (action) {
    //     fix_picture = true;
    //   }
    // }
    // if (doors[3]){
    //   if (action) {
    //     open_door[3] = true;
    //   }
    // }
  } else {
    zombie_chase = false;
    // lose_power = false;
  }

  if (rooms[4]) {
    // lights[0] = true;
    // glUniform1i(Lights[0], lights[0]);
    // lights[1] = true;
    // glUniform1i(Lights[1], lights[1]);
    // agency_loc = vec3(12.5, 0.0, -51.0);
    // if (proximal[3]){
    //   if (action) {
    //     bookcase_open = true;
    //   }
    // }
  } else {
    // bookcase_open = false;
  }

  if (rooms[5]) {
    if (doors[4]){
      if (action) {
        if (get_key) {
          open_door[4] = true;
        }
      }
    }
  } else { }

  if (rooms[6]) {
    // if (!agency_chase) {
      // agency_loc = vec3(45.0, 0.0, 15.0);
    // }
    // hallucinate = true;
    // agency_chase = true;
    // dizziness = sickness(mt);
    // nausea += 0.001 + dizziness;
    // phi = 25 * -sin(nausea *180/M_PI);
    // theta = -90 + 25 * cos((nausea *180/M_PI)/2);
    if (doors[5]){
      if (action) {
        open_door[5] = true;
      }
    }
  } else {
    hallucinate = false;
    // agency_chase = false;
  }

  if (rooms[7]) {
    // zombie_chase = true;
    if (doors[6]){
      if (action) {
        open_door[6] = true;
      }
    }
    if (doors[10]){
      if (action) {
        open_door[10] = true;
      }
    }
  }
  else { /*zombie_chase = false;*/ }

  if (rooms[8]) {
    // agency_loc = vec3(51.0, 0.0, 30.0);
    if (doors[7]){
      if (action) {
        open_door[7] = true;
      }
    }
  } else { }

  if (rooms[9]) {
    shut_door = true;
  }
  else { shut_door = false; }

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

      if (lose_power && flicker < 7) {
        lights[0] = !lights[0];
        glUniform1i(Lights[0], lights[0]);
        flicker++;
      }

      if (lose_power && flicker >= 7 && flicker < 15) {
        flicker++;
        // agency_loc = vec3(12.5, 0.0, -12.5);
        door_color = vec3(0.25, 0.15, 0.05);
        open_door[3] = true;
      }

      if (lose_power && flicker >= 15) {
        lights[0] = false;
        glUniform1i(Lights[0], lights[0]);
        lights[1] = false;
        glUniform1i(Lights[1], lights[1]);
      }

    } else if (step == 1 || step == 3) {

      if (frame == 0.0) step++;
      if (frame > 0) frame = frame - 1.0;
      for (int i = 0; i < 5; i++){
        ghost_height[i] = -sin((frame - i)*M_PI/30);
      }

      display_rot = -frame;

      if (lose_power && flicker < 7) {
        lights[1] = !lights[1];
        glUniform1i(Lights[1], lights[1]);
        flicker++;
      }

    }

  }

  if (step == 4) step = 0;

  if (health == 0) death = true;

  for (int i = 0; i < NUM_DOORS; i++) {
    if (door_open[i] < 90) { // door_rot[i] + 90) {
      if (open_door[i]) { door_open[i] += 0.1 * (time - lasttime); }
    }
  }

  if (ghost_chase) {
    if (ghost_loc.x != mv_pos.x) {
      if (ghost_loc.x - mv_pos.x < 0) {
        ghost_loc.x += 0.1;
      }
      if (ghost_loc.x - mv_pos.x > 0) {
        ghost_loc.x -= 0.1;
      }
    }
    if (ghost_loc.z != mv_pos.z) {
      if (ghost_loc.z - mv_pos.z < 0) {
        ghost_loc.z += 0.1;
      }
      if (ghost_loc.z - mv_pos.z > 0) {
        ghost_loc.z -= 0.1;
      }
    }
  }

  if (get_sweeper) {
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

  if (picture_rot < 270) {
    if (fix_picture) { picture_rot += 1; }
  } else {
    lose_power = true;
  }

  if (bookcase_z < -37.5) {
    if (bookcase_open) { bookcase_z += 0.075; }
  }

  if (bookcase_x[0] > 15.0) {
    if (bookcase_open) { bookcase_x[0] -= 0.075; }
  }

  if (bookcase_x[1] < 35.0) {
    if (bookcase_open) { bookcase_x[1] += 0.075; }
  }

  if (get_key) {

  }

  if (agency_chase) {
    if (agency_loc.x != mv_pos.x) {
      if (agency_loc.x - mv_pos.x < 0) {
        agency_loc.x += 0.1;
      }
      if (agency_loc.x - mv_pos.x > 0) {
        agency_loc.x -= 0.1;
      }
    }
    if (agency_loc.z != mv_pos.z) {
      if (agency_loc.z - mv_pos.z < 0) {
        agency_loc.z += 0.1;
      }
      if (agency_loc.z - mv_pos.z > 0) {
        agency_loc.z -= 0.1;
      }
    }
  }

  if (werewolf_chase) {
    if (werewolf_loc[0].x != mv_pos.x) {
      if (werewolf_loc[0].x - mv_pos.x < 0) {
        werewolf_loc[0].x += 0.1;
      }
      if (werewolf_loc[0].x - mv_pos.x > 0) {
        werewolf_loc[0].x -= 0.1;
      }
    }
    if (werewolf_loc[0].z != mv_pos.z) {
      if (werewolf_loc[0].z - mv_pos.z < 0) {
        werewolf_loc[0].z += 0.1;
      }
      if (werewolf_loc[0].z - mv_pos.z > 0) {
        werewolf_loc[0].z -= 0.1;
      }
    }
  }

  if (zombie_chase) {
    for (int i = 0; i < NUM_ZOMBIES; i++) {
      if (zombie_loc[i].x != mv_pos.x) {
        if (zombie_loc[i].x - mv_pos.x < 0) {
          zombie_loc[i].x += (i + 1) * 0.05;
        }
        if (zombie_loc[i].x - mv_pos.x > 0) {
          zombie_loc[i].x -= (i + 1) * 0.05;
        }
      }
      if (zombie_loc[i].z != mv_pos.z) {
        if (zombie_loc[i].z - mv_pos.z < 0) {
          zombie_loc[i].z += (i + 1) * 0.05;
        }
        if (zombie_loc[i].z - mv_pos.z > 0) {
          zombie_loc[i].z -= (i + 1) * 0.05;
        }
      }
    }
  }

  if (get_gun) {
    for (int i = 0; i < NUM_ZOMBIES; i++) {
      if (z_die[i]) kill_zombie[i] = true;
    }
  } else {
    if (z_die[0] || z_die[1] || z_die[2]) {
      health--;
      hurt = true;
    }// exit(EXIT_FAILURE);
  }

  for (int i = 0; i < NUM_ZOMBIES; i++) {
    if (kill_zombie[i]) {
      if (zombie_mult[i] >= 0.0) {
        zombie_mult[i] -= 0.01;
      }
    }
  }

  if(hurt) {
    mv_vel.z += 20.0 * sin(theta*M_PI/180)/2;
    mv_vel.x += 20.0 * cos(theta*M_PI/180)/2;
  }

  if (door_height > wall_height) {
    if (shut_door) { door_height -= 0.075; }
  }

  if (get_coffee) {
    speed_boost = 2.0;
  }

  title_bar = "Score: " + std::to_string(collider[1]) + " Darts: " + std::to_string(mv_vel.y) + " bool: " + std::to_string(0.01 * (time - lasttime)); // + " l:" + std::to_string(l) + " r:" + std::to_string(r) + " f:" + std::to_string(f) + " b:" + std::to_string(b);

  if (mouse_button == 3 && changed) { fovy -= 5.0; changed = false; } else if (mouse_button == 4 && changed) { fovy += 5.0; changed = false; }

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
        case '/': { if (reload) { fire_gun = true; } } break; // Shoot
        case '1': { hallucinate = !hallucinate; } break; // Weapon 1
        case '2': { } break; // Weapon 2
        case '3': { } break; // Weapon 3
        case 'c': if (toggle) { perspective = !perspective; toggle = false; } break; //fire
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
        case '`': if (toggle) { debug = !debug; toggle = false; } break;
        default: { } break; // Default

      }
    } else {
      switch (i) {
        case '/': fire_gun = false; break; // Stop firing, not the same as bullet landing
        // case 'w': { mv_vel.z = 0.0; mv_vel.x = 0.0; } break;
        // case 's': { mv_vel.z = 0.0; mv_vel.x = 0.0; } break;
        // case 'a': { mv_vel.x = 0.0; mv_vel.z = 0.0; } break;
        // case 'd': { mv_vel.x = 0.0; mv_vel.z = 0.0; } break;
        case ' ': { jump = false; } break; //wire
        case 'f': { action = false; } break; //wire
        case 'c': { toggle = true; } break; //fire
        case '`': { toggle = true; } break; //fire
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

  float gx = 50.0;
  float gy = 10;
  float gz = 50.0;

  float kx = 50.0;
  float ky = 10;
  float kz = -50.0;

  float vx = -50.0;
  float vy = 10;
  float vz = -50.0;

  float cx = -50.0;
  float cy = 10;
  float cz = 50.0;

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


  for (int i = 0; i < NUM_GUNS; i++) {
    // for (int j = 0; j < PARTS_GUN; j++) {
      guns[i][0].update(gx + -0.25*0.2 * cos((display_rot - 0) * M_PI/180), gy + 0.0*0.2, gz + -0.25*0.2 /* - 0.0 */ * sin((display_rot - 0) * M_PI/180), BARREL_W*0.2, BARREL_H*0.2, BARREL_D*0.2, BARREL_R, BARREL_G, BARREL_B, 0, 90 - display_rot, 0);
      guns[i][1].update(gx + -1.25*0.2 * cos((display_rot - 0) * M_PI/180), gy + -0.25*0.2, gz + -1.25*0.2 * sin((display_rot - 0) * M_PI/180), SIGHT_W*0.2, SIGHT_H*0.2, SIGHT_D*0.2, SIGHT_R, SIGHT_G, SIGHT_B, 0, 90 - display_rot, 90);
      guns[i][2].update(gx + 0.025*0.2 * cos((display_rot - 0) * M_PI/180), gy + -1.0*0.2, gz + 0.025*0.2 * sin((display_rot - 0) * M_PI/180), HANDLE_W*0.2, HANDLE_H*0.2, HANDLE_D*0.2, HANDLE_R, HANDLE_G, HANDLE_B, 0, 180 - display_rot, 0);
    // }
  }

  for (int i = 0; i < NUM_KEYS; i++) {
    // for (int j = 0; j < PARTS_KEY; j++) {
      keys[i][0].update(kx + 1.5*0.2 * cos((display_rot - 0) * M_PI/180), ky + 0.0*0.2, kz + 1.5*0.2 * sin((display_rot - 0) * M_PI/180), KEYL_W*0.2, KEYL_H*0.2, KEYL_D*0.2, KEY_R, KEY_G, KEY_B, 0, 90 - display_rot, 0);
      keys[i][1].update(kx - 0.5*0.2 * cos((display_rot - 0) * M_PI/180), ky + 0.0*0.2, kz - 0.5*0.2 * sin((display_rot - 0) * M_PI/180), KEYL_H*0.2, KEYL_D*0.2, KEYL_W*0.2, KEY_R, KEY_G, KEY_B, 0, 0 - display_rot, 0);
      keys[i][2].update(kx - 2.5*0.2 * cos((display_rot - 0) * M_PI/180), ky + 0.0*0.2, kz - 2.5*0.2 * sin((display_rot - 0) * M_PI/180), KEYL_H*0.2, KEYL_D*0.2, KEYL_W*0.2, KEY_R, KEY_G, KEY_B, 0, 0 - display_rot, 0);
      keys[i][3].update(kx - 1.5*0.2 * cos((display_rot - 0) * M_PI/180), ky + 1.5*0.2, kz - 1.5*0.2 * sin((display_rot - 0) * M_PI/180), KEYS_W*0.2, KEYS_H*0.2, KEYS_D*0.2, KEY_R, KEY_G, KEY_B, 0, 90 - display_rot, 0);
      keys[i][4].update(kx - 1.5*0.2 * cos((display_rot - 0) * M_PI/180), ky - 1.5*0.2, kz - 1.5*0.2 * sin((display_rot - 0) * M_PI/180), KEYS_W*0.2, KEYS_H*0.2, KEYS_D*0.2, KEY_R, KEY_G, KEY_B, 0, 90 - display_rot, 0);
      keys[i][5].update(kx + 2.0*0.2 * cos((display_rot - 0) * M_PI/180), ky - 1.0*0.2, kz + 2.0*0.2 * sin((display_rot - 0) * M_PI/180), KEYS_H*0.2, KEYS_D*0.2, KEYS_W*0.2, KEY_R, KEY_G, KEY_B, 0, 0 - display_rot, 0);
    // }
  }

  for (int i = 0; i < NUM_VACCUUMS; i++) {
    // for (int j = 0; j < PARTS_VACCUUM; j++) {
      vaccuums[i][0].update(vx + 0.0*0.2 * cos((display_rot - 0) * M_PI/180), vy - 3.0*0.2, vz + 0.0*0.2 * sin((display_rot - 0) * M_PI/180), BODYL_W*0.2, BODYL_H*0.2, BODYL_D*0.2, VACCUUM_R, VACCUUM_G, VACCUUM_B, 0, 0 - display_rot, 0);
      vaccuums[i][1].update(vx - 0.5*0.2 * cos((display_rot - 0) * M_PI/180), vy + 0.5*0.2, vz - 0.5*0.2 * sin((display_rot - 0) * M_PI/180), BODYS_W*0.2, BODYS_H*0.2, BODYS_D*0.2, VACCUUM_R, VACCUUM_G, VACCUUM_B, 0, 0 - display_rot, 0);
      vaccuums[i][2].update(vx + 2.75*0.2 * cos((display_rot - 65) * M_PI/180), vy + 0.5*0.2, vz + 2.75*0.2 * sin((display_rot - 65) * M_PI/180), HOSEL_W*0.203, HOSEL_H*0.2, HOSEL_D*0.203, HOSE_R, HOSE_G, HOSE_B, 0, 0 - display_rot, 0);
      vaccuums[i][3].update(vx + 1.0*0.2 * cos((display_rot - 0) * M_PI/180), vy + 2.5*0.2, vz + 1.0*0.2 * sin((display_rot - 0) * M_PI/180), HOSEM_W*0.201, HOSEM_H*0.2, HOSEM_D*0.201, HOSE_R, HOSE_G, HOSE_B, 0, 0 - display_rot, 0);
      vaccuums[i][4].update(vx + 1.75*0.2 * cos((display_rot - 50) * M_PI/180), vy + 3.5*0.2, vz + 1.75*0.2 * sin((display_rot - 50) * M_PI/180), HOSES_W*0.202, HOSES_D*0.2, HOSES_H*0.202, HOSE_R, HOSE_G, HOSE_B, 0, 0 - display_rot, 0);
      vaccuums[i][5].update(vx + 2.75*0.2 * cos((display_rot - 65) * M_PI/180), vy - 2.5*0.2, vz + 2.75*0.2 * sin((display_rot - 65) * M_PI/180), NOZZLE_D*0.2, NOZZLE_H*0.2, NOZZLE_W*0.2, HOSE_R, HOSE_G, HOSE_B, 0, 0 - display_rot, 0);
      vaccuums[i][6].update(vx - 2.25*0.2 * cos((display_rot - 25) * M_PI/180), vy - 1.5*0.2, vz - 2.25*0.2 * sin((display_rot - 25) * M_PI/180), STRAP_W*0.2, STRAP_H*0.2, STRAP_D*0.2, STRAP_R, STRAP_G, STRAP_B, 0, 0 - display_rot, 0);
      vaccuums[i][7].update(vx - 2.25*0.2 * cos((display_rot + 25) * M_PI/180), vy - 1.5*0.2, vz - 2.25*0.2 * sin((display_rot + 25) * M_PI/180), STRAP_W*0.2, STRAP_H*0.2, STRAP_D*0.2, STRAP_R, STRAP_G, STRAP_B, 0, 0 - display_rot, 0);
      vaccuums[i][8].update(vx + 2.5*0.2 * cos((display_rot - 90) * M_PI/180), vy - 3.5*0.2, vz + 2.5*0.2 * sin((display_rot - 90) * M_PI/180), WHEEL_W*0.2, WHEEL_H*0.2, WHEEL_D*0.2, WHEEL_R, WHEEL_G, WHEEL_B, 0, -90 - display_rot, 0);
      vaccuums[i][9].update(vx + 2.5*0.2 * cos((display_rot + 90) * M_PI/180), vy - 3.5*0.2, vz + 2.5*0.2 * sin((display_rot + 90) * M_PI/180), WHEEL_W*0.2, WHEEL_H*0.2, WHEEL_D*0.2, WHEEL_R, WHEEL_G, WHEEL_B, 0, 90 - display_rot, 0);
      vaccuums[i][10].update(vx + 1.5*0.2 * cos((display_rot - 0) * M_PI/180), vy + 0.5*0.2, vz + 1.5*0.2 * sin((display_rot - 0) * M_PI/180), LIGHT_W*0.2, LIGHT_H*0.2, LIGHT_D*0.2, LIGHT_R, LIGHT_G, LIGHT_B, 0, 0 - display_rot, 0);
    // }
  }

  for (int i = 0; i < NUM_COFFEES; i++) {
    // for (int j = 0; j < PARTS_COFFEE; j++) {
      coffees[i][0].update(cx + 0.0*0.2 * cos((display_rot - 0) * M_PI/180), cy - 0.8*0.2, cz + 0.0*0.2 * sin((display_rot - 0) * M_PI/180), COFFEE_W*0.2, COFFEE_H*0.2, COFFEE_D*0.2, COFFEE_R, COFFEE_G, COFFEE_B, 0, 0 - display_rot, 0);
      coffees[i][1].update(cx + 0.0*0.2 * cos((display_rot - 0) * M_PI/180), cy - 1.0*0.2, cz + 0.0*0.2 * sin((display_rot - 0) * M_PI/180), CUP_W*0.2, CUP_H*0.2, CUP_D*0.2, DISH_R, DISH_G, DISH_B, 0, 0 - display_rot, 0);
      coffees[i][2].update(cx + 0.0*0.2 * cos((display_rot - 0) * M_PI/180), cy - 1.5*0.2, cz + 0.0*0.2 * sin((display_rot - 0) * M_PI/180), SAUCER_W*0.2, SAUCER_H*0.2, SAUCER_D*0.2, DISH_R, DISH_G, DISH_B, 0, 45 - display_rot, 0);
      coffees[i][3].update(cx + 0.0*0.2 * cos((display_rot - 0) * M_PI/180), cy - 1.5*0.2, cz + 0.0*0.2 * sin((display_rot - 0) * M_PI/180), SAUCER_W*0.2, SAUCER_H*0.2, SAUCER_D*0.2, DISH_R, DISH_G, DISH_B, 0, 0 - display_rot, 0);
    // }
  }

  for (int i = 0; i < NUM_GHOSTS; i++) {
    // for (int j = 0; j < PARTS_GHOST; j++) {
      ghosts[i][0].update(ghosts_loc[0].x, ghost_height[0] + 0.5, ghosts_loc[0].z, ghosts_size[0].x, ghosts_size[0].y, ghosts_size[0].z, GHOST_R, GHOST_G, GHOST_B, 0, 0, 0);
      ghosts[i][1].update(ghosts_loc[0].x, ghost_height[1] + 0.0, ghosts_loc[0].z, ghosts_size[0].x*1.25, ghosts_size[0].y*1.25, ghosts_size[0].z*1.25, GHOST_R, GHOST_G, GHOST_B, 0, 0, 0);
      ghosts[i][2].update(ghosts_loc[0].x + 0.5 * cos(105 * M_PI/180), ghost_height[2] - 1.0, ghosts_loc[0].z + 0.5 * sin(105 * M_PI/180), ghosts_size[0].x/2, ghosts_size[0].y/2, ghosts_size[0].z/2, GHOST_R, GHOST_G, GHOST_B, 45, 0, 45);
      ghosts[i][3].update(ghosts_loc[0].x + 0.5 * cos(225 * M_PI/180), ghost_height[3] - 1.0, ghosts_loc[0].z + 0.5 * sin(225 * M_PI/180), ghosts_size[0].x/2, ghosts_size[0].y/2, ghosts_size[0].z/2, GHOST_R, GHOST_G, GHOST_B, 45, 0, 45);
      ghosts[i][3].update(ghosts_loc[0].x + 0.5 * cos(345 * M_PI/180), ghost_height[4] - 1.0, ghosts_loc[0].z + 0.5 * sin(345 * M_PI/180), ghosts_size[0].x/2, ghosts_size[0].y/2, ghosts_size[0].z/2, GHOST_R, GHOST_G, GHOST_B, 45, 0, 45);
    // }
  }

  for (int i = 0; i < NUM_ZOMBIES; i++) {
    // for (int j = 0; j < PARTS_ZOMBIE; j++) {
    zombies[i][0].update(zombies_loc[i].x + 0.0, agency_loc.y + 1.15, zombies_loc[i].z + 0.0, HAIR_W*zombie_mult[i], HAIR_H*zombie_mult[i], HAIR_D*zombie_mult[i], ZOMBIE_R, ZOMBIE_G, ZOMBIE_B, 0, 0, 0);
    zombies[i][1].update(zombies_loc[i].x + 0.0, agency_loc.y + 0.75, zombies_loc[i].z + 0.0, FACE_W*zombie_mult[i], FACE_H*zombie_mult[i], FACE_D*zombie_mult[i], ZOMBIE_R, ZOMBIE_G, ZOMBIE_B, 0, 0, 0);
    zombies[i][2].update(zombies_loc[i].x + 0.3, agency_loc.y + 0.75, zombies_loc[i].z - 0.175, LENS_W*zombie_mult[i], LENS_H*zombie_mult[i], LENS_D*zombie_mult[i], ZOMBIE_R, ZOMBIE_G, ZOMBIE_B, 0, 0, 0);
    zombies[i][3].update(zombies_loc[i].x + 0.3, agency_loc.y + 0.75, zombies_loc[i].z + 0.175, LENS_W*zombie_mult[i], LENS_H*zombie_mult[i], LENS_D*zombie_mult[i], ZOMBIE_R, ZOMBIE_G, ZOMBIE_B, 0, 0, 0);
    zombies[i][4].update(zombies_loc[i].x + 0.4, agency_loc.y + 0.875, zombies_loc[i].z + 0.0, BRIDGE_W*zombie_mult[i], BRIDGE_H*zombie_mult[i], BRIDGE_D*zombie_mult[i], ZOMBIE_R, ZOMBIE_G, ZOMBIE_B, 0, 0, 0);
    zombies[i][5].update(zombies_loc[i].x + 0.0, agency_loc.y - 0.25, zombies_loc[i].z + 0.0, SHIRT_W*zombie_mult[i], SHIRT_H*zombie_mult[i], SHIRT_D*zombie_mult[i], ZOMBIE_R, ZOMBIE_G, ZOMBIE_B, 0, 0, 0);
    zombies[i][6].update(zombies_loc[i].x + 0.0, agency_loc.y - 0.25, zombies_loc[i].z - 0.375, SUIT_W*zombie_mult[i], SUIT_H*zombie_mult[i], SUIT_D*zombie_mult[i], ZOMBIE_R, ZOMBIE_G, ZOMBIE_B, 0, 0, 0);
    zombies[i][7].update(zombies_loc[i].x + 0.0, agency_loc.y - 0.25, zombies_loc[i].z + 0.375, SUIT_W*zombie_mult[i], SUIT_H*zombie_mult[i], SUIT_D*zombie_mult[i], ZOMBIE_R, ZOMBIE_G, ZOMBIE_B, 0, 0, 0);
    zombies[i][8].update(zombies_loc[i].x + 0.25, agency_loc.y - 0.125, zombies_loc[i].z + 0.0, TIE_W*zombie_mult[i], TIE_H*zombie_mult[i], TIE_D*zombie_mult[i], ZOMBIE_R, ZOMBIE_G, ZOMBIE_B, 0, 0, 0);
    zombies[i][9].update(zombies_loc[i].x + 0.0, agency_loc.y - 0.375, zombies_loc[i].z - 0.5, APPENDAGE_W*zombie_mult[i], APPENDAGE_H*zombie_mult[i], APPENDAGE_D*zombie_mult[i], ZOMBIE_R, ZOMBIE_G, ZOMBIE_B, 0, 0, 0);
    zombies[i][10].update(zombies_loc[i].x + 0.0, agency_loc.y - 0.375, zombies_loc[i].z + 0.5, APPENDAGE_W*zombie_mult[i], APPENDAGE_H*zombie_mult[i], APPENDAGE_D*zombie_mult[i], ZOMBIE_R, ZOMBIE_G, ZOMBIE_B, 0, 0, 0);
    zombies[i][11].update(zombies_loc[i].x + 0.0, agency_loc.y - 1.5, zombies_loc[i].z - 0.25, APPENDAGE_W*zombie_mult[i], APPENDAGE_H*zombie_mult[i], APPENDAGE_D*zombie_mult[i], ZOMBIE_R, ZOMBIE_G, ZOMBIE_B, 0, 0, 0);
    zombies[i][12].update(zombies_loc[i].x + 0.0, agency_loc.y - 1.5, zombies_loc[i].z + 0.25, APPENDAGE_W*zombie_mult[i], APPENDAGE_H*zombie_mult[i], APPENDAGE_D*zombie_mult[i], ZOMBIE_R, ZOMBIE_G, ZOMBIE_B, 0, 0, 0);
    // }
  }

  for (int i = 0; i < NUM_WEREWOLFS; i++) {
    // for (int j = 0; j < PARTS_WEREWOLF; j++) {
    werewolfs[i][0].update(werewolves_loc[i].x + 0.0, agency_loc.y + 1.15, werewolves_loc[i].z + 0.0, HAIR_W*zombie_mult[i], HAIR_H*zombie_mult[i], HAIR_D*zombie_mult[i], WEREWOLF_R, WEREWOLF_G, WEREWOLF_B, 0, 0, 0);
    werewolfs[i][1].update(werewolves_loc[i].x + 0.0, agency_loc.y + 0.75, werewolves_loc[i].z + 0.0, FACE_W*zombie_mult[i], FACE_H*zombie_mult[i], FACE_D*zombie_mult[i], WEREWOLF_R, WEREWOLF_G, WEREWOLF_B, 0, 0, 0);
    werewolfs[i][2].update(werewolves_loc[i].x + 0.3, agency_loc.y + 0.75, werewolves_loc[i].z - 0.175, LENS_W*zombie_mult[i], LENS_H*zombie_mult[i], LENS_D*zombie_mult[i], WEREWOLF_R, WEREWOLF_G, WEREWOLF_B, 0, 0, 0);
    werewolfs[i][3].update(werewolves_loc[i].x + 0.3, agency_loc.y + 0.75, werewolves_loc[i].z + 0.175, LENS_W*zombie_mult[i], LENS_H*zombie_mult[i], LENS_D*zombie_mult[i], WEREWOLF_R, WEREWOLF_G, WEREWOLF_B, 0, 0, 0);
    werewolfs[i][4].update(werewolves_loc[i].x + 0.4, agency_loc.y + 0.875, werewolves_loc[i].z + 0.0, BRIDGE_W*zombie_mult[i], BRIDGE_H*zombie_mult[i], BRIDGE_D*zombie_mult[i], WEREWOLF_R, WEREWOLF_G, WEREWOLF_B, 0, 0, 0);
    werewolfs[i][5].update(werewolves_loc[i].x + 0.0, agency_loc.y - 0.25, werewolves_loc[i].z + 0.0, SHIRT_W*zombie_mult[i], SHIRT_H*zombie_mult[i], SHIRT_D*zombie_mult[i], WEREWOLF_R, WEREWOLF_G, WEREWOLF_B, 0, 0, 0);
    werewolfs[i][6].update(werewolves_loc[i].x + 0.0, agency_loc.y - 0.25, werewolves_loc[i].z - 0.375, SUIT_W*zombie_mult[i], SUIT_H*zombie_mult[i], SUIT_D*zombie_mult[i], WEREWOLF_R, WEREWOLF_G, WEREWOLF_B, 0, 0, 0);
    werewolfs[i][7].update(werewolves_loc[i].x + 0.0, agency_loc.y - 0.25, werewolves_loc[i].z + 0.375, SUIT_W*zombie_mult[i], SUIT_H*zombie_mult[i], SUIT_D*zombie_mult[i], WEREWOLF_R, WEREWOLF_G, WEREWOLF_B, 0, 0, 0);
    werewolfs[i][8].update(werewolves_loc[i].x + 0.25, agency_loc.y - 0.125, werewolves_loc[i].z + 0.0, TIE_W*zombie_mult[i], TIE_H*zombie_mult[i], TIE_D*zombie_mult[i], WEREWOLF_R, WEREWOLF_G, WEREWOLF_B, 0, 0, 0);
    werewolfs[i][9].update(werewolves_loc[i].x + 0.0, agency_loc.y - 0.375, werewolves_loc[i].z - 0.5, APPENDAGE_W*zombie_mult[i], APPENDAGE_H*zombie_mult[i], APPENDAGE_D*zombie_mult[i], WEREWOLF_R, WEREWOLF_G, WEREWOLF_B, 0, 0, 0);
    werewolfs[i][10].update(werewolves_loc[i].x + 0.0, agency_loc.y - 0.375, werewolves_loc[i].z + 0.5, APPENDAGE_W*zombie_mult[i], APPENDAGE_H*zombie_mult[i], APPENDAGE_D*zombie_mult[i], WEREWOLF_R, WEREWOLF_G, WEREWOLF_B, 0, 0, 0);
    werewolfs[i][11].update(werewolves_loc[i].x + 0.0, agency_loc.y - 1.5, werewolves_loc[i].z - 0.25, APPENDAGE_W*zombie_mult[i], APPENDAGE_H*zombie_mult[i], APPENDAGE_D*zombie_mult[i], WEREWOLF_R, WEREWOLF_G, WEREWOLF_B, 0, 0, 0);
    werewolfs[i][12].update(werewolves_loc[i].x + 0.0, agency_loc.y - 1.5, werewolves_loc[i].z + 0.25, APPENDAGE_W*zombie_mult[i], APPENDAGE_H*zombie_mult[i], APPENDAGE_D*zombie_mult[i], WEREWOLF_R, WEREWOLF_G, WEREWOLF_B, 0, 0, 0);
    // }
  }

  for (int i = 0; i < NUM_AGENCIES; i++) {
    // for (int j = 0; j < PARTS_AGENCIE; j++) {
    agencies[i][0].update(agencies_loc[i].x + 0.0, agency_loc.y + 1.15, agencies_loc[i].z + 0.0, HAIR_W*zombie_mult[i], HAIR_H*zombie_mult[i], HAIR_D*zombie_mult[i], AGENCY_R, AGENCY_G, AGENCY_B, 0, 0, 0);
    agencies[i][1].update(agencies_loc[i].x + 0.0, agency_loc.y + 0.75, agencies_loc[i].z + 0.0, FACE_W*zombie_mult[i], FACE_H*zombie_mult[i], FACE_D*zombie_mult[i], SKIN_R, SKIN_G, SKIN_B, 0, 0, 0);
    agencies[i][2].update(agencies_loc[i].x + 0.3, agency_loc.y + 0.75, agencies_loc[i].z - 0.175, LENS_W*zombie_mult[i], LENS_H*zombie_mult[i], LENS_D*zombie_mult[i], AGENCY_R, AGENCY_G, AGENCY_B, 0, 0, 0);
    agencies[i][3].update(agencies_loc[i].x + 0.3, agency_loc.y + 0.75, agencies_loc[i].z + 0.175, LENS_W*zombie_mult[i], LENS_H*zombie_mult[i], LENS_D*zombie_mult[i], AGENCY_R, AGENCY_G, AGENCY_B, 0, 0, 0);
    agencies[i][4].update(agencies_loc[i].x + 0.4, agency_loc.y + 0.875, agencies_loc[i].z + 0.0, BRIDGE_W*zombie_mult[i], BRIDGE_H*zombie_mult[i], BRIDGE_D*zombie_mult[i], AGENCY_R, AGENCY_G, AGENCY_B, 0, 0, 0);
    agencies[i][5].update(agencies_loc[i].x + 0.0, agency_loc.y - 0.25, agencies_loc[i].z + 0.0, SHIRT_W*zombie_mult[i], SHIRT_H*zombie_mult[i], SHIRT_D*zombie_mult[i], SHIRT_R, SHIRT_G, SHIRT_B, 0, 0, 0);
    agencies[i][6].update(agencies_loc[i].x + 0.0, agency_loc.y - 0.25, agencies_loc[i].z - 0.375, SUIT_W*zombie_mult[i], SUIT_H*zombie_mult[i], SUIT_D*zombie_mult[i], AGENCY_R, AGENCY_G, AGENCY_B, 0, 0, 0);
    agencies[i][7].update(agencies_loc[i].x + 0.0, agency_loc.y - 0.25, agencies_loc[i].z + 0.375, SUIT_W*zombie_mult[i], SUIT_H*zombie_mult[i], SUIT_D*zombie_mult[i], AGENCY_R, AGENCY_G, AGENCY_B, 0, 0, 0);
    agencies[i][8].update(agencies_loc[i].x + 0.25, agency_loc.y - 0.125, agencies_loc[i].z + 0.0, TIE_W*zombie_mult[i], TIE_H*zombie_mult[i], TIE_D*zombie_mult[i], AGENCY_R, AGENCY_G, AGENCY_B, 0, 0, 0);
    agencies[i][9].update(agencies_loc[i].x + 0.0, agency_loc.y - 0.375, agencies_loc[i].z - 0.5, APPENDAGE_W*zombie_mult[i], APPENDAGE_H*zombie_mult[i], APPENDAGE_D*zombie_mult[i], AGENCY_R, AGENCY_G, AGENCY_B, 0, 0, 0);
    agencies[i][10].update(agencies_loc[i].x + 0.0, agency_loc.y - 0.375, agencies_loc[i].z + 0.5, APPENDAGE_W*zombie_mult[i], APPENDAGE_H*zombie_mult[i], APPENDAGE_D*zombie_mult[i], AGENCY_R, AGENCY_G, AGENCY_B, 0, 0, 0);
    agencies[i][11].update(agencies_loc[i].x + 0.0, agency_loc.y - 1.5, agencies_loc[i].z - 0.25, APPENDAGE_W*zombie_mult[i], APPENDAGE_H*zombie_mult[i], APPENDAGE_D*zombie_mult[i], AGENCY_R, AGENCY_G, AGENCY_B, 0, 0, 0);
    agencies[i][12].update(agencies_loc[i].x + 0.0, agency_loc.y - 1.5, agencies_loc[i].z + 0.25, APPENDAGE_W*zombie_mult[i], APPENDAGE_H*zombie_mult[i], APPENDAGE_D*zombie_mult[i], AGENCY_R, AGENCY_G, AGENCY_B, 0, 0, 0);
    // }
  }

  if (jump) {
    mv_vel.y += 0.75;
    jump = false;
    fall = true;
  }

  if (!fall) {
    mv_vel.y = 0.0;
  }

  mv_vel.y -= 0.015;

  for (int i = 0; i < NUM_FLOORS; i++) {
    for (int j = 0; j < PARTS_FLOOR; j++) {
      collision(mv_pos.x, mv_pos.y, mv_pos.z, PLAYER_W, PLAYER_H, PLAYER_D, vec3(floors[i][j].x, floors[i][j].y, floors[i][j].z), vec3(floors[i][j].w, floors[i][j].h, floors[i][j].d), collide[i]);
      // collision(mv_pos.x, mv_pos.y, mv_pos.z, PLAYER_W, PLAYER_H, PLAYER_D, platform_loc[i], platform_size[i], collide[i]);
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
      collision(mv_pos.x, mv_pos.y, mv_pos.z, PLAYER_W, PLAYER_H, PLAYER_D, zombies_loc[i], zombies_size[i], z_die[i]);
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


  for (int i = 0; i < NUM_DOORS; i++) {
    proximity(mv_pos.x, mv_pos.y, mv_pos.z, PLAYER_W, PLAYER_H, PLAYER_D, door_loc[i], door_size[i], doors[i]);
  }
  for (int i = 0; i < NUM_INTERACTABLES; i++) {
    proximity(mv_pos.x, mv_pos.y, mv_pos.z, PLAYER_W, PLAYER_H, PLAYER_D, inter_loc[i], inter_size[i], proximal[i]);
  }
  for (int i = 0; i < NUM_PICKUPS; i++) {
    proximity(mv_pos.x, mv_pos.y, mv_pos.z, PLAYER_W, PLAYER_H, PLAYER_D, pickup_loc[i], pickup_size[i], pickup[i]);
  }

  // collision(&enemy_loc[0].x, mv_pos.y, &enemy_loc[0].z, GHOST_W, GHOST_H, GHOST_D, wall_loc, wall_size, collide, NUM_OBJECTS);

  if (!collider[1]) {
  // if (mv_pos.y > 0.0) {
  } else {
    // mv_pos.y = 0.0;
    fall = false;
  }

  for (int i = 0; i < 6; i++) {
    collider[i] = false;
  }

  mv_pos.x += mv_vel.x;
  mv_pos.y += mv_vel.y;
  mv_pos.z += mv_vel.z;

  lasttime = time;

  glutPostRedisplay();

}

#endif
