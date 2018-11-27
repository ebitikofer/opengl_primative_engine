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

    void create (mat4 matr, GLuint unif, GLfloat xp, GLfloat yp, GLfloat zp, GLfloat ws, GLfloat hs, GLfloat ds, GLfloat rc, GLfloat gc, GLfloat bc, int pi, float ya, int ro, int sli, int sta, int typ, material mater) {
      matrix = matr; uniform = unif;
      x = xp; y = yp; z = zp;
      w = ws; h = hs; d = ds;
      r = rc; g = gc; b = bc;
      pitch = pi; yaw = ya; roll = ro;
      sl = sli; st = sta; type = typ;
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

    void render (/*MatrixStack stack,*/ bool hurt, bool hallucinate, color4 ap[], color4 dp[], color4 sp[], color4 light_ambient[], color4 light_diffuse[], color4 light_specular[], GLuint ambient_product, GLuint diffuse_product, GLuint specular_product, GLuint ambient_product2, GLuint diffuse_product2, GLuint specular_product2, GLuint enable, float color_a_pink, color4 emissive[], GLuint Material_Emiss, GLuint shiny) {

      // stack.push(matrix);

      if (hurt) {
        ap[0] = light_ambient[0] * vec4(r * 1.0, g * 1.0, b * 1.0, 1.0) * material_ambient;
        dp[0] = light_diffuse[0] * vec4(r * 1.0, g * 1.0, b * 1.0, 1.0) * material_diffuse;
        sp[0] = light_specular[0] * vec4(r * 1.0, g * 1.0, b * 1.0, 1.0) * material_specular;
        ap[1] = light_ambient[1] * vec4(1.0 * 1.0, 0.0 * 1.0, 0.0 * 1.0, 1.0) * material_ambient;
        dp[1] = light_diffuse[1] * vec4(1.0 * 1.0, 0.0 * 1.0, 0.0 * 1.0, 1.0) * material_diffuse;
        sp[1] = light_specular[1] * vec4(1.0 * 1.0, 0.0 * 1.0, 0.0 * 1.0, 1.0) * material_specular;
        hurt = false;
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
        ap[0] = light_ambient[0] * vec4(r * 1.0, g * 1.0, b * 1.0, 1.0) * material_ambient;
        dp[0] = light_diffuse[0] * vec4(r * 1.0, g * 1.0, b * 1.0, 1.0) * material_diffuse;
        sp[0] = light_specular[0] * vec4(r * 1.0, g * 1.0, b * 1.0, 1.0) * material_specular;
        ap[1] = light_ambient[1] * vec4(r * 1.0, g * 1.0, b * 1.0, 1.0) * material_ambient;
        dp[1] = light_diffuse[1] * vec4(r * 1.0, g * 1.0, b * 1.0, 1.0) * material_diffuse;
        sp[1] = light_specular[1] * vec4(r * 1.0, g * 1.0, b * 1.0, 1.0) * material_specular;
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
          Translate( x, y, z )
          * RotateX(pitch) * RotateY(yaw) * RotateZ(roll)
        );

        // mat4 instance = (Translate( 0.0, 0.5 * PART_HEIGHT, 0.0 ) * Scale( PART_WIDTH, PART_HEIGHT, PART_WIDTH ) );

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
          case 4:
            glUniformMatrix4fv( uniform, 1, GL_TRUE, matrix * instance * Scale( w, h, d ) );
            glUniform1f( enable, 0.0 );
            glDrawArrays( GL_TRIANGLES, 0, NumVertices / 6 ); break;

        };

        // matrix = stack.pop();

    }

    void update (GLfloat xp, GLfloat yp, GLfloat zp, GLfloat ws, GLfloat hs, GLfloat ds, GLfloat rc, GLfloat gc, GLfloat bc, float pi, float ya, float ro) {
      x = xp; y = yp; z = zp;
      w = ws; h = hs; d = ds;
      r = rc; g = gc; b = bc;
      pitch = pi; yaw = ya; roll = ro;
    }

    // void torso() {
    //   // Is the next call necessary?
    //   mvstack.push( model_view );
    //
    //   mat4 instance = ( Translate( 0.0, 0.5 * TORSO_HEIGHT, 0.0 ) *
    // 		    Scale( TORSO_WIDTH, TORSO_HEIGHT, TORSO_WIDTH ) );
    //
    //   glUniformMatrix4fv( ModelView, 1, GL_TRUE, model_view * instance );
    //   glDrawArrays( GL_TRIANGLES, 0, NumVertices );
    //
    //   // Is the next call necessary?
    //   model_view = mvstack.pop();
    // }
    //
    // void head() {
    //     mvstack.push( model_view );
    //
    //     mat4 instance = (Translate( 0.0, 0.5 * HEAD_HEIGHT, 0.0 ) *
    // 		     Scale( HEAD_WIDTH, HEAD_HEIGHT, HEAD_WIDTH ) );
    //
    //     glUniformMatrix4fv( ModelView, 1, GL_TRUE, model_view * instance );
    //     glDrawArrays( GL_TRIANGLES, 0, NumVertices );
    //
    //     model_view = mvstack.pop();
    // }
    //
    // void left_upper_arm() {
    //     mvstack.push( model_view );
    //
    //     mat4 instance = (Translate( 0.0, 0.5 * UPPER_ARM_HEIGHT, 0.0 ) *
    // 		     Scale( UPPER_ARM_WIDTH,
    // 			    UPPER_ARM_HEIGHT,
    // 			    UPPER_ARM_WIDTH ) );
    //
    //     glUniformMatrix4fv( ModelView, 1, GL_TRUE, model_view * instance );
    //     glDrawArrays( GL_TRIANGLES, 0, NumVertices );
    //
    //     model_view = mvstack.pop();
    // }
    //
    // void left_lower_arm() {
    //     mvstack.push( model_view );
    //
    //     mat4 instance = ( Translate( 0.0, 0.5 * LOWER_ARM_HEIGHT, 0.0 ) *
    // 		      Scale( LOWER_ARM_WIDTH,
    // 			     LOWER_ARM_HEIGHT,
    // 			     LOWER_ARM_WIDTH ) );
    //
    //     glUniformMatrix4fv( ModelView, 1, GL_TRUE, model_view * instance );
    //     glDrawArrays( GL_TRIANGLES, 0, NumVertices );
    //
    //     model_view = mvstack.pop();
    // }
    //
    // void right_upper_arm() {
    //     mvstack.push( model_view );
    //
    //     mat4 instance = (Translate( 0.0, 0.5 * UPPER_ARM_HEIGHT, 0.0 ) *
    // 		     Scale( UPPER_ARM_WIDTH,
    // 			    UPPER_ARM_HEIGHT,
    // 			    UPPER_ARM_WIDTH ) );
    //
    //     glUniformMatrix4fv( ModelView, 1, GL_TRUE, model_view * instance );
    //     glDrawArrays( GL_TRIANGLES, 0, NumVertices );
    //
    //     model_view = mvstack.pop();
    // }
    //
    // void right_lower_arm() {
    //     mvstack.push( model_view );
    //
    //     mat4 instance = (Translate( 0.0, 0.5 * LOWER_ARM_HEIGHT, 0.0 ) *
    // 		     Scale( LOWER_ARM_WIDTH,
    // 			    LOWER_ARM_HEIGHT,
    // 			    LOWER_ARM_WIDTH ) );
    //
    //     glUniformMatrix4fv( ModelView, 1, GL_TRUE, model_view * instance );
    //     glDrawArrays( GL_TRIANGLES, 0, NumVertices );
    //
    //     model_view = mvstack.pop();
    // }
    //
    // void left_upper_leg() {
    //     mvstack.push( model_view );
    //
    //     mat4 instance = ( Translate( 0.0, 0.5 * UPPER_LEG_HEIGHT, 0.0 ) *
    // 		      Scale( UPPER_LEG_WIDTH,
    // 			     UPPER_LEG_HEIGHT,
    // 			     UPPER_LEG_WIDTH ) );
    //
    //     glUniformMatrix4fv( ModelView, 1, GL_TRUE, model_view * instance );
    //     glDrawArrays( GL_TRIANGLES, 0, NumVertices );
    //
    //     model_view = mvstack.pop();
    // }
    //
    // void left_lower_leg() {
    //     mvstack.push( model_view );
    //
    //     mat4 instance = (Translate( 0.0, 0.5 * LOWER_LEG_HEIGHT, 0.0 ) *
    // 		     Scale( LOWER_LEG_WIDTH,
    // 			    LOWER_LEG_HEIGHT,
    // 			    LOWER_LEG_WIDTH ) );
    //
    //     glUniformMatrix4fv( ModelView, 1, GL_TRUE, model_view * instance );
    //     glDrawArrays( GL_TRIANGLES, 0, NumVertices );
    //
    //     model_view = mvstack.pop();
    // }
    //
    // void right_upper_leg() {
    //     mvstack.push( model_view );
    //
    //     mat4 instance = (Translate( 0.0, 0.5 * UPPER_LEG_HEIGHT, 0.0 ) *
    // 		     Scale( UPPER_LEG_WIDTH,
    // 			    UPPER_LEG_HEIGHT,
    // 			    UPPER_LEG_WIDTH ) );
    //
    //     glUniformMatrix4fv( ModelView, 1, GL_TRUE, model_view * instance );
    //     glDrawArrays( GL_TRIANGLES, 0, NumVertices );
    //
    //     model_view = mvstack.pop();
    // }
    //
    // void right_lower_leg() {
    //     mvstack.push( model_view );
    //
    //     mat4 instance = ( Translate( 0.0, 0.5 * LOWER_LEG_HEIGHT, 0.0 ) *
    // 		      Scale( LOWER_LEG_WIDTH,
    // 			     LOWER_LEG_HEIGHT,
    // 			     LOWER_LEG_WIDTH ) );
    //
    //     glUniformMatrix4fv( ModelView, 1, GL_TRUE, model_view * instance );
    //     glDrawArrays( GL_TRIANGLES, 0, NumVertices );
    //
    //     model_view = mvstack.pop();
    // }


    // void update() { // Given the theta matrix, generate new transforms for all the joints.
    // void fixup_transforms() {
    //   switch( angle ) {
    //   case Torso:
    //     nodes[Torso].transform =
    //       RotateY( theta[Torso] );
    //     break;
    //
    //   case Head1: case Head2:
    //     nodes[Head].transform =
    //       Translate(0.0, TORSO_HEIGHT+0.5*HEAD_HEIGHT, 0.0) *
    //       RotateX(theta[Head1]) *
    //       RotateY(theta[Head2]) *
    //       Translate(0.0, -0.5*HEAD_HEIGHT, 0.0);
    //     break;
    //
    //   case LeftUpperArm:
    //     nodes[LeftUpperArm].transform =
    //       Translate(-(TORSO_WIDTH+UPPER_ARM_WIDTH),
    // 		0.9*TORSO_HEIGHT, 0.0) *
    //       RotateX(theta[LeftUpperArm]);
    //     break;
    //
    //   case RightUpperArm:
    //     nodes[RightUpperArm].transform =
    //       Translate(TORSO_WIDTH+UPPER_ARM_WIDTH, 0.9*TORSO_HEIGHT, 0.0) *
    //       RotateX(theta[RightUpperArm]);
    //     break;
    //
    //   case RightUpperLeg:
    //     nodes[RightUpperLeg].transform =
    //       Translate(TORSO_WIDTH+UPPER_LEG_WIDTH,
    // 		0.1*UPPER_LEG_HEIGHT, 0.0) *
    //       RotateX(theta[RightUpperLeg]);
    //     break;
    //
    //   case LeftUpperLeg:
    //     nodes[LeftUpperLeg].transform =
    //       Translate(-(TORSO_WIDTH+UPPER_LEG_WIDTH),
    // 		0.1*UPPER_LEG_HEIGHT, 0.0) *
    //       RotateX(theta[LeftUpperLeg]);
    //     break;
    //
    //   case LeftLowerArm:
    //     nodes[LeftLowerArm].transform =
    //       Translate(0.0, UPPER_ARM_HEIGHT, 0.0) *
    //       RotateX(theta[LeftLowerArm]);
    //     break;
    //
    //   case LeftLowerLeg:
    //     nodes[LeftLowerLeg].transform =
    //       Translate(0.0, UPPER_LEG_HEIGHT, 0.0) *
    //       RotateX(theta[LeftLowerLeg]);
    //     break;
    //
    //   case RightLowerLeg:
    //     nodes[RightLowerLeg].transform =
    //       Translate(0.0, UPPER_LEG_HEIGHT, 0.0) *
    //       RotateX(theta[RightLowerLeg]);
    //     break;
    //
    //   case RightLowerArm:
    //     nodes[RightLowerArm].transform =
    //       Translate(0.0, UPPER_ARM_HEIGHT, 0.0) *
    //       RotateX(theta[RightLowerArm]);
    //     break;
    //   }
    // }
    //
    // // Speed of rotations (adjust for different machines)
    // // Note: should modify to be consistent by using glutelapsedtime().
    // GLfloat incr = 5.0;
    // void idle(){
    //
    //   if(moving) {
    //     if (forwards) {
    //       theta[angle] += incr;
    //     } else {
    //       theta[angle] -= incr;
    //     }
    //     if( theta[angle] > 360.0 ) theta[angle] -= 360.0;
    //     if( theta[angle] < 0.0 ) theta[angle] += 360.0;
    //     fixup_transforms();
    //     glutPostRedisplay();
    //   }
    //
    // }
    // }

    // void delete();

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
    GLfloat x;
    GLfloat y;
    GLfloat z;
    GLfloat w;
    GLfloat h;
    GLfloat d;
    GLfloat r;
    GLfloat g;
    GLfloat b;
    float pitch;
    float yaw;
    float roll;
    int sl;
    int st;
    int type;

};

#endif
