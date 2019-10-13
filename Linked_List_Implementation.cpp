#include<bits/stdc++.h>
#include<stdio.h>
using namespace std;

//Creating the Structure of the Node
struct Node {
	int data;
	Node* next;
};

//Creating the head Node - Global Variable
Node* head;

//Function to insert an element at the beginning
void Insert(int x) {
	Node* temp = new Node();
	temp -> data = x;
	temp -> next = head;
	head = temp;
}

//Function to print the contents of the LL
void Print() {
		Node *temp = head;
		printf("List is: ");
		while(temp != NULL){
			printf(" %d",temp->data);
			temp = temp->next;
		}
		printf("\n");
}



int main() {
	head = NULL;	//Means, Empty List
	printf("N: ");
	int n,i,x;
	scanf("%d",&n);
	for(i = 0; i < n ; i++) {
		printf("Enter the number: \n");
		scanf("%d",&x);
		Insert(x);
		Print();

	}
	//Print();
	Node* t_head = head;

	return 0;
}
