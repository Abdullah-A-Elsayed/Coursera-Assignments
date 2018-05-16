#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip> //use double <<fixed<<setprecision(4)
using namespace std;


void printMaxSalary(vector<int> &nums){
	vector<int> sortedToFirstDigit(nums.size());
	for (int j =0 ; j<sortedToFirstDigit.size() ; ++j){
		int maxIndex = 0;
		int maxFirstDigit;
		if(nums[0] >= 100){
			maxFirstDigit = (nums[0]-(nums[0]%100))/100;
		}
		else if(nums[0] >= 10){
			maxFirstDigit = (nums[0]-(nums[0]%10))/10;
		}
		else{
			maxFirstDigit = nums[0];
		}
		for(int i =1 ; i<nums.size() ; ++i){
			int fDigit;
			if(nums[i] >= 100){
				fDigit = (nums[i]-(nums[i]%100))/100;
			}
			else if(nums[i] >= 10){
				fDigit = (nums[i]-(nums[i]%10))/10;
			}
			else{
				fDigit = nums[i];
			}
			if(fDigit > maxFirstDigit){
				maxIndex = i;
				maxFirstDigit = fDigit;
			}
		}
		sortedToFirstDigit[j] = nums[maxIndex];
		nums.erase(nums.begin()+maxIndex);
	}
	for(int i=0; i<sortedToFirstDigit.size();++i){
		cout<<sortedToFirstDigit[i];
	}
}

int main(){
	int n;
	cin>>n; // n: count
	vector<int> numbers(n);
	for(int i=0; i<n ; ++i){
		cin>>numbers[i];
	}
	printMaxSalary(numbers);
	return 0;
}