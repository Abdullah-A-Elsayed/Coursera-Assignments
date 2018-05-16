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

struct node{
  int id,left,right;
  long long key;
  node(int idd, int leftt, int rightt, long long keyy){
    left = leftt;
    id = idd;
    right = rightt;
    key = keyy;
  }
};
class TreeOrders {
  int n;
  int ri;
  vector <long long> key;
  vector <int> left;
  vector <int> right;
  vector<node> result;
public:
  long long min,max;
  void read() {
    cin >> n;
    key.resize(n);
    left.resize(n);
    right.resize(n);
  //root set up
  //vector<bool> is_root (n,true);
  //
    for (int i = 0; i < n; i++) {
      cin >> key[i] >> left[i] >> right[i];
    if(i==0){min = max = key[i];}
    else{
      if(key[i] < min ) min = key [i];
      if (key[i] > max) max = key[i];
    }
    //if(left[i]!=-1) is_root[left[i]] = false;
    //if(right[i]!=-1) is_root[right[i]] = false;
    }
  //find root
  /*for (int i = 0; i < n; i++) {
      if(is_root[i]==true){
      ri = i;
      break;
    }
    }*/
  }

bool isBST(int id, long long min, long long max) //worked
{ 
  /* an empty tree is BST */
  if (id==-1 || n ==0 ) 
     return 1;

  /* false if this node violates the min/max constraint */ 
  if (key[id] < min || key[id] > max) 
     return 0; 

  /* otherwise check the subtrees recursively, 
   tightening the min or max constraint */
  return
    isBST(left[id], min, key[id] - 1 ) &&  /*left smaller*/
    isBST(right[id], key[id], max);  /*right can equal or greater*/
} 

/* ----------------------------- in -------------------------------*/
  void in(int ni){
    if(left[ni]!=-1) in(left[ni]);
    result.push_back(node(ni,left[ni],right[ni],key[ni]));
    if(right[ni]!=-1) in(right[ni]);
  }
  vector <node> in_order() {
  result.clear();
  if(n!=0) in(ri);
    return result;
  }
  /* ---------------------------------------------------------------*/
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

bool check_BST (vector<node> in_){//failed for unknown test case!!
  /*
    duplicated keys should exist as right children
  */
  for(int i=1; i<in_.size(); ++i){
    if(in_[i].key<in_[i-1].key) return false;
    if(in_[i].key==in_[i-1].key){
      if(!(in_[i-1].right==in_[i].id)) return false;
    }
  }
  return true;
}
int main_with_large_stack_space() {
  ios_base::sync_with_stdio(0);
  TreeOrders t;
  t.read();
 // vector<node> in_order = t.in_order();
  //if(check_BST(in_order)) cout <<"CORRECT"<<std::endl;
 // else cout <<"INCORRECT"<<std::endl;

if(t.isBST(0,t.min,t.max)) cout <<"CORRECT"<<std::endl;
else cout <<"INCORRECT"<<std::endl;
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