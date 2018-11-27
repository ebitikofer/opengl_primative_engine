#ifndef MODELS_H
#define MODELS_H

#include <Angel.h>
#include "engine.h"

#define FLOOR_SIZE 100
#define NUM_TILES  50
#define TILE_SIZE  FLOOR_SIZE / NUM_TILES
#define WALL_HEIGHT 15

#define PLAYER_W 2.0
#define PLAYER_H 5.0
#define PLAYER_D 2.0

#define FLOOR_W TILE_SIZE
#define FLOOR_H 1.0
#define FLOOR_D TILE_SIZE
#define FLOOR_R 0.2
#define FLOOR_G 0.1
#define FLOOR_B 0.0

#define COLOR_FLOORS  4
//   vec3(0.6, 0.6, 0.6),

#define LON_WALL_W 0.5
#define LON_WALL_H WALL_HEIGHT
#define LON_WALL_D TILE_SIZE
#define LON_WALL_R 0.7
#define LON_WALL_G 0.6
#define LON_WALL_B 0.5

#define LAT_WALL_W TILE_SIZE
#define LAT_WALL_H WALL_HEIGHT
#define LAT_WALL_D 0.5
#define LAT_WALL_R 0.7
#define LAT_WALL_G 0.6
#define LAT_WALL_B 0.5

#define ROOF_W FLOOR_SIZE
#define ROOF_H 1.0
#define ROOF_D FLOOR_SIZE
#define ROOF_R 0.2
#define ROOF_G 0.1
#define ROOF_B 0.1

#define DOOR_W 5.0
#define DOOR_H 10.0
#define DOOR_D 0.5
#define DOOR_R 0.25
#define DOOR_G 0.15
#define DOOR_B 0.05

#define BULB_W 0.5
#define BULB_H 0.5
#define BULB_D 0.25
#define SHAFT_W 0.25
#define SHAFT_H 0.25
#define SHAFT_D 0.25
#define DOORKNOB_R 0.9
#define DOORKNOB_G 0.7
#define DOORKNOB_B 0.0

#define MOON_W 10.0
#define MOON_H 10.0
#define MOON_D 10.0
#define MOON_R 0.9
#define MOON_G 0.9
#define MOON_B 1.0

#define TOP_W 2.5
#define TOP_H 0.1
#define TOP_D 5.0
#define LEG_W 0.1
#define LEG_H 2.0
#define LEG_D 0.1
#define TABLE_R 0.5
#define TABLE_G 0.3
#define TABLE_B 0.1

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
#define WHEEL_W 1.0
#define WHEEL_H 2.0
#define WHEEL_D 2.0
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

#define GHOST_W 2.0
#define GHOST_H 2.0
#define GHOST_D 2.0
#define GHOST_R 0.9
#define GHOST_G 0.9
#define GHOST_B 1.0

#define FRAME_W 28.0
#define FRAME_H 20.0
#define FRAME_D 0.5
#define STRING_W 0.5
#define STRING_H 8.0
#define STRING_D 0.5
#define STRING_R 0.9
#define STRING_G 0.9
#define STRING_B 0.7
#define PICTURE_R 0.9
#define PICTURE_G 0.7
#define PICTURE_B 0.0

#define SWITCH_W 2.0
#define SWITCH_H 2.0
#define SWITCH_D 2.0
#define BASE_W 2.0
#define BASE_H 2.0
#define BASE_D 2.0
// #define LIGHT_R 0.9
// #define LIGHT_G 0.9
// #define LIGHT_B 1.0

#define BOOKCASELZ_W 5.0
#define BOOKCASELZ_H 15.0
#define BOOKCASELZ_D 25.0
#define BOOKCASELX_W 25.0
#define BOOKCASELX_H 15.0
#define BOOKCASELX_D 5.0
#define BOOKCASESZ_W 5.0
#define BOOKCASESZ_H 15.0
#define BOOKCASESZ_D 10.0
#define BOOKCASESX_W 10.0
#define BOOKCASESX_H 15.0
#define BOOKCASESX_D 5.0
#define BOOKCASE_R 0.25
#define BOOKCASE_G 0.15
#define BOOKCASE_B 0.05

#define KEYL_W 1.0
#define KEYL_H 1.0
#define KEYL_D 3.0
#define KEYS_W 1.0
#define KEYS_H 1.0
#define KEYS_D 2.0
#define KEY_R 0.9
#define KEY_G 0.7
#define KEY_B 0.0

#define FIRE_W 1.0
#define FIRE_H 1.0
#define FIRE_D 1.0
#define LOG_W 1.0
#define LOG_H 1.0
#define LOG_D 2.0
#define LOG_R 0.9
#define LOG_G 0.7
#define LOG_B 0.0
#define FIRE_R 0.9
#define FIRE_G 0.7
#define FIRE_B 0.0

#define HAIR_W 0.76
#define HAIR_H 0.15
#define HAIR_D 0.76
#define FACE_W 0.75
#define FACE_H 0.75
#define FACE_D 0.75
#define LENS_W 0.25
#define LENS_H 0.25
#define LENS_D 0.25
#define BRIDGE_W 0.06125
#define BRIDGE_H 0.06125
#define BRIDGE_D 0.5
#define SHIRT_W 0.5
#define SHIRT_H 1.25
#define SHIRT_D 0.5
#define SUIT_W 0.5
#define SUIT_H 1.25
#define SUIT_D 0.25
#define TIE_W 0.25
#define TIE_H 1.0
#define TIE_D 0.25
#define APPENDAGE_W 0.25
#define APPENDAGE_H 1.5
#define APPENDAGE_D 0.25
#define SKIN_R 0.8
#define SKIN_G 0.8
#define SKIN_B 0.6
#define SHIRT_R 1.0
#define SHIRT_G 1.0
#define SHIRT_B 1.0
#define AGENCY_R 0.0
#define AGENCY_G 0.0
#define AGENCY_B 0.0

#define ZOMBIE_W 2.0
#define ZOMBIE_H 2.0
#define ZOMBIE_D 2.0
#define ZOMBIE_R 0.1
#define ZOMBIE_G 0.3
#define ZOMBIE_B 0.1

#define WEREWOLF_W 2.0
#define WEREWOLF_H 2.0
#define WEREWOLF_D 2.0
#define WEREWOLF_R 0.1
#define WEREWOLF_G 0.1
#define WEREWOLF_B 0.1

#define COFFEE_W 1.0
#define COFFEE_H 1.0
#define COFFEE_D 1.0
#define CUP_W 1.25
#define CUP_H 1.25
#define CUP_D 1.25
#define SAUCER_W 2.0
#define SAUCER_H 0.1
#define SAUCER_D 2.0
#define COFFEE_R 0.1
#define COFFEE_G 0.1
#define COFFEE_B 0.0
#define DISH_R 0.9
#define DISH_G 0.9
#define DISH_B 1.0

#define TREE_W 1.0
#define TREE_H 5.0
#define TREE_D 1.0
#define TREE_R 0.5
#define TREE_G 0.3
#define TREE_B 0.1

#define ROCK_W 2.0
#define ROCK_H 2.0
#define ROCK_D 2.0
#define ROCK_R 0.5
#define ROCK_G 0.4
#define ROCK_B 0.3

#define ANIMAL_W 1.0
#define ANIMAL_H 1.0
#define ANIMAL_D 1.0
#define ANIMAL_R 1.0
#define ANIMAL_G 1.0
#define ANIMAL_B 1.0
// vec3 animal_col[NUM_OF_ANIMALS] = { vec3(1.0, 0.0, 0.0), vec3(0.0, 1.0, 0.0), vec3(0.0, 0.0, 1.0) };

#define BARREL_W 0.75
#define BARREL_H 1.0
#define BARREL_D 3.0
#define BARREL_R 0.6
#define BARREL_G 0.6
#define BARREL_B 0.6

#define COLOR_BARREL  5
//   vec3(0.9, 0.6, 0.5),

#define SIGHT_W 0.25
#define SIGHT_H 0.25
#define SIGHT_D 2.0
#define SIGHT_R 0.5
#define SIGHT_G 0.5
#define SIGHT_B 0.5

#define HANDLE_W 0.6
#define HANDLE_H 2.0
#define HANDLE_D 0.5
#define HANDLE_R 0.4
#define HANDLE_G 0.4
#define HANDLE_B 0.4

#define BULLET_W 0.1
#define BULLET_H 0.1
#define BULLET_D 0.1
#define BULLET_R 0.1
#define BULLET_G 0.3
#define BULLET_B 0.1

// #define TIP_B 0.01
// #define TIP_T 0.01
// #define TIP_H 0.5
// #define TIP_SL 16
// #define TIP_ST 10
// #define TIP_RE 0.5
// #define TIP_GR 0.5
// #define TIP_BL 0.5
//
// #define BODY_B 0.1
// #define BODY_T 0.1
// #define BODY_H 0.6
// #define BODY_SL 16
// #define BODY_ST 10
// #define BODY_RE 0.1
// #define BODY_GR 0.1
// #define BODY_BL 0.1

#define FEATHER_B 0.0
#define FEATHER_T 0.4
#define FEATHER_H 0.3
#define FEATHER_SL 16
#define FEATHER_ST 10
#define FEATHER_RE 0.0
#define FEATHER_GR 0.0
#define FEATHER_BL 0.0

#define FLOORS        0
#define NUM_FLOORS    7
#define PARTS_FLOOR   1

#define MOONS         1
#define NUM_MOONS     1
#define PARTS_MOON    1

#define GUNS          2
#define NUM_GUNS      1
#define PARTS_GUN     3

#define KEYS          3
#define NUM_KEYS      1
#define PARTS_KEY     6

#define VACCUUMS      4
#define NUM_VACCUUMS  1
#define PARTS_VACCUUM 11

#define COFFEES       5
#define NUM_COFFEES   1
#define PARTS_COFFEE  4

#define PLAYERS       6
#define NUM_PLAYERS   1
#define PARTS_PLAYER  4

#define GHOSTS        7
#define NUM_GHOSTS    1
#define PARTS_GHOST   5

#define ZOMBIES       8
#define NUM_ZOMBIES   3
#define PARTS_ZOMBIE  13

#define WEREWOLFS     9
#define NUM_WEREWOLFS 1
#define PARTS_WEREWOLF 13

#define AGENCIES      10
#define NUM_AGENCIES  1
#define PARTS_AGENCIE 13

Object floors[NUM_FLOORS][PARTS_FLOOR];
Object moons[NUM_MOONS][PARTS_MOON];
Object guns[NUM_GUNS][PARTS_GUN];
Object keys[NUM_KEYS][PARTS_KEY];
Object vaccuums[NUM_VACCUUMS][PARTS_VACCUUM];
Object coffees[NUM_COFFEES][PARTS_COFFEE];
Object ghosts[NUM_GHOSTS][PARTS_GHOST];
Object zombies[NUM_ZOMBIES][PARTS_ZOMBIE];
Object werewolfs[NUM_WEREWOLFS][PARTS_WEREWOLF];
Object agencies[NUM_AGENCIES][PARTS_AGENCIE];
Object players[NUM_PLAYERS][PARTS_PLAYER];

bool render_[AGENCIES + 1];

// void load() {

//     mat4  m;
//
//     m = RotateY( theta[Torso] );
//     model[Torso] = Object( m, torso, NULL, &model[Head1] );
//
//     m = Translate(0.0, TORSO_HEIGHT+0.5*HEAD_HEIGHT, 0.0) *
//       RotateX(theta[Head1]) *
//       RotateY(theta[Head2]) *
//       Translate(0.0, -0.5*HEAD_HEIGHT, 0.0);
//
//     model[Head1] = Object( m, head, &model[LeftUpperArm], NULL );
//
//     m = Translate(-(TORSO_WIDTH+UPPER_ARM_WIDTH), 0.9*TORSO_HEIGHT, 0.0) *
// 	RotateX(theta[LeftUpperArm]);
//     model[LeftUpperArm] =
// 	Object( m, left_upper_arm, &model[RightUpperArm], &model[LeftLowerArm] );
//
//     m = Translate(TORSO_WIDTH+UPPER_ARM_WIDTH, 0.9*TORSO_HEIGHT, 0.0) *
// 	RotateX(theta[RightUpperArm]);
//     model[RightUpperArm] =
// 	Object( m, right_upper_arm,
// 	      &model[LeftUpperLeg], &model[RightLowerArm] );
//
//     m = Translate(-(TORSO_WIDTH+UPPER_LEG_WIDTH), 0.1*UPPER_LEG_HEIGHT, 0.0) *
// 	RotateX(theta[LeftUpperLeg]);
//     model[LeftUpperLeg] =
// 	Object( m, left_upper_leg, &model[RightUpperLeg], &model[LeftLowerLeg] );
//
//     m = Translate(TORSO_WIDTH+UPPER_LEG_WIDTH, 0.1*UPPER_LEG_HEIGHT, 0.0) *
// 	RotateX(theta[RightUpperLeg]);
//     model[RightUpperLeg] =
// 	Object( m, right_upper_leg, NULL, &model[RightLowerLeg] );
//
//     m = Translate(0.0, UPPER_ARM_HEIGHT, 0.0) * RotateX(theta[LeftLowerArm]);
//     model[LeftLowerArm] = Object( m, left_lower_arm, NULL, NULL );
//
//     m = Translate(0.0, UPPER_ARM_HEIGHT, 0.0) * RotateX(theta[RightLowerArm]);
//     model[RightLowerArm] = Object( m, right_lower_arm, NULL, NULL );
//
//     m = Translate(0.0, UPPER_LEG_HEIGHT, 0.0) * RotateX(theta[LeftLowerLeg]);
//     model[LeftLowerLeg] = Object( m, left_lower_leg, NULL, NULL );
//
//     m = Translate(0.0, UPPER_LEG_HEIGHT, 0.0) * RotateX(theta[RightLowerLeg]);
//     model[RightLowerLeg] = Object( m, right_lower_leg, NULL, NULL );

  // floors[0].create(mv, model_view, -50.0 + FLOOR_SIZE / 2, -2.5, -50.0 + FLOOR_SIZE / 2, 50.0, ROOF_H, 50.0, ROOF_R, ROOF_G, ROOF_B, 0, 0, 0, 0, 0, 0, Object::wood);
  //
  // floors[1].create(mv, model_view, -50.0 + FLOOR_SIZE / 2, -2.5, -50.0 + FLOOR_SIZE / 2, ROOF_W, ROOF_H, 10.0, ROOF_R, ROOF_G, ROOF_B, 0, 0, 0, 0, 0, 0, Object::wood);
  // floors[2].create(mv, model_view, -50.0 + FLOOR_SIZE / 2, -2.5, -50.0 + FLOOR_SIZE / 2, 10.0, ROOF_H, ROOF_D, ROOF_R, ROOF_G, ROOF_B, 0, 0, 0, 0, 0, 0, Object::wood);
  //
  // floors[3].create(mv, model_view, 50.0, 7.5, 50.0, 25.0, ROOF_H, 25.0, ROOF_R, ROOF_G, ROOF_B, 0, 0, 0, 0, 0, 0, Object::wood);
  // floors[4].create(mv, model_view, -50.0, 7.5, 50.0, 25.0, ROOF_H, 25.0, ROOF_R, ROOF_G, ROOF_B, 0, 0, 0, 0, 0, 0, Object::wood);
  // floors[5].create(mv, model_view, -50.0, 7.5, -50.0, 25.0, ROOF_H, 25.0, ROOF_R, ROOF_G, ROOF_B, 0, 0, 0, 0, 0, 0, Object::wood);
  // floors[6].create(mv, model_view, 50.0, 7.5, -50.0, 25.0, ROOF_H, 25.0, ROOF_R, ROOF_G, ROOF_B, 0, 0, 0, 0, 0, 0, Object::wood);

// }

// void traverse( Object node ) {
//   // base case
//   if ( node == NULL ) { return; }
//
//   // Recursive case, first remember the current transform.
//   mvstack.push( model_view );
//
//   mv *= node.transform;
//   node.render(mvstack);
//   traverse( node.child );
//
//   //  if ( node->child != NULL) { traverse( node->child ); }
//
//   mv = mvstack.pop();
//
//   traverse( node.sibling );
//   //  if ( node->sibling != NULL) { traverse( node->sibling ); }
// }


void render_models(/*MatrixStack stack,*/ bool hurt, bool hallucinate, color4 aps[], color4 dps[], color4 sps[], color4 light_ambients[], color4 light_diffuses[], color4 light_speculars[], GLuint ambient_product, GLuint diffuse_product, GLuint specular_product, GLuint ambient_product2, GLuint diffuse_product2, GLuint specular_product2, GLuint enable, float color_a_pink, color4 emissive[], GLuint Material_Emiss, GLuint shiny) {

  if (render_[FLOORS]) {
    for (int i = 0; i < NUM_FLOORS; i++) {
      for (int j = 0; j < PARTS_FLOOR; j++) {
        floors[i][j].render(/*mvstack*/ hurt, hallucinate, aps, dps, sps, light_ambients, light_diffuses, light_speculars, ambient_product, diffuse_product, specular_product, ambient_product2, diffuse_product2, specular_product2, enable, color_a_pink, emissive, Material_Emiss, shiny);
      }
    }
  }

  if (render_[MOONS]) {
    for (int i = 0; i < NUM_MOONS; i++) {
      for (int j = 0; j < PARTS_MOON; j++) {
        moons[i][j].render(/*mvstack*/ hurt, hallucinate, aps, dps, sps, light_ambients, light_diffuses, light_speculars, ambient_product, diffuse_product, specular_product, ambient_product2, diffuse_product2, specular_product2, enable, color_a_pink, emissive, Material_Emiss, shiny);
      }
    }
  }

  if (render_[GUNS]) {
    for (int i = 0; i < NUM_GUNS; i++) {
      for (int j = 0; j < PARTS_GUN; j++) {
        guns[i][j].render(/*mvstack*/ hurt, hallucinate, aps, dps, sps, light_ambients, light_diffuses, light_speculars, ambient_product, diffuse_product, specular_product, ambient_product2, diffuse_product2, specular_product2, enable, color_a_pink, emissive, Material_Emiss, shiny);
      }
    }
  }

  if (render_[KEYS]) {
    for (int i = 0; i < NUM_KEYS; i++) {
      for (int j = 0; j < PARTS_KEY; j++) {
        keys[i][j].render(/*mvstack*/ hurt, hallucinate, aps, dps, sps, light_ambients, light_diffuses, light_speculars, ambient_product, diffuse_product, specular_product, ambient_product2, diffuse_product2, specular_product2, enable, color_a_pink, emissive, Material_Emiss, shiny);
      }
    }
  }

  if (render_[VACCUUMS]) {
    for (int i = 0; i < NUM_VACCUUMS; i++) {
      for (int j = 0; j < PARTS_VACCUUM; j++) {
        vaccuums[i][j].render(/*mvstack*/ hurt, hallucinate, aps, dps, sps, light_ambients, light_diffuses, light_speculars, ambient_product, diffuse_product, specular_product, ambient_product2, diffuse_product2, specular_product2, enable, color_a_pink, emissive, Material_Emiss, shiny);
      }
    }
  }

  if (render_[COFFEES]) {
    for (int i = 0; i < NUM_COFFEES; i++) {
      for (int j = 0; j < PARTS_COFFEE; j++) {
        coffees[i][j].render(/*mvstack*/ hurt, hallucinate, aps, dps, sps, light_ambients, light_diffuses, light_speculars, ambient_product, diffuse_product, specular_product, ambient_product2, diffuse_product2, specular_product2, enable, color_a_pink, emissive, Material_Emiss, shiny);
      }
    }
  }

  if (render_[GHOSTS]) {
    for (int i = 0; i < NUM_GHOSTS; i++) {
      for (int j = 0; j < PARTS_GHOST; j++) {
        ghosts[i][j].render(/*mvstack*/ hurt, hallucinate, aps, dps, sps, light_ambients, light_diffuses, light_speculars, ambient_product, diffuse_product, specular_product, ambient_product2, diffuse_product2, specular_product2, enable, color_a_pink, emissive, Material_Emiss, shiny);
      }
    }
  }

  if (render_[ZOMBIES]) {
    for (int i = 0; i < NUM_ZOMBIES; i++) {
      for (int j = 0; j < PARTS_ZOMBIE; j++) {
        zombies[i][j].render(/*mvstack*/ hurt, hallucinate, aps, dps, sps, light_ambients, light_diffuses, light_speculars, ambient_product, diffuse_product, specular_product, ambient_product2, diffuse_product2, specular_product2, enable, color_a_pink, emissive, Material_Emiss, shiny);
      }
    }
  }

  if (render_[WEREWOLFS]) {
    for (int i = 0; i < NUM_WEREWOLFS; i++) {
      for (int j = 0; j < PARTS_WEREWOLF; j++) {
        werewolfs[i][j].render(/*mvstack*/ hurt, hallucinate, aps, dps, sps, light_ambients, light_diffuses, light_speculars, ambient_product, diffuse_product, specular_product, ambient_product2, diffuse_product2, specular_product2, enable, color_a_pink, emissive, Material_Emiss, shiny);
      }
    }
  }

  if (render_[AGENCIES]) {
    for (int i = 0; i < NUM_AGENCIES; i++) {
      for (int j = 0; j < PARTS_AGENCIE; j++) {
        agencies[i][j].render(/*mvstack*/ hurt, hallucinate, aps, dps, sps, light_ambients, light_diffuses, light_speculars, ambient_product, diffuse_product, specular_product, ambient_product2, diffuse_product2, specular_product2, enable, color_a_pink, emissive, Material_Emiss, shiny);
      }
    }
  }

}

#endif
