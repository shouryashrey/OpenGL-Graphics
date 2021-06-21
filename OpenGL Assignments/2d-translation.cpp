#include <GLUT/glut.h>
#include <math.h>
#include <iostream>

float tx, ty, tz = 0.0;

void draw_car()
{
	//car boundary
	glBegin(GL_POLYGON);
	glVertex2f(100, 100);
	glVertex2f(450, 100);
	glVertex2f(450, 160);
	glVertex2f(400, 200);
	glVertex2f(200, 200);
	glVertex2f(150, 160);
	glVertex2f(100, 150);
	glEnd();
	//wheel 1
	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.0, 0.0);
	int x1 = 200, y = 100, r = 25;
	for (int i = 0; i < 360; i++)
	{
		float th = i * 3.142 / 180;
		glVertex2f(x1 + r * cos(th), y + r * sin(th));
	}
	glEnd();
	//wheel 2
	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.0, 0.0);
	int x2 = 380;
	for (int i = 0; i < 360; i++)
	{
		float th = i * 3.142 / 180;
		glVertex2f(x2 + r * cos(th), y + r * sin(th));
	}
	glEnd();
}

void display()
{

	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1, 0, 0);
	draw_car();

	//switch matrix mode to modelview in order to work with object coordinates
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	// in-built glTranslatef, set tz=0 for 2-d translation
	//glTranslatef(tx, ty, 0.0);

	// without in-built method, multiply modelview matrix with translate matrix

	GLfloat translate[16] = {1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, tx, ty, tz, 1}; //4x4 transformation matrix expressed in column-major order
	glMultMatrixf(translate);													 //multiplies matrix in argument, with the current matrix and saves the result in current matrix.
																				 //Current matrix here is modelview matrix

	glColor3f(0, 0, 1);
	draw_car();

	//switch from object co-ordinates to projection (camera) coordinates
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glFlush();
}

void myInit()
{
	glClearColor(1, 1, 1, 1);
	glColor3f(0, 0, 1);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-100, 700, -100, 400);
}

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(800, 500);
	std::cout << "Enter translation in x-axis tx";
	std::cin >> tx;
	std::cout << "Enter translation in y-axis ty";
	std::cin >> ty;
	glutCreateWindow("2D Translation");
	glutDisplayFunc(display);
	myInit();
	glutMainLoop();
}
