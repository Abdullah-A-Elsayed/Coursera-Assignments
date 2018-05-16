#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip> //use double <<fixed<<setprecision(4)
using namespace std;
void dividePrizes(int n, vector<int> &prizes){
	prizes.push_back(1);
	n-=1;
	while(n > 0){
		if (n > prizes[prizes.size()-1]){
			prizes.push_back(prizes[prizes.size()-1]+1);
			n-= prizes[prizes.size()-1];
		}
		else{
			prizes[prizes.size()-1]+= n;
			n = 0;
		}
	}
}

int main(){
	int n;
	cin>>n; // n: count
	vector<int> prizes;
	dividePrizes(n,prizes);
	cout<<prizes.size()<<endl;
	for(int i=0; i<prizes.size() ; ++i){
		cout<<prizes[i]<<" ";
	}
	return 0;
}