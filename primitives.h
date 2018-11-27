#ifndef PRIMITIVES_H
#define PRIMITIVES_H

#include <Angel.h>

const int NumVertices = 36; // (6 faces)(2 triangles/face)(3 vertices/triangle)
const int NumNodes = 11;
const int NumAngles = 11;

const int NumTimesToSubdivide = 5;
const int NumTriangles        = 4096;  // (4 faces)^(NumTimesToSubdivide + 1)
const int NumVertices2        = 3 * NumTriangles;

typedef Angel::vec4 point4;
typedef Angel::vec4 color4;

point4 points[NumVertices];
color4 colors[NumVertices];

point4 points2[NumVertices2];
vec4   normals[NumVertices2];

int Index = 0;        // Global to keep track of what vertex we are setting.

// color4 vertex_colors[8] = {
//
//   color4(0.0, 0.0, 0.0, 1.0),  // black
//   color4(1.0, 0.0, 0.0, 1.0),  // red
//   color4(1.0, 1.0, 0.0, 1.0),  // yellow
//   color4(0.0, 1.0, 0.0, 1.0),  // green
//   color4(0.0, 0.0, 1.0, 1.0),  // blue
//   color4(1.0, 0.0, 1.0, 1.0),  // magenta
//   color4(1.0, 1.0, 1.0, 1.0),  // white
//   color4(0.0, 1.0, 1.0, 1.0)   // cyan
//
// };

color4 vertex_colors[8] = {

  color4(0.9, 0.9, 0.9, 1.0),  // black
  color4(1.0, 1.0, 1.0, 1.0),  // white
  color4(0.9, 0.9, 0.9, 1.0),  // black
  color4(1.0, 1.0, 1.0, 1.0),  // white
  color4(0.9, 0.9, 0.9, 1.0),  // black
  color4(1.0, 1.0, 1.0, 1.0),  // white
  color4(0.9, 0.9, 0.9, 1.0),  // black
  color4(1.0, 1.0, 1.0, 1.0),  // white

};

point4 vertices[8] = {

  point4(-0.5, -0.5,  0.5, 1.0),
  point4(-0.5,  0.5,  0.5, 1.0),
  point4( 0.5,  0.5,  0.5, 1.0),
  point4( 0.5, -0.5,  0.5, 1.0),
  point4(-0.5, -0.5, -0.5, 1.0),
  point4(-0.5,  0.5, -0.5, 1.0),
  point4( 0.5,  0.5, -0.5, 1.0),
  point4( 0.5, -0.5, -0.5, 1.0)

};

// MyQuad generates two triangles for each face and assigns colors to the vertices
void quad(int a, int b, int c, int d) {

  colors[Index] = vertex_colors[a]; points[Index] = vertices[a]; Index++;
  colors[Index] = vertex_colors[b]; points[Index] = vertices[b]; Index++;
  colors[Index] = vertex_colors[c]; points[Index] = vertices[c]; Index++;
  colors[Index] = vertex_colors[a]; points[Index] = vertices[a]; Index++;
  colors[Index] = vertex_colors[c]; points[Index] = vertices[c]; Index++;
  colors[Index] = vertex_colors[d]; points[Index] = vertices[d]; Index++;

}

// generate 12 triangles: 36 vertices and 36 colors
void cube() {

  Index = 0;

  quad(1, 0, 3, 2);
  quad(2, 3, 7, 6);
  quad(3, 0, 4, 7);
  quad(6, 5, 1, 2);
  quad(4, 5, 6, 7);
  quad(5, 4, 0, 1);

}

void triangle(const point4& a, const point4& b, const point4& c) {

  normals[Index] = a;  normals[Index].w=0.0;  points2[Index] = a;  Index++;
  normals[Index] = b;  normals[Index].w=0.0;  points2[Index] = b;  Index++;
  normals[Index] = c;  normals[Index].w=0.0;  points2[Index] = c;  Index++;

}


point4 unit(const point4& p) {

  float len = p.x*p.x + p.y*p.y + p.z*p.z;
  point4 t;
  if (len > DivideByZeroTolerance) {
    t = p / sqrt(len);
    t.w = 1.0;
  }
  return t;

}

void divide_triangle(const point4& a, const point4& b, const point4& c, int count) {

  if (count > 0) {
    point4 v1 = unit(a + b);
    point4 v2 = unit(a + c);
    point4 v3 = unit(b + c);
    divide_triangle( a, v1, v2, count - 1);
    divide_triangle( c, v2, v3, count - 1);
    divide_triangle( b, v3, v1, count - 1);
    divide_triangle(v1, v3, v2, count - 1);
  } else {
    triangle(a, b, c);
  }

}

void tetrahedron(int count) {

  Index = 0;

  point4 v[4] = {
    vec4(0.0, 0.0, 1.0, 1.0),
    vec4(0.0, 0.942809, -0.333333, 1.0),
    vec4(-0.816497, -0.471405, -0.333333, 1.0),
    vec4(0.816497, -0.471405, -0.333333, 1.0)
  };

  divide_triangle(v[0], v[1], v[2], count);
  divide_triangle(v[3], v[2], v[1], count);
  divide_triangle(v[0], v[3], v[1], count);
  divide_triangle(v[0], v[2], v[3], count);

}

#endif
