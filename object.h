#ifndef OBJECT_H
#define OBJECT_H

class Object {

    enum material { wood, metal, glass, ceramic };

  public:

    Object() : render(NULL), sibling(NULL), child(NULL) {}

    Object( mat4& m, void (*render)( void ), Object* sibling, Object* child ) :
	   transform(m), render(render), sibling(sibling), child(child) {}

   // void render(mat4 matrix, GLuint uniform) {
   //
   //   if (hurt) {
   //     ap = light_ambient * vec4(r, g, b, 1.0);
   //     dp = light_diffuse * vec4(r, g, b, 1.0);
   //     sp = light_specular * vec4(r, g, b, 1.0);
   //     ap2 = light2_ambient * vec4(1.0, 0.0, 0.0, 1.0);
   //     dp2 = light2_diffuse * vec4(1.0, 0.0, 0.0, 1.0);
   //     sp2 = light2_specular * vec4(1.0, 0.0, 0.0, 1.0);
   //     hurt = false;
   //   } else if (hallucinate) {
   //     color_a_pink += 0.001;
   //     red = sin(color_a_pink*M_PI/180/2);
   //     green = sin(90 + 1.5 * color_a_pink*M_PI/180/2);
   //     blue = sin(180 + 2.0 * color_a_pink*M_PI/180/2);
   //     ap = light_ambient * vec4(red * 0.6, green * 0.6, blue * 0.6, 1.0);
   //     dp = light_diffuse * vec4(red * 0.5, green * 0.5, blue * 0.5, 1.0);
   //     sp = light_specular * vec4(red * 0.4, green * 0.4, blue * 0.4, 1.0);
   //     ap = light2_ambient * vec4(-red * 0.4, -green * 0.5, -blue * 0.6, 1.0);
   //     dp = light2_diffuse * vec4(-blue * 0.5, -red * 0.6, -green * 0.4, 1.0);
   //     sp = light2_specular * vec4(-green * 0.6, -blue * 0.4, -red * 0.5, 1.0);
   //   } else {
   //     ap = light_ambient * vec4(r, g, b, 1.0);
   //     dp = light_diffuse * vec4(r, g, b, 1.0);
   //     sp = light_specular * vec4(r, g, b, 1.0);
   //     ap2 = light2_ambient * vec4(r, g, b, 1.0);
   //     dp2 = light2_diffuse * vec4(r, g, b, 1.0);
   //     sp2 = light2_specular * vec4(r, g, b, 1.0);
   //   }
   //
   //     glUniform4fv(ambient_product, 1, ap);
   //     glUniform4fv(diffuse_product, 1, dp);
   //     glUniform4fv(specular_product, 1, sp);
   //
   //     glUniform4fv(ambient_product2, 1, ap2);
   //     glUniform4fv(diffuse_product2, 1, dp2);
   //     glUniform4fv(specular_product2, 1, sp2);
   //
   //     mat4 instance = (
   //       Translate( x, y, z )
   //       * RotateX(pitch) * RotateY(yaw) * RotateZ(roll)
   //     );
   //
   //     switch (type) {
   //       case 0:
   //         glUniformMatrix4fv( uniform, 1, GL_TRUE, matrix * instance * Scale( w, h, d ) );
   //         glUniform1f( enable, 0.0 );
   //         glDrawArrays( GL_TRIANGLES, 0, NumVertices ); break;
   //       // case 1:
   //       //   glUniformMatrix4fv( uniform, 1, GL_TRUE, matrix * instance );
   //       //   glUniform1f( enable, 2.0 );
   //       //   gluCylinder(qobj, w, d, h, sl, st); break;
   //       case 2:
   //         glUniform4fv(Material_Emiss, 1, emissive);
   //           glUniformMatrix4fv( uniform, 1, GL_TRUE, matrix * instance * Scale( w, h, d ) );
   //           glUniform1f( enable, 1.0 );
   //           glDrawArrays( GL_TRIANGLES, NumVertices, NumVertices2 );
   //         glUniform4fv(Material_Emiss, 1, emissive_off); break;
   //       case 4:
   //         glUniformMatrix4fv( uniform, 1, GL_TRUE, matrix * instance * Scale( w, h, d ) );
   //         glUniform1f( enable, 0.0 );
   //         glDrawArrays( GL_TRIANGLES, 0, NumVertices / 6 ); break;
   //
   //     };
   //
   // }

    mat4  transform;
    void  (*render)( void );
    Object* sibling;
    Object* child;
    material mat;
    mat4 matrix;
    // color4 material_ambient;
    // color4 material_diffuse;
    // color4 material_specular;
    // float  material_shininess;
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
    int pitch;
    int yaw;
    int roll;
    int sl;
    int st;
    int type;

};

#endif
