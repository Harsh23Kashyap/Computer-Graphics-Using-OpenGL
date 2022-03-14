//
//  main.cpp
//  question2
//
//  Created by Harsh on 14/03/22.
//
// Making a circle

#include <GLUT/glut.h>
#include <iostream>
using namespace std;

void init();
void display();
void reshape(int,int);
void Circle(int r);
void drawPixel(int x, int y);

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB);
    glutInitWindowPosition(300, 200);
    glutInitWindowSize(800, 800);
    glutCreateWindow("Rhombus");
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    init();
    
    glutMainLoop();
    return 0;
}

void init()
{
    glClearColor(0.0, 0.0, 0.0, 0.0); //Black Screen
    
}
void drawPixel(int x, int y)
{
    glBegin(GL_POINTS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex2f(x, y);
    glEnd();
}
void Circle(int x_centre, int y_centre, int r)
{
    int x = r, y = 0;
    // Initialising the value of P
    int P = 0;
    while (x != y)
    {
        y++;
        // Mid-point is inside or on the perimeter
        if(P>0)
            x--;

        P = (x - 0.5) * (x - 0.5) + (y * y) - r * r;

        // All the perimeter points have already been printe

        // Printing the generated point and its reflection
        // in the other octants after translation
        drawPixel(x + x_centre, y + y_centre);
        drawPixel(y + x_centre, x + y_centre);
        drawPixel(y + x_centre, -x + y_centre);
        drawPixel(-x + x_centre, y + y_centre);
        drawPixel(-x - x_centre, -y - y_centre);
        drawPixel(-y + x_centre, -x + y_centre);
        drawPixel(-y + x_centre, x + y_centre);
        drawPixel(x + x_centre, -y + y_centre);
       
    }
}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    //draw Circle
    int r=50;
    Circle(0,0,r);

    glFlush();
}
void reshape(int w, int h)
{
    glViewport(0, 0,(GLsizei) w,(GLsizei) h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-100, 100, -100, 100);
    glMatrixMode(GL_MODELVIEW);
}
