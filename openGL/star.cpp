#include<GL/glut.h>

void star(void)
{
    // Quads - door
	glColor3f(1, 1, 0.5); //this will set a color of the square.
	glBegin(GL_LINE_LOOP); // write shape u want to create

	glVertex3f(-0.5, -0.1, 0.0); // v1
	glVertex3f(0.2, 1, 0.0); // v2
	glVertex3f(0.6, -0.2, 0.0); // v3
	glVertex3f(-0.6, 0.6, 0.0); // v4
	glVertex3f(0.9, 0.5, 0.0); // v4
	glEnd();
}
