#include <GLUT/glut.h>
#include <math.h>

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	//center
	int x, y;
	float th;

	//circle1: radius 1 and center 0,0
	glBegin(GL_LINE_LOOP);
	for (int i = 0; i < 360; i++)
	{
		th = i * 3.142 / 180;
		glVertex2f(cos(th), sin(th));
	}
	glEnd();

	//circle2: radius r and center x,y
	x = 50, y = 50;
	int r = 40;
	glColor3f(1, 0, 0);
	//flag GL_LINE_LOOP will not fill-in the circle, whereas the GL_POLYGON will fill-in the circle
	glBegin(GL_POLYGON);
	for (int i = 0; i < 360; i++)
	{
		th = i * 3.142 / 180;
		glVertex2f(x + r * cos(th), y + r * sin(th));
	}
	glEnd();

	glFlush();
}

void myInit()
{
	glClearColor(1, 1, 1, 1);
	glColor3f(0, 0, 1);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-250, 250, -250, 250);
}

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutCreateWindow("circle trigonometric");
	glutDisplayFunc(display);
	myInit();
	glutMainLoop();
}
