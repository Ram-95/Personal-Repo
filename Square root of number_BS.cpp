/* Square root of a number using Binary Search */

/*
Implement int sqrt(int x). Compute and return the square root of x.
If x is not a perfect square, return floor(sqrt(x))
*/


#include<iostream>
#include<stdio.h>
using namespace std;

long int Square_root(long int x)
{
    long int low = 0;
    long int high = x;
    long int mid;
    long int ans = -1;

    while(low <= high) {
        mid = (low + high)/2;
        long int temp = mid * mid;

        if(temp <= x) {
            ans = mid;
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }

    }

    return(ans);

}


int main() {
long int n;
scanf("%ll",&n);
printf("%ll",Square_root(n));

return 0;
}

