/* To print the nth Fibonacci number */
#include<stdio.h>
#include<conio.h>
int fib(int x)
{
    if(x == 0)
        return 0;
    else if(x == 1)
        return 1;
    else
        return fib(x-1) + fib(x-2);
}

int main()
{
int n, i, f1 = 0, f2 = 1, fibo;
printf("Enter the number: ");
scanf("%d",&n);
printf("The %dth Fibonacci number is: %d\n",n, fib(n));
for(i=0;i<n;i++)
{
    printf("%d  ",f1);
    fibo = f1 + f2;
    f1 = f2;
    f2 = fibo;
}
getch();
return 0;
}
