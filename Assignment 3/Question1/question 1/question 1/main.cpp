//
//  main.cpp
//  question 1
//
//  Created by Harsh on 07/03/22.
//
// Making a rhombus

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
void Circle(int r)
{
    float x=r,y=0;
    float x1=0.0;
    float P=0.0;
    while(x!=y)
    {
        drawPixel(x, y);
        drawPixel(-x, y);
        drawPixel(x, -y);
        drawPixel(-x, -y);
        drawPixel(y, x);
        drawPixel(-y, x);
        drawPixel(y, -x);
        drawPixel(-y, -x);
        y++;
        x1=x-0.5;
        P=x1*x1+y*y-r*r;
        if(P<=0)
            x=x-1;
    }

}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    //draw Circle
    int r=50;
    Circle(r);

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
