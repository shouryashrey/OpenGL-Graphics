#include <GLUT/glut.h>

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    
    glColor3f(1.0, 0.0, 0.0);
    
    //rect
    glBegin(GL_QUADS);
    glColor3f(1.0, 0.0, 0.0);
    glVertex2f(10.0, 10.0);
    glColor3f(0.0, 1.0, 0.0);
    glVertex2f(100.0, 10.0);
    glColor3f(0.0, 0.0, 1.0);
    glVertex2f(100.0, 200.0);
    glColor3f(1.0, 1.0, 0.0);
    glVertex2f(10.0, 200.0);
    
    glEnd();

    glFlush();
}

void myinit()
{
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glColor3f(1.0, 0.0, 0.0);
    glPointSize(10.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 499.0, 0.0, 499.0);
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Rectangle");
    glutDisplayFunc(display);

    myinit();
    glutMainLoop();
}




////    traingle
//    glBegin(GL_TRIANGLES);
//    glColor3f(1.0, 0.0, 0.0);
//    glVertex2f(210.0, 210.0);
//    glVertex2f(350.0, 280.0);
//    glVertex2f(300.0, 220.0);
//    glVertex2f(200.0, 100.0);
//    glEnd();
