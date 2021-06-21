#include <GLUT/glut.h>
//#include <Windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>

void circle()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 0.0, 0.0);
    //glPointSize(2.0);

    float r = 100;

    float x = 0, y = r;
    float p = 1 - r;

    while (x <= y)
    {
        x++;
        if (p < 0)
        {
            p += 2 * (x + 1) + 1;
        }
        else
        {
            y--;
            p += 2 * (x + 1) + 1 - 2 * (y - 1);
        }
        glBegin(GL_POINTS);
        glVertex2i(x, y);
        glVertex2i(-x, y);
        glVertex2i(x, -y);
        glVertex2i(-x, -y);

        glVertex2i(y, x);
        glVertex2i(-y, x);
        glVertex2i(y, -x);
        glVertex2i(-y, -x);
        glEnd();
    }

    glFlush();
}
void myinit()
{
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-250, 250, -250, 250);
}
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Mid Point Circle");
    glutDisplayFunc(circle);
    myinit();
    glutMainLoop();
    return 0;
}
