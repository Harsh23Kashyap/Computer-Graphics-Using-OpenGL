//
//  main.cpp
//  Evaluation
//
//  Created by Harsh on 21/03/22.
// Question 9
// Evaluation MST

#include <GLUT/glut.h>
#include <iostream>
using namespace std;

void init();
void display();
void reshape(int,int);
void drawPixel(int x, int y);
void Circle(int x_centre, int y_centre, int r);
void DigitalDifferentialAnalyser(int x0, int y0, int x1, int y1);

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
       
        PixelDraw(x + x_centre, y + y_centre);
        PixelDraw(y + x_centre, x + y_centre);
        PixelDraw(y + x_centre, -x + y_centre);
        PixelDraw(-x + x_centre, y + y_centre);
        PixelDraw(-x + x_centre, -y + y_centre);
        PixelDraw(-y + x_centre, -x + y_centre);
        PixelDraw(-y + x_centre, x + y_centre);
        PixelDraw(x + x_centre, -y + y_centre);
       
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

void DigitalDifferentialAnalyser(int x0, int y0, int x1, int y1)
{
    int dx,dy,step;
    float X, Y, Xinc, Yinc;
    dx = x1-x0;
    dy = y1-y0;
    if(abs(dx)>abs(dy))
        step=abs(dx);
    else
        step=abs(dy);
    Xinc = dx/(float)step;
    Yinc = dy/(float)step;
    X = x0;
    Y = y0;
    for(int i=0;i <= step; i++)
    {
        PixelDraw(X, Y);
        X+=Xinc;
        Y+=Yinc;
    }
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    //draw Circle
    int xc,yc,r;
    cout<<"Enter center X  : "<<endl;
    cin>>xc;
    cout<<"Enter center Y  : "<<endl;
    cin>>yc;
    cout<<"Enter Radius  : "<<endl;
    cin>>r;
    Circle(xc,yc,r);
    //Bottom line
    DigitalDifferentialAnalyser(xc-r, yc-r, xc+r, yc-r);
    // Left Line
    DigitalDifferentialAnalyser(xc-r, yc-r, xc-r, yc+r);
    // Right Line
    DigitalDifferentialAnalyser(xc-r, yc+r, xc+r, yc+r);
    // Top Line
    DigitalDifferentialAnalyser(xc+r, yc-r, xc+r, yc+r);
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
