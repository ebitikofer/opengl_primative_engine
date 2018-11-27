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

  point4  eye(mv_pos.x + radius * cos(theta * M_PI/180) * cos(phi * M_PI/180),
              mv_pos.y + radius * sin(phi * M_PI/180),
              mv_pos.z + radius * sin(theta * M_PI/180) * cos(phi * M_PI/180),
              1.0);
  point4  at(mv_pos.x, mv_pos.y, mv_pos.z, 1.0);
  vec4    up(0.0, 1.0, 0.0, 0.0);

  glClearColor(SKY_R, SKY_G, SKY_B, 0.0);
  glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

  p = Perspective(fovy, aspect, zNear, zFar);
  cv = LookAt(eye, at, up);
  glUniformMatrix4fv(projection, 1, GL_TRUE, p);
  glUniformMatrix4fv(camera_view, 1, GL_TRUE, cv);

  set_objects(); // Set objects for render

  // traverse( &nodes[Torso] );
  // traverse( floor_model[0] );

  // Environment
  // light();
  // walls();
  // roof();

  render_[FLOORS] = true;

  if (!get_gun) {
    render_[GUNS] = true;
  } else {// if (!get_gun) gun_pickup(); else ; // gun();
    render_[GUNS] = false;
    if (fire_gun) {
      reload = false;
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

    for (int i = 0; i < NUM_BULLETS; i++) {
      if (active[i]) {
        bullet_dist[i] += 1.0;
        object(mv, model_view, bullet[i].x - bullet_dist[i] * cos((bullet_ang[i]) * M_PI/180), bullet[i].y - 0.0, bullet[i].z - bullet_dist[i] * sin((bullet_ang[i]) * M_PI/180), BULLET_W, BULLET_H, BULLET_D, AGENCY_R, AGENCY_G, AGENCY_B, 0, -bullet_ang[i], 0, 0, 0, 0); // translate down half of the object
        if (bullet_dist[i] == DRAW_DISTANCE) {
          active[i] = false;
        }
      }
    }
  }

  if (!get_key) {
    render_[KEYS] = true;
  } else {
    render_[KEYS] = false;
    exit(EXIT_SUCCESS);
  }

  if (!get_sweeper) {
    render_[VACCUUMS] = true;
  } else {
    render_[VACCUUMS] = false;
  }

  if (!get_coffee) {
    render_[COFFEES] = true;
  } else {
    render_[COFFEES] = false;
  }

  if (perspective) character();

  render_[GHOSTS] = true;
  render_[ZOMBIES] = true;
  render_[WEREWOLFS] = true;
  render_[AGENCIES] = true;

  render_models(/*mvstack*/ hurt, hallucinate, aps, dps, sps, light_ambients, light_diffuses, light_speculars, ambient_product, diffuse_product, specular_product, ambient_product2, diffuse_product2, specular_product2, enable, color_a_pink, emissive, Material_Emiss, shiny);

  // HUD

  cv = mat4(1.0);
  pv = mat4(1.0);
  glUniformMatrix4fv(camera_view, 1, GL_TRUE, cv);
  glUniformMatrix4fv(projection, 1, GL_TRUE, pv);

  // render_hud(/*mvstack*/ hurt, hallucinate, aps, dps, sps, light_ambients, light_diffuses, light_speculars, ambient_product, diffuse_product, specular_product, ambient_product2, diffuse_product2, specular_product2, enable, color_a_pink, emissive, Material_Emiss, shiny);

  for (int i = 0; i < health; i++) {
    object(mv, model_view, -0.8 + 0.1 * i, 0.8, 0.0, 0.1, 0.01, 0.0, 0.0, 1.0, 0.0, 0, 0, 0, 0, 0, 4);
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

// void floor() {
  // sobject(mv, model_view, -50.0 + FLOOR_SIZE / 2, -2.5, -50.0 + FLOOR_SIZE / 2, ROOF_W, ROOF_H, ROOF_D, ROOF_R, ROOF_G, ROOF_B, 0, 0, 0, 0, 0, 0);
  // for (int i = 0; i < NUM_TILES; i++) {
  //   // for (int j = 0; j < NUM_TILES; j++) {
  //     object(mv, model_view, -50.0 + (i * TILE_SIZE) + TILE_SIZE / 2, -2.5, -50.0  + (0 * TILE_SIZE) + TILE_SIZE * NUM_TILES / 2, FLOOR_W, FLOOR_H, FLOOR_D * NUM_TILES, FLOOR_R, FLOOR_G, FLOOR_B, 0, 0, 0, 0, 0, 0);
  //   // }
  // }
// }

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

void character() {
  object(mv, model_view, mv_pos.x + 0.0, mv_pos.y + 1.15, mv_pos.z + 0.0, HAIR_W, HAIR_H, HAIR_D, AGENCY_R, AGENCY_G, AGENCY_B, 0, -theta, 0, 0, 0, 0); // translate down half of the object
  object(mv, model_view, mv_pos.x + 0.0, mv_pos.y + 0.75, mv_pos.z + 0.0, FACE_W, FACE_H, FACE_D, SKIN_R, SKIN_G, SKIN_B, 0, -theta, 0, 0, 0, 0); // translate down half of the object
  object(mv, model_view, mv_pos.x - 0.4 * cos((theta - 30) * M_PI/180), mv_pos.y + 0.75, mv_pos.z - 0.4 * sin((theta - 30) * M_PI/180), LENS_W, LENS_H, LENS_D, AGENCY_R, AGENCY_G, AGENCY_B, 0, -theta, 0, 0, 0, 0); // translate down half of the object
  object(mv, model_view, mv_pos.x - 0.4 * cos((theta + 30) * M_PI/180), mv_pos.y + 0.75, mv_pos.z - 0.4 * sin((theta + 30) * M_PI/180), LENS_W, LENS_H, LENS_D, AGENCY_R, AGENCY_G, AGENCY_B, 0, -theta, 0, 0, 0, 0); // translate down half of the object
  object(mv, model_view, mv_pos.x - 0.4 * cos(theta * M_PI/180), mv_pos.y + 0.875, mv_pos.z - 0.4 * sin(theta * M_PI/180), BRIDGE_W, BRIDGE_H, BRIDGE_D, AGENCY_R, AGENCY_G, AGENCY_B, 0, -theta, 0, 0, 0, 0); // translate down half of the object
  object(mv, model_view, mv_pos.x + 0.0, mv_pos.y - 0.25, mv_pos.z + 0.0, SHIRT_W, SHIRT_H, SHIRT_D, SHIRT_R, SHIRT_G, SHIRT_B, 0, -theta, 0, 0, 0, 0); // translate down half of the object
  object(mv, model_view, mv_pos.x + 0.1 * cos(theta * M_PI/180), mv_pos.y - 0.25, mv_pos.z + 0.1 * sin(theta * M_PI/180), SHIRT_W, SHIRT_H, SHIRT_D, AGENCY_R, AGENCY_G, AGENCY_B, 0, -theta, 0, 0, 0, 0); // translate down half of the object
  object(mv, model_view, mv_pos.x - 0.25 * cos((theta - 0) * M_PI/180), mv_pos.y - 0.125, mv_pos.z - 0.25 * sin((theta - 0) * M_PI/180), TIE_W, TIE_H, TIE_D, AGENCY_R, AGENCY_G, AGENCY_B, 0, -theta, 0, 0, 0, 0); // translate down half of the object
  object(mv, model_view, mv_pos.x + 0.375 * cos((theta - 90) * M_PI/180), mv_pos.y - 0.25, mv_pos.z + 0.375  * sin((theta - 90) * M_PI/180), SUIT_W, SUIT_H, SUIT_D, AGENCY_R, AGENCY_G, AGENCY_B, 0, -theta, 0, 0, 0, 0); // translate down half of the object
  object(mv, model_view, mv_pos.x + 0.375 * cos((theta + 90) * M_PI/180), mv_pos.y - 0.25, mv_pos.z + 0.375 * sin((theta + 90) * M_PI/180), SUIT_W, SUIT_H, SUIT_D, AGENCY_R, AGENCY_G, AGENCY_B, 0, -theta, 0, 0, 0, 0); // translate down half of the object
  object(mv, model_view, mv_pos.x + 0.5 * cos((theta - 90) * M_PI/180), mv_pos.y - 0.375, mv_pos.z + 0.5 * sin((theta - 90) * M_PI/180), APPENDAGE_W, APPENDAGE_H, APPENDAGE_D, AGENCY_R, AGENCY_G, AGENCY_B, 0, -theta, 0, 0, 0, 0); // translate down half of the object
  object(mv, model_view, mv_pos.x + 0.5 * cos((theta + 90) * M_PI/180), mv_pos.y - 0.375, mv_pos.z + 0.5 * sin((theta + 90) * M_PI/180), APPENDAGE_W, APPENDAGE_H, APPENDAGE_D, AGENCY_R, AGENCY_G, AGENCY_B, 0, -theta, 0, 0, 0, 0); // translate down half of the object
  object(mv, model_view, mv_pos.x + 0.25 * cos((theta - 90) * M_PI/180), mv_pos.y - 1.5, mv_pos.z + 0.25 * sin((theta - 90) * M_PI/180), APPENDAGE_W, APPENDAGE_H, APPENDAGE_D, AGENCY_R, AGENCY_G, AGENCY_B, 0, -theta, 0, 0, 0, 0); // translate down half of the object
  object(mv, model_view, mv_pos.x + 0.25 * cos((theta + 90) * M_PI/180), mv_pos.y - 1.5, mv_pos.z + 0.25 * sin((theta + 90) * M_PI/180), APPENDAGE_W, APPENDAGE_H, APPENDAGE_D, AGENCY_R, AGENCY_G, AGENCY_B, 0, -theta, 0, 0, 0, 0); // translate down half of the object
}

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

void set_objects() {

  // ENVIRONMENT
  disp_rot = display_rot;

  platform_loc[0] = vec3(0.0, -2.5, 0.0);
  platform_loc[1] = vec3(0.0, 12.5, 0.0);

  wall_loc[0] = vec3(0.0, wall_height, 50.0);
  wall_loc[1] = vec3(0.0, wall_height, -50.0);
  wall_loc[2] = vec3(-50.0, wall_height, -5.0);
  wall_loc[3] = vec3(50.0, wall_height, 0.0);
  wall_loc[4] = vec3(-7.5, wall_height, 40.0);
  wall_loc[5] = vec3(45.0, wall_height, 40.0);
  wall_loc[6] = vec3(25.0, wall_height, 20.0);
  wall_loc[7] = vec3(4.375, wall_height, 0.0);
  wall_loc[8] = vec3(-45.0, wall_height, 0.0);
  wall_loc[9] = vec3(45.0, wall_height, -25.0);
  wall_loc[10] = vec3(25.0, wall_height, -25.0);
  wall_loc[11] = vec3(5.0, wall_height, -25.0);
  wall_loc[12] = vec3(-25.0, wall_height, -13.75);
  wall_loc[13] = vec3(-25.0, wall_height, -47.5);
  wall_loc[14] = vec3(25.0, wall_height, 36.25);
  wall_loc[15] = vec3(25.0, wall_height, 20.0);
  wall_loc[16] = vec3(25.0, wall_height, 0.0);
  wall_loc[17] = vec3(25.0, wall_height, -25.0);
  wall_loc[18] = vec3(0.0, wall_height, -32.5);
  wall_loc[19] = vec3(0.0, wall_height, -5.0);
  wall_loc[20] = vec3(-50.0, door_height, 45.0);

  wall_loc[21] = vec3(-50.0, wall_height, 35.0);
  wall_loc[22] = vec3(-50.0, wall_height, 0.0);
  wall_loc[23] = vec3(-50.0, wall_height, -25.0);
  wall_loc[24] = vec3(-50.0, wall_height, -45.0);

  wall_loc[25] = vec3(-45.0, wall_height, -50.0);
  wall_loc[26] = vec3(-25.0, wall_height, -50.0);
  wall_loc[27] = vec3(0.0, wall_height, -50.0);
  wall_loc[28] = vec3(32.5, wall_height, -50.0);

  wall_loc[29] = vec3(50.0, wall_height, -35.0);
  wall_loc[30] = vec3(50.0, wall_height, -5.0);
  wall_loc[31] = vec3(50.0, wall_height, 17.5);
  wall_loc[32] = vec3(50.0, wall_height, 42.5);

  wall_loc[33] = vec3(40.0, wall_height, 50.0);
  wall_loc[34] = vec3(15.0, wall_height, 50.0);
  wall_loc[35] = vec3(-5.0, wall_height, 50.0);
  wall_loc[36] = vec3(-25.0, wall_height, 50.0);
  wall_loc[37] = vec3(-45.0, wall_height, 50.0);

  wall_loc[38] = vec3(-12.5, wall_height, 13.75);
  wall_loc[39] = vec3(-12.5, wall_height, 36.25);
  wall_loc[40] = vec3(-18.75, wall_height, 10.0);
  wall_loc[41] = vec3(-18.75, wall_height, 20.0);
  wall_loc[42] = vec3(-25.0, wall_height, 28.75);
  wall_loc[43] = vec3(-28.125, wall_height, 0.0);

  ghosts_loc[0] = vec3(ghost_loc.x*ghost_mult, ghost_height[0]*ghost_mult, ghost_loc.z*ghost_mult);

  zombies_loc[0] = vec3(zombie_loc[0].x*zombie_mult[0], zombie_height[0]*zombie_mult[0], zombie_loc[0].z*zombie_mult[0]);
  zombies_loc[1] = vec3(zombie_loc[1].x*zombie_mult[1], zombie_height[0]*zombie_mult[1], zombie_loc[1].z*zombie_mult[1]);
  zombies_loc[2] = vec3(zombie_loc[2].x*zombie_mult[2], zombie_height[0]*zombie_mult[2], zombie_loc[2].z*zombie_mult[2]);

  agencies_loc[0] = vec3(agency_loc.x, agency_loc.y, agency_loc.z);

  werewolves_loc[0] = vec3(werewolf_loc[0].x*werewolf_mult[0], werewolf_loc[0].y*werewolf_mult[0], werewolf_loc[0].z*werewolf_mult[0]);

  inter_loc[0] = vec3(-37.5, 0.0, 0.0);
  inter_loc[1] = vec3(-25.0, 0.0, -42.5);
  inter_loc[2] = vec3(12.5, table_loc[1].y, -1.0); // Picture
  inter_loc[3] = vec3(bookcase_loc[0].x + 1.5, bookcase_loc[0].y, bookcase_loc[0].z);

  pickup_loc[0] = vec3(-50.0, 10.0, -50.0); // Vaccuum
  pickup_loc[1] = vec3(50.0, 10.0, -50.0);
  pickup_loc[2] = vec3(50.0, 10.0, 50.0);
  pickup_loc[3] = vec3(-50.0, 10.0, 50.0);

  platform_size[0] = vec3(ROOF_W, ROOF_H, ROOF_D);
  platform_size[1] = vec3(ROOF_W, ROOF_H, ROOF_D);

  wall_size[0] = vec3(100, LAT_WALL_H, LAT_WALL_D);
  wall_size[1] = vec3(100, LAT_WALL_H, LAT_WALL_D);
  wall_size[2] = vec3(LON_WALL_W, LON_WALL_H, 90.0);
  wall_size[3] = vec3(LON_WALL_W, LON_WALL_H, 100.0);
  wall_size[4] = vec3(85.0, LAT_WALL_H, LAT_WALL_D);
  wall_size[5] = vec3(10.0, LAT_WALL_H, LAT_WALL_D);
  wall_size[6] = vec3(50.0, LAT_WALL_H, LAT_WALL_D);
  wall_size[7] = vec3(41.25, LAT_WALL_H, LAT_WALL_D);
  wall_size[8] = vec3(10.0, LAT_WALL_H, LAT_WALL_D);
  wall_size[9] = vec3(10.0, LAT_WALL_H, LAT_WALL_D);
  wall_size[10] = vec3(20.0, LAT_WALL_H, LAT_WALL_D);
  wall_size[11] = vec3(10.0, LAT_WALL_H, LAT_WALL_D);
  wall_size[12] = vec3(LON_WALL_W, LON_WALL_H, 52.5);
  wall_size[13] = vec3(LON_WALL_W, LON_WALL_H, 5.0);
  wall_size[14] = vec3(LON_WALL_W, LON_WALL_H, 7.5);
  wall_size[15] = vec3(LON_WALL_W, LON_WALL_H, 15.0);
  wall_size[16] = vec3(LON_WALL_W, LON_WALL_H, 15.0);
  wall_size[17] = vec3(LON_WALL_W, LON_WALL_H, 40.0);
  wall_size[18] = vec3(LON_WALL_W, LON_WALL_H, 35.0);
  wall_size[19] = vec3(LON_WALL_W, LON_WALL_H, 10.0);
  wall_size[20] = vec3(LON_WALL_W, LON_WALL_H, 10.0);

  wall_size[21] = vec3(LON_WALL_W, LON_WALL_H*6/8+0.2, 10.0);
  wall_size[22] = vec3(LON_WALL_W, LON_WALL_H*6/8+0.2, 20.0);
  wall_size[23] = vec3(LON_WALL_W, LON_WALL_H*6/8+0.2, 10.0);
  wall_size[24] = vec3(LON_WALL_W, LON_WALL_H*6/8+0.2, 10.0);

  wall_size[25] = vec3(10.0, LAT_WALL_H*6/8+0.2, LAT_WALL_D);
  wall_size[27] = vec3(20.0, LAT_WALL_H*6/8+0.2, LAT_WALL_D);
  wall_size[26] = vec3(10.0, LAT_WALL_H*6/8+0.2, LAT_WALL_D);
  wall_size[28] = vec3(35.0, LAT_WALL_H*6/8+0.2, LAT_WALL_D);

  wall_size[29] = vec3(LON_WALL_W, LON_WALL_H*6/8+0.2, 30.0);
  wall_size[30] = vec3(LON_WALL_W, LON_WALL_H*6/8+0.2, 10.0);
  wall_size[31] = vec3(LON_WALL_W, LON_WALL_H*6/8+0.2, 15.0);
  wall_size[32] = vec3(LON_WALL_W, LON_WALL_H*6/8+0.2, 15.0);

  wall_size[33] = vec3(20.0, LAT_WALL_H*6/8+0.2, LAT_WALL_D);
  wall_size[34] = vec3(10.0, LAT_WALL_H*6/8+0.2, LAT_WALL_D);
  wall_size[36] = vec3(10.0, LAT_WALL_H*6/8+0.2, LAT_WALL_D);
  wall_size[35] = vec3(10.0, LAT_WALL_H*6/8+0.2, LAT_WALL_D);
  wall_size[37] = vec3(10.0, LAT_WALL_H*6/8+0.2, LAT_WALL_D);

  wall_size[38] = vec3(LON_WALL_W, LON_WALL_H, 27.5);
  wall_size[39] = vec3(LON_WALL_W, LON_WALL_H, 7.5);
  wall_size[40] = vec3(12.5, LAT_WALL_H, LAT_WALL_D);
  wall_size[41] = vec3(12.5, LAT_WALL_H, LAT_WALL_D);
  wall_size[42] = vec3(LON_WALL_W, LON_WALL_H, 22.5);
  wall_size[43] = vec3(13.75, LAT_WALL_H, LAT_WALL_D);

  ghosts_size[0] = vec3(GHOST_W*ghost_mult, GHOST_H*ghost_mult, GHOST_D*ghost_mult);

  zombies_size[0] = vec3(ZOMBIE_W*zombie_mult[0], ZOMBIE_H*zombie_mult[0], ZOMBIE_D*zombie_mult[0]);
  zombies_size[1] = vec3(ZOMBIE_W*zombie_mult[1], ZOMBIE_H*zombie_mult[1], ZOMBIE_D*zombie_mult[1]);
  zombies_size[2] = vec3(ZOMBIE_W*zombie_mult[2], ZOMBIE_H*zombie_mult[2], ZOMBIE_D*zombie_mult[2]);

  // werewolfs_size[2] = vec3(ZOMBIE_W*werewolf_mult[2], ZOMBIE_H*werewolf_mult[2], ZOMBIE_D*werewolf_mult[2]);

  inter_size[0] = vec3(2.0, 2.0, 2.0);
  inter_size[1] = vec3(2.0, 2.0, 2.0);
  inter_size[2] = vec3(2.0, 2.0, 2.0);
  inter_size[3] = vec3(2.0, 2.0, 2.0);

  pickup_size[4] = vec3(1.0, 1.0, 1.0);
  pickup_size[5] = vec3(2.5, 1.0, 2.5);
  pickup_size[6] = vec3(2.5, 1.0, 2.5);
  pickup_size[7] = vec3(2.5, 1.0, 2.5);

}
