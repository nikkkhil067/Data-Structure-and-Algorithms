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

int anyBase2anyBase(int n, int b1, int b2){
	
	int decimal = base2Decimal(n, b1);
	int destination = decimal2Base(decimal, b2);

	return destination;
}

int main(){
	
	int number, base1, base2;

	cin>>number;
	cin>>base1;
	cin>>base2;

	cout<<anyBase2anyBase(number, base1, base2);

	return 0;
}

