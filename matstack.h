#ifndef MATSTACK_H
#define MATSTACK_H

// Better to use STL stacks!!
class MatrixStack {
    int    _index;
    int    _size;
    mat4*  _matrices;

   public:
    MatrixStack( int numMatrices = 32 ):_index(0), _size(numMatrices)
        { _matrices = new mat4[numMatrices]; }

    ~MatrixStack()
	{ delete[]_matrices; }

    void push( const mat4& m ) {
        assert( _index + 1 < _size );
        _matrices[_index++] = m;
    }

    mat4& pop( void ) {
        assert( _index - 1 >= 0 );
        _index--;
         return _matrices[_index];
    }
};

#endif

// void load() {
//     mat4  m;
//     m = RotateY( theta[Torso] );
//     model[Torso] = Object( m, torso, NULL, &model[Head1] );
//     m = Translate(0.0, TORSO_HEIGHT+0.5*HEAD_HEIGHT, 0.0) *
//       RotateX(theta[Head1]) *
//       RotateY(theta[Head2]) *
//       Translate(0.0, -0.5*HEAD_HEIGHT, 0.0);
//     model[Head1] = Object( m, head, &model[LeftUpperArm], NULL );
//     m = Translate(-(TORSO_WIDTH+UPPER_ARM_WIDTH), 0.9*TORSO_HEIGHT, 0.0) *
//       RotateX(theta[LeftUpperArm]);
//     model[LeftUpperArm] = Object( m, left_upper_arm, &model[RightUpperArm], &model[LeftLowerArm] );
//     m = Translate(TORSO_WIDTH+UPPER_ARM_WIDTH, 0.9*TORSO_HEIGHT, 0.0) *
// 	     RotateX(theta[RightUpperArm]);
//     model[RightUpperArm] = Object( m, right_upper_arm, &model[LeftUpperLeg], &model[RightLowerArm] );
//     m = Translate(-(TORSO_WIDTH+UPPER_LEG_WIDTH), 0.1*UPPER_LEG_HEIGHT, 0.0) *
//       RotateX(theta[LeftUpperLeg]);
//     model[LeftUpperLeg] = Object( m, left_upper_leg, &model[RightUpperLeg], &model[LeftLowerLeg] );
//     m = Translate(TORSO_WIDTH+UPPER_LEG_WIDTH, 0.1*UPPER_LEG_HEIGHT, 0.0) *
//       RotateX(theta[RightUpperLeg]);
//     model[RightUpperLeg] = Object( m, right_upper_leg, NULL, &model[RightLowerLeg] );
//     m = Translate(0.0, UPPER_ARM_HEIGHT, 0.0) * RotateX(theta[LeftLowerArm]);
//     model[LeftLowerArm] = Object( m, left_lower_arm, NULL, NULL );
//     m = Translate(0.0, UPPER_ARM_HEIGHT, 0.0) * RotateX(theta[RightLowerArm]);
//     model[RightLowerArm] = Object( m, right_lower_arm, NULL, NULL );
//     m = Translate(0.0, UPPER_LEG_HEIGHT, 0.0) * RotateX(theta[LeftLowerLeg]);
//     model[LeftLowerLeg] = Object( m, left_lower_leg, NULL, NULL );
//     m = Translate(0.0, UPPER_LEG_HEIGHT, 0.0) * RotateX(theta[RightLowerLeg]);
//     model[RightLowerLeg] = Object( m, right_lower_leg, NULL, NULL );
// }

// void traverse( Object node ) {
//   // base case
//   if ( node == NULL ) { return; }
//   // Recursive case, first remember the current transform.
//   mvstack.push( model_view );
//   mv *= node.transform;
//   node.render(mvstack);
//   traverse( node.child );
//   //  if ( node->child != NULL) { traverse( node->child ); }
//   mv = mvstack.pop();
//   traverse( node.sibling );
//   //  if ( node->sibling != NULL) { traverse( node->sibling ); }
// }

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
