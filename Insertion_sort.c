#include<stdio.h>
#include<conio.h>
/* Insertion Sort */
void insertion_sort(int b[], int n1)
{
int j, key, in,k;
    for(j=1;j<n1;j++)
    {
        key = b[j];
        in = j-1;
        while(in >= 0 && b[in] > key)
        {
            b[in + 1] = b[in];
            in = in - 1;

        }
        b[in + 1] = key;
    }
printArray(b,n1);

}

/* Selection Sort */
void selection_sort(int b[], int n1)
{
    int ind,j, min_index;
    for(ind = 0; ind < n1-1; ind++)
    {
        min_index = ind;
        for(j = ind+1;j < n1; j++)
        {
            if(b[j] < b[min_index])
                min_index = j;
        }

    swap(&b[min_index], &b[ind]);
    }
// Swapping the values

printArray(b,n1);
}


void bubble_sort(int a[], int n1)
{
    int i,j;
    for(i=0;i<n1;i++)
    {
        for(j=i+1;j < n1;j++)
        {
            if(a[i] > a[j])
            {
                swap(&a[i], &a[j]);
                break;
            }

        }
    }
printArray(a,n1);
}


void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void printArray(int arr[], int size)
{
    int i;
    for(i = 0; i < size; i++)
        printf("%d\t",arr[i]);
}

/* Main Function */
int main()
{
    int a[100];
    int i,j, n;
    printf("Enter the size of array: ");
    scanf("%d",&n);
    printf("Enter the elements in the array: ");
    for(i=0;i<n;i++)
    {
        scanf("%d", &a[i]);
    }
printf("\n\nUnsorted Array is: \n");
printArray(a,n);


printf("\n\nSorted array(Insertion Sort) is: \n");
insertion_sort(a, n);

printf("\n\nSorted array(Selection Sort) is: \n");
selection_sort(a,n);

printf("\n\nSorted array(Bubble Sort) is: \n");
bubble_sort(a,n);

getch();
return 0;
}
