#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <string>
#define matrix vector<vector<int>>
using namespace std;

void createNumAndOp(vector<int> &nums, vector<char> &ops,string line){
	int num_chars = line.length();
	for(int i =0; i<num_chars ; ++i){
		(i%2==0)? /* num*/ nums.push_back(line[i]-'0') : ops.push_back(line[i]);
	}
}

int operate(int a, char op, int b){
	int r;
	r = (op == '+')? a+b : (op == '-')? a-b : (op == '*')? a*b : (op == '/')? a/b : 0;
	return r;
}

bool Mgreater(int a, int b){
	return a>b;
}
void min_max (vector<int> &vals , vector<int> &results){ //0 min , las > max
	sort(vals.begin(),vals.end(), Mgreater);
	results.push_back(vals[vals.size()-1]);
	results.push_back(vals[0]);
}

void fillMinMatrixAndMax( matrix &min , matrix &max , vector<int> &nums , vector<char> &ops){
	for(int i = 0; i<nums.size(); ++i){ //filling zeros
		for(int j = 0; j < nums.size(); ++j){
			min[i].push_back(0);
			max[i].push_back(0);
		}
	}
	for(int i = 0; i<nums.size(); ++i){ //nums in first diagonal
		min[i][i] = nums[i];
		max[i][i] = nums[i];
	}
	// upper diagonals
	for(int diff = 1; diff<nums.size(); ++diff){
		for(int i =0; i<nums.size()-diff ; ++i){
			int j = i + diff;
			vector<int> max_possibleWays;
			vector<int> min_possibleWays;
			for(int op =i; op<j; ++op){
				vector<int> possible_op;
				vector<int> op_min_max;
				possible_op.push_back(operate(min[i][op],ops[op],min[op+1][j]));
				possible_op.push_back(operate(max[i][op],ops[op],max[op+1][j]));
				possible_op.push_back(operate(min[i][op],ops[op],max[op+1][j]));
				possible_op.push_back(operate(max[i][op],ops[op],min[op+1][j]));
				min_max(possible_op,op_min_max);
				max_possibleWays.push_back(op_min_max[1]);
				min_possibleWays.push_back(op_min_max[0]);
			}
			vector<int> MAXminAndmax;
			vector<int> MINminAndmax;
			min_max(min_possibleWays,MINminAndmax);
			min_max(max_possibleWays,MAXminAndmax);
			// end of i means item about to be filled
			min[i][j] = MINminAndmax[0];
			max[i][j] = MAXminAndmax[1];
			
		}
	}
}
int main(){
	string line;
	cin>>line;
	vector<int> nums;
	vector<char> ops;
	createNumAndOp(nums,ops,line);
	matrix min(nums.size()), max(nums.size());
	fillMinMatrixAndMax(min,max,nums,ops);
	for(int i = 0; i<nums.size(); ++i){ 
		for(int j = 0; j<nums.size(); ++j){
			cout << max[i][j] << "  ";
		}
		cout<<endl;
	}
	return 0;
}