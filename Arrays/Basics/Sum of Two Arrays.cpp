#include<bits/stdc++.h>
u-ng namespace std;

int main(){
	
	int n1;
	cin>>n1;

	int *arr1= new int [n1];
	for(int i=0;i<n1;i++){
		cin>>arr1[i];
	}

	int n2;
	cin>>n2;

	int *arr2 = new int [n2];
	for(int i=0;i<n2;i++){
		cin>>arr2[i];
	}

	int m = max(n1,n2);

	int *ans = new int[m]; 

	int carry = 0;
	int i= n1 - 1; //last index
	int j = n2 - 1; //last index
	int k = m - 1; //last index

	while(k>=0){

		int sum = carry;

		if(i>=0){
			sum+=arr1[i];
		}
		if(j>=0){
			sum+=arr2[j];
		}

		int q = sum /10;
		int r = sum%10;

		ans[k] = r;
		carry = q;
		i--;
		j--;
		k--;
	}

	if(carry!=0){
		cout<<carry<<endl;
	}

	for(int i=0;i<m;i++){
		cout<<ans[i]<<endl;
	}
	return 0;
}

