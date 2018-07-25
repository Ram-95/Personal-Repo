#include<stdio.h>
void print_binary(int x)
{
    int rem;
    if(x>0)
    {
        print_binary(x/2);
        rem = x%2;
        printf("%d ", rem);
    }
}

int main()
{
int ones = 0, zeros = 0;
int n;
printf("Enter n: ");
scanf("%d",&n);
int rem;
print_binary(n); // Print Binary representation of the Number

while(n>0)
{
    rem = n%2;
//    printf("%d ",rem);
    if(rem)
        ones++;
    else
        zeros++;
    n = n/2;
}
printf("\nThe No of ones is: %d and \nzeros is: %d",ones,zeros);


return 0;
}
