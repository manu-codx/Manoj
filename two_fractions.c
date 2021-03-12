#include<stdio.h>
typedef struct fraction
{
   int n;
   int d; 
}
fract;
fract input()
{
   fract f;
   printf("Enter numerator: \n");
   scanf("%d",&f.n);
   printf("Enter denominator: \n");
   scanf("%d",&f.d);
   return f;
}
fract compute(fract f1,fract f2)
{
    fract f;
   int max,lcm;
   max = (f1.d > f2.d)? f1.d : f2.d;
   while(1)
   {
       if((max % f1.d == 0) && (max % f2.d == 0))
       {
           lcm = max;
           break;
       }
          
       ++max;   
   }
   int m1 = lcm/f1.d;
   int m2 = lcm/f2.d;
   f.d = lcm; 
   f.n = (m1*f1.n) + (m2*f2.n); 
      int min = (f.n < f.d)? f.n : f.d;
   while(min >= 1)
   {
       if(f.n % min == 0 && f.d % min == 0)
       {
           f.n = f.n/min;
           f.d = f.d/min;
           break;
       }
       --min;
   }
   return f;
}
void print(fract f,fract f1,fract f2)
{
   printf("%d/%d + %d/%d = %d/%d",f1.n,f1.d,f2.n,f2.d,f.n,f.d);
}
int main()
{
   fract f1,f2;
   printf("Fraction-1\n");
   f1 = input();
   printf("Fraction-2\n");
   f2 = input();
   fract f = compute(f1,f2);
   print(f,f1,f2);
   return 0;
}
