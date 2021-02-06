#include<bits/stdc++.h>
using namespace std;

int base2Decimal(int n, int b){
	int value = 0;
	int power = 1;
	while(n>0){
		int dig = n%10;
		n = n/10;

		value += dig*power;
		power = power*b;
	}
	return value;
}

int main(){
	int number, base;

	cin>>number;
	cin>>base;

	cout<<base2Decimal(number,base);
	
	return 0;
}

