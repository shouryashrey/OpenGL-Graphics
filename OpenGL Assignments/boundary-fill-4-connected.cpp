#include <iostream>
#include <math.h>
#include<GLUT/glut.h>

using namespace std;
float boundaryCol[] = {1, 0, 0}; //color of boundary of polygon
float fillColor[] = {0, 0, 1};   //color to be filled inside the polygon

void draw_poly()
{
    glLineWidth(1);
    glPointSize(1);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3fv(boundaryCol); //passing the boundaryColor vector as the color for our polygon
    glBegin(GL_LINE_LOOP);
    glVertex2i(150, 100);
    glVertex2i(300, 300);
    glVertex2i(450, 100);
    glEnd();
    glFlush();
}

void boundary_fill4(int x, int y, float *fillColor, float *boundaryColor)
{
    float color[3];
    glReadPixels(x, y, 1.0, 1.0, GL_RGB, GL_FLOAT, color);
    //color stores the color of x,y pixel, which we have read using glReadPixels
    //boundaryColor is boundary color of drawn polygon, fillColor is color with which we wish to fill our polygon

    if ((color[0] != boundaryColor[0] || color[1] != boundaryColor[1] || color[2] != boundaryColor[2]) && (color[0] != fillColor[0] || color[1] != fillColor[1] || color[2] != fillColor[2]))
    {
        glColor3f(fillColor[0], fillColor[1], fillColor[2]);
        glBegin(GL_POINTS);
        glVertex2i(x, y);
        glEnd();
        glFlush();

        //recursive function call for 4 neighbours: right, left, top, bottom
        boundary_fill4(x + 1, y, fillColor, boundaryColor);
        boundary_fill4(x - 1, y, fillColor, boundaryColor);
        boundary_fill4(x, y + 1, fillColor, boundaryColor);
        boundary_fill4(x, y - 1, fillColor, boundaryColor);
    }
}
void init()
{

    glClearColor(1.0, 1.0, 1.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0, 600, 0, 500);
}

void mouse(int btn, int state, int x, int y)
{
    y = 500 - y;
    if (btn == GLUT_LEFT_BUTTON)
    {
        if (state == GLUT_DOWN)
        {

            //glReadPixels(x,y,1.0,1.0,GL_RGB,GL_FLOAT,intCol);
            boundary_fill4(x, y, fillColor, boundaryCol);
        }
    }
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600, 500);
    glutInitWindowPosition(200, 200);
    glutCreateWindow("Boundary Fill 4 connected");
    glutDisplayFunc(draw_poly);
    glutMouseFunc(mouse);
    init();
    glutMainLoop();
    return 0;
}
