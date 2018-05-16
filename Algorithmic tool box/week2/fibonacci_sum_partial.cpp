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
vector<int> generalSum(vector<long long> rems , long long flag1 , long long flag2){
	flag1 = flag1%rems.size();
	flag2 = flag2%rems.size();
	// 0 > sum from flag1 to end of period, 1 > sum of period , 2 sum from 0 to flag2
	long long s0=0,s1=0,s2=0;
	for(int i = 0; i<rems.size();++i){
		s1=(s1+rems[i])%10;
		if (i>=flag1) s0=(s0+rems[i])%10;
		if (i<=flag2) s2=(s2+rems[i])%10;
	}
	vector<int> back(3);back[0] = s0;back[1]=s1;back[2]=s2;
	return back;
}
int sumLastDigit(long long start , long long n){
	vector<long long> remains = Pissano_Period_advanced(10);
	vector<int> sums = generalSum(remains,start,n);
	long long n_periods =(n-start)/remains.size() -1;
	return (sums[0]+((sums[1]*n_periods)%10)+sums[2])%10;
}
int main(){
	long long b ;
	long long c ;
	cin>>b>>c;
	cout<<sumLastDigit(b,c)<<endl;
	return 0;
}