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

int main(){
	long long c ;
	long long d ;
	cin>>c>>d;
	cout<<GCD(c,d)<<endl;
	return 0;
}