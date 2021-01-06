#include<bits/stdc++.h>
using namespace std;

void maxMin(int arr[], int size){
    
	int max, min;

    if(size == 1){	
        max = arr[0];
        min = arr[0];
	}
    else{
		if(arr[0]>arr[1]){
    	   	max = arr[0];
        	min = arr[1];
		}
		else
        	max = arr[1];
        	min = arr[0];
	}
    for(int i=2;i<size;i++){
        if(arr[i]>max)
            max = arr[i];
        else
            min = arr[i];
    }
    cout<<max<<" ";
    cout<<min;

}

int main(){
    int arr[] = {2,3,1,4,5};
    int size = sizeof(arr)/sizeof(arr[0]);

    maxMin(arr,size);
    return 0;
}
