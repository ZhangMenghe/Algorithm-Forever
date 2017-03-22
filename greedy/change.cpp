#include <iostream>
//change money with 1, 5,10,could use greedy in this way
int get_change(int m) {
  //write your code here
  int n = m/10;
  int five = (m-n*10)/5;
  int one  = m-n*10-five*5;
  n+=five+one;
  return n;
}

int main() {
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}
