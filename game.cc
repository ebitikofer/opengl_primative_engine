//***************
// Eric Bitikofer
// 10/14/18
// 3D game made in OpenGL
//

#include <Angel.h>
#include "engine.h"
#include "instance.h"

// display function, update everything for display
void display(void) {

  int i = 0, j = 0;

  if (!solid_part) glPolygonMode( GL_FRONT_AND_BACK, GL_LINE );
              else glPolygonMode( GL_FRONT_AND_BACK, GL_FILL );

  glutSetWindowTitle(title_bar.c_str());

  point4  eye(mvx + radius * cos(theta * M_PI/180) * cos(phi * M_PI/180),
              radius * sin(phi * M_PI/180),
              mvz + radius * sin(theta * M_PI/180) * cos(phi * M_PI/180),
              1.0);
  point4  gun(mvx + radius * cos(theta * M_PI/180) * cos(phi * M_PI/180),
              radius * sin(phi * M_PI/180),
              mvz + radius * sin(theta * M_PI/180) * cos(phi * M_PI/180),
              1.0);
  point4  at(mvx, 0.0, mvz, 1.0);
  vec4    up(0.0, 1.0, 0.0, 0.0);

  glClearColor(SKY_R, SKY_G, SKY_B, 0.0);
  glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
  glEnable( GL_DEPTH_TEST );

  cv = LookAt(eye, at, up);
  pv = LookAt(gun, at, up);
  // mv = RotateZ(move_angle);
  p = Perspective(fovy, aspect, zNear, zFar);


  glUniformMatrix4fv(camera_view, 1, GL_TRUE, cv);
  // glUniformMatrix4fv(model_view, 1, GL_TRUE, mv);
  glUniformMatrix4fv(projection, 1, GL_TRUE, p);

  // PLAYER
  object(pv, model_view, 2.0, 0.0, -5.0, BARREL_W, BARREL_H, BARREL_D, BARREL_R, BARREL_G, BARREL_B, 0, 0, 0, 0, 0, 0);
  object(pv, model_view, 1.6, -0.5, -5.75, SIGHT_W, SIGHT_H, SIGHT_D, SIGHT_R, SIGHT_G, SIGHT_B, 0, 0, 0, 0, 0, 0);
  object(pv, model_view, 2.1, -1.1, -4.0, HANDLE_W, HANDLE_H, HANDLE_D, HANDLE_R, HANDLE_G, HANDLE_B, 0, 0, 0, 0, 0, 0);

  // // DART
  // object(mv, model_view, 2.0, 0.0, -2.8, TIP_B, TIP_H, TIP_T, 0, 0, 0, TIP_SL, TIP_ST, 1);
  // object(mv, model_view, 2.0, 0.0, -2.4, BODY_B, BODY_H, BODY_T, 0, 0, 0, BODY_SL, BODY_ST, 1);
  // object(mv, model_view, 2.0, 0.0, -2.3, FEATHER_B, FEATHER_H, FEATHER_T, 0, 0, 0, FEATHER_SL, FEATHER_ST, 1);

  // ENVIRONMENT
  object(mv, model_view,   0.0, 0.0,  50.0, LAT_WALL_W * NUM_TILES, LAT_WALL_H, LAT_WALL_D, LAT_WALL_R, LAT_WALL_G, LAT_WALL_B, 0, 0, 0, 0, 0, 0);
  object(mv, model_view,  -7.5, 0.0,  40.0, LAT_WALL_W * NUM_TILES - 15.0, LAT_WALL_H, LAT_WALL_D, LAT_WALL_R, LAT_WALL_G, LAT_WALL_B, 0, 0, 0, 0, 0, 0);
  object(mv, model_view,  45.0, 0.0,  40.0, LAT_WALL_W * NUM_TILES - 90.0, LAT_WALL_H, LAT_WALL_D, LAT_WALL_R, LAT_WALL_G, LAT_WALL_B, 0, 0, 0, 0, 0, 0);
  object(mv, model_view,  25.0, 0.0,  20.0, LAT_WALL_W * NUM_TILES - 50.0, LAT_WALL_H, LAT_WALL_D, LAT_WALL_R, LAT_WALL_G, LAT_WALL_B, 0, 0, 0, 0, 0, 0);
  object(mv, model_view,  -5.0, 0.0,   0.0, LAT_WALL_W * NUM_TILES - 40.0, LAT_WALL_H, LAT_WALL_D, LAT_WALL_R, LAT_WALL_G, LAT_WALL_B, 0, 0, 0, 0, 0, 0);
  object(mv, model_view, -45.0, 0.0,   0.0, LAT_WALL_W * NUM_TILES - 90.0, LAT_WALL_H, LAT_WALL_D, LAT_WALL_R, LAT_WALL_G, LAT_WALL_B, 0, 0, 0, 0, 0, 0);
  object(mv, model_view,  45.0, 0.0, -25.0, LAT_WALL_W * NUM_TILES - 90.0, LAT_WALL_H, LAT_WALL_D, LAT_WALL_R, LAT_WALL_G, LAT_WALL_B, 0, 0, 0, 0, 0, 0);
  object(mv, model_view,  25.0, 0.0, -25.0, LAT_WALL_W * NUM_TILES - 80.0, LAT_WALL_H, LAT_WALL_D, LAT_WALL_R, LAT_WALL_G, LAT_WALL_B, 0, 0, 0, 0, 0, 0);
  object(mv, model_view,   5.0, 0.0, -25.0, LAT_WALL_W * NUM_TILES - 90.0, LAT_WALL_H, LAT_WALL_D, LAT_WALL_R, LAT_WALL_G, LAT_WALL_B, 0, 0, 0, 0, 0, 0);
  object(mv, model_view,   0.0, 0.0, -50.0, LAT_WALL_W * NUM_TILES, LAT_WALL_H, LAT_WALL_D, LAT_WALL_R, LAT_WALL_G, LAT_WALL_B, 0, 0, 0, 0, 0, 0);

  object(mv, model_view, -50.0, 0.0,  -5.0, LON_WALL_W, LON_WALL_H, LON_WALL_D * NUM_TILES - 10.0, LON_WALL_R, LON_WALL_G, LON_WALL_B, 0, 0, 0, 0, 0, 0);
  object(mv, model_view, -25.0, 0.0,   0.0, LON_WALL_W, LON_WALL_H, LON_WALL_D * NUM_TILES - 20.0, LON_WALL_R, LON_WALL_G, LON_WALL_B, 0, 0, 0, 0, 0, 0);
  object(mv, model_view, -25.0, 0.0, -47.5, LON_WALL_W, LON_WALL_H, LON_WALL_D * NUM_TILES - 95.0, LON_WALL_R, LON_WALL_G, LON_WALL_B, 0, 0, 0, 0, 0, 0);
  object(mv, model_view,  25.0, 0.0,  37.5, LON_WALL_W, LON_WALL_H, LON_WALL_D * NUM_TILES - 95.0, LON_WALL_R, LON_WALL_G, LON_WALL_B, 0, 0, 0, 0, 0, 0);
  object(mv, model_view,  25.0, 0.0,  20.0, LON_WALL_W, LON_WALL_H, LON_WALL_D * NUM_TILES - 90.0, LON_WALL_R, LON_WALL_G, LON_WALL_B, 0, 0, 0, 0, 0, 0);
  object(mv, model_view,  25.0, 0.0,   0.0, LON_WALL_W, LON_WALL_H, LON_WALL_D * NUM_TILES - 90.0, LON_WALL_R, LON_WALL_G, LON_WALL_B, 0, 0, 0, 0, 0, 0);
  object(mv, model_view,  25.0, 0.0, -25.0, LON_WALL_W, LON_WALL_H, LON_WALL_D * NUM_TILES - 60.0, LON_WALL_R, LON_WALL_G, LON_WALL_B, 0, 0, 0, 0, 0, 0);
  object(mv, model_view,   0.0, 0.0, -32.5, LON_WALL_W, LON_WALL_H, LON_WALL_D * NUM_TILES - 65.0, LON_WALL_R, LON_WALL_G, LON_WALL_B, 0, 0, 0, 0, 0, 0);
  object(mv, model_view,   0.0, 0.0,  -5.0, LON_WALL_W, LON_WALL_H, LON_WALL_D * NUM_TILES - 90.0, LON_WALL_R, LON_WALL_G, LON_WALL_B, 0, 0, 0, 0, 0, 0);
  object(mv, model_view,  50.0, 0.0,   0.0, LON_WALL_W, LON_WALL_H, LON_WALL_D * NUM_TILES, LON_WALL_R, LON_WALL_G, LON_WALL_B, 0, 0, 0, 0, 0, 0);
  for (i = 0; i < NUM_TILES; i++) {
    for (j = 0; j < NUM_TILES; j++) {
      object(mv, model_view, -50.0 + (i * TILE_SIZE) + TILE_SIZE / 2, -2.5, -50.0 + (j * TILE_SIZE)  + TILE_SIZE / 2, FLOOR_W, FLOOR_H, FLOOR_D, FLOOR_R, FLOOR_G, FLOOR_B, 0, 0, 0, 0, 0, 0);
      // if (i % 5 == 0) {
      //   if (j % 10 == 0) {
      //     object(mv, model_view, -50.0 + (i / 6 * 10.0), 0.0, -50.0 + ( j / 10 * 20.0), TREE_W, TREE_H, TREE_D, TREE_R, TREE_G, TREE_B, -10, 45, 10, 0, 0, 0); // translate down half of the object
      //     object(mv, model_view, -45.0 + (i / 6 * 10.0), 0.0, -45.0 + ( j / 10 * 20.0), ROCK_W, ROCK_H, ROCK_D, ROCK_R, ROCK_G, ROCK_B, 45, 45, 45, 0, 0, 0); // translate down half of the object
      //     object(mv, model_view, -30.0 + (i / 6 * 10.0), 0.0, -30.0 + ( j / 10 * 20.0), ANIMAL_W, ANIMAL_H, ANIMAL_D, FLOOR_R, FLOOR_G, FLOOR_B, 0, 0, 0, 0, 0, 0); // translate down half of the object
      //   }
      // }
    }
  }

  object(mv, model_view, -5.0, 0.0, -5.0, TREE_W, TREE_H, TREE_D, TREE_R, TREE_G, TREE_B, -10, 45, 10, 0, 0, 0); // translate down half of the object
  object(mv, model_view, -5.0, 0.0, -5.0, ROCK_W, ROCK_H, ROCK_D, ROCK_R, ROCK_G, ROCK_B, 45, 45, 45, 0, 0, 0); // translate down half of the object
  object(mv, model_view, -5.0, 0.0, -5.0, ANIMAL_W, ANIMAL_H, ANIMAL_D, FLOOR_R, FLOOR_G, FLOOR_B, 0, 0, 0, 0, 0, 0); // translate down half of the object

  // collision(everything);

  glFlush();
  glutSwapBuffers();

}

int main(int argc, char **argv) {

  // INIT
  init(argc, argv);

  glutDisplayFunc(display);
  glutIdleFunc(animation); // Game start
  glutMenu();

  // RUN
  glutMainLoop();

  return(EXIT_SUCCESS);

}

// //----------------------------------------------------------------------------
// int main(int argc, char **argv)
// {
//
//   glutInit(&argc, argv);
//   glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
//   glutInitWindowSize(512, 512);
//   glutCreateWindow("Sphere");
//
//   glewInit();
//
//   init();
//
//   glutDisplayFunc(display);
//   glutReshapeFunc(reshape);
//   glutKeyboardFunc(keyboard);
//   glutIdleFunc(idle);
//   glutMainLoop();
//   return(EXIT_SUCCESS);
// }
