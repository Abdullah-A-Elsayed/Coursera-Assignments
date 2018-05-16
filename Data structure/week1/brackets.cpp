#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <string>
#include <list>
#include <stack>
#include <queue>
using namespace std;

int main(){
	string input;
	getline(cin, input);
	stack<vector<char>> bracks;
	int done = 0;
	for(int i=0; i<input.length() ; i++){
		char x = input[i];
		if(x == '(' || x == '{' || x == '[' || x == ']' || x == '}' || x == ')' ){  // is bracket
			if(x == '(' || x == '{' || x == '[' ){									//opening bracket
				vector<char> stack_in(2);
				stack_in[0] = x;
				stack_in[1] = i + '1';
				bracks.push(stack_in);
			}
			else{																	//closing bracket
				if(!bracks.empty()){ //filled
					if ((x==']'&& bracks.top()[0]!='[') || (x==')'&& bracks.top()[0]!='(') || (x=='}'&& bracks.top()[0]!='{') ){	//not match											// not_match
						cout<<i+1; done =1 ;break;
					}
					else{  //match
						bracks.pop();
					}
				}
				else{
					cout<<i+1; done =1 ;break;
				}
			}
		}
	}
	if(!done){
		if(bracks.empty()) cout<<"Success"<<endl;
		else cout<<bracks.top()[1]<<endl;
	}
return 0;
}