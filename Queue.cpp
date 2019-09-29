/* Program to implement Queue */
#include<stdio.h>
#include<iostream>
#include<queue>
using namespace std;

//Function to show the contents of the queue
void show_queue(queue <int> temp) {
	queue <int> q = temp;
	while(!q.empty()) {
		printf("%d ", q.front());
		q.pop();
	}
}


int main(){
	queue <int> q;
	int n,val;
	
	printf("Enter the no. of elements to push to queue: ");
	scanf("%d",&n);
	
	for(int i=0;i<n;i++) {
		printf("Enter the element: ");
		scanf("%d",&val);
		q.push(val);
	}
	printf("Contents of the Queue are: ");
	show_queue(q);
	return 0;
}
