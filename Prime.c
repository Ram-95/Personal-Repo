#include<stdio.h>
int main()
{
int n,i,j;
int flag = 0;
printf("Enter a number: ");
scanf("%d",&n);
/* Module to check if prime or not
for(i=2;i<n-1;i++)
{
    if(n%i == 0)
        flag = 1;
}
if(flag)
    printf("%d is NOT a PRIME.\n\n", n);
else
    printf("%d is a PRIME.\n\n", n);



/* Module to print prime numbers below 'n'
for(i=2;i<=n;i++)
{
    flag = 0;
    for(j=2;j<i;j++)
    {
        if(i%j == 0)
        {
            flag = 1;
            break;
        }

    }
    if(flag == 0)
        printf("%d ",i);
}

*/
int a=0,b=1,c;
printf("%d  ",a);
printf("%d  ",b);
for(i=1;i<n-1;i++)
{


c = a+b;
printf("%d  ",c);
a =b;
b=c;
}
return 0;
}
