#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin>>n;

	int* arr = new int[n];

	for(int i=0;i<n;i++){
		cin>>arr[i];
	}

	int data;
	cin>>data;

	int left = 0;
	int right = n - 1;

	int firstIndex = -1;
	int lastIndex = -1;

	while(left <= right){
		int mid = (left + right)/2;
		
		if(arr[mid] == data){
			firstIndex = mid;
			right = mid - 1;
		}
		else if(arr[mid] < data){
			left = mid + 1; 
		}
		else{
			right = mid - 1;
		}
	}

	left = 0;
	right = n -1 ;

	while(left <= right){
		int mid = (left + right)/2;
		
		if(arr[mid] == data){
			lastIndex = mid;
			left = mid + 1;
		}
		else if(arr[mid] < data){
			left = mid + 1; 
		}
		else{
			right = mid - 1;
		}
	}

	cout<<firstIndex<<endl;
	cout<<lastIndex;
	return 0;
}

