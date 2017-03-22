#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#if defined(__unix__) || defined(__APPLE__)
#include <sys/resource.h>
#endif

using namespace std;
/*
Tree traverse: inorder , preorder ,postorder
5
4 1 2
2 3 4
5 -1 -1
1 -1 -1
3 -1 -1
Output:
1 2 3 4 5
4 2 1 3 5
1 3 2 5 4
*/
class TreeOrders {
  int n;
  vector <int> key;
  vector <int> left;
  vector <int> right;

public:
  void read() {
    cin >> n;
    key.resize(n);
    left.resize(n);
    right.resize(n);
    for (int i = 0; i < n; i++) {
      cin >> key[i] >> left[i] >> right[i];
    }
  }

//inorder: push all left, pop and move to right branch
  vector <int> in_order() {
    vector<int> result;
    stack<int> nstack;
    int index = 0;//root is 0
    while (1){
      if (index != -1){
        nstack.push(index);
        index = left[index];
      }

      else{
        if (!nstack.empty()){
          int popIndex = nstack.top();
          result.push_back(key[popIndex]);
          nstack.pop();
          index = right[popIndex];
        }
        else
          break;
      }
    }
    return result;
  }
//preorder:push root first then pop to push r->right and r->left, 
  //add r to result list
  vector <int> pre_order() {
    vector<int> result;
    // Finish the implementation
    // You may need to add a new recursive method to do that
    stack<int> nstack;
    int index = 0;//root is 0
    nstack.push(index);
    while (!nstack.empty()){
      index = nstack.top();
      nstack.pop();
      int recordIndex = index;
      //nstack.push(recordIndex);
      if (right[recordIndex] != -1)//push right
      {
        index = right[recordIndex];
        nstack.push(index);
      }
      result.push_back(key[recordIndex]);
      if (left[recordIndex] != -1)//push left
      {
        index = left[recordIndex];
        nstack.push(index);
      }
    }
    return result;
  }
//push right and self to move to the most left node
//output the left move to right while push self back to stack
//until go to the left end of right child 
  vector <int> post_order() {
    vector<int> result;
    // Finish the implementation
    // You may need to add a new recursive method to do that
    stack<int> nstack;
    int index = 0;//root is 0
    do{
      while (index != -1){
        if (right[index] != -1) //right not empty, push right and self then move left
          nstack.push(right[index]);
          nstack.push(index);
          index = left[index];
      }
      index = nstack.top();
      nstack.pop();
      if (!nstack.empty() && right[index] == nstack.top()){ //get right and push self back
        nstack.pop();
        nstack.push(index);
        index = right[index];
      }
      else{//no child and 
        result.push_back(key[index]);
        index = -1;
      }
    } while (!nstack.empty());
    return result;
  }
};

void print(vector <int> a) {
  for (size_t i = 0; i < a.size(); i++) {
    if (i > 0) {
      cout << ' ';
    }
    cout << a[i];
  }
  cout << '\n';
}

int main_with_large_stack_space() {
  ios_base::sync_with_stdio(0);
  TreeOrders t;
  t.read();
  print(t.in_order());
  print(t.pre_order());
  print(t.post_order());
  return 0;
}

int main(int argc, char **argv)
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

