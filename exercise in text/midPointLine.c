#include<stdio.h>

main()
{
    int x,y,x0,y0,x1,y1;
    float d,dx,dy,m;

    printf("\n\n");

    printf("Enter the value of x0: ");
    scanf("%d",&x0);

    printf("Enter the value of x1: ");
    scanf("%d",&x1);

    printf("Enter the value of y0: ");
    scanf("%d",&y0);

    printf("Enter the value of y1: ");
    scanf("%d",&y1);


    dx = x1- x0;
    dy = y1 - y0;

    m = dy/dx;


    // if M<1
    if(m<1)
    {

        d = (dy - (dx/2));
        x = x0;
        y = y0;

        printf("(%d,%d),",x,y);

        while(x<x1)
        {
            x = x+1;

            if(d<0)
            {
                d = d+dy;
            }
            else
            {
                d=d+dy-dx;
                y = y+1;
            }

            printf("(%d,%d), ",x,y);
        }

    }

    // if M > 1
    else
    {

        d = (dx - (dy/2));
        x = x0;
        y = y0;

        printf("(%d,%d), ",x,y);

        while(y<y1)
        {
            y = y+1;

            if(d<0)
            {
                d = d+dx;
            }
            else
            {
                d=d+dx-dy;
                x = x+1;
            }

            printf("(%d,%d), ",x,y);
        }
    }

}
