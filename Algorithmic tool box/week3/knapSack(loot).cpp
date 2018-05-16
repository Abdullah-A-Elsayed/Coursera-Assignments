#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip> //use double <<fixed<<setprecision(4)
using namespace std;

bool howToSort(vector<int> &a, vector<int> &b){
	double vpm1 = double(a[0])/a[1]; // value per mass
	double vpm2 = double(b[0])/b[1];
	return vpm1>vpm2;
}

double maxLootValue(int m ,vector<vector<int>> &things){
	double maxVal=0;
	for(int i=0;i<things.size();++i){
		if (m == 0) return maxVal;
		int taken;
		taken = (things[i][1]>m)?/* weight>capacity?*/m:things[i][1];
		//updating excluding things as I'm interested in max value only
		maxVal += double(things[i][0])/things[i][1]*taken;
		m -= taken;
	}
	return maxVal;
}

int main(){
	int n,m;
	cin>>n>>m; // n: count, m: capacity
	vector<vector<int>> things(n);
	// inputs
	for(int i=0;i<n;++i){
		int value , weight;
		cin>> value >> weight;
		things[i].push_back(value);
		things[i].push_back(weight);
	}
	sort(things.begin(),things.end(),howToSort);
	cout<<fixed<<setprecision(4)<<maxLootValue(m,things);
	return 0;
}