#include <iostream>
#include <string>
#include <vector>
using namespace std;
class minHeap {
private:
	vector<int> nums;
	void sift_up(int index){
		int father = this->father(index);
		if (father == -1) return;
		if(nums[father] > nums[index]){
			swaps.push_back(father);
			swaps.push_back(index);
			swap(index,father);
			sift_up(father);
		}
		else{
			return;
		}
	}
	void sift_down(int i){
		int lsi = left_son(i);
		int rsi = right_son(i);
		//geting minimum
		int min_i = i;
		if(lsi!=-1){
			if(nums[lsi]<nums[min_i]) min_i = lsi;
		}
		if(rsi!=-1){
			if(nums[rsi]<nums[min_i]) min_i = rsi;
		}
		//swapping
		if(min_i!=i){
			swap(i,min_i);
			swaps.push_back(i);
			swaps.push_back(min_i);
			sift_down(min_i);
		}
	}
	void swap(int index1 , int index2){
		int t = nums[index1];
		nums[index1] = nums[index2];
		nums[index2] = t;
	}
public:
	vector<int> swaps;
	minHeap(vector<int> ns){
		nums = ns;
	}
	int father (int son_index){ // index to index
		if(son_index !=0) return (son_index-1)/2;
		return -1; //no father
	}
	int left_son (int father_index){ 
		int i = 2*father_index+1;
		if(i < nums.size()) return i;
		return -1; //indicating that it has no sons
	}
	int right_son (int father_index){ //working on positive integers only
		int i = 2*father_index+2;
		if(i < nums.size()) return i;
		return -1; //indicating that it has no sons
	}
	void make_heap (){
		for(int i = father(nums.size()-1); i>-1; --i){
			sift_down(i);
		}
	}
	void print_swaps(){
		cout<<swaps.size()/2<<endl;
		for(int i=0; i<swaps.size();i+=2){
			cout<<swaps[i]<<" "<<swaps[i+1]<<endl;
		}
	}
	void print_linear_swaps(){
		for(int i=0; i<swaps.size();i+=1){
			cout<<swaps[i]<<" ";
		}
		cout<<endl;
	}
	void print_heap(){
		for(int i=0; i<nums.size();++i){
			cout<<nums[i]<<" ";
		}
		cout<<endl;
	}
};
int main(){
	int n;
	cin>>n;
	//reading array
	vector<int> nums(n);
	for(int i=0; i<n; ++i){
		cin>>nums[i];
	}
	minHeap heap(nums);
	heap.make_heap();
	heap.print_swaps();
	return 0;
}