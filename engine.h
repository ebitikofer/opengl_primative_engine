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
#include "input.h"
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
#define NUM_BULLETS 100
#define NUM_DOORS	11
#define NUM_BOOKCASE	10
#define NUM_ENEMIES	4
#define NUM_TABLES	4
#define NUM_INTERACTABLES	4
#define NUM_PICKUPS	4
#define NUM_ROOMS 10

#define NUM_PARTS 10

MatrixStack mvstack;

enum cardinal{ north, south, east, west };

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

// Globals to control moving around a scene.
vec3 mv_pos = vec3(0.0, 5.0, 0.0); // vec3(-37.5, 5.0, 30.0); // vec3(-50.0, 0.0, 45.0);
vec3 mv_vel = vec3(0.0, 0.0, 0.0);

// Projection transformation parameters
GLfloat fovy = 70.0;  // Field-of-view in Y direction angle (in degrees)
GLfloat zNear = 0.5;  // Near clipping plane
GLfloat zFar = 250.0; // Far clipping plane
GLfloat aspect;       // Viewport aspect ratio

const GLfloat dr = 5.0; // 5.0 * DegreesToRadians;

// Viewing transformation parameters
GLfloat radius = 0.0;
GLfloat theta = 90.0;
GLfloat phi = 0.0;
GLfloat psi = 0.0;
GLfloat pitch = 3.0;
GLfloat yaw = 0.0;
GLfloat roll = 0.0;

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

bool p_die = false;

GLfloat l = 0.0;
GLfloat r = 0.0;
GLfloat u = 0.0;
GLfloat d = 0.0;
GLfloat f = 0.0;
GLfloat b = 0.0;

bool collider[6] = { false };

bool jump = false,
     fall = true;

float red = 0.0, green = 0.5, blue = 1.0, color_a_pink = 0.0;

vec3 book_colors[30] = { vec3(0.0, 0.0, 0.0) };

// Title bar modifiers
std::string title_bar;

bool display_bool = false;

bool death = false, hurt = false, hallucinate = false;

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

  light_positions[0] = vec4(-65.0,  30.0, -55.0, 1.0); // Position of light1
  light_positions[1] = vec4(12.5, 12.5, -12.5, 0.0); // Position of light2 (it will change, so needs to be global).
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

  if (hurt) {
    aps[0] = light_ambients[0] * vec4(r, g, b, 1.0);
    dps[0] = light_diffuses[0] * vec4(r, g, b, 1.0);
    sps[0] = light_speculars[0] * vec4(r, g, b, 1.0);
    aps[1] = light_ambients[1] * vec4(1.0, 0.0, 0.0, 1.0);
    dps[1] = light_diffuses[1] * vec4(1.0, 0.0, 0.0, 1.0);
    sps[1] = light_speculars[1] * vec4(1.0, 0.0, 0.0, 1.0);
    hurt = false;
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

void collision (GLfloat &x, GLfloat &y, GLfloat &z, GLfloat w, GLfloat h, GLfloat d, vec3 loc, vec3 size, bool &result) {
  //
  // //loop through all the normals
  // foreach normal in allNormals
  // {
  // 	//projection might be a for loop over one model’s vertices simply getting max and min value of dot(vertex, normal)
  // 	intervalA = projection(objectA, normal);
  // 	intervalB = projection(objectB, normal);
  //
  // 	//from this point on take first object as moving and the second one as static
  // 	//calculate the velocity of moving object
  // 	finalVelocity = velocityA-velocityB;
  //
  // 	//in order to prevent tunneling we need to expand the intervals by the model velocities - optimization
  // 	//if the velocity is > 0 then we expand it to the right and vice versa
  // 	if (finalVelocity > 0.0f)
  // 	    velocityIntervalA.end += intervalA.end + finalVelocity;
  // 	else
  // 	    velocityIntervalA.start += intervalB.start + finalVelocity;
  //
  // 	//if the velocity expanded intervals overlap, test the times
  // 	if (velocityIntervalA.start <= intervalB.end && intervalB.start <= velocityIntervalA.end)
  // 	{
  // 	    //we need the time intervals of overlap and find out if they overlap with each other :D
  // 	    //we have multiple time intervals, let's take the latest entry time and the earliest leave time, if maxEntry collision
  //
  // 	    //it's calculated for one frame and since the velocity says how much the object moves in one frame, max time is 1 min is 0
  // 	    entry = 0.0f;
  // 	    leave = 1.0f;
  // 	    amount = 0.0;
  //
  // 	    if (intervalA.end <= intervalB.start)
  // 	    {
  // 		//interval A is going away from interval B, no possible collision
  // 		if (finalVelocity <= 0.0f)
  // 		    return res;
  // 		//calculate the time of entering and leaving the other interval, t=s/v
  // 		entry = absVal((intervalB.start - intervalA.end)/finalVelocity);
  // 		leave = absVal((intervalB.end - intervalA.start)/finalVelocity);
  // 	    }
  // 	    //interval B is on the left
  // 	    else if (intervalB.end <= intervalA.start)
  // 	    {
  // 		if (finalVelocity >=0.0f)
  // 		    return res;
  // 		entry = absVal((intervalA.start - intervalB.end)/finalVelocity);
  // 		leave = absVal((intervalA.end - intervalB.start)/finalVelocity);
  // 	    }
  // 	    //intervals already overlap
  // 	    else
  // 	    {
  // 		//deciding how do the overlap
  // 		if (intervalA.start <= intervalB.start)
  // 		{
  // 		    leave = absVal((intervalB.end - intervalA.start)/finalVelocity);
  // 		    amount = intervalA.end - intervalB.start;
  // 		}
  // 		else
  // 		{
  // 		    leave = absVal((intervalA.end - intervalB.start)/finalVelocity);
  // 		    amount = intervalB.end - intervalA.start;
  // 		}
  // 	    }
  //
  // 	    //here we can leave if the collision happens in the future frames (time is higher than max time of the frame = 1)
  // 	    if (entry > 1.0f)
  // 		return;
  //
  //
  // 	    //save max and min of overlap borders
  // 	    if (maxEntry < entry)
  // 	    {
  // 		maxEntry = entry;
  // 		minAmout = amount;
  // 		collisionNormal = normal;
  // 	    }
  //       	    //this is the case of overlap, we can use the amount to push the objects out of each other
  // 	    else if (amount < minAmount)
  // 	    {
  // 		minAmount = amount;
  // 		overlapNormal = normal;
  // 	    }
  // 	    if (minLeave >= leave)
  // 		minLeave = leave;
  //
  // 	}
  // 	//if they don't overlap then we have found the separating axis (current normal) and we can say there is no collision
  // 	else
  // 	    return;
  // 	}
  //
  // 	//if there is a time interval that lies inside all the found ones, collision happened
  // 	if (minLeave>=maxEntry)
  // 	    foundInterval = true;

  /////physics


//
// //to keep the track of in-frame time <0.0; 1.0>
// left = 1.0;
// elapsed = 1.0;
// end = false;
//
// //gravity etc.
// applyEnviromentals();
//
// while(!end)
// {
// 	findCollisions();
// 	//the physics will set elapsed something greater than 1.0 if the collision happens in the next frame
// 	//physics module also changes the velocity vectors of the objects according to the collision responses
// 	elapsed = solvePhysics(left);
//
// 	if (elapsed > 1.0)
// 		break;
//
// 	//move the objects (according to their velocities, some might be modified by the physics solving)
// 	moveObjects(elapsed);
// 	//octree update
// 	rebuildTree();
// 	left -= elapsed;
// }
// //move the objects to the end of the frame
// moveObjects(left);
// rebuildTree();



  // var length:Number = box2.x - box1.x;
  // var phw = ;
  // var ohw = ;
  //
  // var gap_between_boxes:Number = length - half_width_box1 - half_width_box2;
  // if(gap_between_boxes > 0) trace("It's a big gap between boxes")
  // else if(gap_between_boxes == 0) trace("Boxes are touching each other")
  // else if(gap_between_boxes < 0) trace("Boxes are penetrating each other")

  if (x - w/2 < loc.x + size.x/2 && x + w/2 > loc.x - size.x/2 &&
      y - h/2 < loc.y + size.y/2 && y + h/2 > loc.y - size.y/2 &&
      z - d/2 < loc.z + size.z/2 && z + d/2 > loc.z - size.z/2 ) {
    result = true;
    collider[1] = true;
    l = (loc.x + size.x / 2) - (x - w / 2);
    r = (x + w / 2) - (loc.x - size.x / 2);
    u = (loc.y + size.y / 2) - (y - h / 2);
    d = (y + h / 2) - (loc.y - size.y / 2);
    f = (loc.z + size.z / 2) - (z - d / 2);
    b = (z + d / 2) - (loc.z - size.z / 2);
         if (l < f && l < b && l < u && l < d && l < r) { x += l; mv_vel.x = 0.0; }
    else if (r < f && r < b && r < u && r < d && r < l) { x -= r; mv_vel.x = 0.0; }
    else if (u < f && u < b && u < l && u < r && u < d) { y += u; mv_vel.y = 0.0; }
    else if (d < f && d < b && d < l && d < r && d < u) { y -= d; mv_vel.y = 0.0; }
    else if (f < u && f < d && f < l && f < r && f < b) { z += f; mv_vel.z = 0.0; }
    else if (b < u && b < d && b < l && b < r && b < f) { z -= b; mv_vel.z = 0.0; }
  } else {
    result = false;
  }
}

void proximity (GLfloat x, GLfloat y, GLfloat z, GLfloat w, GLfloat h, GLfloat d, vec3 loc, vec3 size, bool &result) {
  float m = 0.0;
  if (x - w / 2 < (loc.x + (size.x + m) / 2) && x + w / 2 > (loc.x - (size.x - m) / 2) &&
      y - h / 2 < (loc.y + (size.y + m) / 2) && y + h / 2 > (loc.y - (size.y - m) / 2) &&
      z - d / 2 < (loc.z + (size.z + m) / 2) && z + d / 2 > (loc.z - (size.z - m) / 2) ) {
    result = true;
  } else {

    // result = false;
  }
}

// myReshape function, reshapes the window when resized
void reshape (int width, int height) {

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

  sc_x = width / 600.0;
  sc_y = height / 600.0;

  std::cout << sc_x << std::endl;
  std::cout << sc_y << std::endl;

}

// init function, initializes the drawables and GL_DEPTH_TEST
void init(int argc, char **argv) {

  std::uniform_real_distribution<double> morpher1(0.25, 0.75);
  std::uniform_real_distribution<double> morpher2(0.25, 0.75);
  std::uniform_real_distribution<double> morpher3(0.25, 0.75);

  glutInit(&argc, argv);
  glutInitDisplayMode( GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH );
  glutInitWindowSize( SCREEN_WIDTH, SCREEN_HEIGHT );
  glutCreateWindow( "SEDATIVE FELLA" );
  glutReshapeFunc(reshape);
  glewInit();
  glutIgnoreKeyRepeat(1);
  glutKeyboardFunc(keyboard);
  glutKeyboardUpFunc(keyboardUp);
  glutSpecialFunc(special);
  glutSpecialUpFunc(specialUp);
  glutMouseFunc(mouse);

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
