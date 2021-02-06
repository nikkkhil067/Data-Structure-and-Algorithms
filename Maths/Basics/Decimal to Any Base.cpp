#include<bits/stdc++.h>
using namespace std;

int decimal2Base(int n, int b){
	int value = 0;

	int power = 1;
	
	while(n > 0){
		int dig = n % b;
		n = n / b;

		value += dig * power;
		power = power * 10;
	}
	return value;
} 

int main(){
	
	int number, base;
	
	cin>>number;
	cin>>base;
	
	cout <<  decimal2Base(number, base);
	return 0;
}

