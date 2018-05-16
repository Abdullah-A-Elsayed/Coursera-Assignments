#include <iostream>
#include <vector>
using namespace std;
long long GCD(long long a, long long b){
	if(a < b){
		long long m = a;
		a = b;
		b = m;
	}
	// a is > b always
	if (b == 0){
		return a;
	}
	else{
		return GCD(b,a%b);
	}
}

long long LCM(long long a, long long b){
	return a/GCD(a,b)*b;
}

int main(){
	long long c ;
	long long d ;
	cin>>c>>d;
	cout<<LCM(c,d)<<endl;
	return 0;
}