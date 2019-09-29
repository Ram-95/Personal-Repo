#include<iostream>
#include<stdlib.h>
using namespace std;
int linear_search(int b[10], int key);

int linear_search(int b[10], int key)
{
    int i;
    for(i=0;i<(sizeof(b)/sizeof(b[0]));i++)
    {
        if(b[i] == key)
            return(1);

    }
    return(0);
}
int main()
{
    int a[10] = {1,5,9,14,241,6,2,5,63,47};
    int n,i;
    cin>>n;
    if(linear_search(a, n))
        cout<<"Element Found.";
    else
        cout<<"Element NOT Found.";
return 0;
}
