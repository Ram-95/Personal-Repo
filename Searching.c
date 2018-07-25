#include<stdio.h>
#include<conio.h>
void linear_search(int key, int b[], int size)
{
    int i;

    int flag = 0;

    for(i=0; i< size;i++)
    {
        if(b[i] == key)
        {
            flag = 1; // come out of the loop if element found
            break;
        }
    }
        if(flag)
            printf("\nKEY PRESENT\n");
        else
            printf("\nKEY NOT PRESENT\n");
}

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
//printArray(b,n1);

}

int binary_search(int k, int b[],int low, int high)
{

    int mid = (low + high)/2;
    if(k == b[mid])
    {
        return mid;

    }
    if(k < b[mid])
    {
       return binary_search(k,b,low,mid-1);
    }
    else
        return binary_search(k,b,mid+1,high);

return -1;
}

int main()
{
int a[8] = {5,9,8,4,51,6,2,47};
int size = sizeof(a)/sizeof(a[0]);
int key1;
printf("Enter key: ");
scanf("%d", &key1);
printf("\nLINEAR SEARCH\n\n");
linear_search(key1,a,size);
int i;


insertion_sort(a,size);


for(i=0;i<size;i++)
    printf("%d  ",a[i]);
printf("\nBINARY SEARCH\n");
int res = binary_search(key1,a,0,size);
(res != -1)? printf("\nElement Present at location %d\n",res) : printf("Not Present");
getch();
return 0;
}
