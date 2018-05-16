#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip> //use double <<fixed<<setprecision(4)
using namespace std;

bool howToSort(int a, int b){
	return a>b;
}
long long maxAdsProfit(vector<int> &profit, vector<int> &clicks){
	long long max =0;
	for(int i =0 ; i<profit.size(); ++i){
		long long a = profit[i];
		max+= a * clicks[i];
	}
	return max;
}

int main(){
	int n;
	cin>>n; // n: count
	vector<int> profits(n);
	vector<int> clicks(n);
	// inputs
	for(int i=0;i<n;++i){
		cin>>profits[i];
	}
	for(int i=0;i<n;++i){
		cin>>clicks[i];
	}
	sort(profits.begin(),profits.end(),howToSort);
	sort(clicks.begin(),clicks.end(),howToSort);
	cout<<maxAdsProfit(profits,clicks);
	return 0;
}