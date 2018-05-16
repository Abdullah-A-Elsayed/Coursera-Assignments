#include <iostream>
#include <vector>
using namespace std;
vector<long long> Pissano_Period_advanced(long long m){
	vector<long long> remains; // of 1 period
	remains.push_back(0);remains.push_back(1);
	for(long long i = 2 ; 1 ; ++i){
		long long rem = (remains[i-1]+remains[i-2])%m;
		if(rem == 1 && remains[i-1] ==0){ 
			remains.pop_back();
			break;
		}
		remains.push_back(rem);
	}
	return remains;
}
long long hugeModM(long long n, long long m){
	vector<long long> remains = Pissano_Period_advanced(m);
	long long period = remains.size();
	return remains[n%period];
}
int main(){
	long long c ;
	long long d ;
	cin>>c>>d;
	cout<<hugeModM(c,d)<<endl;
	return 0;
}