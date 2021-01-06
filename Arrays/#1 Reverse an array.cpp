#include<bits/stdc++.h>
using namespace std;

void reverseArray(int arr[], int start, int end){
    while(start<=end){
        int temp;
        arr[start] = arr[end];
        arr[end] = temp;
        temp = arr[start];
    }
    start++;
    end--;
}

void printArray(int arr[], int size){
    for(int i=0;i<size;i++){
        cout<<arr[i]<< " ";
    }
}

int main(){
    int arr[] = {1,2,3,4,5,6};
    int size = sizeof(arr)/sizeof(arr[0]);

    reverseArray(arr, 0, size-1);

    printArray(arr, size);

    return 0;
}
//Time Complexity : 0(n)
//Space Complexity : 0(n)