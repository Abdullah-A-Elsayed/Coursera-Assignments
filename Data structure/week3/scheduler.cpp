#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
struct core{
	int id;
	long long work;
};

struct compare{ //to be used for sift_down in priority queue
	bool operator()(core& a, core& b){
		if(a.work == b.work) return a.id > b.id;
		if(a.work < b.work) return false;//don't swap
		return true;
	}
};

class scheduler{
private:
	queue<int> times;
	vector<int> cores;
	vector<long long> info;
	int current_time;
public:
	scheduler(int n, queue<int> ts){
		times = ts;
		for(int i=0; i<n ; ++i){
			cores.push_back(0);
		}
		current_time = 0;
	}
	void run(){
		while(times.size()){
			for(int i=0; i<cores.size(); i++){
				if(cores[i]>0) cores[i]--;
				if(cores[i]==0){//assign program
					if(times.size()==0) break;
					cores[i]= times.front();
					times.pop();
					info.push_back(i);
					info.push_back(current_time);
				}
			}
			current_time++;
		}
	}
	void run_v_2(){//using heap sort
		//initializing cores
		priority_queue<core, vector<core>, compare> cores_heap;
		for(int i=0; i<cores.size(); ++i){
			core c;
			c.id = i;
			c.work =0;
			cores_heap.push(c);
		}
		//programs sched..
		while(times.size()){
			int program_d = times.front();
			times.pop();
			core next = cores_heap.top();
			info.push_back(next.id);
			info.push_back(next.work);
			next.work+=program_d;
			//reArranging heap
			cores_heap.pop();
			cores_heap.push(next);
		}
	}

	void print_processes(){
		for(int i=0; i<info.size(); i+=2){
			cout<<info[i]<<" "<<info[i+1]<<endl;
		}
		cout<<endl;
	}
};

int main(){
	int n,m; //threads number, jobs number.
	cin>>n>>m;
	queue<int> times;
	int temp;
	for(int i=0; i<m; ++i){
		cin>>temp;
		times.push(temp);
	}
	scheduler jobs(n,times);
	jobs.run_v_2();
	jobs.print_processes();
	return 0;
}