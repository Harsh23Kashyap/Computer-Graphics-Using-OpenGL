
//  Draw a triangle
//  question2
//
//  Created by Harsh on 07/02/22.
//

#ifdef __APPLE_CC__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
void initGL()
{
   glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Black background
}
 
void display() {
   glClear(GL_COLOR_BUFFER_BIT);
 
    glBegin(GL_TRIANGLES);
    glColor3f(1, 1, 1);
    
    glVertex3f(0, 0.5f, 1);
    glVertex3f(0.5, 0, 0);
    glVertex3f(0, 0, 1);
    glEnd();
 
 
   glFlush();
}
 
int main(int argc, char** argv) {
   glutInit(&argc, argv);          // Initialize GLUT
   glutCreateWindow("Triangle");
   glutInitWindowSize(320, 320);   // Set the window's initial width & height
   glutInitWindowPosition(50, 50); // Position the window's initial top-left corner
   glutDisplayFunc(display);
   initGL();                       // Our own OpenGL initialization
   glutMainLoop();                 // Enter the event-processing loop
   return 0;
}
