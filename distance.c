//WAP to find the distance between two point using 4 functions




#include<stdio.h>
#include<math.h>
int inp()
{
float p;
printf("enter x and y  co ordinates of  2 points");
scanf("%f",&p);
return p;


}
int compute(float x1,float y1,float y2,float x2)
{
float s;
s=sqrt(pow((x2-x1),2)+pow((y2-y1),2));
return s;

}
void display(float x1,float y1,float y2,float x2,float s)
{
printf("Distance between %f %f and %f %f is %f ",x1,y1,x2,y2,s);
}
void main()
{
float x1,y1,x2,y2,s;
x1=inp();
y1=inp();
x2=inp();
y2=inp();
s=compute(x1,y1,y2,x2);
display(x1,y1,y2,x2,s);
}
