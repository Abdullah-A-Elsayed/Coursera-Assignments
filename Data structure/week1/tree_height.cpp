#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <string>
#include <list>
#include <stack>
#include <queue>
using namespace std;
struct node{
	int father;
	vector<int> childs;
	int id;
	int height;
};
int root_and_childing(vector<node> &nodes){
	int root;
	for(int i =0;i<nodes.size();++i){
		nodes[i].height = 1;
		if (nodes[i].father == -1) root = i; //i = node id
		else nodes[nodes[i].father].childs.push_back(i); // adding node as a child in the father
	}
	return root;
}

int get_height(int root, vector<node> &nodes){ // can be improved by traveling on leaves only but still bad
	int max_height = 1;
	for(int i=0; i<nodes.size(); ++i){
		if(i!=root){ // child node
			int height = 2;
			node now = nodes[i];
			while(now.father!=root){
				height ++;
				now = nodes[now.father];
			}
			max_height = (max_height > height)? max_height : height;
		}
	}
	return max_height;
}

int get_height_v2(int root, vector<node> &nodes){
	int max_height = 1;
	for(int i=0; i<nodes.size(); ++i){
		if(!nodes[i].childs.size()){ // have no childs
			int height = 2;
			node now = nodes[i];
			while(now.father!=root){ //calculating height
				height ++;
				now = nodes[now.father];
			}
			max_height = (max_height > height)? max_height : height;
		}
	}
	return max_height;
}

int get_height_v3(int root, vector<node> &nodes){
	
	for(int i=0; i<nodes.size(); ++i){
		if(!nodes[i].childs.size()){ // have no childs
			int height = nodes[i].height;
			int next = nodes[i].father;
			while(1){
				if(nodes[next].height >= (height+1)) break;
				else{
					nodes[next].height = height+1;
					height = nodes[next].height;
					//if current fathrer is the root break
					if(nodes[next].id == root) break;
					next = nodes[next].father;
				}
			}
		}
	}
	return nodes[root].height;
}

int get_height_recursion(vector<node> &nodes , node current){
	if(!current.childs.size()) return 1;
	int max_height = 1;
	int height;
	for(int i =0; i < current.childs.size() ;  ++i){
	 height = get_height_recursion(nodes , nodes[current.childs[i]]) + 1;
	 // 1 branch done
	 max_height = (max_height > height)? max_height : height;
	}
	return max_height;
}

int main(){
	//guaranteed 1 root.
	int n;
	cin>>n;
	vector<node> nodes(n);
	for(int i =0; i<n; ++i){
		nodes[i].id= i;
		cin >> nodes[i].father;
	}
	int root = root_and_childing(nodes);
	cout<<get_height_v3( root, nodes);
return 0;
}