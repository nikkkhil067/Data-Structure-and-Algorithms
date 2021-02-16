#include<bits/stdc++.h>
using namespace std;

int elementInArray(int n, int arr[], int element){
	int index = -1;
	for(int i=0;i<n;i++){
		if(arr[i]==element){}
			index = i;
			break;
		}
	}
	return index;
}

int main(){
	
	int n;
	cin>>n;

	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}

	int element;
	cin>>element;

	cout<<elementInArray(n, arr, element);
	return 0;
}

