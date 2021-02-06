/*Span of Array - Difference between the maximum and 
				  the minimum element of the array*/

#include<bits/stdc++.h>
using namespace std;

int spanOfArray(int n, int arr[]){
	int max = arr[0];
	int min = arr[0];
	for(int i=1;i<n;i++){
		if(arr[i]>max)
			max = arr[i];
		if(arr[i]<min)
			min = arr[i];
	}
	int span = (max - min);
	return span;
}

int main(){
	
	int n;
	cin>>n;

	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}

	cout<<spanOfArray(n, arr);
	return 0;
}

