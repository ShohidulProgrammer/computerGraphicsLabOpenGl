#include <GL/glut.h>
void house()
{
    //house start from here
	// GL_TRIANGLES
	glBegin(GL_TRIANGLES); // write shape u want to create
	glVertex3f(0.0, .3, 0);
	glVertex3f(-0.5, 0, 0);
	glVertex3f(0.5, 0, 0);
	glEnd();

	// Quads - room
	glColor3f(2, 1, 1); //this will set a color of the square.
	glBegin(GL_QUADS); // write shape u want to create

	glVertex3f(-0.4, 0, 0.0); // v1
	glVertex3f(-0.4, -0.5, 0.0); // v2
	glVertex3f(0.4, -0.5, 0.0); // v3
	glVertex3f(0.4, 0, 0.0);
	glEnd();




	// Quads - door
	glColor3f(0, 0.2, 0.5); //this will set a color of the square.
	glBegin(GL_QUADS); // write shape u want to create

	glVertex3f(-0.1, -0.1, 0.0); // v1
	glVertex3f(-0.1, -0.5, 0.0); // v2
	glVertex3f(0.1, -0.5, 0.0); // v3
	glVertex3f(0.1, -0.1, 0.0); // v4
	glEnd();



	// Quads - leftWindow
	glColor3f(0.6, 0.2, 0.5); //this will set a color of the square.
	glBegin(GL_QUADS); // write shape u want to create

	glVertex3f(-0.25, -0.1, 0.0); // v1
	glVertex3f(-0.25, -0.2, 0.0); // v2
	glVertex3f(-0.15, -0.2, 0.0); // v3
	glVertex3f(-0.15, -0.1, 0.0); // v4
	glEnd();



	// Quads - rightWindow
	glColor3f(0.6, 0.2, 0.5); //this will set a color of the square.
	glBegin(GL_QUADS); // write shape u want to create

	glVertex3f(0.25, -0.1, 0.0); // v1
	glVertex3f(0.25, -0.2, 0.0); // v2
	glVertex3f(0.15, -0.2, 0.0); // v3
	glVertex3f(0.15, -0.1, 0.0); // v4
	glEnd();





	//stair start from here
	int i,color=1;
	float x1 = (-0.3), y1 = (-0.5), x2 = (0.3), y2 = (-0.6);

	for(i=0;i<3;i++,x1+=0.1,x2-=0.1,y1-=0.1,y2-=0.1)
    {
        if(color==1)
        {/**<  */
            glColor3f(1.0, 0, 0.5);
            color = 0;
        }
        else
        {
            glColor3f(1.0, 1, 0.5);
            color = 1;
        }
        glBegin(GL_QUADS); // write shape u want to create

        glVertex3f(x1, y1, 0.0); // v1
        glVertex3f(x1, y2, 0.0); // v2
        glVertex3f(x2, y2, 0.0); // v3
        glVertex3f(x2, y1, 0.0); // v4
        glEnd();
    }

}
