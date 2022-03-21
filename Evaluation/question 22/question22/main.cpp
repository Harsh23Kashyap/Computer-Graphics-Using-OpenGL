#include <GLUT/glut.h>
#include<iostream>
using namespace std;
int X1, Y1, r;

void plot(int x, int y)
{
    glBegin(GL_POINTS);
    glVertex2i(x + X1, y + Y1);
    glEnd();
}
void myinit(void)
{
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glColor3f(1.0f, 1.0f, 1.0f);
    glPointSize(3.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-100.0,100.0,-100.0,100.0);
    
}
void midPointCircleAlgo()
{
    int x = 0;
    int y = r;
    float pk = 5 / 4 - r;
    plot(x, y);
    while (y > x)
    {
        if
            (pk < 0)
        {
            x++;
            pk += 2 * x + 1;
        }
        else
        {
            y--;
            x++;
            pk += 2 * (x - y) + 1;
        }
        plot(x, y);
        plot(x, -y);
        plot(-x, y);
        plot(-x, -y);
        plot(y, x);
        plot(-y, x);
        plot(y, -x);
        plot(-y, -x);
    }
}
void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0, 0.0, 1.0);
    glPointSize(3.0);
    midPointCircleAlgo();
    glBegin(GL_POLYGON);
    int a = 20 + X1;
    float b= (30.0+r)/1.414;
    glVertex2i(a - r + b, (Y1 + r)-b);
    glVertex2i(a - r + b, (Y1 - r)-b);
    glVertex2i(a + r +b, (Y1 - r)-b);
    glVertex2i(a + r + b, (Y1 + r)-b);
    glEnd();
    glFlush();
}

int main(int argc, char** argv)
{
    cout << "Enter the coordinates of the center:" << endl;
    cout << "X-coordinate:";
    cin >> X1;
    cout << "Y-coordinate:";
    cin >> Y1;
    cout << "Enter radius:";
    cin >> r;
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 480);
    glutInitWindowPosition(200,150);
    glutCreateWindow("Q21 Circle and Square ");
    glutDisplayFunc(display);
    myinit();
    glutMainLoop();
    return 0;
}
