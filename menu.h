#ifndef MENU_H
#define MENU_H

#include <Angel.h>

// menu_select function, functions for menu click
void menu_select(int mode) {

  switch (mode) {
    case 1: ; break;
    case 2: glutIdleFunc(NULL); break;
    case 3: /* solid_part = !solid_part; */ glutPostRedisplay(); break;
    case 4: exit(EXIT_SUCCESS);
  }

}

// null_select function, function for menu items that dont do anything
void null_select(int mode) { }

// glutMenu function, menu generating function
void glutMenu(void) {

  int glut_menu[3];

  glut_menu[1] = glutCreateMenu(null_select);
  glutAddMenuEntry("start : tilde", 0);
  glutAddMenuEntry("right : right arrow", 0);
  glutAddMenuEntry("left  : left arrow", 0);
  glutAddMenuEntry("down  : up arrow", 0);
  glutAddMenuEntry("up    : down arrow", 0);

  glut_menu[2] = glutCreateMenu(null_select);
  glutAddMenuEntry("start  : x", 0);
  glutAddMenuEntry("fire   : space", 0);
  glutAddMenuEntry("weak   : 1", 0);
  glutAddMenuEntry("medium : 2", 0);
  glutAddMenuEntry("strong : 3", 0);

  glut_menu[0] = glutCreateMenu(NULL);
  glutAddSubMenu("freelook", glut_menu[1]);
  glutAddSubMenu("operate the gun", glut_menu[2]);

  glutCreateMenu(menu_select);
  glutAddMenuEntry("Start", 1);
  glutAddMenuEntry("Stop", 2);
  // glutAddMenuEntry("Toggle Wireframe", 3);
  glutAddSubMenu("How to...", glut_menu[0]);
  glutAddMenuEntry("Quit", 4);
  // glutAttachMenu(GLUT_LEFT_BUTTON);
  glutAttachMenu(GLUT_MIDDLE_BUTTON);

}

#endif
