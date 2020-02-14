// geomeryDraw.cpp.cpp : Defines the entry point for the console application.
//

//#include "stdafx.h"

#include <GL/glut.h>

// function declaration
void house(void);
void chessBoard(void);
void star(void);

void shapes(void) {
	glColor3f(1.0, 1, 0.5); //this will set a color of the schessBoard();
	//star();
	chessBoard();

}

void display (void) {

	// clearing the window with black color, 1st 3 parameter are for R,G,B. last one for opacity
	glClearColor (0.0,0.0,0.0,1.0);
    glClear (GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
	     //viewing transformation
	//glulookat() positions the camera towards the object
	//camera position, camera target, upvector
    gluLookAt (0.0, 0.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
	shapes();
	glFlush();
}

void reshape (int w, int h) {

	// 1st 2 parameters for lower left corner of the viewport rectangle. the default is 0,0
	// the next coordinates are width and hight of the viewport
//Set the viewport to be the entire window
	glViewport (0, 0, (GLsizei)w, (GLsizei)h);

	// setting the camera
	glMatrixMode (GL_PROJECTION);
	glLoadIdentity ();

	//perspective transform
	//gluPerspective (30, (GLfloat)w / (GLfloat)h, 1.0, 100.0);
	gluPerspective (30, 1, 1.0, 100.0);
	glMatrixMode (GL_MODELVIEW); //switch back the the model editing mode.

}

int main (int argc, char **argv) {
    glutInit (&argc, argv);
	glutInitDisplayMode (GLUT_SINGLE); // single buffering.. (double buffering for animation)
	// full screen is 1000,1000
	// this 0,0 or 1000,1000 are world co ordinates
	glutInitWindowSize (700, 700);
	glutInitWindowPosition (100, 100);
    glutCreateWindow ("A basic OpenGL Window");
	// registering callback functions
    glutDisplayFunc (display);
	glutReshapeFunc (reshape);

    glutMainLoop ();
    return 0;
}
