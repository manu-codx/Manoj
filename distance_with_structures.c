//WAP to find the distance between two points using structures and 4 functions.



#include<stdio.h>
int height()
{
int h;
printf("Enter h value");
scanf("%d",&h);
return h;
}
int base()
{
int b;
printf("enter b value");
scanf("%d",&b);
return b;
}
int input()
{
int d;
printf("enter d value");
scanf("%d",&d);
return d;
}
int main()
{
int x,y,z;
double r,vol=0;
x=height();
y=base();
z=input();
vol=0.33*((x*y*z)+(z/y));

printf("Volume is %lf",vol);

return 0;
}
