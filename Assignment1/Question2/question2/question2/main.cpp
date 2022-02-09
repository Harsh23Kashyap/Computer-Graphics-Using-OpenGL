//
//  Draw a point of width 10 pixel
//  question2
//
//  Created by Harsh on 07/02/22.
//

#ifdef __APPLE_CC__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
 
void display() {
   glClear(GL_COLOR_BUFFER_BIT);
 
   glBegin(GL_POINTS);
    glColor3f(1.0, 1.0, 1.0);
    glPointSize(20.0f);
    glVertex2f(0.0, 0.0);
    //glVertex2f(0.5, 0.5);
    
 glEnd();
 
 
   glFlush();
}
 


int main(int argc, char *argv[]) {
    glutInit(&argc, argv);
    glutInitWindowSize(640, 480);
    glutInitWindowPosition(10, 10);
    glutCreateWindow("Point");
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}

