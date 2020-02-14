#include<GL/glut.h>

void chessBoard(void)
{
    // Quads
    int i,j,color=0;
	float x1, y1 = (1.3), x2, y2 = (1.1);

	//stair start from here

	for(i=0;i<8;i++,y1-=0.2,y2-=0.2)
    {
        x1 = (-1.3), x2 = (-1.1);
        for(j=0;j<8;j++,x1+=0.2,x2+=0.2)
        {
            // set color
            if(color==1)
                {
                    // pink color
                    glColor3f(1.0, 0, 0.5);
                    color = 0;
                }
                else
                {
                    //glColor3f(1.0, 1, 0.5);
                    // white color
                    glColor3f(2, 1, 1); //this will set a color of the square.
                    color = 1;
                }

                glBegin(GL_QUADS); // write shape u want to create
                glVertex3f(x1, y1, 0.0); // v1
                glVertex3f(x1, y2, 0.0); // v2
                glVertex3f(x2, y2, 0.0); // v3
                glVertex3f(x2, y1, 0.0); // v4
                glEnd();

        }
        // set color
            if(color==1)
                {
                    // pink color
                    glColor3f(1.0, 0, 0.5);
                    color = 0;
                }
                else
                {
                    //glColor3f(1.0, 1, 0.5);
                    // white color
                    glColor3f(2, 1, 1); //this will set a color of the square.
                    color = 1;
                }
    }


}
