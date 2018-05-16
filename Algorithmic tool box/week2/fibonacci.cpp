#include <iostream>
#include <vector>
using namespace std;
long long fibonacci(long long n){
	if(n<=1) return n;
	vector<long long> fibos(n+1);
	fibos[0] =0;
	fibos[1] =1;
	for(int i=2 ; i < n+1 ; ++i){
		fibos[i] = fibos [i-1] + fibos [i-2];
	}
	return fibos[n];
}

int main(){
	long long c ;
	cin>>c;
	cout<<fibonacci(c)<<endl;
	return 0;
}