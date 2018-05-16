#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip> //use double <<fixed<<setprecision(4)
using namespace std;
void numToArray(int a, vector<int> &as){
		while(a>0){
			as.insert(as.begin(),a%10);
			a/=10;
		}
}
bool howToSort(int a, int b){	
	vector<int> as;
	vector<int> bs;
	numToArray(a,as);
	numToArray(b,bs);
	// last digit extend is needed wrong
	// short will be extendid with first digits of longer (by comparison)
	if (bs.size()>as.size()){ //bs is longer
		for(int i =0; i<bs.size();++i){
			if(i>=as.size()){
				if(bs[i]>bs[i-as.size()]) return false;
				if(bs[i-as.size()]>bs[i]) return true;
			}
			else{
				if(as[i]>bs[i]) return true;
				if(bs[i]>as[i]) return false;
				// if equal it will stay looping
			}
		} 
	}
	else { //as is longer
		for(int i =0; i<as.size();++i){
			if(i>=bs.size()){
				if(as[i]>as[i-bs.size()]) return true;
				if(as[i-bs.size()]>as[i]) return false;
			}
			else{
				if(as[i]>bs[i]) return true;
				if(bs[i]>as[i]) return false;
				// if equal it will stay looping
			}
		}
	}
	// they are equal, soln making two jointed arrays then checking
	//b to a
	vector<int> bigA(as.size());
	bigA = as;
	for(int i=0;i<bs.size();++i){
		bigA.push_back(bs[i]);
	}
	int r1=0; int mul =1;
	for(int i = bigA.size()-1; i>-1; --i){
		r1+=bigA[i]*mul;
		mul*=10;
	}
	//a to b
	vector<int> bigB(bs.size());
	bigB = bs;
	for(int i=0;i<as.size();++i){
		bigB.push_back(as[i]);
	}
	int r2=0; int mul2 =1;
	for(int i = bigB.size()-1; i>-1; --i){
		r2+=bigB[i]*mul2;
		mul2*=10;
	}
	return r1 > r2;
}

int main(){
	int n;
	cin>>n; // n: count
	vector<int> numbers(n);
	for(int i=0; i<n ; ++i){
		cin>>numbers[i];
	}
	sort(numbers.begin(),numbers.end(),howToSort);
	for(int i=0;i<numbers.size();++i) cout<<numbers[i];

	return 0;
}