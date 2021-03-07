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

	while(left<=right){
		int mid = (left+right)/2;

		if(arr[mid] == data){
			cout<<mid<<endl;
			return 0;
		}
		else if(arr[mid] < data){
			left = mid + 1;
		}
		else{
			right = mid - 1;
		}
	}
	//cout<<"Element doesn't exist";
	return -1;
}

