#include <iostream>
#include <vector>

using std::vector;
//given n, output a1 a2 a3...an such that sum(a) = n and a are distinct
// maximized #a
vector<int> optimal_summands(int n) {
  vector<int> summands;
  //write your code here
  if(n<=2){
    summands.push_back(n);
    return summands;
  } 
  int l=1;
  while(n>2*l){
    summands.push_back(l);
    n-=l;
    l++;
    
  }
  summands.push_back(n);
  return summands;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> summands = optimal_summands(n);
  std::cout << summands.size() << '\n';
  for (size_t i = 0; i < summands.size(); ++i) {
    std::cout << summands[i] << ' ';
  }
}
