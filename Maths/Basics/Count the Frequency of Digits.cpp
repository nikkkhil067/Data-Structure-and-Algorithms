#include<bits/stdc++.h>
using namespace std;


int digitFrequency(int number, int digit){
	int count = 0;

	while(number > 0){
		int dig = number % 10;
		number = number / 10;

		if(dig == digit){
			count++;
		}
	}
	return count;
}

int main(){
	
	int number;
	int digit;

	cin>>number;
	cin>>digit;

	cout << digitFrequency(number, digit);

	return 0;
}

