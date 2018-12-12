#ifndef ENGINE_H
#define ENGINE_H

#include <Angel.h>
#include <chrono>
#include <random>
#include <assert.h>
#include "utility.h"
#include "matstack.h"
#include "object.h"
#include "primitives.h"
#include "models.h"

// Screen dimensions
#define SCREEN_WIDTH  600
#define SCREEN_HEIGHT 600

// Drawing
#define DRAW_DISTANCE 69.0

// Motion rates
#define RATE_CAMERA_H	4
#define RATE_CAMERA_V	2

#define NUM_OBJECTS	44
#define NUM_DOORS	11
#define NUM_BOOKCASE	10
#define NUM_ENEMIES	4
#define NUM_TABLES	4
#define NUM_INTERACTABLES	4
#define NUM_PICKUPS	10
#define NUM_ROOMS 10

#define NUM_PARTS 10

MatrixStack mvstack;

enum cardinal{ north, south, east, west };

static int screen_width = SCREEN_WIDTH;
static int screen_height = SCREEN_HEIGHT;

bool quit;

GLUquadricObj *qobj;  // For drawing cylinders

GLuint camera_view;   // camera-view matrix uniform shader variable location
GLuint model_view;    // model-view matrix uniform shader variable location
GLuint projection;    // projection matrix uniform shader variable location
GLuint color_change;  // projection matrix uniform shader variable location
GLuint enable;  // projection matrix uniform shader variable location
GLuint ambient_product;
GLuint diffuse_product;
GLuint specular_product;
GLuint ambient_product2;
GLuint diffuse_product2;
GLuint specular_product2;

mat4 p, mv, cv, pv;   // shader variables
vec4 cc;

// Projection transformation parameters
GLfloat fovy = 70.0;  // Field-of-view in Y direction angle (in degrees)
GLfloat zNear = 0.5;  // Near clipping plane
GLfloat zFar = 250.0; // Far clipping plane
GLfloat aspect;       // Viewport aspect ratio

// Viewing transformation parameters
GLfloat radius = 0.0;
GLfloat theta = 90.0;
GLfloat phi = 0.0;
GLfloat psi = 0.0;
GLfloat pitch = 3.0;
GLfloat yaw = 0.0;
GLfloat roll = 0.0;

bool key_buffer[256] = { false };
bool spec_buffer[256] = { false };

static int mouse_button;
static int mouse_button_state;
bool changed = false;
int lastX = 0;
int lastY = 0;
float xoffset = 0;
float yoffset = 0;

bool moving = false;

bool perspective = false;

bool collide[NUM_OBJECTS] = { false };

bool proximal[NUM_INTERACTABLES] = { false };

bool pickup[NUM_PICKUPS] = { false };

bool doors[NUM_DOORS] = { false };

bool g_die[NUM_GHOSTS] = { false };

bool z_die[NUM_ZOMBIES] = { false };

bool w_die[NUM_WEREWOLFS] = { false };

bool a_die[NUM_AGENCIES] = { false };

bool p_die[NUM_ENEMIES] = { false };

GLfloat left = 0.0;
GLfloat right = 0.0;
GLfloat up = 0.0;
GLfloat down = 0.0;
GLfloat forward = 0.0;
GLfloat backward = 0.0;

float red = 0.0, green = 0.5, blue = 1.0, color_a_pink = 0.0;

vec3 book_colors[30] = { vec3(0.0, 0.0, 0.0) };

// Title bar modifiers
std::string title_bar;

bool display_bool = false;

bool death = false, hallucinate = false;
bool heal = false, hurt = false, strengthen = false, weaken = false, resupply = false, energize = false;

GLuint Lights[2];
color4 light_ambients[2] = { vec4(1.0, 1.0, 1.0, 1.0) };
color4 light_diffuses[2] = { vec4(1.0, 1.0, 1.0, 1.0) };
color4 light_speculars[2] = { vec4(1.0, 1.0, 1.0, 1.0) };

GLuint Lights_Pos[2];
point4 light_positions[2] = { vec4(0.0, 0.0, 0.0, 0.0) }; // Position of lights

bool lights[2] = { false };

// Next variables used to move light2.
GLfloat light_theta = 0.0; // the angle of light2
GLfloat light_incr = 0.001; // the amount to move light2 in radians/millisecond
bool rotate = false; // are we animating light2?

color4 emissive[2] = { vec4(0.0, 0.0, 0.0, 0.0) };

GLuint shiny;
GLuint Material_Emiss; // uniform location of emissive property of surface

color4 aps[2] = { vec4(1.0, 1.0, 1.0, 1.0) };
color4 dps[2] = { vec4(1.0, 1.0, 1.0, 1.0) };
color4 sps[2] = { vec4(1.0, 1.0, 1.0, 1.0) };

std::string score_text = "0";

float sc_x = SCREEN_WIDTH / 600;
float sc_y = SCREEN_HEIGHT / 600;

void lighting () {

  light_positions[0] = vec4(-65.0, 30.0, -55.0, 0.0); // Position of light1
  light_positions[1] = vec4(20.0, 20.0, 20.0, 0.0); // Position of light2 (it will change, so needs to be global).
  //point4 light_position(0.0, 0.0, 1.0, 0.0); // If you want a non-positional light use 0.0 for fourth value

  // Initialize first light lighting parameters
  light_ambients[0] = vec4(0.2, 0.2, 0.2, 1.0);
  light_diffuses[0] = vec4(0.5, 0.5, 0.5, 1.0);
  light_speculars[0] = vec4(0.6, 0.6, 0.6, 1.0);

  // Initialize second light lighting parameters
  light_ambients[1] = vec4(1.0, 1.0, 1.0, 1.0);
  light_diffuses[1] = vec4(1.0, 1.0, 1.0, 1.0);
  light_speculars[1] = vec4(1.0, 1.0, 1.0, 1.0);

  lights[0] = true;  // Is light1 on?
  lights[1] = true;  // Is light2 on?

  emissive[0] = vec4(0.0, 0.0, 0.0, 1.0); // off
  emissive[1] = vec4(1.0, 1.0, 1.0, 1.0); // on

  aps[0] = light_ambients[0];
  dps[0] = light_diffuses[0];
  sps[0] = light_speculars[0];

  aps[1] = light_ambients[1];
  dps[1] = light_diffuses[1];
  sps[1] = light_speculars[1];

}

void object(mat4 matrix, GLuint uniform, GLfloat x, GLfloat y, GLfloat z, GLfloat w, GLfloat h, GLfloat d, GLfloat r, GLfloat g, GLfloat b, int pitch, int yaw, int roll, int sl, int st, int type) {

  if (heal) {
    aps[0] = light_ambients[0] * vec4(r, g, b, 1.0);
    dps[0] = light_diffuses[0] * vec4(r, g, b, 1.0);
    sps[0] = light_speculars[0] * vec4(r, g, b, 1.0);
    aps[1] = light_ambients[1] * vec4(0.0, 0.5, 0.0, 1.0);
    dps[1] = light_diffuses[1] * vec4(0.0, 0.5, 0.0, 1.0);
    sps[1] = light_speculars[1] * vec4(0.0, 0.5, 0.0, 1.0);
    heal = false;
  } else if (hurt) {
    aps[0] = light_ambients[0] * vec4(r, g, b, 1.0);
    dps[0] = light_diffuses[0] * vec4(r, g, b, 1.0);
    sps[0] = light_speculars[0] * vec4(r, g, b, 1.0);
    aps[1] = light_ambients[1] * vec4(0.25, 0.0, 0.0, 1.0);
    dps[1] = light_diffuses[1] * vec4(0.25, 0.0, 0.0, 1.0);
    sps[1] = light_speculars[1] * vec4(0.25, 0.0, 0.0, 1.0);
    hurt = false;
  } else if (strengthen) {
    aps[0] = light_ambients[0] * vec4(r, g, b, 1.0);
    dps[0] = light_diffuses[0] * vec4(r, g, b, 1.0);
    sps[0] = light_speculars[0] * vec4(r, g, b, 1.0);
    aps[1] = light_ambients[1] * vec4(0.0, 0.5, 0.5, 1.0);
    dps[1] = light_diffuses[1] * vec4(0.0, 0.5, 0.5, 1.0);
    sps[1] = light_speculars[1] * vec4(0.0, 0.5, 0.5, 1.0);
    strengthen = false;
  } else if (weaken) {
    aps[0] = light_ambients[0] * vec4(r, g, b, 1.0);
    dps[0] = light_diffuses[0] * vec4(r, g, b, 1.0);
    sps[0] = light_speculars[0] * vec4(r, g, b, 1.0);
    aps[1] = light_ambients[1] * vec4(0.25, 0.25, 0.25, 1.0);
    dps[1] = light_diffuses[1] * vec4(0.25, 0.25, 0.25, 1.0);
    sps[1] = light_speculars[1] * vec4(0.25, 0.25, 0.25, 1.0);
    weaken = false;
  } else if (resupply) {
    aps[0] = light_ambients[0] * vec4(r, g, b, 1.0);
    dps[0] = light_diffuses[0] * vec4(r, g, b, 1.0);
    sps[0] = light_speculars[0] * vec4(r, g, b, 1.0);
    aps[1] = light_ambients[1] * vec4(0.25, 0.25, 0.0, 1.0);
    dps[1] = light_diffuses[1] * vec4(0.25, 0.25, 0.0, 1.0);
    sps[1] = light_speculars[1] * vec4(0.25, 0.25, 0.0, 1.0);
    resupply = false;
  } else if (energize) {
    aps[0] = light_ambients[0] * vec4(r, g, b, 1.0);
    dps[0] = light_diffuses[0] * vec4(r, g, b, 1.0);
    sps[0] = light_speculars[0] * vec4(r, g, b, 1.0);
    aps[1] = light_ambients[1] * vec4(0.25, 0.0, 0.25, 1.0);
    dps[1] = light_diffuses[1] * vec4(0.25, 0.0, 0.25, 1.0);
    sps[1] = light_speculars[1] * vec4(0.25, 0.0, 0.25, 1.0);
    energize = false;
  } else if (hallucinate) {
    color_a_pink += 0.001;
    red = sin(color_a_pink*M_PI/180/2);
    green = sin(90 + 1.5 * color_a_pink*M_PI/180/2);
    blue = sin(180 + 2.0 * color_a_pink*M_PI/180/2);
    aps[0] = light_ambients[0] * vec4(red * 0.6, green * 0.6, blue * 0.6, 1.0);
    dps[0] = light_diffuses[0] * vec4(red * 0.5, green * 0.5, blue * 0.5, 1.0);
    sps[0] = light_speculars[0] * vec4(red * 0.4, green * 0.4, blue * 0.4, 1.0);
    aps[1] = light_ambients[1] * vec4(-red * 0.4, -green * 0.5, -blue * 0.6, 1.0);
    dps[1] = light_diffuses[1] * vec4(-blue * 0.5, -red * 0.6, -green * 0.4, 1.0);
    sps[1] = light_speculars[1] * vec4(-green * 0.6, -blue * 0.4, -red * 0.5, 1.0);
  } else {
    aps[0] = light_ambients[0] * vec4(r, g, b, 1.0);
    dps[0] = light_diffuses[0] * vec4(r, g, b, 1.0);
    sps[0] = light_speculars[0] * vec4(r, g, b, 1.0);
    aps[1] = light_ambients[1] * vec4(r, g, b, 1.0);
    dps[1] = light_diffuses[1] * vec4(r, g, b, 1.0);
    sps[1] = light_speculars[1] * vec4(r, g, b, 1.0);
  }

    glUniform4fv(ambient_product, 1, aps[0]);
    glUniform4fv(diffuse_product, 1, dps[0]);
    glUniform4fv(specular_product, 1, sps[0]);

    glUniform4fv(ambient_product2, 1, aps[1]);
    glUniform4fv(diffuse_product2, 1, dps[1]);
    glUniform4fv(specular_product2, 1, sps[1]);

    mat4 instance = (
      Translate( x, y, z )
      * RotateX(pitch) * RotateY(yaw) * RotateZ(roll)
    );

    switch (type) {
      case 0:
        glUniformMatrix4fv( uniform, 1, GL_TRUE, matrix * instance * Scale( w, h, d ) );
        glUniform1f( enable, 0.0 );
        glDrawArrays( GL_TRIANGLES, 0, NumVertices ); break;
      // case 1:
      //   glUniformMatrix4fv( uniform, 1, GL_TRUE, matrix * instance );
      //   glUniform1f( enable, 2.0 );
      //   gluCylinder(qobj, w, d, h, sl, st); break;
      case 2:
        glUniform4fv(Material_Emiss, 1, emissive[1]);
          glUniformMatrix4fv( uniform, 1, GL_TRUE, matrix * instance * Scale( w, h, d ) );
          glUniform1f( enable, 1.0 );
          glDrawArrays( GL_TRIANGLES, NumVertices, NumVertices2 );
        glUniform4fv(Material_Emiss, 1, emissive[0]); break;
      case 3:
        glUniformMatrix4fv( uniform, 1, GL_TRUE, matrix * instance * Scale( w, h, d ) );
        glUniform1f( enable, 0.0 );
        glDrawArrays( GL_TRIANGLES, 0, NumVertices / 12 ); break;
      case 4:
        glUniformMatrix4fv( uniform, 1, GL_TRUE, matrix * instance * Scale( w, h, d ) );
        glUniform1f( enable, 0.0 );
        glDrawArrays( GL_TRIANGLES, 0, NumVertices / 9 ); break;

    };

}

void collision(vec3 &position, vec3 size, vec3 &velocity, vec3 loc, vec3 bound, bool &result, float margin, bool is_collision, bool &collider) {

  if (position.x - size.x / 2 < loc.x + (bound.x + margin) / 2 && position.x + size.x / 2 > loc.x - (bound.x + margin) / 2 &&
      position.y - size.y / 2 < loc.y + (bound.y + margin) / 2 && position.y + size.y / 2 > loc.y - (bound.y + margin) / 2 &&
      position.z - size.z / 2 < loc.z + (bound.z + margin) / 2 && position.z + size.z / 2 > loc.z - (bound.z + margin) / 2 ) {

    result = true;

    if(is_collision) {

      collider = true;

      left =      (loc.x      + bound.x / 2) - (position.x -  size.x / 2);
      right =     (position.x +  size.x / 2) - (loc.x      - bound.x / 2);
      up =        (loc.y      + bound.y / 2) - (position.y -  size.y / 2);
      down =      (position.y +  size.y / 2) - (loc.y      - bound.y / 2);
      forward =   (loc.z      + bound.z / 2) - (position.z -  size.z / 2);
      backward =  (position.z +  size.z / 2) - (loc.z      - bound.z / 2);

           if (left <  forward && left <  backward && left <       up && left <      down && left <       right) { position.x += left; velocity.x = 0.0; }
      else if (right < forward && right < backward && right <      up && right <     down && right <       left) { position.x -= right; velocity.x = 0.0; }
      else if (up <    forward && up <    backward && up <       left && up <       right && up <          down) { position.y += up; velocity.y = 0.0; }
      else if (down <  forward && down <  backward && down <     left && down <     right && down <          up) { position.y -= down; velocity.y = 0.0; }
      else if (forward <    up && forward <   down && forward <  left && forward <  right && forward < backward) { position.z += forward; velocity.z = 0.0; }
      else if (backward <   up && backward <  down && backward < left && backward < right && backward < forward) { position.z -= backward; velocity.z = 0.0; }

    }

  } else {

    result = false;

  }

}

// myReshape function, reshapes the window when resized
void reshape (int width, int height) {

  screen_height = height;
  screen_width = width;

  glViewport(0, 0, width, height);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  // gluPerspective(100.0, (GLfloat) w / (GLfloat) h, 1.0, 30.0);
  aspect = (GLfloat) width / (GLfloat) height;
  gluPerspective(fovy, aspect, zNear, zFar);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  // glTranslatef(0.0, 1.2, -5.5);  /* viewing transform  */
  // glUniformMatrix4fv(Projection, 1, GL_TRUE, projection);

  sc_x = 600.0 / width;
  sc_y = 600.0 / height;

  std::cout << sc_x << std::endl;
  std::cout << sc_y << std::endl;

}

void motion(int x, int y) {

  if ( x < 50 || x > screen_width - 50) {

    lastX = screen_width/2;
    lastY = screen_height/2;
    glutWarpPointer(screen_width/2, screen_height/2);

    return;

  } else if (y < 50 || y > screen_height - 50) {

    lastX = screen_width/2;
    lastY = screen_height/2;
    glutWarpPointer(screen_width/2, screen_height/2);

    return;

  }

  // if (firstMouse) {
  //   lastX = x;
  //   lastY = y;
  //   firstMouse = false;
  // }

  xoffset = x - lastX;
  yoffset = lastY - y;

  lastX = x;
  lastY = y;

}

void mouse(int button, int state, int x, int y) {

  mouse_button = button;
  mouse_button_state = state;
  changed = true;

}

// keyboard function, keyboard callback for key down functionality
void keyboard(unsigned char key, int x, int y) { key_buffer[key] = true; }

// keyboardUp function, keyboard callback for key up functionality
void keyboardUp(unsigned char key, int x, int y) { key_buffer[key] = false; }

// special function, special callback for special key down functionality
void special(int key, int x, int y) { spec_buffer[key] = true; }

// specialUp function, special callback for special key up functionality
void specialUp(int key, int x, int y) { spec_buffer[key] = false; }

// init function, initializes the drawables and GL_DEPTH_TEST
void init(int argc, char **argv) {

  std::uniform_real_distribution<double> morpher1(0.25, 0.75);
  std::uniform_real_distribution<double> morpher2(0.25, 0.75);
  std::uniform_real_distribution<double> morpher3(0.25, 0.75);

  glutInit(&argc, argv);
  glutInitDisplayMode( GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH );
  glutInitWindowSize( SCREEN_WIDTH, SCREEN_HEIGHT );
  glutCreateWindow( "K3YB04RD K1D!" );
  glutReshapeFunc(reshape);
  glewInit();
  glutIgnoreKeyRepeat(1);
  glutKeyboardFunc(keyboard);
  glutKeyboardUpFunc(keyboardUp);
  glutSpecialFunc(special);
  glutSpecialUpFunc(specialUp);
  glutMouseFunc(mouse);
  glutPassiveMotionFunc(motion);
  glutMotionFunc(motion);
  glutSetCursor(GLUT_CURSOR_NONE);

  qobj = gluNewQuadric();

  cube();
  tetrahedron(NumTimesToSubdivide);

  load(mv, model_view);

  for (int i = 0; i < 30; i++) {
    book_colors[i] = vec3(morpher1(mt), morpher2(mt), morpher3(mt));
  }

  lighting();

  // Create a vertex array object
  GLuint vao;
  glGenVertexArrays(1, &vao);
  glBindVertexArray(vao);

  // Create and initialize a buffer object
  GLuint buffer;
  glGenBuffers(1, &buffer);
  glBindBuffer(GL_ARRAY_BUFFER, buffer);
  glBufferData(GL_ARRAY_BUFFER, sizeof(points) + sizeof(points2) + sizeof(colors) + sizeof(normals), NULL, GL_STATIC_DRAW);
  glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(points), points);
  glBufferSubData(GL_ARRAY_BUFFER, sizeof(points), sizeof(points2), points2);
  glBufferSubData(GL_ARRAY_BUFFER, sizeof(points2), sizeof(colors), colors);
  // glBufferSubData(GL_ARRAY_BUFFER, sizeof(colors), sizeof(normals), normals);

  // Load shaders and use the resulting shader program
  GLuint program = InitShader("shaders/vshader.glsl", "shaders/fshader.glsl");
  glUseProgram(program);

  // // set up vertex arrays
  GLuint vPosition = glGetAttribLocation(program, "vPosition");
  glEnableVertexAttribArray(vPosition);
  glVertexAttribPointer(vPosition, 4, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(0));

  GLuint vColor = glGetAttribLocation(program, "vColor");
  glEnableVertexAttribArray(vColor);
  glVertexAttribPointer(vColor, 4, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(sizeof(points2)));

  GLuint vNormal = glGetAttribLocation(program, "vNormal");
  glEnableVertexAttribArray(vNormal);
  glVertexAttribPointer(vNormal, 4, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(sizeof(normals)));

  model_view = glGetUniformLocation(program, "model_view");
  camera_view = glGetUniformLocation(program, "camera_view");
  projection = glGetUniformLocation(program, "projection");
  color_change = glGetUniformLocation(program, "color_change");
  enable = glGetUniformLocation(program, "enable");

  ambient_product = glGetUniformLocation(program, "AmbientProduct");
  diffuse_product = glGetUniformLocation(program, "DiffuseProduct");
  specular_product = glGetUniformLocation(program, "SpecularProduct");
  ambient_product2 = glGetUniformLocation(program, "AmbientProduct2");
  diffuse_product2 = glGetUniformLocation(program, "DiffuseProduct2");
  specular_product2 = glGetUniformLocation(program, "SpecularProduct2");

  glUniform4fv(glGetUniformLocation(program, "LightPosition"), 1, light_positions[0]);

  Lights_Pos[2] = glGetUniformLocation(program, "LightPosition2");
  glUniform4fv(Lights_Pos[2], 1, light_positions[1]);

  shiny = glGetUniformLocation(program, "Shininess");

  Material_Emiss = glGetUniformLocation(program, "emissive");

  Lights[0] = glGetUniformLocation(program, "light1");
  glUniform1i(Lights[0], lights[0]);

  Lights[1] = glGetUniformLocation(program, "light2");
  glUniform1i(Lights[1], lights[1]);

  glEnable(GL_DEPTH_TEST);
  glClearColor(0.5, 0.5, 0.5, 1.0);

}

#endif
