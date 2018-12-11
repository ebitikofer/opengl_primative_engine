//***************
// Eric Bitikofer
// 10/14/18
// 3D game made in OpenGL
//

#include <Angel.h>
#include "engine.h"
#include "models.h"
#include "object.h"
#include "instance.h"
#include "game.h"
#include "menu.h"

cardinal door_dir[NUM_DOORS];

// display function, update everything for display
void display(void) {

  if (!solid_part) glPolygonMode( GL_FRONT_AND_BACK, GL_LINE );
              else glPolygonMode( GL_FRONT_AND_BACK, GL_FILL );

  if (perspective) radius = 6.0;
              else radius = 0.1;

  glutSetWindowTitle(title_bar.c_str());

  point4  eye(players[0][0].position.x + radius * cos(theta * M_PI/180) * cos(phi * M_PI/180),
              players[0][0].position.y + radius * sin(phi * M_PI/180),
              players[0][0].position.z + radius * sin(theta * M_PI/180) * cos(phi * M_PI/180),
              1.0);
  point4  at(players[0][0].position.x, players[0][0].position.y, players[0][0].position.z, 1.0);
  vec4    up(0.0, 1.0, 0.0, 0.0);

  glClearColor(sky.x, sky.y, sky.z, 0.0);
  glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

  p = Perspective(fovy, aspect, zNear, zFar);
  cv = LookAt(eye, at, up);
  glUniformMatrix4fv(projection, 1, GL_TRUE, p);
  glUniformMatrix4fv(camera_view, 1, GL_TRUE, cv);

  // traverse( &nodes[Torso] );
  // traverse( floor_model[0] );

  // Environment
  // light();
  // walls();
  // roof();

  render_[FLOORS] = true;

  if (!get_gun) { render_[GUNS] = true; }
  else { render_[GUNS] = false; } // if (!get_gun) gun_pickup(); else ; // gun();
  if (!get_launcher) { render_[LAUNCHERS] = true; }
  else { render_[LAUNCHERS] = false; }
  if (!get_laser) { render_[LASERS] = true; }
  else { render_[LASERS] = false; }
  if (!get_vaccuum) { render_[VACCUUMS] = true; }
  else { render_[VACCUUMS] = false; }

  if (!get_coffee) { render_[COFFEES] = true; }
  else { render_[COFFEES] = false; }

  if (!get_bullet) { render_[BULLETS] = true; }
  else { render_[BULLETS] = false; }
  if (!get_rocket) { render_[ROCKETS] = true; }
  else { render_[ROCKETS] = false; }
  if (!get_health) { render_[HEALTHS] = true; }
  else { render_[HEALTHS] = false; }
  if (!get_shield) { render_[SHIELDS] = true; }
  else { render_[SHIELDS] = false; }

  if (!get_key) { render_[KEYS] = true; }
  else { render_[KEYS] = false; }

  if (perspective) { render_[PLAYERS] = true; }
  else { render_[PLAYERS] = false; }

  render_[GHOSTS] = true;
  render_[ZOMBIES] = true;
  render_[WEREWOLFS] = true;
  render_[AGENCIES] = true;

  for (int i = 0; i < NUM_BULLET; i++) {
    if (active[i]) {
      bullet_dist[i] += bullet_speed;
      object(mv, model_view, bullet[i].x - bullet_dist[i] * cos(bullet_theta[i] * M_PI/180) * cos(bullet_phi[i] * M_PI/180), bullet[i].y - bullet_dist[i] * sin(bullet_phi[i] * M_PI/180), bullet[i].z - bullet_dist[i] * sin(bullet_theta[i] * M_PI/180) * cos(bullet_phi[i] * M_PI/180), bullet_size.x, bullet_size.y, bullet_size.z, bullet_color.x, bullet_color.y, bullet_color.z, bullet_phi[i], -bullet_theta[i], bullet_phi[i], 0, 0, 0);
      std::cout << bullet_dist[i] << std::endl;
      if (bullet_dist[i] >= DRAW_DISTANCE) {
        std::cout << "deactivate" << std::endl;
        active[i] = false;
      }
    }
  }

  render_models(/*mvstack*/ heal, hurt, strengthen, weaken, resupply, energize, hallucinate, aps, dps, sps, light_ambients, light_diffuses, light_speculars, ambient_product, diffuse_product, specular_product, ambient_product2, diffuse_product2, specular_product2, enable, color_a_pink, emissive, Material_Emiss, shiny);

  // HUD

  cv = mat4(1.0);
  pv = mat4(1.0);
  glUniformMatrix4fv(camera_view, 1, GL_TRUE, cv);
  glUniformMatrix4fv(projection, 1, GL_TRUE, pv);

  // render_hud(/*mvstack*/ hurt, hallucinate, aps, dps, sps, light_ambients, light_diffuses, light_speculars, ambient_product, diffuse_product, specular_product, ambient_product2, diffuse_product2, specular_product2, enable, color_a_pink, emissive, Material_Emiss, shiny);

  float rp_x = 0.0;
  float rp_y = 0.0;
  float hp_x = -0.95;
  float hp_y = 0.95;
  float sp_x = -0.95;
  float sp_y = 0.95;
  float am_x = 0.95;
  float am_y = -0.95;

  object(mv, model_view, rp_x, rp_y, 0.0, 0.01 * sc_x, 0.2 * sc_y, 0.0, 0.01, 0.125, 0.125, 0, 0, 0, 0, 0, 4);
  object(mv, model_view, rp_x, rp_y, 0.0, 0.01 * sc_x, 0.05 * sc_y, 0.0, 0.01, 0.125, 0.125, 0, 0, 45, 0, 0, 4);
  object(mv, model_view, rp_x, rp_y, 0.0, 0.01 * sc_x, 0.1 * sc_y, 0.0, 0.01, 0.125, 0.125, 0, 0, 90, 0, 0, 4);
  object(mv, model_view, rp_x, rp_y, 0.0, 0.01 * sc_x, 0.05 * sc_y, 0.0, 0.01, 0.125, 0.125, 0, 0, 135, 0, 0, 4);

  for (int i = 0; i < health; i++) {
    object(mv, model_view, hp_x - 0.015 * sc_x + 0.1 * i, hp_y, 0.0, 0.025 * sc_x, 0.025 * sc_y, 0.0, 0.25, 0.0, 0.0, 0, 0, -135, 0, 0, 4);
    object(mv, model_view, hp_x + 0.015 * sc_x + 0.1 * i, hp_y, 0.0, 0.025 * sc_x, 0.025 * sc_y, 0.0, 0.25, 0.0, 0.0, 0, 0, -135, 0, 0, 4);
    object(mv, model_view, hp_x + 0.1 * i, hp_y, 0.0, 0.05 * sc_x, 0.05 * sc_y, 0.0, 0.25, 0.0, 0.0, 0, 0, 45, 0, 0, 3);
  }

  for (int i = 0; i < shield; i++) {
    object(mv, model_view, hp_x - 0.00075 * sc_x + 0.0666 * i, hp_y - 0.085 * sc_y, 0.0, 0.01 * sc_x, 0.03 * sc_y, 0.0, 0.0, 1.0, 1.0, 0, 0, 0, 0, 0, 4);
    object(mv, model_view, hp_x - 0.00075 * sc_x + 0.0666 * i, hp_y - 0.085 * sc_y, 0.0, 0.01 * sc_x, 0.03 * sc_y, 0.0, 0.0, 1.0, 1.0, 0, 0, 90, 0, 0, 4);
    object(mv, model_view, hp_x - 0.00075 * sc_x + 0.0666 * i, hp_y - 0.085 * sc_y, 0.0, 0.01 * sc_x, 0.03 * sc_y, 0.0, 0.0, 1.0, 1.0, 0, 0, 180, 0, 0, 4);
    object(mv, model_view, hp_x - 0.00075 * sc_x + 0.0666 * i, hp_y - 0.085 * sc_y, 0.0, 0.01 * sc_x, 0.03 * sc_y, 0.0, 0.0, 1.0, 1.0, 0, 0, 270, 0, 0, 4);
  }

  if (get_gun) {
    if (clip_size == 25) {
      for (int i = 0; i < magazine; i++) {
        object(mv, model_view, am_x - 0.05 * i, am_y + 0.025 * sc_y, 0.0, 0.025 * sc_x, 0.025 * sc_y, 0.0, BULLET_R, BULLET_G, BULLET_B, 0, 0, -135, 0, 0, 3);
        object(mv, model_view, am_x - 0.05 * i, am_y, 0.0, 0.03 * sc_x, 0.05 * sc_y, 0.0, 0.1, 0.1, 0.1, 0, 0, 180, 0, 0, 4);
        object(mv, model_view, am_x - 0.05 * i, am_y, 0.0, 0.03 * sc_x, 0.05 * sc_y, 0.0, 0.1, 0.1, 0.1, 0, 0, 0, 0, 0, 4);
      }
    } else if (clip_size == 3) {
      for (int i = 0; i < magazine; i++) {
        object(mv, model_view, am_x - 0.05 * i, am_y + 0.025 * sc_y, 0.0, 0.025 * sc_x, 0.025 * sc_y, 0.0, ROCKET_R, ROCKET_G, ROCKET_B, 0, 0, -135, 0, 0, 3);
        object(mv, model_view, am_x - 0.05 * i, am_y, 0.0, 0.03 * sc_x, 0.05 * sc_y, 0.0, ROCKET_R, ROCKET_G, ROCKET_B, 0, 0, 180, 0, 0, 4);
        object(mv, model_view, am_x - 0.05 * i, am_y, 0.0, 0.03 * sc_x, 0.05 * sc_y, 0.0, ROCKET_R, ROCKET_G, ROCKET_B, 0, 0, 0, 0, 0, 4);
        object(mv, model_view, am_x - 0.05 * i - 0.011, am_y, 0.0, 0.05 * sc_y, 0.03 * sc_x, 0.0, ROCKET_R, ROCKET_G, ROCKET_B, 0, 0, 90, 0, 0, 4);
        object(mv, model_view, am_x - 0.05 * i + 0.009, am_y, 0.0, 0.03 * sc_x, 0.05 * sc_y, 0.0, ROCKET_R, ROCKET_G, ROCKET_B, 0, 0, 0, 0, 0, 4);
      }
    } else if (clip_size == 100) {
      for (int i = 0; i < magazine; i++) {
        object(mv, model_view, am_x - 0.01 * i, am_y + 0.0125, 0.0, 0.01 * sc_x, 0.06 * sc_y, 0.0, LASER_R, LASER_G, LASER_B, 0, 0, 180, 0, 0, 4);
        object(mv, model_view, am_x - 0.01 * i, am_y + 0.0125, 0.0, 0.01 * sc_x, 0.06 * sc_y, 0.0, LASER_R, LASER_G, LASER_B, 0, 0, 0, 0, 0, 4);
      }
    }
  }

  glFlush();
  glutSwapBuffers();

}

int main(int argc, char **argv) {

  init(argc, argv);

  glutDisplayFunc(display);
  glutIdleFunc(animation); // Game start
  glutMenu();

  // RUN
  glutMainLoop();

  return(EXIT_SUCCESS);

}
