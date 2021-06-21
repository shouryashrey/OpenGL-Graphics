#include <GLUT/glut.h>
//#include <Windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>

float xs, xe, ys, ye;

void display(void)
{
    float dy, dx, len, x, y, k, Xin, Yin;
    dx = xe - xs;
    dy = ye - ys;

    if (abs(dx) > abs(dy))
    {
        len = abs(dx);
    }
    else
        len = abs(dy);

    Xin = dx / len;
    Yin = dy / len;

    x = xs;
    y = ys;
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glEnd();

    for (k = 1; k <= len; k++)
    {
        x = x + Xin;
        y = y + Yin;

        glBegin(GL_POINTS);
        glVertex2i(x, y);
        glEnd();
    }

    glFlush();
}

void init(void)
{
    glClearColor(0.7, 0.7, 0.7, 0.7);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 500, 0, 500);
}

using namespace std;

int main(int argc, char **argv)
{
    
    printf("Enter the value of xs : ");
    scanf("%f", &xs);
    printf("Enter the value of ys : ");
    scanf("%f", &ys);
    printf("Enter the value of xe : ");
    scanf("%f", &xe);
    printf("Enter the value of ye : ");
    scanf("%f", &ye);

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("DDA Line Algo");
    init();
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}
