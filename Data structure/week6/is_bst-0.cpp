#include <iostream>
#include <vector>
#include <algorithm>
#if defined(__unix__) || defined(__APPLE__)
#include <sys/resource.h>
#endif

using std::vector;
using std::ios_base;
using std::cin;
using std::cout;

class TreeOrders {
  int n;
  int ri;
  vector <long long> key;
  vector <int> left;
  vector <int> right;
  vector<long long> result;
public:
  void read() {
    cin >> n;
    key.resize(n);
    left.resize(n);
    right.resize(n);
	//root set up
	vector<bool> is_root (n,true);
	//
    for (int i = 0; i < n; i++) {
      cin >> key[i] >> left[i] >> right[i];
	  if(left[i]!=-1) is_root[left[i]] = false;
	  if(right[i]!=-1) is_root[right[i]] = false;
    }
	//find root
	for (int i = 0; i < n; i++) {
      if(is_root[i]==true){
		  ri = i;
		  break;
	  }
    }
  }
/* ----------------------------- in -------------------------------*/
  void in(int ni){
	  if(left[ni]!=-1) in(left[ni]);
	  result.push_back(key[ni]);
	  if(right[ni]!=-1) in(right[ni]);
  }
  vector <long long> in_order() {
	result.clear();
	if(n!=0) in(ri);
    return result;
  }
/*------------------------------- pre -------------------------------*/
  void pre(int ni){
	  result.push_back(key[ni]);
	  if(left[ni]!=-1) pre(left[ni]);
	  if(right[ni]!=-1) pre(right[ni]);
  }
  vector <long long> pre_order() {
    result.clear();
	if(n!=0)pre(ri);
    return result;
  }
/* -------------------------- post -------------------------------------*/
  void post(int ni){
	  if(left[ni]!=-1) post(left[ni]);
	  if(right[ni]!=-1) post(right[ni]);
	  result.push_back(key[ni]);
  }
  vector <long long> post_order() {
    result.clear();
	if(n!=0)post(ri);
    return result;
  }
/* ---------------------------------------------------------------------*/
};

void print(vector <long long> a) {
  for (size_t i = 0; i < a.size(); i++) {
    if (i > 0) {
      cout << ' ';
    }
    cout << a[i];
  }
  cout << '\n';
}

bool check_BST (vector<long long> in_){
	for(int i=1; i<in_.size(); ++i){
		if(in_[i]<in_[i-1]) return false;
	}
	return true;
}
int main_with_large_stack_space() {
  ios_base::sync_with_stdio(0);
  TreeOrders t;
  t.read();
  vector<long long> in_order = t.in_order();
  if(check_BST(in_order)) cout <<"CORRECT"<<std::endl;
  else cout <<"INCORRECT"<<std::endl;
  //print(t.pre_order());
  //print(t.post_order());
  return 0;
}

int main (int argc, char **argv)
{
#if defined(__unix__) || defined(__APPLE__)
  // Allow larger stack space
  const rlim_t kStackSize = 16 * 1024 * 1024;   // min stack size = 16 MB
  struct rlimit rl;
  int result;

  result = getrlimit(RLIMIT_STACK, &rl);
  if (result == 0)
  {
      if (rl.rlim_cur < kStackSize)
      {
          rl.rlim_cur = kStackSize;
          result = setrlimit(RLIMIT_STACK, &rl);
          if (result != 0)
          {
              std::cerr << "setrlimit returned result = " << result << std::endl;
          }
      }
  }
#endif

  return main_with_large_stack_space();
}