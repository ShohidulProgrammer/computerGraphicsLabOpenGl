#include<stdio.h>

main()
{
    int xc,yc,x=0,y,r,p;
    printf("Enter the center value of X: ");
    scanf("%d",&xc);
    printf("Enter the center value of Y: ");
    scanf("%d",&yc);
    printf("Enter the radius value: ");
    scanf("%d",&r);

    x = 0;
    y = r;
    printf("%d,%d",x+xc,y+yc);

    p=1-r;

    while(x<=y)
    {
        x++;
        if(p<0)
        {
            p=p+2*x+1;
        }
        else
        {
            y=y-1;
            p=p+2*x+1-2*y;
        }
        printf(" %d,%d",x+xc,y+yc);
    }
    printf("\n\n");
}
