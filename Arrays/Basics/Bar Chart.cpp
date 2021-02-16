#include<bits/stdc++.h>
using namespace std;

void barChart(int n, int arr[]){
	int max = arr[0];
	for(int i=1;i<n;i++){
		if(arr[i]>max)
			max = arr[i];
	}

	for(int floor=max;floor>=1;floor--){
		for(int i=0;i<n;i++){
			if(arr[i]>=floor)
				cout<<"*\t"; 
			else
				cout<<"\t";
		}
		cout<<" ";
	}
}

int main(){
	
	int n;
	cin>>n;

	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}

	barChart(n, arr);

	return 0;
}

