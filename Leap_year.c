#include<stdio.h>
#include<conio.h>
int main()
{
int year;
printf("Enter year: ");
scanf("%d",&year);
if((year%400 == 0) || ((year%4 == 0) && (year % 100 != 0)))
    printf("LEAP YEAR");
else
    printf("NOT A LEAP YEAR");
getch();
return 0;
}
