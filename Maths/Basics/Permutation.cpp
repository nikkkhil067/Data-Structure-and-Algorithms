#include<bits/stdc++.h>
using namespace std;

int fact(int x){
	int returnValue = 1;

	for(int i=1;i<=x;i++){
		returnValue = returnValue*i;
	}
	return returnValue;
}

void display(int n, int r, int npr){
	cout<<  n << "P" << r  << "=" << npr;
}

int main(){
	int n;
	int r;

	cin>>n;
	cin>>r;

	int nfact = fact(n);
	int rfact = fact(n-r);

	int npr = nfact/rfact;

	display(n,r,npr);

	return 0;
}

