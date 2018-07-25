#include<stdio.h>
#include<conio.h>
// r -> higher index  ; p -> Lower index
void print_array(int b[],int p, int r)
{
    int i;
    for(i=p;i<r;i++)
        printf("%d  ",b[i]);
}
void swap(int *x, int *y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

int partition(int arr[], int p, int r)
{
    int i,x,j;
    x = arr[r]; // x is pivot; takes the last element as pivot
    i = p-1;
    for(j = p; j <= r-1; j++)
    {
        if(arr[j] <= x)
        {
            i = i + 1;
            swap(&arr[i],&arr[j]);
        }

    }
    swap(&arr[i+1],&arr[r]);
    return i+1;
}

void quick_sort(int b[], int p, int r)
{
    int q;
    if(p<r)
    {
        q = partition(b,p,r);
        quick_sort(b,p,q-1);
        quick_sort(b,q+1,r);
    }
}

int main()
{
int a[] = {7,5,9,4,2,11,25,1,95,58};
int size = sizeof(a)/sizeof(a[0]);
printf("Unsorted Elements are: \n");
print_array(a,0,size);

quick_sort(a,0,size-1);
printf("\n\nSorted Elements are: \n");

print_array(a,0,size);
return 0;
}
