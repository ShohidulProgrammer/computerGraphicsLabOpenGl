#include <math.h>
#include<GL/glut.h>
#include <iostream>
using namespace std;

// Estrutura de dados
typedef struct _Vector{
   double x,y,z;
} Vector;

// Constantes
const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;

// Variáveis
double radian;
double speed = 10;
double rot; // Rotation Angle
float posX,posY;
int obj=3;//=0;

// Vetores
Vector pos;
Vector vel;
Vector dir;
Vector dis;
Vector mouseCoords;
Vector tablePos;
Vector teaPotPos;

void tableLeg(double thick,double len)  // draw one leg of the table
{
    glPushMatrix();
    glTranslated(0,len/2,0);
    glScaled(thick,len,thick);
    glutSolidCube(1.0);
    glPopMatrix();
}

void table(double topWid, double topThick,double legThick,double legLength)
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


void display(){
     glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
     glLoadIdentity();
     glOrtho(-SCREEN_WIDTH/2, SCREEN_WIDTH/2, -SCREEN_HEIGHT/2, SCREEN_HEIGHT/2, -100, 100);

     // draw table
     glColor3f(255,255,0);
     glPushMatrix();
     glTranslated(0.4,0,0.4);
     glTranslated(tablePos.x-45, tablePos.y-120, 0);
     //glTranslated(pos.x-45, pos.y-120, 0);
     table(182,10,10,100);
     glPopMatrix();



     // draw teapot
     glColor3f(255,0,0); //RGB Color
     glTranslated(teaPotPos.x, teaPotPos.y, 0);
     //glTranslated(posX,posY,0);
     //glTranslated(pos.x, pos.y, 0);
     glRotatef(rot, 0, 0, 1);
     glutSolidTeapot(20);

     glFlush();
     glutSwapBuffers();
}

float move_unit = 3.1f;
void keyboardown(int key, int x, int y)
{
    switch (key){
        case GLUT_KEY_RIGHT:
            posX +=move_unit;;
            teaPotPos.x = posX;
            break;

        case GLUT_KEY_LEFT:
            posX -=move_unit;;
            teaPotPos.x = posX;
        break;

        case GLUT_KEY_UP:
            posY +=move_unit;;
            teaPotPos.y = posY;
            break;

        case GLUT_KEY_DOWN:
            posY -=move_unit;;
            teaPotPos.y = posY;
        break;

        default:
         break;
    }
    glutPostRedisplay();
}

void mouse(int btn, int state, int x, int y){
    mouseCoords.x = x - SCREEN_WIDTH/2;
    mouseCoords.y = -y + SCREEN_HEIGHT/2;

    //Left Button Click
    if(btn == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        // select object using RGB color
         y = glutGet( GLUT_WINDOW_HEIGHT ) - y;
         unsigned char pixel[4];
         // copy rgb color in pixel array
         glReadPixels(x, y, 1, 1, GL_RGB, GL_UNSIGNED_BYTE, pixel);
         if(pixel[0] == 255 && pixel[1] == 0 && pixel[2] == 0) // if clicked on red color
            {
                obj = 1; // if Clicked On teaPot
            }
         else if(pixel[0] == 255 && pixel[1] == 255 && pixel[2] == 0) // if clicked on yellow color
            {
                obj = 0; // if Clicked On table
            }
    }
}

void setMovable()
{
    if(obj == 1)
    {
        // teapot select
        teaPotPos.x = pos.x;
        teaPotPos.y = pos.y;
    }
    else if(obj == 0)
    {
        // table select
        tablePos.x = pos.x;
        tablePos.y = pos.y;
    }
}




void move(){
     dis.x = mouseCoords.x - pos.x;
     dis.y = mouseCoords.y - pos.y;

     // If the magnitude is less than the speed, define the mouseCoords
     if(sqrt(dis.y*dis.y + dis.x*dis.x) < speed){
          pos.x = mouseCoords.x;
          pos.y = mouseCoords.y;
     }
     else{
          radian = atan2(dis.y, dis.x);
          pos.x += cos(radian) * speed;
          pos.y += sin(radian) * speed;
          //rot = radian * 100 / 3.14;
     }
}



void update(int value){
     setMovable();
     move();
     glutPostRedisplay();
     glutTimerFunc(.10, update, 0);
}


void init(){
     glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
     glutInitWindowSize(SCREEN_WIDTH, SCREEN_HEIGHT);
     glutCreateWindow("Teste");
     glutDisplayFunc(display);
     glutSpecialFunc(keyboardown);
     glutMouseFunc(mouse);
     glutTimerFunc(25, update, 0);
     glClearColor(1, 1, 1, 1);
     glMatrixMode(GL_PROJECTION);
     glLoadIdentity();
     glMatrixMode(GL_MODELVIEW);
}


int main(int argc, char** argv)
{
    glutInit(&argc,argv);
	init();
    glutMainLoop();
return 0;
}
