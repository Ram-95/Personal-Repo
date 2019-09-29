/* Program to find out the sum of all elements in an array */
#include<stdlib.h>
#include<iostream>
using namespace std;

//Function to show the contents of the array

void show(int arr[], int len) {
	for(int j = 0; j < len; j++) {
		printf("%d ",arr[j]);
	}
}


int main() {
	int arr[100];
	int n, sum = 0;
	printf("Enter the size of the array: ");
	scanf("%d",&n);
	
	for(int i=0;i<n;i++) {
		scanf("%d",&arr[i]);
	}
	
	printf("Contents of the Array: ");
	show(arr,n);
	
	for(int k = 0; k < n; k++) {
		sum += arr[k];
	}
	
	printf("\nSum of elements is: %d",sum);
	
	
	return 0;
}
