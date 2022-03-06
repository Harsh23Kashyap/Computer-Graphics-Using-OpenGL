#include <GLUT/glut.h>
#include <iostream>
using namespace std;

void init();
void display();
void reshape(int,int);
void DDA(int,int,int,int);

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB);
    glutInitWindowPosition(300, 200);
    glutInitWindowSize(500, 500);
    glutCreateWindow("DDA");
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    init();
    
    glutMainLoop();
    return 0;
}

void init(){
    glClearColor(0.0, 0.0, 0.0, 0.0); //Black Screen
    
}

void DDA(int x0, int y0, int x1, int y1){
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
        glBegin(GL_POINTS);
        glColor3f(1.0, 1.0, 0.0);
        glVertex2f(X, Y);
        glEnd();
        X+=Xinc;
        Y+=Yinc;
    }
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    //draw DDA Line
    int x0,x1,y0,y1;
    x0 = y0 = 10;
    x1 = y1 = 50;
    DDA(x0,y0,x1,y1);

    glFlush();
}

void reshape(int w, int h)
{
    glViewport(0, 0,(GLsizei) w,(GLsizei) h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 100, 0, 100);
    glMatrixMode(GL_MODELVIEW);
}
