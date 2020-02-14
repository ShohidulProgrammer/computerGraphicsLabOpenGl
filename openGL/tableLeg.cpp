#include<GL/glut.h>
void tableLeg(double thick,double len)  // draw one table leg
{
    glPushMatrix();
    glTranslated(0,len/2,0);
    glScaled(thick,len,thick);
    glutSolidCube(1.0);
    glPopMatrix();
}
