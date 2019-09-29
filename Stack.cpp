/* Program to implement Stack */
#include<stdlib.h>
#include<iostream>
#include<stack>
using namespace std;

//function to show contents of the stack

void show_stack(stack<int> temp) {
	stack<int> s =temp;
	while(!s.empty()){
		printf("%d ",s.top());
		s.pop();
	}
}

int main() {
	stack<int> st;
	int n, val;
	printf("Enter n: ");
	scanf("%d",&n);
	
	for(int i = 0; i < n; i++){
		printf("Enter the Element: ");
		scanf("%d",&val);
		st.push(val);
	}
	// Size or no. of contents of the stack
	printf("Size of Stack is: %d\n",st.size());
	
	// Showing the contents of the stack
	printf("Contents of Stack: ");
	show_stack(st);
	
	return 0;
}
