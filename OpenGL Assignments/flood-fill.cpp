#include <iostream>
#include <math.h>
#include<GLUT/glut.h>

using namespace std;

float oldCol[] = {1, 1, 1};
float newCol[] = {0, 0, 1};

void draw_poly()
{
    glLineWidth(1);
    glPointSize(1);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1, 0, 0);
    glBegin(GL_LINE_LOOP);
    glVertex2i(100, 100);
    glVertex2i(200, 100);
    glColor3f(0, 1, 0);
    glVertex2i(200, 200);
    glVertex2i(100, 200);
    glEnd();
    glFlush();
}

void flood_fill_4(int x, int y, float *oldcolor, float *newcolor)
{
    float color[3];
    glReadPixels(x, y, 1.0, 1.0, GL_RGB, GL_FLOAT, color);

    if (color[0] == oldcolor[0] && color[1] == oldcolor[1] && color[2] == oldcolor[2])
    {

        glColor3f(newcolor[0], newcolor[1], newcolor[2]);
        glBegin(GL_POINTS);
        glVertex2i(x, y);
        glEnd();
        glFlush();
        flood_fill_4(x + 1, y, oldcolor, newcolor);
        flood_fill_4(x - 1, y, oldcolor, newcolor);
        flood_fill_4(x, y + 1, oldcolor, newcolor);
        flood_fill_4(x, y - 1, oldcolor, newcolor);
    }
}
void init()
{

    glClearColor(1.0, 1.0, 1.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0, 500, 0, 500);
}

void mouse(int btn, int state, int x, int y)
{
    y = 500 - y;
    if (btn == GLUT_LEFT_BUTTON)
    {
        if (state == GLUT_DOWN)
        {
            flood_fill_4(x, y, oldCol, newCol);
        }
    }
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(200, 200);
    glutCreateWindow("Flood Fill");
    glutDisplayFunc(draw_poly);
    glutMouseFunc(mouse);
    init();
    glutMainLoop();
    return 0;
}
