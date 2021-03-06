#include<bits/stdc++.h>
using namespace std;

//Find the Difference - n2 - n1 (Given array 2 is always larger than array 1)

int main(){
	
	int n1;
	cin>>n1;

	int* arr1 = new int[n1];

	for(int i=0;i<n1;i++){
		cin>>arr1[i];
	}

	int n2;
	cin>>n2;

	int* arr2 = new int[n2];

	for(int i=0;i<n2;i++){
		cin>>arr2[i];
	}

	int* ans = new int[n2];

	int i = n1 - 1;
	int j = n2 - 1;
	int k = n2 - 1;

	int borrow = 0;

	while(k>=0){
		int diff = (arr2[j] - borrow);

		if(i>=0){
			diff -= arr1[i];
		}
		if(diff<0){
			diff+=10;
			borrow=1;
		}
		else{
			borrow=0;
		}
		ans[k] = diff;
		i--;
		j--;
		k--;
	}

	i=0;

	while(ans[i]==0){
		i++;
	}
	while(i<n2){
		cout<<ans[i]<<endl;
		i++;
	}

	return 0;
}

