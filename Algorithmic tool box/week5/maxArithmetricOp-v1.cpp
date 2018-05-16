#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <string>
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

void fillMinMatrixAndMax( vector<vector<int>> &min , vector<vector<int>> &max , vector<int> &nums , vector<char> &ops){
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
	for(int diff = 1; diff < nums.size(); ++diff){
		for(int i =0; i < nums.size()-diff ; ++i){
			int j = i + diff;
			vector<int> possibleWays;
			for(int op =i; op<j; ++op){
				possibleWays.push_back(operate(min[i][op],ops[op],min[op+1][j]));
				possibleWays.push_back(operate(max[i][op],ops[op],max[op+1][j]));
				possibleWays.push_back(operate(min[i][op],ops[op],max[op+1][j]));
				possibleWays.push_back(operate(max[i][op],ops[op],min[op+1][j]));
			}
			vector<int> minAndmax;
			min_max(possibleWays,minAndmax);
			// end of i means item about to be filled
			min[i][j] = minAndmax[0];
			max[i][j] = minAndmax[1];
			
		}
	}
}

int getMax(vector<vector<int>> &m){
	return m[0][m[0].size()-1];
}
int main(){
	string line;
	cin>>line;
	vector<int> nums;
	vector<char> ops;
	createNumAndOp(nums,ops,line);
	vector<vector<int>> min(nums.size()), max(nums.size());
	fillMinMatrixAndMax(min,max,nums,ops);
	//cout<<getMax(max);
	for(int i = 0; i<nums.size(); ++i){ 
		for(int j = 0; j<nums.size(); ++j){
			cout << min[i][j] << "  ";
		}
		cout<<endl;
	}
	return 0;
}