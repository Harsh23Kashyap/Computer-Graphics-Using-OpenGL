//
//  main.cpp
//  Evaluation
//
//  Created by Harsh on 21/03/22.
//
// Making a Diagram given

#include <GLUT/glut.h>
#include <iostream>
using namespace std;

void init();
void display();
void reshape(int,int);
void drawPixel(int x, int y);
void Circle(int x_centre, int y_centre, int r);
void DDA(int x0, int y0, int x1, int y1);

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB);
    glutInitWindowPosition(300, 200);
    glutInitWindowSize(800, 800);
    glutCreateWindow("MST EVALUATION");
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
void PixelDraw(int x, int y)
{
    glBegin(GL_POINTS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex2f(x, y);
    glEnd();
}

//MidPoint Algo
void Circle(int x_centre, int y_centre, int r)
{
    int x = 0, y = r;
    int P = 1-r;
    while (x <= y )
    {
       
        PixelDraw(-x + x_centre, y + y_centre);
        PixelDraw(-x + x_centre, -y + y_centre);
        PixelDraw(-y + x_centre, -x + y_centre);
        PixelDraw(-y + x_centre, x + y_centre);
       
        x++;
        if(P<0)
        {
            P=P+2*x+3;
        }
        else
        {
            P=P+2*x-2*y+5;
            y--;
        }

    }
}

void bresenhamLine(int x0, int y0, int x1, int y1)
{
    int dy, dx, incx, incy, x, y, p, inc1, inc2;
    dx = abs(x1-x0);
    dy = abs(y1-y0);
    incx = 1;
    if (x1 < x0) incx = -1;
    incy = 1;
    if (y1 < y0) incy = -1;
    x = x0; y = y0;
    
    if (dx > dy)
    {
        PixelDraw(x, y);
        p = 2 * dy-dx;
        for (int i=0; i<dx; i++)
        {
            if (p >= 0)
            {
                y += incy;
                p = p+2*dy-2*dx;
            }
            else
                p = p+2*dy;
            x += incx;
            
            PixelDraw(x, y);
        }

    }
    else {
        cout<<x<<" "<<y<<endl;
        PixelDraw(x, y);
        p = 2*dx-dy;
        inc2 = 2*dx;
        for (int i=0; i<dy; i++)
        {
            if (p >= 0)
            {
                x += incx;
                p = p+2*dx-dy;
            }
            else
                p = p+2*dx;
            y += incy;
            PixelDraw(x, y);
        }
    }
}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    //draw Circle
    int xc=0,yc=0,r=20;
    
    Circle(xc,yc,r);
    bresenhamLine(0, r, r, 0);
    bresenhamLine(0, -r, r, 0);
    bresenhamLine(0, r, 0, -r);
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
