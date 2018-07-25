#include<stdio.h>
#include<conio.h>
int main()
{
int n,a;
printf("Enter n: ");
scanf("%d",&n);
int sum = 0;
while(n!=0)
{
    a = n%10;
    sum = sum + a;
    n = n/10;
    printf("\nValue is %d",a);
}
printf("SOD: %d", sum);
getch();
return 0;
}
