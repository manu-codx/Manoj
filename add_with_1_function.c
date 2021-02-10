//Write a program to add two user input numbers using one function


include <stdio.h>
 
void main()
{
    int i, num, sum = 0;
 
    printf("Enter an integer number \n");
    scanf ("%d", &num);
    for (i = 1; i <= num; i++)
    {
        sum = sum + i;
    }
    printf ("Sum of first %d  numbers = %d\n", num, sum);
}
