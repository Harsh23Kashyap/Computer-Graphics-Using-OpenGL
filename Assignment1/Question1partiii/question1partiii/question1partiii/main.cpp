// display a green window
//  main.cpp
//  Question1partiii
//
//  Created by Harsh on 07/02/22.
//


#ifdef __APPLE_CC__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

void initGL() {
   glClearColor(0.8f, 1.0f, 0.0f, 0.9f); // Green Color
}
 
void display()
{
   glClear(GL_COLOR_BUFFER_BIT);
 
    glBegin(GL_POLYGON);
   glEnd();
 
   glFlush();
}
 
int main(int argc, char** argv) {
   glutInit(&argc, argv);
   glutCreateWindow("White Window");
   glutInitWindowSize(320, 320);
   glutInitWindowPosition(50, 50);
   glutDisplayFunc(display);
   initGL();
   glutMainLoop();
   return 0;
}
