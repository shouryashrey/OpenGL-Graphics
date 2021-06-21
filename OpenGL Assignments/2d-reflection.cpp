#include <GLUT/glut.h>
#include <math.h>
#include <iostream>

char ch;

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

void draw_triangle()
{
	glBegin(GL_TRIANGLES);
	glVertex2i(100, 100);
	glVertex2i(100, 200);
	glVertex2i(200, 150);
	glEnd();
}
void display()
{

	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1, 0, 0);
	draw_car(); //or draw_triangle();

	//switch matrix mode to modelview in order to work with object coordinates
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	// in-built glScalef, set tz=0 for 2-d translation
	//glScalef(sx, sy, 0);

	// without in-built method, multiply modelview matrix with translate matrix

	GLfloat reflect_x[16] = {1, 0, 0, 0, 0, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1};

	GLfloat reflect_y[16] = {-1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1};

	std::cout << "The axis for reflection is " << ch;

	if (ch == 'x')
	{
		glMultMatrixf(reflect_x); // Multiply with reflection about x-axis matrix
	}
	else if (ch == 'y')
	{
		glMultMatrixf(reflect_y); // Multiply with reflection about y-axis matrix
	}
	else
	{
		std::cout << "Wrong choice";
	}

	glColor3f(0, 0, 1);
	draw_car(); //or draw_triangle();

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
	gluOrtho2D(-500, 500, -300, 500);
}

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(1000, 800);
	std::cout << "Enter the axis for reflection x or y ";
	std::cin >> ch;

	glutCreateWindow("2D Reflection");
	glutDisplayFunc(display);
	myInit();
	glutMainLoop();
}
