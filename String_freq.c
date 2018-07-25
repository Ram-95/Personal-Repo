#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<ctype.h>
int main()
{
char a[50];
int size = sizeof(a)/sizeof(a[0]);
printf("Enter the string: ");
gets(a);
printf("%s\n %d",a, size);
int i,j;
int count = 0;

for(i=0;i<strlen(a);i++)
{
count = 0;
    for(j = 0; j < size; j++)
    {
        if(a[i] == a[j])
            count = count + 1;
    }
printf("\nCount of character %c is: %d", a[i], count);
}


getch();
return 0;
}
