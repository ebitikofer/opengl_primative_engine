#ifndef INPUT_H
#define INPUT_H

#include <Angel.h>

bool key_buffer[256] = { false };
bool spec_buffer[256] = { false };

static int mouse_button;
bool changed = false;

// keyboard function, keyboard callback for key down functionality
void keyboard(unsigned char key, int x, int y) { key_buffer[key] = true; }

// keyboardUp function, keyboard callback for key up functionality
void keyboardUp(unsigned char key, int x, int y) { key_buffer[key] = false; }

// special function, special callback for special key down functionality
void special(int key, int x, int y) { spec_buffer[key] = true; }

// specialUp function, special callback for special key up functionality
void specialUp(int key, int x, int y) { spec_buffer[key] = false; }

void mouse(int button, int state, int x, int y) { mouse_button = button; changed = true; }

#endif
