/*
#include <iostream> 
#include <string> 
#include <vector> 
#include <algorithm> 
using namespace std; 
  
// A comparison function which is used by sort() in printLargest() 
int myCompare(string X, string Y) 
{ 
    // first append Y at the end of X 
    string XY = X.append(Y); 
  
    // then append X at the end of Y 
    string YX = Y.append(X); 
  
    // Now see which of the two formed numbers is greater 
    return XY.compare(YX) > 0 ? 1: 0; 
} 
  
// The main function that prints the arrangement with the largest value. 
// The function accepts a vector of strings 
void printLargest(vector<string> arr) 
{ 
    // Sort the numbers using library sort funtion. The function uses 
    // our comparison function myCompare() to compare two strings. 
    // See http://www.cplusplus.com/reference/algorithm/sort/ for details 
    sort(arr.begin(), arr.end(), myCompare); 
  
    for (int i=0; i < arr.size() ; i++ ) 
        cout << arr[i]; 
} 
  
// driver program to test above functions 
int main() 
{ 
    vector<string> arr; 
  
    //output should be 6054854654 
    arr.push_back("54"); 
    arr.push_back("546"); 
    arr.push_back("548"); 
    arr.push_back("60"); 
    printLargest(arr); 
  
    // output should be 777776 
    /*arr.push_back("7"); 
    arr.push_back("776"); 
    arr.push_back("7"); 
    arr.push_back("7");*/
  
    //output should be 998764543431 
    /*arr.push_back("1"); 
    arr.push_back("34"); 
    arr.push_back("3"); 
    arr.push_back("98"); 
    arr.push_back("9"); 
    arr.push_back("76"); 
    arr.push_back("45"); 
    arr.push_back("4"); 
    
  
   return 0; 
} 
*/

#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;

void show(vector <int> ar) {
	for(int j=0;j<ar.size();j++) {
		cout << ar[j];
	}
}

int main() {
	int n;
	printf("Enter n: ");
	scanf("%d",&n);
	vector<int> arr(n);
	for(int i=0;i < n; i++) {
		cin >> arr[i];
		}
	}
	show(arr);
	return 0;
}

