#include <GLUT/glut.h>
#include <math.h>
#include <iostream>

float a, x = 0, y = 0;

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

	// in-built glTranslatef, set tz=0 for 2-d translation
	//glRotatef(a, 0, 0, 1);

	// without in-built method, multiply modelview matrix with translate matrix

	GLfloat rotate[16] = {cos(a), sin(a), 0, 0, -sin(a), cos(a), 0, 0, 0, 0, 1, 0, 0, 0, 0, 1}; //4x4 transformation matrix expressed in column-major order

	//rotation around origin
	// glMultMatrixf(rotate);		//multiplies matrix in argument, with the current matrix and saves the result in current matrix.
	//Current matrix here is modelview matrix

	//rotation around pt (x,y)
	GLfloat translate1[16] = {1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, x, y, 0, 1};
	GLfloat translate2[16] = {1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, -x, -y, 0, 1};

	// First apply translate (-x, -y), then rotate, then translate(x,y)
	glMultMatrixf(translate2);
	glMultMatrixf(rotate);
	glMultMatrixf(translate1);

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
	gluOrtho2D(-200, 600, -100, 700);
}

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(800, 800);
	std::cout << "Enter angle of rotation in degrees";
	std::cin >> a;
	std::cout << "Enter x value of point about which to rotate";
	std::cin >> x;
	std::cout << "Enter y value  of point about which to rotate";
	std::cin >> y;
	glutCreateWindow("2D Rotation");
	glutDisplayFunc(display);
	myInit();
	glutMainLoop();
}
