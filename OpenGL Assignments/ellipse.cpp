#include <GLUT/glut.h>
//#include <Windows.h>
//#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>

float a, b, h, k; //h,k center and a,b are x_radius and y_radius

void midptellipse()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1, 0, 0);
	float fx, fy, d1, d2, x, y;
	x = 0;
	y = b;

	// Initial decision parameter of region 1
	d1 = (b * b) - (a * a * b) +
		(0.25 * a * a);
	fx = 2 * b * b * x;
	fy = 2 * a * a * y;

	// For region 1
	while (fx < fy)
	{

		// Print points based on 4-way symmetb
		/*cout << x + h << " , " << y + k << endl;
		cout << -x + h << " , " << y + k << endl;
		cout << x + h << " , " << -y + k << endl;
		cout << -x + h << " , " << -y + k << endl; */
		glBegin(GL_POINTS);
		glVertex2i(x + h, y + k);
		glVertex2i(-x + h, y + k);
		glVertex2i(x + h, -y + k);
		glVertex2i(-x + h, -y + k);
		glEnd();

		// Checking and updating value of
		// decision parameter based on algorithm
		if (d1 < 0)
		{
			x++;
			fx = fx + (2 * b * b);
			d1 = d1 + fx + (b * b);
		}
		else
		{
			x++;
			y--;
			fx = fx + (2 * b * b);
			fy = fy - (2 * a * a);
			d1 = d1 + fx - fy + (b * b);
		}
	}

	// Decision parameter of region 2
	d2 = ((b * b) * ((x + 0.5) * (x + 0.5))) +
		((a * a) * ((y - 1) * (y - 1))) -
		(a * a * b * b);

	// Plotting points of region 2
	while (y >= 0)
	{

		// Print points based on 4-way symmetb
		/*	cout << x + h << " , " << y + k << endl;
		cout << -x + h << " , " << y + k << endl;
		cout << x + h << " , " << -y + k << endl;
		cout << -x + h << " , " << -y + k << endl; */

		glBegin(GL_POINTS);
		glVertex2i(x + h, y + k);
		glVertex2i(-x + h, y + k);
		glVertex2i(x + h, -y + k);
		glVertex2i(-x + h, -y + k);
		glEnd();
		// Checking and updating parameter
		// value based on algorithm
		if (d2 > 0)
		{
			y--;
			fy = fy - (2 * a * a);
			d2 = d2 + (a * a) - fy;
		}
		else
		{
			y--;
			x++;
			fx = fx + (2 * b * b);
			fy = fy - (2 * a * a);
			d2 = d2 + fx - fy + (a * a);
		}
	}
	glFlush();
}

void myinit()
{
	glClearColor(1, 1, 1, 0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-250, 250, -250, 250);
}
int main(int argc, char** argv)
{
	// To draw a ellipse of major and
	// minor radius 15, 10 centred at (50, 50)
	printf("Enter x radius for ellipse : ");
	scanf("%f", &a);
	printf("Enter y radius for ellipse : ");
	scanf("%f", &b);
	printf("Enter x co-ordinate of ellipse center : ");
	scanf("%f", &h);
	printf("Enter y co-ordinate of ellipse center : ");
	scanf("%f", &k);

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(50, 50);
	glutCreateWindow("Mid Point Ellipse");
	glutDisplayFunc(midptellipse);
	myinit();

	glutMainLoop();

	return 0;
}
