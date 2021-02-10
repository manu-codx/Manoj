//WAP to find the volume of a tromboloid using 4 functions.

#include<math.h>
#include<stdio.h>
struct Point
{
float x;
float  y;
};
typedef struct Point point;
point input()
{
point p;
printf("enter co ordinates for point 1");
scanf("%f %f",&p.x,&p.y);
return p;
}
float compute(point p1,point p2)
{
    float s;
s=sqrt(pow((p1.x-p1.y),2)+pow((p2.x-p2.y),2));
return s;
}
void result(point p1,point p2,float s)
{
    printf("distance between %f %f and %f %f is %f",p1.x,p1.y,p2.x,p2.y,s);
}
int main()
{
point p1,p2;
float s;
p1=input();
p2=input();
s=compute(p1,p2);
result(p1,p2,s);
return 0;
}
