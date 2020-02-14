#include <math.h>
#include<GL/glut.h>

typedef struct _Vector{
   double x,y,z;
} Vector;

// Constantes
const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 590;

// Variáveis
double radian;
double speed = 10;
double rot; // Angulo de Rotação

// Vetores
Vector pos;
Vector vel;
Vector dir;
Vector dis;
Vector mouseCoords;
POINT mousePos;

GLfloat rotation = 90.0;
float posX = 0.4, posY = 0, posZ = 0.4; // for table x,y,z = 0.4, 0, 0.4
                                        // for teapot x,y,z = 0.6, 1.1, 0.6




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
    //glTranslated(0.4,0,0.4);
    glTranslated(pos.x, pos.y, 0);
    glRotatef(rot, 0, 0, 1);
    table(1.3,0.06,0.05,0.9);
     glPopMatrix();
    // draw teapot
    //aglOrtho(-SCREEN_WIDTH/2, SCREEN_WIDTH/2, -SCREEN_HEIGHT/2, SCREEN_HEIGHT/2, -100, 100);
    glPushMatrix();
    glTranslated(posX,posY,posZ); //posX = 0.6, posY = 1.1, posZ = 0.6;
    glRotated(30,0,1,0);
    glutSolidTeapot(0.2);
    glPopMatrix();

    glFlush();
}
float move_unit = 0.1f;
void keyboardown(int key, int x, int y)
{
    switch (key){
        case GLUT_KEY_RIGHT:
            posX+=move_unit;;
            break;

        case GLUT_KEY_LEFT:
            posX-=move_unit;;
        break;

        case GLUT_KEY_UP:
            posY+=move_unit;;
            break;

        case GLUT_KEY_DOWN:
            posY-=move_unit;;
        break;

        default:
         break;
    }
    glutPostRedisplay();
}




/* Callback handler for mouse event */
void mouse(int button, int state, int x, int y) {
   if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) { // Pause/resume

       mouseCoords.x = x - SCREEN_WIDTH/2;
       mouseCoords.y = -y + SCREEN_HEIGHT/2;
   }
   //glutPostRedisplay();
}


void move(){
     dis.x = mouseCoords.x - pos.x;
     dis.y = mouseCoords.y - pos.y;

     // If the magnetude is less than the speed, define the mouseCoords
     if(sqrt(dis.y*dis.y + dis.x*dis.x) < speed){
          pos.x = mouseCoords.x;
          pos.y = mouseCoords.y;
     }
     else{
          radian = atan2(dis.y, dis.x);
          pos.x += cos(radian) * speed;
          pos.y += sin(radian) * speed;
          rot = radian * 100 / 3.14;
     }

}

void update(int value){
     move();
     glPushMatrix();
        glTranslated(pos.x, pos.y, 0);
        glRotated(30,0,1,0);
        glutSolidTeapot(0.2);
     glPopMatrix();
     glutPostRedisplay();
     glutTimerFunc(10, update, 0);
}


void init(){
     glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB|GLUT_DEPTH);
     glutInitWindowSize(SCREEN_WIDTH, SCREEN_HEIGHT);
     glutInitWindowPosition(100,100);
     glutCreateWindow("Teste");

     // function calling
     glutDisplayFunc(displaySolid);
     glutSpecialFunc(keyboardown);
     glutMouseFunc(mouse);
     glutTimerFunc(25, update, 0);

     // color and lighting
     glEnable(GL_LIGHTING);
     glEnable(GL_LIGHT0);
     glShadeModel(GL_SMOOTH);
     glEnable(GL_NORMALIZE);
     glEnable(GL_DEPTH_TEST);

     // glClearColor(1, 1, 1, 1); white
     glMatrixMode(GL_PROJECTION);
     glLoadIdentity();
     glMatrixMode(GL_MODELVIEW);


    glClearColor(0.1,0.1,0.1,0.0); // black
    glViewport(0,0,640,480);
}

int main(int argc, char** argv)
{
    glutInit(&argc,argv);
	init();
    glutMainLoop();
return 0;
}
