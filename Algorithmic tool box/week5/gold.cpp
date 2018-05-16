#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <string>
using namespace std;
void fill_matrix(vector<vector<int>> &m,int W, vector<int> bars){
	//initializing
	int n = bars.size();
	for(int i=0;i<n;++i){
		for(int j =0; j<=W; ++j){
			m[i].push_back(0);
		}
	}
	//initializing done
	//filling first row
	for(int u =1; u<=W; ++u){
		if(bars[0]<= u) m[0][u] = bars[0];
	}
	//from colum(k) 1 to n m[t][k]
	for(int t=1;t<n;++t){
		for(int k = 1; k<=W; ++k){
			m[t][k] = m[t-1][k]; //not selecting taking val of prev row(bars) same cap
			if(bars[t]<=k){
				if(bars[t]+m[t-1][k-bars[t]]>m[t][k]) m[t][k] = bars[t]+m[t-1][k-bars[t]];
			}
		}
	}
}
int main(){
	int W,n;
	cin>>W>>n;
	vector<int> bars(n);
	for (int i =0; i<n; ++i){
		cin >> bars[i];
	}
	vector<vector<int>> matrix(n);
	fill_matrix(matrix,W,bars);
	 /*for(int i=0;i<n;++i){
		for(int j =0; j<=W; ++j){
			cout<<matrix[i][j]<<" ";
		}
		cout<<endl;
	}*/
	cout<<matrix[n-1][W];
	return 0;
}