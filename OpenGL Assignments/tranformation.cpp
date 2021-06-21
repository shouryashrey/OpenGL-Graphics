#include <stdio.h>
#include <math.h>
#include <iostream>
#include <vector>
#include <GLUT/glut.h>
using namespace std;

int pntX1, pntY1, choice = 0, edges;
vector<int> pntX{0,200,200,0};
vector<int> pntY{0,0,200,200};
int transX=200, transY=200;
double scaleX=2, scaleY=2;
double angle = 45;
double angleRad= angle * 3.1416 / 180;

double round(double d)
{
    return floor(d + 0.5);
}

void draw()
{
    glBegin(GL_POLYGON);
    glColor3f(1.0, 1.0, 0.0);
    for (int i = 0; i < edges; i++)
    {
        glVertex2i(pntX[i], pntY[i]);
    }
    glEnd();
}

void Trans(int x, int y)
{
    glBegin(GL_POLYGON);
    glColor3f(1.0, 0.0, 1.0);
    for (int i = 0; i < edges; i++)
    {
        glVertex2i(pntX[i] + x, pntY[i] + y);
    }
    glEnd();
}

void Rotation(double angleRad)
{
    glBegin(GL_POLYGON);
    glColor3f(1.0, 0.0, 1.0);
    for (int i = 0; i < edges; i++)
    {
        glVertex2i(round((pntX[i] * cos(angleRad)) - (pntY[i] * sin(angleRad))), round((pntX[i] * sin(angleRad)) + (pntY[i] * cos(angleRad))));
    }
    glEnd();
}

void Scale(double x, double y)
{
    glBegin(GL_POLYGON);
    glColor3f(1.0, 0.0, 1.0);
    for (int i = 0; i < edges; i++)
    {
        glVertex2i(round(pntX[i] * x), round(pntY[i] * y));
    }
    glEnd();
}

void myInit(void)
{
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glColor3f(0.0f, 0.0f, 0.0f);
    glPointSize(4.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-700.0, 700.0, -500.0, 500.0);
}


void myDisplay(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0, 0.0, 0.0);
    if (choice == 1)
    {
        draw();
//        printf("hello");
        Trans(transX, transY);
    }
    else if (choice == 2)
    {
        draw();
        Rotation(angleRad);
    }
    else if (choice == 3)
    {
        draw();
        Scale(scaleX, scaleY);
    }
    

    glFlush();
}

int main(int argc, char** argv)
{
    cout << "Enter your choice:\n\n";
    cout << "1.Translation" << endl;
    cout << "2.Rotation" << endl;
    cout << "3.Scaling" << endl;
    cout << "4.Exit" << endl;
    cin >> choice;
    if (choice == 4) {
        return 0;
    }
    edges = 4;
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(700, 500);
    glutInitWindowPosition(200, 350);
    glutCreateWindow("2D Transformations about the origin");
    glutDisplayFunc(myDisplay);
    myInit();
    glutMainLoop();
    
    return 0;
}
