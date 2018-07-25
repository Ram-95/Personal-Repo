#include<stdio.h>
#include<conio.h>
int factorial1(int x)
{
    int fact = 1;
    int i;
    if(x == 0)
        return fact;
    else
    {
        for(i=x;i>0;i--)
        {
            fact = fact * i;
        }
        return fact;
    }
}

int factorial(int y)
{
    int fact = 1;
    if(y == 0)
        return fact;
    else
    {
        return y * factorial(y-1);
    }
}

int main()
{
int n;
printf("Enter the value of n:");
scanf("%d",&n);
printf("Factorial of %d is: %d",n, factorial(n));
getch();
return 0;
}
