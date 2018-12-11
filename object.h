#ifndef OBJECT_H
#define OBJECT_H

#include <Angel.h>
#include <string>
#include "matstack.h"
#include "primitives.h"

class Object {

  public:

    enum material { wood, metal, glass, ceramic };

    Object() : /*render(NULL),*/ sibling(NULL), child(NULL) {}

    Object( mat4& m, /*void (*render)( void ),*/ Object* sibling, Object* child ) :
	   transform(m), /*render(render),*/ sibling(sibling), child(child) {}

    ~Object() {}

    void create (mat4 matr, GLuint unif, vec3 movement, vec3 growth, vec3 interpolation, vec3 heading, int sli, int sta, int typ, material mater) {

      left = 0.0; right = 0.0;
      up = 0.0; down = 0.0;
      forward = 0.0; backward = 0.0;

      fall = true; collide = false;

      matrix = matr; uniform = unif;

      position = movement;
      size = growth;
      color = interpolation;
      rotation = heading;

      sl = sli; st = sta;
      type = typ;

      switch (mater) {
        case 0:
          material_ambient = vec4(1.0, 1.0, 1.0, 1.0);
          material_diffuse = vec4(1.0, 1.0, 1.0, 1.0);
          material_specular = vec4(1.0, 1.0, 1.0, 1.0);
          material_shininess = 10.0;
          break;
        case 1:
          material_ambient = vec4(1.0, 1.0, 1.0, 1.0);
          material_diffuse = vec4(1.0, 1.0, 1.0, 1.0);
          material_specular = vec4(1.0, 1.0, 1.0, 1.0);
          material_shininess = 40.0;
          break;
        case 2:
          material_ambient = vec4(1.0, 1.0, 1.0, 1.0);
          material_diffuse = vec4(1.0, 1.0, 1.0, 1.0);
          material_specular = vec4(1.0, 1.0, 1.0, 1.0);
          material_shininess = 70.0;
          break;
        case 3:
          material_ambient = vec4(1.0, 1.0, 1.0, 1.0);
          material_diffuse = vec4(1.0, 1.0, 1.0, 1.0);
          material_specular = vec4(1.0, 1.0, 1.0, 1.0);
          material_shininess = 50.0;
          break;
      }
    }

    void render (/*MatrixStack stack,*/ bool heal, bool hurt, bool strengthen, bool weaken, bool resupply, bool energize, bool hallucinate,
      color4 ap[], color4 dp[], color4 sp[],
      color4 light_ambient[], color4 light_diffuse[], color4 light_specular[],
      GLuint ambient_product, GLuint diffuse_product, GLuint specular_product,
      GLuint ambient_product2, GLuint diffuse_product2, GLuint specular_product2,
      GLuint enable, float color_a_pink, color4 emissive[], GLuint Material_Emiss, GLuint shiny) {

      // stack.push(matrix);

      if (heal) {
        ap[0] = light_ambient[0] * vec4(color.x, color.y, color.z, 1.0);
        dp[0] = light_diffuse[0] * vec4(color.x, color.y, color.z, 1.0);
        sp[0] = light_specular[0] * vec4(color.x, color.y, color.z, 1.0);
        ap[1] = light_ambient[1] * vec4(0.0, 0.5, 0.0, 1.0);
        dp[1] = light_diffuse[1] * vec4(0.0, 0.5, 0.0, 1.0);
        sp[1] = light_specular[1] * vec4(0.0, 0.5, 0.0, 1.0);
        heal = false;
      } else if (hurt) {
        ap[0] = light_ambient[0] * vec4(color.x, color.y, color.z, 1.0);
        dp[0] = light_diffuse[0] * vec4(color.x, color.y, color.z, 1.0);
        sp[0] = light_specular[0] * vec4(color.x, color.y, color.z, 1.0);
        ap[1] = light_ambient[1] * vec4(0.25, 0.0, 0.0, 1.0);
        dp[1] = light_diffuse[1] * vec4(0.25, 0.0, 0.0, 1.0);
        sp[1] = light_specular[1] * vec4(0.25, 0.0, 0.0, 1.0);
        hurt = false;
      } else if (strengthen) {
        ap[0] = light_ambient[0] * vec4(color.x, color.y, color.z, 1.0);
        dp[0] = light_diffuse[0] * vec4(color.x, color.y, color.z, 1.0);
        sp[0] = light_specular[0] * vec4(color.x, color.y, color.z, 1.0);
        ap[1] = light_ambient[1] * vec4(0.0, 0.5, 0.5, 1.0);
        dp[1] = light_diffuse[1] * vec4(0.0, 0.5, 0.5, 1.0);
        sp[1] = light_specular[1] * vec4(0.0, 0.5, 0.5, 1.0);
        strengthen = false;
      } else if (weaken) {
        ap[0] = light_ambient[0] * vec4(color.x, color.y, color.z, 1.0);
        dp[0] = light_diffuse[0] * vec4(color.x, color.y, color.z, 1.0);
        sp[0] = light_specular[0] * vec4(color.x, color.y, color.z, 1.0);
        ap[1] = light_ambient[1] * vec4(0.25, 0.25, 0.25, 1.0);
        dp[1] = light_diffuse[1] * vec4(0.25, 0.25, 0.25, 1.0);
        sp[1] = light_specular[1] * vec4(0.25, 0.25, 0.25, 1.0);
        weaken = false;
      } else if (resupply) {
        ap[0] = light_ambient[0] * vec4(color.x, color.y, color.z, 1.0);
        dp[0] = light_diffuse[0] * vec4(color.x, color.y, color.z, 1.0);
        sp[0] = light_specular[0] * vec4(color.x, color.y, color.z, 1.0);
        ap[1] = light_ambient[1] * vec4(0.25, 0.25, 0.0, 1.0);
        dp[1] = light_diffuse[1] * vec4(0.25, 0.25, 0.0, 1.0);
        sp[1] = light_specular[1] * vec4(0.25, 0.25, 0.0, 1.0);
        resupply = false;
      } else if (energize) {
        ap[0] = light_ambient[0] * vec4(color.x, color.y, color.z, 1.0);
        dp[0] = light_diffuse[0] * vec4(color.x, color.y, color.z, 1.0);
        sp[0] = light_specular[0] * vec4(color.x, color.y, color.z, 1.0);
        ap[1] = light_ambient[1] * vec4(0.25, 0.0, 0.25, 1.0);
        dp[1] = light_diffuse[1] * vec4(0.25, 0.0, 0.25, 1.0);
        sp[1] = light_specular[1] * vec4(0.25, 0.0, 0.25, 1.0);
        energize = false;
      } else if (hallucinate) {
        color_a_pink += 0.001;
        float red = sin(color_a_pink*M_PI/180/2);
        float green = sin(90 + 1.5 * color_a_pink*M_PI/180/2);
        float blue = sin(180 + 2.0 * color_a_pink*M_PI/180/2);
        ap[0] = light_ambient[0] * vec4(red * 0.6, green * 0.6, blue * 0.6, 1.0) * material_ambient;
        dp[0] = light_diffuse[0] * vec4(red * 0.5, green * 0.5, blue * 0.5, 1.0) * material_diffuse;
        sp[0] = light_specular[0] * vec4(red * 0.4, green * 0.4, blue * 0.4, 1.0) * material_specular;
        ap[1] = light_ambient[1] * vec4(-red * 0.4, -green * 0.5, -blue * 0.6, 1.0) * material_ambient;
        dp[1] = light_diffuse[1] * vec4(-blue * 0.5, -red * 0.6, -green * 0.4, 1.0) * material_diffuse;
        sp[1] = light_specular[1] * vec4(-green * 0.6, -blue * 0.4, -red * 0.5, 1.0) * material_specular;
      } else {
        ap[0] = light_ambient[0] * vec4(color.x * 1.0, color.y * 1.0, color.z * 1.0, 1.0) * material_ambient;
        dp[0] = light_diffuse[0] * vec4(color.x * 1.0, color.y * 1.0, color.z * 1.0, 1.0) * material_diffuse;
        sp[0] = light_specular[0] * vec4(color.x * 1.0, color.y * 1.0, color.z * 1.0, 1.0) * material_specular;
        ap[1] = light_ambient[1] * vec4(color.x * 1.0, color.y * 1.0, color.z * 1.0, 1.0) * material_ambient;
        dp[1] = light_diffuse[1] * vec4(color.x * 1.0, color.y * 1.0, color.z * 1.0, 1.0) * material_diffuse;
        sp[1] = light_specular[1] * vec4(color.x * 1.0, color.y * 1.0, color.z * 1.0, 1.0) * material_specular;
      }

    //   if (hurt) {
    //     ap[0] = light_ambient[0] * vec4(r * 1.0, g * 1.0, b * 1.0, 1.0) * material_ambient;
    //     dp[0] = light_diffuse[0] * vec4(r * 1.0, g * 1.0, b * 1.0, 1.0) * material_diffuse;
    //     sp[0] = light_specular[0] * vec4(r * 1.0, g * 1.0, b * 1.0, 1.0) * material_specular;
    //     ap[1] = light_ambient[1] * vec4(1.0 * 1.0, 0.0 * 1.0, 0.0 * 1.0, 1.0) * material_ambient;
    //     dp[1] = light_diffuse[1] * vec4(1.0 * 1.0, 0.0 * 1.0, 0.0 * 1.0, 1.0) * material_diffuse;
    //     sp[1] = light_specular[1] * vec4(1.0 * 1.0, 0.0 * 1.0, 0.0 * 1.0, 1.0) * material_specular;
    //     hurt = false;
    //   } else if (hallucinate) {
    //     color_a_pink += 0.001;
    //     red = sin(color_a_pink*M_PI/180/2);
    //     green = sin(90 + 1.5 * color_a_pink*M_PI/180/2);
    //     blue = sin(180 + 2.0 * color_a_pink*M_PI/180/2);
    //     ap[0] = light_ambient[0] * vec4(red * 0.6, green * 0.6, blue * 0.6, 1.0) * material_ambient;
    //     dp[0] = light_diffuse[0] * vec4(red * 0.5, green * 0.5, blue * 0.5, 1.0) * material_diffuse;
    //     sp[0] = light_specular[0] * vec4(red * 0.4, green * 0.4, blue * 0.4, 1.0) * material_specular;
    //     ap[1] = light_ambient[1] * vec4(-red * 0.4, -green * 0.5, -blue * 0.6, 1.0) * material_ambient;
    //     dp[1] = light_diffuse[1] * vec4(-blue * 0.5, -red * 0.6, -green * 0.4, 1.0) * material_diffuse;
    //     sp[1] = light_specular[1] * vec4(-green * 0.6, -blue * 0.4, -red * 0.5, 1.0) * material_specular;
    //   } else {
    //     ap[0] = light_ambient[0] * vec4(r * 1.0, g * 1.0, b * 1.0, 1.0) * material_ambient;
    //     dp[0] = light_diffuse[0] * vec4(r * 1.0, g * 1.0, b * 1.0, 1.0) * material_diffuse;
    //     sp[0] = light_specular[0] * vec4(r * 1.0, g * 1.0, b * 1.0, 1.0) * material_specular;
    //     ap[1] = light_ambient[1] * vec4(r * 1.0, g * 1.0, b * 1.0, 1.0) * material_ambient;
    //     dp[1] = light_diffuse[1] * vec4(r * 1.0, g * 1.0, b * 1.0, 1.0) * material_diffuse;
    //     sp[1] = light_specular[1] * vec4(r * 1.0, g * 1.0, b * 1.0, 1.0) * material_specular;
    //   }

      // for (int i = 0; i < 2; i++) {
      //   ap[i] = light_ambient[i] * vec4(rgb[i].x * rgbm[i].x, rgb[i].y * rgbm[i].y, rgb[i].z * rgbm[i].z, 1.0) * material_ambient;
      //   dp[i] = light_diffuse[i] * vec4(rgb[i].x * rgbm[i].x, rgb[i].y * rgbm[i].y, rgb[i].z * rgbm[i].z, 1.0) * material_diffuse;
      //   sp[i] = light_specular[i] * vec4(rgb[i].x * rgbm[i].x, rgb[i].y * rgbm[i].y, rgb[i].z * rgbm[i].z, 1.0) * material_specular;
      // }

        glUniform4fv(ambient_product, 1, ap[0]);
        glUniform4fv(diffuse_product, 1, dp[0]);
        glUniform4fv(specular_product, 1, sp[0]);

        glUniform4fv(ambient_product2, 1, ap[1]);
        glUniform4fv(diffuse_product2, 1, dp[1]);
        glUniform4fv(specular_product2, 1, sp[1]);

        glUniform1f(shiny, material_shininess);

        glUniform4fv(Material_Emiss, 1, emissive[0]);

        mat4 instance = (
          Translate( position.x, position.y, position.z )
          * RotateX(rotation.x) * RotateY(rotation.y) * RotateZ(rotation.z)
        );

        // mat4 instance = (Translate( 0.0, 0.5 * PART_HEIGHT, 0.0 ) * Scale( PART_WIDTH, PART_HEIGHT, PART_WIDTH ) );

        switch (type) {
          case 0:
            glUniformMatrix4fv( uniform, 1, GL_TRUE, matrix * instance * Scale( size.x, size.y, size.z ) );
            glUniform1f( enable, 0.0 );
            glDrawArrays( GL_TRIANGLES, 0, NumVertices ); break;
          // case 1:
          //   glUniformMatrix4fv( uniform, 1, GL_TRUE, matrix * instance );
          //   glUniform1f( enable, 2.0 );
          //   gluCylinder(qobj, w, d, h, sl, st); break;
          case 2:
            glUniform4fv(Material_Emiss, 1, emissive[1]);
              glUniformMatrix4fv( uniform, 1, GL_TRUE, matrix * instance * Scale( size.x, size.y, size.z ) );
              glUniform1f( enable, 1.0 );
              glDrawArrays( GL_TRIANGLES, NumVertices, NumVertices2 );
            glUniform4fv(Material_Emiss, 1, emissive[0]); break;
          case 4:
            glUniformMatrix4fv( uniform, 1, GL_TRUE, matrix * instance * Scale( size.x, size.y, size.z ) );
            glUniform1f( enable, 0.0 );
            glDrawArrays( GL_TRIANGLES, 0, NumVertices / 6 ); break;

        };

        // matrix = stack.pop();

    }

    void update (vec3 movement, vec3 scaling, vec3 interpolation, vec3 heading) {

      position = movement;
      size = scaling;
      color = interpolation;
      rotation = heading;

    }

    void collision (vec3 loc, vec3 bound, bool &result, float margin, bool is_collision) {

      if (position.x - size.x / 2 < loc.x + (bound.x + margin) / 2 && position.x + size.x / 2 > loc.x - (bound.x + margin) / 2 &&
          position.y - size.y / 2 < loc.y + (bound.y + margin) / 2 && position.y + size.y / 2 > loc.y - (bound.y + margin) / 2 &&
          position.z - size.z / 2 < loc.z + (bound.z + margin) / 2 && position.z + size.z / 2 > loc.z - (bound.z + margin) / 2 ) {

        result = true;

        if(is_collision) {

          collide = true;

          left     = (loc.x      + bound.x / 2) - (position.x - size.x  / 2);
          right    = (position.x + size.x  / 2) - (loc.x      - bound.x / 2);
          up       = (loc.y      + bound.y / 2) - (position.y - size.y  / 2);
          down     = (position.y + size.y  / 2) - (loc.y      - bound.y / 2);
          forward  = (loc.z      + bound.z / 2) - (position.z - size.z  / 2);
          backward = (position.z + size.z  / 2) - (loc.z      - bound.z / 2);

               if (left     < forward && left     < backward && left     <   up && left     < down  && left     <    right) { position.x += left;     velocity.x = 0.0; }
          else if (right    < forward && right    < backward && right    <   up && right    < down  && right    <     left) { position.x -= right;    velocity.x = 0.0; }
          else if (up       < forward && up       < backward && up       < left && up       < right && up       <     down) { position.y += up;       velocity.y = 0.0; }
          else if (down     < forward && down     < backward && down     < left && down     < right && down     <       up) { position.y -= down;     velocity.y = 0.0; }
          else if (forward  <      up && forward  < down     && forward  < left && forward  < right && forward  < backward) { position.z += forward;  velocity.z = 0.0; }
          else if (backward <      up && backward < down     && backward < left && backward < right && backward <  forward) { position.z -= backward; velocity.z = 0.0; }

        }

      } else {

        result = false;

      }

    }

    void chase_(vec3 chased, float speed) {

      float x_len = 0, y_len = 0;

      if (position.x != chased.x) {
        if (position.x - chased.x < 0) { position.x += speed; }
        if (position.x - chased.x > 0) { position.x -= speed; }
      }
      if (position.z != chased.z) {
        if (position.z - chased.z < 0) { position.z += speed; }
        if (position.z - chased.z > 0) { position.z -= speed; }
      }

      x_len = position.x - chased.x;
      y_len = position.z - chased.z;

      rotation.y = -( atan( x_len / (y_len + 0.01) ) * 180 / M_PI ) + 90;

    }

    void loop_reset() {

      velocity.x = 0.0;
      velocity.z = 0.0;

    }

    // void delete();

    void gravity_update() {

      if (!fall) { velocity.y = 0.0; }

      if (jump) {
        velocity.y += 0.75;
        jump = false;
        fall = true;
      }

      velocity.y -= 0.015;

    }

    void position_update() {

      if (!collide) { fall = true; } else { fall = false; }

      collide = false;

      position.x += velocity.x;
      position.y += velocity.y;
      position.z += velocity.z;

      velocity.x = 0.0;
      velocity.z = 0.0;

    }

    void check_fall_death () {
      if (position.y < -300.0) { position = vec3(0.0, 40.0, 0.0); }
    }

    std::string name;
    mat4  transform;
    // void  (*render)( void );
    Object* sibling;
    Object* child;
    material mat;
    mat4 matrix;
    color4 material_ambient;
    color4 material_diffuse;
    color4 material_specular;
    float  material_shininess;
    GLuint uniform;
    vec3 position;
    vec3 velocity;
    vec3 accelaration;
    vec3 size;
    vec3 color;
    vec3 rotation;
    int sl;
    int st;
    GLfloat weight;
    float health;
    int type;
    bool rigidbody;
    bool collide;

    bool fall;
    bool jump;

    GLfloat left;
    GLfloat right;
    GLfloat up;
    GLfloat down;
    GLfloat forward;
    GLfloat backward;


};

#endif
