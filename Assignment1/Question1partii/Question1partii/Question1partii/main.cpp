// display a white window
//  main.cpp
//  Question1partii
//
//  Created by Harsh on 07/02/22.
//


#ifdef __APPLE_CC__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

void initGL() {
   glClearColor(1.0f, 1.0f, 1.0f, 1.0f); // White Color
}
 
void display()
{
   glClear(GL_COLOR_BUFFER_BIT);
 
    glBegin(GL_POLYGON);
   glEnd();
 
   glFlush();  // Render now
}
 
/* Main function: GLUT runs as a console application starting at main()  */
int main(int argc, char** argv) {
   glutInit(&argc, argv);          // Initialize GLUT
   glutCreateWindow("White Window");  // Create window with the given title
   glutInitWindowSize(320, 320);   // Set the window's initial width & height
   glutInitWindowPosition(50, 50); // Position the window's initial top-left corner
   glutDisplayFunc(display);
   initGL();                       // Our own OpenGL initialization
   glutMainLoop();                 // Enter the event-processing loop
   return 0;
}
