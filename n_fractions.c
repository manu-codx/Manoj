//WAP to find the sum of n fractions.

#include<stdio.h>
typedef struct fraction
{
    int n; //numerator
    int d; //denominator
}fract;
void input(int n, fract fractions[n])
{
    for(int i = 0;i < n;i++)
    {
        printf("Enter the numerator of fraction %d : \n",i+1);
        scanf("%d",&fractions[i].n);
        printf("Enter the denominator of fraction %d : \n",i+1);
        scanf("%d",&fractions[i].d);
    }
}
fract compute(int n, fract fractions[n])
{
    fract f;//holds answer
    //finding denominator
    f.d = 1;
    for(int i = 0;i < n;i++)
        f.d = f.d * fractions[i].d;

    //finding numerator 
    f.n = 0;
    for(int i = 0; i < n;i++)
    {
        int temp = fractions[i].n;
        for(int j = 0;j < n;j++)
        {
            if(i!=j)
            {
                temp = temp * fractions[j].d;
                
            }
       } 
       f.n = f.n + temp; 
    }   
    //simplyfying
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
void print(int n,fract fractions[n],fract f)
{
    printf("Sum of ");
    for(int i = 0;i < n-1; i++)
        printf("%d/%d + ",fractions[i].n,fractions[i].d);
    printf("%d/%d = %d/%d",fractions[n-1].n,fractions[n-1].d,f.n,f.d);    
}
int main()
{
    int n;
    printf("Enter the number of fractions:\n");
    scanf("%d",&n);
    fract fractions[n];
    input(n,fractions);
    fract f = compute(n,fractions);
    print(n,fractions,f);
}
