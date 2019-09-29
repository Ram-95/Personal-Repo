#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;

int compare_func(string a, string b){
	string ab = a.append(b);
	
	string ba= b.append(a);
	
	return ab.compare(ba) > 0 ? 1: 0;
	
}

void largest_concatenated(vector <string> arr) {
	sort(arr.begin(), arr.end(), compare_func);
	
	for(int i = 0; i < arr.size(); i++){
		cout << arr[i];
	}
	
}

int main() {
	vector <string> arr;
	int t,n,temp;
	string inp;
	scanf("%d",&t);
	while(t--) {
		scanf("%d\n",&n);
		vector<string> arr(n);
		for(int i =0; i < n; i++) {
			cin >> arr[i];
		}
		largest_concatenated(arr);
		printf("\n");
	}
	return 0;
}

