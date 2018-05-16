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
int check_candidate(int candidate, vector<int> &nums, int start, int end){
	if(candidate == -1) return -1;
	int count = 0;
	for (int i=start; i<= end; ++i){
		if(nums[i] == candidate) ++count;
	}
	if (count > (end-start+1)/2) return candidate;
	else return -1;
}
int find_majority(vector<int> &nums, int start, int end){
	if (start == end) return nums[start];
	int mid = start + (end-start)/2;
	int candidate_l = find_majority(nums, start, mid);
	int candidate_r = find_majority(nums, mid+1, end);
	int verify_l = check_candidate(candidate_l, nums, start, end);
	int verify_r = check_candidate(candidate_r, nums, start, end);
	if(verify_l!=-1) return verify_l;
	if(verify_r!=-1) return verify_r;
	return -1;
}
int majority_casting( vector<int> &nums){
	int res = find_majority(nums, 0, nums.size()-1);
	if(res == -1) return 0;
	return 1;
}
int main(){
	int n;
	cin>>n; // n: count
	vector<int> numbers(n);
	for(int i=0; i<n ; ++i){
		cin>>numbers[i];
	}
	cout << majority_casting(numbers);
	return 0;
}