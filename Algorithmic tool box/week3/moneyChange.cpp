#include <iostream>
#include <vector>
using namespace std;
int changeMoney(int m){
	int numCoins = 0;
	if(m / 10 != 0){
		numCoins += m/10;
		m %= 10;
	}
	if(m / 5 != 0){
		numCoins += m/5;
		m %= 5;
	}
	if(m / 1 != 0){
		numCoins += m/1;
		m %= 1;
	}
	return numCoins;
}
int main(){
	int m;
	cin>>m;
	cout<<changeMoney(m)<<endl;
	return 0;
}