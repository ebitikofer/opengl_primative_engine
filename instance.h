#ifndef INSTANCE_H
#define INSTANCE_H

#include <Angel.h>
#include "engine.h"
#include "game.h"
#include "models.h"

// Motion rates
#define RATE_PLAYER	  0.5
#define RATE_GUN	    1

#define NUM_ZOMBIES	3

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
        door_height = 27.5,
        speed_boost = 1.0;

vec3 zombie_loc[NUM_ZOMBIES] = {
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
  vec4(-25.0, -50.0, 40.0, 0.0),
  vec4(-25.0, -50.0, 0.0, -50.0),
  vec4(0.0, -25.0, 0.0, -50.0),
  vec4(25.0, 0.0, 0.0, -25.0),
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

  if (rooms[0]) {
    if (doors[0]){
      if (action) {
        open_door[0] = true;
      }
    }
    if (doors[8]){
      if (action) {
        open_door[8] = true;
      }
    }
  } else { }

  if (rooms[1]) {
    if (doors[1]){
      if (action) {
        open_door[1] = true;
      }
    }
  } else { }

  if (rooms[2]) {
    // ghost_chase = true;
    if (pickup[0]){
      get_sweeper = true;
    }
    if (doors[2]){
      if (action) {
        open_door[2] = true;
      }
    }
    if (doors[9]){
      if (action) {
        open_door[9] = true;
      }
    }
  }
  else { ghost_chase = false; }

  if (rooms[3]) {
    if (proximal[2]){
      if (action) {
        fix_picture = true;
      }
    }
    // if (doors[3]){
    //   if (action) {
    //     open_door[3] = true;
    //   }
    // }
  } else {
    lose_power = false;
  }

  if (rooms[4]) {
    light1 = true;
    glUniform1i(Light1,light1);
    light2 = true;
    glUniform1i(Light2,light2);
    agency_loc = vec3(12.5, 0.0, -51.0);
    if (proximal[3]){
      if (action) {
        bookcase_open = true;
      }
    }
  } else {
    bookcase_open = false;
  }

  if (rooms[5]) {
    if (pickup[1]){
      get_key = true;
    }
    if (doors[4]){
      if (action) {
        if (get_key) {
          open_door[4] = true;
        }
      }
    }
  } else { }

  if (rooms[6]) {
    if (!agency_chase) {
      agency_loc = vec3(45.0, 0.0, 15.0);
    }
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
    agency_chase = false;
  }

  if (rooms[7]) {
    zombie_chase = true;
    if (pickup[2]){
      get_gun = true;
    }
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
  else { zombie_chase = false; }

  if (rooms[8]) {
    agency_loc = vec3(51.0, 0.0, 30.0);
    if (doors[7]){
      if (action) {
        open_door[7] = true;
      }
    }
  } else { }

  if (rooms[9]) {
    shut_door = true;
    if (pickup[3]){
      get_coffee = true;
    }
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

      display_rot += frame;
      // display_rot += 0.1;
      // if (display_rot > 359.9) {
      //   display_rot = 0.0;
      // }

      if (lose_power && flicker < 7) {
        light1 = !light1;
        glUniform1i(Light1,light1);
        flicker++;
      }

      if (lose_power && flicker >= 7 && flicker < 15) {
        flicker++;
        // agency_loc = vec3(12.5, 0.0, -12.5);
        door_color = vec3(0.25, 0.15, 0.05);
        open_door[3] = true;
      }

      if (lose_power && flicker >= 15) {
        light1 = false;
        glUniform1i(Light1,light1);
        light2 = false;
        glUniform1i(Light2,light2);
      }

    } else if (step == 1 || step == 3) {

      if (frame == 0.0) step++;
      if (frame > 0) frame = frame - 1.0;
      for (int i = 0; i < 5; i++){
        ghost_height[i] = -sin((frame - i)*M_PI/30);
      }

      display_rot -= frame;

      if (lose_power && flicker < 7) {
        light2 = !light2;
        glUniform1i(Light2,light2);
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
        case '-': /* light1 = !light1; glUniform1i(Light1,light1); */ health -= 1; break;
        case '=': /* light2 = !light2; glUniform1i(Light2,light2); */ health += 1; break;
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

  if (jump) {
    mv_vel.y += 0.75;
    jump = false;
    fall = true;
  }

  if (!fall) {
    mv_vel.y = 0.0;
  }

  mv_vel.y -= 0.015;

  for (int i = 0; i < 1; i++) {
    collision(mv_pos.x, mv_pos.y, mv_pos.z, PLAYER_W, PLAYER_H, PLAYER_D, platform_loc[i], platform_size[i], collide[i]);
  }

  if(!debug) {
    // for (int i = 0; i < NUM_OBJECTS; i++) {
      // collision(mv_pos.x, mv_pos.y, mv_pos.z, PLAYER_W, PLAYER_H, PLAYER_D, wall_loc[i], wall_size[i], collide[i]);
    // }
    // for (int i = 0; i < NUM_BOOKCASE; i++) {
      // collision(mv_pos.x, mv_pos.y, mv_pos.z, PLAYER_W, PLAYER_H, PLAYER_D, bookcase_loc[i], bookcase_size[i], collide[i]);
    // }
    // for (int i = 0; i < NUM_DOORS; i++) {
      // if (!open_door[i]) collision(mv_pos.x, mv_pos.y, mv_pos.z, PLAYER_W, PLAYER_H, PLAYER_D, door_loc[i], door_size[i], collide[i]);
    // }
    for (int i = 0; i < NUM_TABLES; i++) {
      collision(mv_pos.x, mv_pos.y, mv_pos.z, PLAYER_W, PLAYER_H, PLAYER_D, table_loc[i], table_size[i], collide[i]);
    }
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
