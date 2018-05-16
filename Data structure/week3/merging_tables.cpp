#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::max;
using std::vector;

struct DisjointSetsElement {
	int size, parent, rank;//size: number of real rows in one table
	
	DisjointSetsElement(int size = 0, int parent = -1, int rank = 0):
	    size(size), parent(parent), rank(rank) {}
};

struct DisjointSets {
	int size; //number of sets
	int max_table_size; //number of real elements in one table
	vector <DisjointSetsElement> sets;

	DisjointSets(int size): size(size), max_table_size(0), sets(size) {
		for (int i = 0; i < size; i++)
			sets[i].parent = i;// make set for each table
	}

	int getRoot(int table) {
		// find root and compress path
		if(sets[table].parent == table) return table;

		sets[table].parent = getRoot(sets[table].parent);
		return sets[table].parent;
		//what about rank? how to decrease?
	}

	void merge(int destination, int source) {
		int realDestination = getRoot(destination);
		int realSource = getRoot(source);
		if (realDestination != realSource) {//very important!!!
			// merge two components
			// use union by rank heuristic
			 // update max_table_size
			if(sets[realDestination].rank<sets[realSource].rank){
					//copy data
					sets[realSource].size+=sets[realDestination].size;
					sets[realDestination].size =0;
					// join
					sets[realDestination].parent = realSource;
					//max_size
					max_table_size = max(max_table_size, sets[realSource].size);
			}
			else{
				//copy data
					sets[realDestination].size+=sets[realSource].size;
					sets[realSource].size =0;
					// join
					sets[realSource].parent = realDestination;
					if(sets[realDestination].rank==sets[realSource].rank) sets[realDestination].rank+=1;
					//max_size
					max_table_size = max(max_table_size, sets[realDestination].size);
			}
		}		
	}
};

int main() {
	int n, m;
	cin >> n >> m;
	vector<int> output(m);
	DisjointSets tables(n);
	for (auto &table : tables.sets) {
		cin >> table.size;
		tables.max_table_size = max(tables.max_table_size, table.size);
	}

	for (int i = 0; i < m; i++) {
		int destination, source;
		cin >> destination >> source;
		// 1 to 0 indexed
                --destination;
                --source; 
		
		tables.merge(destination, source);
		output[i] = tables.max_table_size;
	}

	for(int i=0; i<m; ++i) cout << output[i] << endl;

	return 0;
}
