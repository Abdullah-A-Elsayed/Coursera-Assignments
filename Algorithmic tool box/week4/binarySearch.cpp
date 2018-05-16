#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip> //use double <<fixed<<setprecision(4)
using namespace std;
int binarySearch(vector<int> &nums,int start,int end, int key){
	if(start>end) return -1;
	//code
	int mid = start + (end - start)/2;
	if(nums[mid] == key) return mid;
	if(key > nums[mid]){
		return binarySearch(nums,mid+1,end,key);
	}
	else{
		return binarySearch(nums,start,mid-1,key);
	}
}
int main(){
	int n;
	cin>>n; // n: count
	vector<int> numbers(n);
	for(int i=0; i<n ; ++i){
		cin>>numbers[i];
	}
	int k;
	cin>>k; // n: count
	vector<int> keys(k);
	for(int i=0; i<k ; ++i){
		cin>>keys[i];
	}

	for(int i=0; i<k ; ++i){
		int key_index;
		key_index = binarySearch(numbers,0,n-1,keys[i]);
		cout << key_index <<" ";
	}
	return 0;
}