#include <GLUT/glut.h>
//#include <Windows.h>
//#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>

int xs, ys, xe, ye, x, y;

void display()
{

    x = xs;
    y = ys;
    int dx, dy,   //deltas
        pk,       //decision parameter
        k, y_inc; //looping variable

    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1, 0, 0);
    //plot first point xs, ys
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glEnd();

    // difference between starting and ending points
    dx = xe - xs;
    dy = ye - ys;
    pk = 2 * dy - dx;

    if (dx >= 0)
        y_inc = 1;
    else
        y_inc = -1;

    for (k = 0; k < abs(dx); k++)
    {
        if (pk < 0)
        {
            pk = pk + 2 * dy; //calculate next pk
                              //next pixel: (x+1, y )
        }
        else
        {
            //next pixel: (x+1, y(+,-)1)
            pk = pk + 2 * dy - 2 * dx; //calculate next pk
            y = y + y_inc;
        }
        x++;
        glBegin(GL_POINTS);
        glVertex2i(x, y);
        glEnd();
    }

    glFlush();
}
void init(void)
{
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 500.0, 0.0, 500.0);
}

int main(int argc, char **argv)
{
    printf("Enter the value of xs : ");
    scanf("%d", &xs);
    printf("Enter the value of ys : ");
    scanf("%d", &ys);
    printf("Enter the value of xe : ");
    scanf("%d", &xe);
    printf("Enter the value of ye : ");
    scanf("%d", &ye);

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(0, 0);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Bresenham Line");
    glutDisplayFunc(display);
    init();
    glutMainLoop();
    return 0;
}
