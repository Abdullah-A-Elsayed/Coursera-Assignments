/*
take care:
	sort of cpp makes problems when pass a,b to how to sort
	 and get exactly like b,a -it crashes
	 **so if a=b true, b=a must be false**
 debug tab then locals to see
*/
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
		return true;
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
		return false;
	}
}
bool myhowToSort(int a, int b){
	
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
	return true;
}
void mySort(vector<int> &nums){
	for(int i=0; i<nums.size() ; ++i){
		for(int j = i+1; j<nums.size() ;++j){
			if(myhowToSort(nums[j],nums[i])) {
				iter_swap(nums.begin()+i,nums.begin()+j);
			}
		}
	}
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