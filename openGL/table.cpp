#include<GL/glut.h>

void wall(double thickness);
void tableLeg(double thick,double len);
void table(double topWid, double topThick,double legThick,double legLen)
{
    glPushMatrix();
    glTranslated(0,legLen,0);
    glScaled(topWid, topThick,topWid);
    glutSolidCube(1.0);
    glPopMatrix();
    double dist =0.95* topWid/2.0 - legThick/2.0;
    glPushMatrix();
    glTranslated(dist,0,dist);
    tableLeg(legThick,legLen);
    glTranslated(0.0,0.0,-2*dist);
    tableLeg(legThick,legLen);
    glTranslated(-2*dist,0,2*dist);
    tableLeg(legThick,legLen);
    glTranslated(0,0,-2*dist);
    tableLeg(legThick,legLen);
    glPopMatrix();
}
