#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip> //use double <<fixed<<setprecision(4)
using namespace std;

bool howToSort(vector<int> &a, vector<int> &b){
	return a[1]<b[1]; //minimum end
}
void getMinPoints(vector<vector<int>> &segments, vector<int> &points){
	int i =0;
	while(i<segments.size()){
		points.push_back(segments[i][1]);
		i+=1;
		while(i<segments.size()&&(segments[i][0]<=points[points.size()-1])){
			i+=1;
		}
	}
}

int main(){
	int n;
	cin>>n; // n: count
	vector<vector<int>> segments(n);
	// inputs
	for(int i=0;i<n;++i){
		int firstPoint,secPoint;
		cin>>firstPoint>>secPoint;
		segments[i].push_back(firstPoint);
		segments[i].push_back(secPoint);
	}
	sort(segments.begin(),segments.end(),howToSort);
	vector<int> points;
	getMinPoints(segments,points);
	cout<<points.size()<<endl;
	for(int i =0; i<points.size(); ++i){
		cout<<points[i]<<" ";
	}
	return 0;
}