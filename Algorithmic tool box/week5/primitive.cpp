#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <string>
using namespace std;
int minSeq(int n , vector<int> &actualSeq){
	vector<int> mins(n+1);
	mins[1] = 0; //1 -> 0 (0 digits written after 1)
	if(n==1){actualSeq.push_back(1);return mins[n];}
	vector<string> steps; //length will be n+1
	steps.push_back("empty");
	steps.push_back("done");
	for(int i = 2; i<= n; ++i){
		mins[i] = (1+mins[i-1]);
		steps.push_back("sub");
		if(i%2==0){
			if(1+mins[i/2]<mins[i]){
				mins[i] = 1+mins[i/2];
				steps[i]="div2";
			}
		}
		if(i%3==0){
			if(1+mins[i/3]<mins[i]){
				mins[i] = 1+mins[i/3];
				steps[i]="div3";
			}
		}
	}
	actualSeq.push_back(n);
	int i =n;
	while(i>=1){
		if(steps[i] == "sub"){
			i-=1;
			actualSeq.insert(actualSeq.begin(),i);
		}
		else if(steps[i] == "div2"){
			i/=2;
			actualSeq.insert(actualSeq.begin(),i);
		}
		else if(steps[i] == "div3"){
			i/=3;
			actualSeq.insert(actualSeq.begin(),i);
		}
		else {
			break;
		}
	}
	return mins[n];
}
int main(){
	int n;
	cin>>n;
	vector<int> actualSeq;
	int min = minSeq(n,actualSeq);
	cout<<min<<endl;
	for(int i =0; i<=min; ++i){
		cout<<actualSeq[i]<<" ";
	}
	return 0;
}