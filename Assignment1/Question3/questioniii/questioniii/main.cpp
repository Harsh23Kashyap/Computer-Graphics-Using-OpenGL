
//
//  Draw a green line from (10,10) to (50,50)
//  question3
//
//  Created by Harsh on 07/02/22.
//

#ifdef __APPLE_CC__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
void initGL() {
   glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Black background
}
 
void display() {
   glClear(GL_COLOR_BUFFER_BIT);
 
    glBegin(GL_LINES);
        glVertex2f(-0.8f, 0.0f);
      glVertex2f(0.8f, 0.0f);
    glEnd();
    glBegin(GL_LINES);
      
      glVertex2f(50.0f, 50.0f);
    glEnd();
 
 
   glFlush();
}
 
int main(int argc, char *argv[]) {
    glutInit(&argc, argv);
    glutInitWindowSize(6400, 4800);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Point");
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}



