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

#define COLOR_SKY 1

// Motion rates
#define RATE_PLAYER	  0.5
#define RATE_GUN	    1

// Color vec3s
vec3 sky = vec3(SKY_R, SKY_G, SKY_B);
// vec3 sky = vec3(0.05, 0.0, 0.1);
// vec3 sky = vec3(0.8, 1.0, 1.0);

// std::uniform_real_distribution<double> sickness(0.0, 0.005);

vec3 pickup_size[NUM_PICKUPS] = { vec3(0.0, 0.0, 0.0) };

GLfloat disp_rot = 0.0;

float display_rot = 0.0;

bool fire_gun = false, reload = true, action = false, fire_mode = true;
float elevation = 0.0, frame = 3.0;
int score = 0, health = 5, shield = 7, magazine = 25, bullet_ammo = 25, rocket_ammo = 3;
int clip_size = 25;
bool solid_part = true, game_over = false;
int count = 0;

bool follow[4] = { false };

GLfloat speed_boost = 1.0;

vec3 bullet[NUM_BULLET] = { vec3(0.0, 0.0, 0.0) };
vec3 bullet_size = vec3(BULLET_W, BULLET_H, BULLET_D);
vec3 bullet_color = vec3(0.28, 0.26, 0.1);
GLfloat bullet_dist[NUM_BULLET];
GLfloat bullet_speed = 1.0;
int bullet_theta[NUM_BULLET] = { 0 };
int bullet_phi[NUM_BULLET] = { 0 };

bool debug = false,
     view_toggle = true,
     debug_toggle = true,
     fire_mode_toggle = true,
     werewolf_chase = false,
     ghost_chase = false,
     agency_chase = false,
     zombie_chase = false,
     get_gun = false,
     get_launcher = false,
     get_laser = false,
     get_vaccuum = false,
     get_coffee = false,
     get_bullet = false,
     get_rocket = false,
     get_health = false,
     get_shield = false,
     get_key = false,
     kill_ghost = false,
     active[NUM_BULLET] = { false },
     sweep_ghost = false,
     robot_collision = false;

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

void set_room(vec3 location, vec3 bound) {
  for (int i = 0; i < NUM_ROOMS; i++) {
    if (location.x - bound.x / 2 < bounds[i].x &&
        location.x + bound.x / 2 > bounds[i].y &&
        location.z - bound.z / 2 < bounds[i].z &&
        location.z + bound.z / 2 > bounds[i].w ) {
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
        case 'w': { players[0][0].velocity.z -= speed_boost * sin(theta*M_PI/180)/2; players[0][0].velocity.x -= speed_boost * cos(theta*M_PI/180)/2; } break;
        case 's': { players[0][0].velocity.z += speed_boost * sin(theta*M_PI/180)/2; players[0][0].velocity.x += speed_boost * cos(theta*M_PI/180)/2; } break;
        case 'a': { players[0][0].velocity.x -= speed_boost * sin(theta*M_PI/180)/2; players[0][0].velocity.z += speed_boost * cos(theta*M_PI/180)/2; } break;
        case 'd': { players[0][0].velocity.x += speed_boost * sin(theta*M_PI/180)/2; players[0][0].velocity.z -= speed_boost * cos(theta*M_PI/180)/2; } break;
        case ' ': { if (!players[0][0].fall) players[0][0].jump = true; } break; // Action
        case 'f': { action = true; } break; // Action
        case '/': { if (reload) { fire_gun = true; reload = false; } } break; // Shoot
        case '1': { if (get_gun) { bullet_size = vec3(BULLET_W, BULLET_H, BULLET_D); bullet_color = vec3(0.28, 0.26, 0.1); bullet_speed = 1.0; clip_size = 25; magazine = bullet_ammo; } } break; // medium size medium speed bullet
        case '2': { if (get_launcher) { bullet_size = vec3(ROCKET_W, ROCKET_H, ROCKET_D); bullet_color = vec3(0.27, 0.32, 0.17); bullet_speed = 0.5; clip_size = 3; magazine = rocket_ammo; } } break; // large size slow speed rocket
        case '3': { if (get_laser) { bullet_size = vec3(LASER_W, LASER_H, LASER_D); bullet_color = vec3(1.0, 0.25, 0.75); bullet_speed = 2.5; clip_size = 100; magazine = clip_size; } } break; // small size fast speed beam
        case 'v': { if (fire_mode_toggle) { fire_mode = !fire_mode; fire_mode_toggle = false; } } break;
        case 'c': if (view_toggle) { perspective = !perspective; view_toggle = false; } break; //fire
        // Utility
        case '-': /* lights[0] = !lights[0]; glUniform1i(Lights[0], lights[0]); */ health -= 1; break;
        case '=': /* lights[1] = !lights[1]; glUniform1i(Lights[1], lights[1]); */ health += 1; break;
        case 'W': { solid_part = !solid_part; } break; //wire
        case 'z': zNear *= 1.1; zFar /= 1.1; break;
        case 'Z': zNear /= 1.1; zFar *= 1.1; break;
        case 'r': radius *= 1.5; break;
        case 'R': radius /= 1.5; break;
        case 'X': fovy -= 5; if (fovy < 0) { fovy = 1; } break;
        case 'V': fovy += 5; /* break; */ if (fovy > 179) { fovy = 179; } break;
        case '~': zNear = 0.1; zFar = 300.0; radius = 3.0; theta = 0.0; phi = 0.0; break; // reset
        case '`': if (debug_toggle) { debug = !debug; debug_toggle = false; } break;
        default: { } break; // Default

      }
    } else {
      switch (i) {
        case '/': fire_gun = false; if (clip_size == 3 || ( clip_size == 25 && fire_mode)) { reload = true; } break; // Stop firing, not the same as bullet landing
        case ' ': { players[0][0].jump = false; } break; //wire
        case 'f': { action = false; } break; //wire
        case 'v': { fire_mode_toggle = true; } break;
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

void move_and_face(Object &actor, vec3 size, vec3 growth, vec3 color, vec3 center_loc, vec3 rot) {

  actor.update(
    vec3(actor.position.x + center_loc.z * cos((rot.y + center_loc.x) * M_PI/180), actor.position.y + center_loc.y, actor.position.z + center_loc.z * sin((rot.y + center_loc.x) * M_PI/180)),
    vec3(size.x * growth.x, size.y * growth.y, size.z * growth.z),
    vec3(color.x, color.y, color.z),
    vec3(rot.x, -rot.y, rot.z)
  );

}

void update_everything() {

  // pickup_size[0] = vec3(1.0, 1.0, 1.0);
  // pickup_size[1] = vec3(2.5, 1.0, 2.5);
  // pickup_size[2] = vec3(2.5, 1.0, 2.5);
  // pickup_size[3] = vec3(2.5, 1.0, 2.5);
  // pickup_size[4] = vec3(1.0, 1.0, 1.0);
  // pickup_size[5] = vec3(2.5, 1.0, 2.5);
  // pickup_size[6] = vec3(2.5, 1.0, 2.5);
  // pickup_size[7] = vec3(2.5, 1.0, 2.5);

  vec3 coffee_parts_rot[PARTS_COFFEE] = {
    vec3(0.0, display_rot - 45.0, 0.0),
    vec3(0.0, display_rot, 0.0),
    vec3(0.0, display_rot - 45.0, 0.0),
    vec3(0.0, display_rot, 0.0),
    vec3(0.0, display_rot - 45.0, 0.0),
    vec3(0.0, display_rot, 0.0)
  };

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

  // ghosts_loc[0] = vec3(ghost_loc.x*ghost_mult[0], ghost_height[0]*ghost_mult[0], ghost_loc.z*ghost_mult[0]);
  ghosts_size[0] = vec3(GHOST_W*ghost_mult[0], GHOST_H*ghost_mult[0], GHOST_D*ghost_mult[0]);

  for(int i = 0; i < NUM_ZOMBIES; i++) {
    zombies_size[i] = vec3(ZOMBIE_W*zombie_mult[i], ZOMBIE_H*zombie_mult[i], ZOMBIE_D*zombie_mult[i]);
  }

  // werewolves_loc[0] = vec3(werewolf_loc[0].x*werewolf_mult[0], werewolf_loc[0].y*werewolf_mult[0], werewolf_loc[0].z*werewolf_mult[0]);
  werewolves_size[0] = vec3(ZOMBIE_W*werewolf_mult[0], ZOMBIE_H*werewolf_mult[0], ZOMBIE_D*werewolf_mult[0]);

  agencies_size[0] = vec3(ZOMBIE_W*agency_mult[0], ZOMBIE_H*agency_mult[0], ZOMBIE_D*agency_mult[0]);

  for (int i = 0; i < NUM_GUNS; i++) {
    for (int j = 0; j < PARTS_GUN; j++) {
      move_and_face(guns[i][j], gun_parts_size[j],
        vec3(gun_mult[i], gun_mult[i], gun_mult[i]), gun_parts_colors[j],
        gun_parts_diff[j], vec3(0, display_rot, 0)
      );
    }
  }

  for (int i = 0; i < NUM_LAUNCHERS; i++) {
    for (int j = 0; j < PARTS_LAUNCHER; j++) {
      move_and_face(launchers[i][j], launcher_parts_size[j],
        vec3(launcher_mult[i], launcher_mult[i], launcher_mult[i]), launcher_parts_colors[j],
        launcher_parts_diff[j], vec3(0, display_rot, 0)
      );
    }
  }

  for (int i = 0; i < NUM_LASERS; i++) {
    for (int j = 0; j < PARTS_LASER; j++) {
      move_and_face(lasers[i][j], laser_parts_size[j],
        vec3(laser_mult[i], laser_mult[i], laser_mult[i]), laser_parts_colors[j],
        laser_parts_diff[j], vec3(0, display_rot, 0)
      );
    }
  }

  for (int i = 0; i < NUM_VACCUUMS; i++) {
    for (int j = 0; j < PARTS_VACCUUM; j++) {
      move_and_face(vaccuums[i][j], vacuum_parts_size[j],
        vec3(vacuum_mult[i], vacuum_mult[i], vacuum_mult[i]), vacuum_parts_colors[j],
        vacuum_parts_diff[j], vec3(0, display_rot, 0)
      );
    }
  }

  for (int i = 0; i < NUM_COFFEES; i++) {
    for (int j = 0; j < PARTS_COFFEE; j++) {
      move_and_face(coffees[i][j], coffee_parts_size[j],
        vec3(coffee_mult[i], coffee_mult[i], coffee_mult[i]), coffee_parts_colors[j],
        coffee_parts_diff[j], coffee_parts_rot[j]
      );
    }
  }

  for (int i = 0; i < NUM_BULLETS; i++) {
    for (int j = 0; j < PARTS_BULLET; j++) {
      move_and_face(bullets[i][j], bullet_parts_size[j],
        vec3(bullet_mult[i], bullet_mult[i], bullet_mult[i]), bullet_parts_colors[j],
        bullet_parts_diff[j], vec3(0, display_rot, 45)
      );
    }
  }

  for (int i = 0; i < NUM_ROCKETS; i++) {
    for (int j = 0; j < PARTS_ROCKET; j++) {
      move_and_face(rockets[i][j], rocket_parts_size[j],
        vec3(rocket_mult[i], rocket_mult[i], rocket_mult[i]), rocket_parts_colors[j],
        rocket_parts_diff[j], vec3(0, display_rot, 45)
      );
    }
  }

  for (int i = 0; i < NUM_HEALTHS; i++) {
    for (int j = 0; j < PARTS_HEALTH; j++) {
      move_and_face(vaccuums[i][j], health_parts_size[j],
        vec3(health_mult[i], health_mult[i], health_mult[i]), health_parts_colors[j],
        health_parts_diff[j], vec3(display_rot, display_rot, display_rot)
      );
    }
  }

  for (int i = 0; i < NUM_SHIELDS; i++) {
    for (int j = 0; j < PARTS_SHIELD; j++) {
      move_and_face(shields[i][j], shield_parts_size[j],
        vec3(shield_mult[i], shield_mult[i], shield_mult[i]), shield_parts_colors[j],
        shield_parts_diff[j], vec3(display_rot, display_rot, display_rot)
      );
    }
  }

  for (int i = 0; i < NUM_KEYS; i++) {
    for (int j = 0; j < PARTS_KEY; j++) {
      move_and_face(keys[i][j], key_parts_size[j],
        vec3(key_mult[i], key_mult[i], key_mult[i]), key_parts_colors[j],
        key_parts_diff[j], vec3(0, display_rot, 0)
      );
    }
  }

  for (int i = 0; i < NUM_GHOSTS; i++) {
    for (int j = 0; j < PARTS_GHOST; j++) {
      move_and_face(ghosts[i][j], ghost_parts_size[j],
        vec3(ghost_mult[i], ghost_mult[i], ghost_mult[i]), ghost_parts_colors[j],
        ghost_parts_diff[j], vec3(ghost_parts_rot[j].x, ghost_theta[i], ghost_parts_rot[j].z)
      );
    }
  }

  for (int i = 0; i < NUM_ZOMBIES; i++) {
    for (int j = 0; j < PARTS_ZOMBIE; j++) {
      move_and_face(zombies[i][j], zomb_parts_size[j],
        vec3(zombie_mult[i], zombie_mult[i], zombie_mult[i]), zomb_parts_colors[j],
        zomb_parts_diff[j], vec3(0, zombie_theta[i], 0)
      );
    }
  }

  for (int i = 0; i < NUM_WEREWOLFS; i++) {
    for (int j = 0; j < PARTS_WEREWOLF; j++) {
      move_and_face(werewolfs[i][j], wolf_parts_size[j],
        vec3(werewolf_mult[i], werewolf_mult[i], werewolf_mult[i]), wolf_parts_colors[j],
        wolf_parts_diff[j], vec3(0, werewolf_theta[i], 0)
      );
    }
  }

  for (int i = 0; i < NUM_AGENCIES; i++) {
    for (int j = 0; j < PARTS_AGENCIE; j++) {
      move_and_face(agencies[i][j], agen_parts_size[j],
        vec3(agency_mult[i], agency_mult[i], agency_mult[i]), agen_parts_colors[j],
        agen_parts_diff[j], vec3(0, agency_theta[i], 0)
      );
    }
  }

}

// animation function, runs the updating of the variables
void animation(void) {

  static GLint lasttime = glutGet(GLUT_ELAPSED_TIME);
  GLint nowtime = glutGet(GLUT_ELAPSED_TIME);
  GLint dtime = nowtime - lasttime;
  std::cout << dtime << std::endl;

  set_room(players[0][0].position, players[0][0].size);

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
  if (pickup[4]) { get_bullet = true; }
  if (pickup[5]) { get_rocket = true; }
  if (pickup[6]) { get_health = true; }
  if (pickup[7]) { get_shield = true; }
  if (pickup[8]) { get_launcher = true; }
  if (pickup[9]) { get_laser = true; }

  if (follow[3]) { agency_chase = true; } else { agency_chase = false; }
  if (follow[2]) { werewolf_chase = true; } else { werewolf_chase = false; }
  if (follow[0]) { ghost_chase = true; } else { ghost_chase = false; }
  if (follow[1]) { zombie_chase = true; } else { zombie_chase = false; }

  if (frame >= 0.0 && frame <= 360.0) {
    if (step == 0 || step == 2) {
      if (frame == 0.0) frame = 1.0;
      if (frame == 360) step++;
      if (frame < 360) frame = frame + 1.0;
      for (int i = 0; i < 5; i++){ ghost_height[i] = sin((frame - i)*M_PI/30); }
      display_rot = frame;
      // display_rot += 0.1;
      // if (display_rot > 359.9) {
      //   display_rot = 0.0;
      // }
    } else if (step == 1 || step == 3) {
      if (frame == 0.0) step++;
      if (frame > 0) frame = frame - 1.0;
      for (int i = 0; i < 5; i++){ ghost_height[i] = -sin((frame - i)*M_PI/30); }
      display_rot = -frame;
    }

  }

  if (step == 4) step = 0;

  if (health == 0) death = true;

  if (ghost_chase) {
    for (int i = 0; i < NUM_GHOSTS; i++) {
      for (int j = 0; j < PARTS_GHOST; j++) {
        ghosts[i][j].chase_(players[0][0].position, 0.1);
      }
    }
  }

  if (agency_chase) {
    for (int i = 0; i < NUM_AGENCIES; i++) {
      for (int j = 0; j < PARTS_AGENCIE; j++) {
        agencies[i][j].chase_(players[0][0].position, 0.1);
      }
    }
  }

  if (werewolf_chase) {
    for (int i = 0; i < NUM_WEREWOLFS; i++) {
      for (int j = 0; j < PARTS_WEREWOLF; j++) {
        werewolfs[i][j].chase_(players[0][0].position, 0.05);
      }
    }
  }

  if (zombie_chase) {
    for (int i = 0; i < NUM_ZOMBIES; i++) {
      for (int j = 0; j < PARTS_ZOMBIE; j++) {
        zombies[i][j].chase_(players[0][0].position, (i + 1) * 0.05);
      }
    }
  }

  if (kill_ghost) {
    if (ghost_mult[0] >= 0.0) {
      ghost_mult[0] -= 0.01;
    }
  }

  if (get_coffee) {
    speed_boost = 2.0;
    energize = true;
    get_coffee = false;
    pickup[3] = false;
  }

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
        if (agency_mult[i] >= 0.0) {
          agency_mult[i] -= 0.01;
        }
      }
    }
    if (fire_gun) {
      for (int i = 0; i < NUM_BULLET; i++) {
        if (magazine <= 0) {
          if (bullet_ammo > 0 && rocket_ammo > 0) {
            if (clip_size == 25) {
              if (count >= 40) {
                magazine = clip_size;
                count = 0;
              }
            } else if (clip_size == 3) {
              if (count >= 80) {
                magazine = clip_size;
                count = 0;
              }
            }
            count++;
          }
        } else if (!active[i]) {
          // reload = false;
          active[i] = true;
          bullet[i] = players[0][0].position;
          bullet_theta[i] = theta;
          bullet_phi[i] = phi;
          bullet_dist[i] = 0.0;
          magazine--;
          if (clip_size == 25) {
            bullet_ammo--;
          }
          if (clip_size == 3) {
            rocket_ammo--;
          }
          fire_gun = false;
          break;
        }
        if (clip_size == 100) {
          if (magazine < 50) {
            magazine++;
          }
        }

      }
    } else {
      if (clip_size == 25 && !fire_mode) {
        reload = true;
      }
    }
  }

  if (get_launcher) {
  }

  if (get_laser) {
  }

  if (get_vaccuum) {
    if (g_die[0]) kill_ghost = true;
  } else {
    if (g_die[0]) {
      health--;
      hurt = true;
    } // exit(EXIT_FAILURE);
  }

  if (get_bullet) {
    bullet_ammo += 25;
    magazine = bullet_ammo;
    resupply = true;
    get_bullet = false;
    pickup[4] = false;
  }

  if (get_rocket) {
    rocket_ammo += 3;
    magazine = rocket_ammo;
    resupply = true;
    get_rocket = false;
    pickup[5] = false;
  }

  if (get_health) {
    health += 3;
    heal = true;
    get_health = false;
    pickup[6] = false;
  }

  if (get_shield) {
    shield += 3;
    strengthen = true;
    get_shield = false;
    pickup[7] = false;
  }

  if (get_key) { exit(EXIT_SUCCESS); }

  // for (int i = 0; i < NUM_ENEMIES; i++) {
    if (p_die[0]) {
      health--;
      hurt = true;
      p_die[0] = false;
    }// exit(EXIT_FAILURE);
    if (p_die[1]) {
      if (shield > 0) {
        shield--;
        hurt = true;
      } else {
        health -= 2;
        hurt = true;
      }
      p_die[1] = false;
    }// exit(EXIT_FAILURE);
    if (p_die[2]) {
      if (shield > 0) {
        shield -= 2;
        hurt = true;
      } else {
        health--;
        hurt = true;
      }
      magazine--;
      p_die[2] = false;
    }// exit(EXIT_FAILURE);
    if (p_die[3]) {
      if (shield > 0) {
        shield--;
        hurt = true;
      } else {
        health--;
        hurt = true;
      }
      if (clip_size == 25) {
        bullet_ammo--;
      }
      if (clip_size == 3) {
        rocket_ammo--;
      }
      p_die[3] = false;
    }// exit(EXIT_FAILURE);
  // }

  if(hurt) {
    players[0][0].velocity.z += 20.0 * sin(theta*M_PI/180)/2;
    players[0][0].velocity.x += 20.0 * cos(theta*M_PI/180)/2;
  }

  if (mouse_button == 3 && changed) { fovy -= 5.0; changed = false; } else if (mouse_button == 4 && changed) { fovy += 5.0; changed = false; }

  update_everything();

  for (int i = 0; i < NUM_PLAYERS; i++) {
    for (int j = 0; j < PARTS_PLAYER; j++) {
      players[i][j].gravity_update();
    }
  }

  for (int i = 0; i < NUM_ZOMBIES; i++) {
    for (int j = 0; j < PARTS_ZOMBIE; j++) {
      zombies[i][j].gravity_update();
    }
  }


  for (int i = 0; i < NUM_GHOSTS; i++) {
    for (int j = 0; j < PARTS_GHOST; j++) {
      ghosts[i][j].gravity_update();
    }
  }

  for (int i = 0; i < NUM_WEREWOLFS; i++) {
    for (int j = 0; j < PARTS_WEREWOLF; j++) {
      werewolfs[i][j].gravity_update();
    }
  }
  for (int i = 0; i < NUM_FLOORS; i++) {
    for (int j = 0; j < PARTS_FLOOR; j++) {
      collision(players[0][0].position, players[0][0].size, players[0][0].velocity, floors[i][j].position, floors[i][j].size, collide[i], 0.0, true, players[0][0].collide);
    }
  }

  for (int i = 0; i < NUM_FLOORS; i++) {
    for (int j = 0; j < PARTS_FLOOR; j++) {
      for (int k = 0; k < NUM_ZOMBIES; k++) {
        for (int l = 0; l < PARTS_ZOMBIE; l++) {
          collision(zombies[k][l].position, players[0][0].size, zombies[k][l].velocity, floors[i][j].position, floors[i][j].size, collide[i], 0.0, true, zombies[k][l].collide);
        }
      }
    }
  }

  for (int i = 0; i < NUM_FLOORS; i++) {
    for (int j = 0; j < PARTS_FLOOR; j++) {
      for (int k = 0; k < NUM_GHOSTS; k++) {
        for (int l = 0; l < PARTS_GHOST; l++) {
          collision(ghosts[k][l].position, players[0][0].size, ghosts[k][l].velocity, floors[i][j].position, floors[i][j].size, collide[i], 0.0, true, ghosts[k][l].collide);
        }
      }
    }
  }

  for (int i = 0; i < NUM_FLOORS; i++) {
    for (int j = 0; j < PARTS_FLOOR; j++) {
      for (int k = 0; k < NUM_WEREWOLFS; k++) {
        for (int l = 0; l < PARTS_WEREWOLF; l++) {
          collision(werewolfs[k][l].position, players[0][0].size, werewolfs[k][l].velocity, floors[i][j].position, floors[i][j].size, collide[i], 0.0, true, werewolfs[k][l].collide);
        }
      }
    }
  }

  for (int i = 0; i < NUM_FLOORS; i++) {
    for (int j = 0; j < PARTS_FLOOR; j++) {
      for (int k = 0; k < NUM_AGENCIES; k++) {
        for (int l = 0; l < PARTS_AGENCIE; l++) {
          collision(agencies[k][l].position, players[0][0].size, agencies[k][l].velocity, floors[i][j].position, floors[i][j].size, collide[i], 0.0, true, agencies[k][l].collide);
        }
      }
    }
  }

  bool filler = false;

  if(!debug) {

    // for (int i = 0; i < NUM_OBJECTS; i++) {
      // collision(players[0][0].position, players[0][0].size, players[0][0].velocity, wall_loc[i], wall_size[i], collide[i]);
    // }

    for (int i = 0; i < NUM_GHOSTS; i++) { collision(players[0][0].position, players[0][0].size, players[0][0].velocity, ghosts[i][0].position, players[0][0].size, g_die[i], 0.0, true, filler); }
    for (int i = 0; i < NUM_ZOMBIES; i++) { collision(players[0][0].position, players[0][0].size, players[0][0].velocity, zombies[i][0].position, players[0][0].size, p_die[1], 0.0, true, filler); }
    for (int i = 0; i < NUM_WEREWOLFS; i++) { collision(players[0][0].position, players[0][0].size, players[0][0].velocity, werewolfs[i][0].position, players[0][0].size, p_die[2], 0.0, true, filler); }
    for (int i = 0; i < NUM_AGENCIES; i++) { collision(players[0][0].position, players[0][0].size, players[0][0].velocity, agencies[i][0].position, players[0][0].size, p_die[3], 0.0, true, filler); }

    for (int i = 0; i < NUM_BULLET; i++) {
      vec3 bullet_adj_pos = vec3(
        bullet[i].x - bullet_dist[i] * cos(bullet_theta[i] * M_PI/180) * cos(bullet_phi[i] * M_PI/180),
        bullet[i].y - bullet_dist[i] * sin(bullet_phi[i] * M_PI/180),
        bullet[i].z - bullet_dist[i] * sin(bullet_theta[i] * M_PI/180) * cos(bullet_phi[i] * M_PI/180)
      );
      if (active[i]) {
        for (int j = 0; j < NUM_ZOMBIES; j++) { collision(bullet_adj_pos, bullet_size, players[0][0].velocity, zombies[i][0].position, players[0][0].size, z_die[j], 1.0, false, filler); }
        for (int j = 0; j < NUM_WEREWOLFS; j++) { collision(bullet_adj_pos, bullet_size, players[0][0].velocity, werewolfs[i][0].position, players[0][0].size, w_die[j], 1.0, false, filler); }
        for (int j = 0; j < NUM_AGENCIES; j++) { collision(bullet_adj_pos, bullet_size, players[0][0].velocity, agencies[i][0].position, players[0][0].size, a_die[j], 1.0, false, filler); }
      }
    }

    for (int i = 0; i < NUM_GHOSTS; i++) { collision(players[0][0].position, players[0][0].size, players[0][0].velocity, ghosts[i][0].position, players[0][0].size, follow[0], 15.0, false, filler); }
    for (int i = 0; i < NUM_ZOMBIES; i++) { collision(players[0][0].position, players[0][0].size, players[0][0].velocity, zombies[i][0].position, players[0][0].size, follow[1], 20.0, false, filler); }
    for (int i = 0; i < NUM_WEREWOLFS; i++) { collision(players[0][0].position, players[0][0].size, players[0][0].velocity, werewolfs[i][0].position, players[0][0].size, follow[2], 30.0, false, filler); }
    for (int i = 0; i < NUM_AGENCIES; i++) { collision(players[0][0].position, players[0][0].size, players[0][0].velocity, agencies[i][0].position, players[0][0].size, follow[3], 25.0, false, filler); }

  }

  // for (int i = 0; i < NUM_FLOORS; i++) {
  //   for (int j = 0; j < PARTS_FLOOR; j++) {
  //     for (int k = 0; k < NUM_WEREWOLFS; k++) {
  //       for (int l = 0; l < PARTS_WEREWOLF; l++) {
  //         werewolfs[k][l].collision(floors[i][j].position, floors[i][j].size, robot_collision, 0.0, false);
  //       }
  //     }
  //   }
  // }



  // for (int i = 0; i < NUM_DOORS; i++) {
  //   collision(players[0][0].position, players[0][0].size, door_loc[i], door_size[i], doors[i]);
  // }

  // for (int i = 0; i < NUM_INTERACTABLES; i++) {
  //   collision(players[0][0].position, players[0][0].size, inter_loc[i], inter_size[i], proximal[i]);
  // }



  for (int i = 0; i < NUM_GUNS; i++) { collision(players[0][0].position, players[0][0].size, players[0][0].velocity, gun_loc[i], pickup_size[0], pickup[0], 1.0, false, filler); }
  for (int i = 0; i < NUM_LAUNCHERS; i++) { collision(players[0][0].position, players[0][0].size, players[0][0].velocity, launcher_loc[i], pickup_size[8], pickup[8], 1.0, false, filler); }
  for (int i = 0; i < NUM_LASERS; i++) { collision(players[0][0].position, players[0][0].size, players[0][0].velocity, laser_loc[i], pickup_size[9], pickup[9], 1.0, false, filler); }
  for (int i = 0; i < NUM_VACCUUMS; i++) { collision(players[0][0].position, players[0][0].size, players[0][0].velocity, vacuum_loc[i], pickup_size[1], pickup[1], 1.0, false, filler); }
  for (int i = 0; i < NUM_COFFEES; i++) { collision(players[0][0].position, players[0][0].size, players[0][0].velocity, coffee_loc[i], pickup_size[3], pickup[3], 1.0, false, filler); }
  for (int i = 0; i < NUM_BULLETS; i++) { collision(players[0][0].position, players[0][0].size, players[0][0].velocity, bullet_loc[i], pickup_size[4], pickup[4], 1.0, false, filler); }
  for (int i = 0; i < NUM_ROCKETS; i++) { collision(players[0][0].position, players[0][0].size, players[0][0].velocity, rocket_loc[i], pickup_size[5], pickup[5], 1.0, false, filler); }
  for (int i = 0; i < NUM_HEALTHS; i++) { collision(players[0][0].position, players[0][0].size, players[0][0].velocity, health_loc[i], pickup_size[6], pickup[6], 1.0, false, filler); }
  for (int i = 0; i < NUM_SHIELDS; i++) { collision(players[0][0].position, players[0][0].size, players[0][0].velocity, shield_loc[i], pickup_size[7], pickup[7], 1.0, false, filler); }
  for (int i = 0; i < NUM_KEYS; i++) { collision(players[0][0].position, players[0][0].size, players[0][0].velocity, key_loc[i], pickup_size[2], pickup[2], 1.0, false, filler); }



  for (int i = 0; i < NUM_WEREWOLFS; i++) {
    for (int j = 0; j < PARTS_WEREWOLF; j++) {
      werewolfs[i][j].position_update();
    }
  }

  for (int i = 0; i < NUM_ZOMBIES; i++) {
    for (int j = 0; j < PARTS_ZOMBIE; j++) {
      zombies[i][j].position_update();
    }
  }


  for (int i = 0; i < NUM_GHOSTS; i++) {
    for (int j = 0; j < PARTS_GHOST; j++) {
      ghosts[i][j].position_update();
    }
  }

  for (int i = 0; i < NUM_PLAYERS; i++) {
    for (int j = 0; j < PARTS_PLAYER; j++) {
      players[i][j].position_update();
    }
  }



  for (int i = 0; i < NUM_PLAYERS; i++) {
    for (int j = 0; j < PARTS_PLAYER; j++) {
      players[i][j].check_fall_death();
    }
  }

  for (int i = 0; i < NUM_ZOMBIES; i++) {
    for (int j = 0; j < PARTS_ZOMBIE; j++) {
      zombies[i][j].check_fall_death();
    }
  }


  for (int i = 0; i < NUM_GHOSTS; i++) {
    for (int j = 0; j < PARTS_GHOST; j++) {
      ghosts[i][j].check_fall_death();
    }
  }

  for (int i = 0; i < NUM_WEREWOLFS; i++) {
    for (int j = 0; j < PARTS_WEREWOLF; j++) {
      werewolfs[i][j].check_fall_death();
    }
  }



  title_bar = " X: " + std::to_string(players[0][0].position.x)
            + " Y: " + std::to_string(players[0][0].position.y)
            + " Z: " + std::to_string(players[0][0].position.z)
            + " WE: " + std::to_string(werewolfs[0][0].position.y);
            // 0.01 * (time - lasttime)); // + " l:" + std::to_string(l) + " r:" + std::to_string(r) + " f:" + std::to_string(f) + " b:" + std::to_string(b);

  if (health <= 0) { exit(EXIT_SUCCESS); }

  // ENVIRONMENT
  disp_rot = display_rot;

  lasttime = nowtime;

  glutPostRedisplay();

}

#endif
