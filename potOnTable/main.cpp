#include<GL/glut.h>

void tableLeg(double thick,double len)  // draw one leg of the table
{
    glPushMatrix();
    glTranslated(0,len/2,0);
    glScaled(thick,len,thick);
    glutSolidCube(1.0);
    glPopMatrix();
}

table(double topWid, double topThick,double legThick,double legLength)
{
    // draw top side of the table
    glPushMatrix();
    glTranslated(0,legLength,0);
    glScaled(topWid, topThick,topWid);
    glutSolidCube(1.1);

    // draw leg of the table
    glPopMatrix();
    double distance =0.95* topWid/2.0 - legThick/2.0;
    glPushMatrix();

    glTranslated(distance,0,distance); // leg 1
    tableLeg(legThick,legLength);

    glTranslated(0,0,-2*distance); // leg 2
    tableLeg(legThick,legLength);

    glTranslated(-2*distance,0,2*distance); // leg 3
    tableLeg(legThick,legLength);

    glTranslated(0,0,-2*distance); // leg 4
    tableLeg(legThick,legLength);
    glPopMatrix();
}

void displaySolid(void)
{
    GLfloat mat_ambient[] = { 3.2f,1.0f,0.7f,1.0f};// red
    GLfloat mat_diffuse[] = { 0.7f,0.7f,0.7f,1.0f};
    GLfloat mat_specular[] = { 1.0f,1.0f,1.0f,1.0f};
    GLfloat mat_shininess[]={50.0f};

    glMaterialfv(GL_FRONT,GL_AMBIENT,mat_ambient);
    glMaterialfv(GL_FRONT,GL_DIFFUSE,mat_diffuse);
    glMaterialfv(GL_FRONT,GL_SPECULAR,mat_specular);
    glMaterialfv(GL_FRONT,GL_SHININESS,mat_shininess);

    // set the light sources properties
    GLfloat lightIntensity[] ={ 1.0f,1.0f,1.0f,7.0f};
    GLfloat light_position[] ={ 5.0f,6.0f,3.0f,0.0f};
    glLightfv(GL_LIGHT0 ,GL_POSITION,light_position);
    glLightfv(GL_LIGHT0 ,GL_DIFFUSE,lightIntensity);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1.33,1.33, -1,1,0.1,100.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(2.3,1.3,2.0,0.0,0.25,0.0,0.0,1.0,0.0);
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

    // draw table
    glPushMatrix();
    glTranslated(0.4,0,0.4);
    table(1.3,0.06,0.05,0.9);
    glPopMatrix();

    // draw teapot
    glPushMatrix();
    glTranslated(0.6,1.1,0.6);
    glRotated(30,0,1,0);
    glutSolidTeapot(0.2);

    glPopMatrix();
    glFlush();
}
int main(int argc, char** argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB|GLUT_DEPTH);
    glutInitWindowSize(640,480);
    glutInitWindowPosition(100,100);
    glutCreateWindow("simple shaded scene consisting of a tea pot on a table ");
    glutDisplayFunc(displaySolid);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glShadeModel(GL_SMOOTH);
    glEnable(GL_NORMALIZE);
    glEnable(GL_DEPTH_TEST);
    glClearColor(0.1,0.1,0.1,0.0);
    glViewport(0,0,640,480);
    glutMainLoop();
return 0;
}
