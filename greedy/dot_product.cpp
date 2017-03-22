#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;
//given two sequence A(a1,a2, ... an) and B(b1,b2...bn).Make them to pairs (ai,bj) and maximum the sum of those ai*bj 
//Input: n
//...... a1 a2..an
//       b1 b2...bn
long long max_dot_product(vector<int> a, vector<int> b) {
  // write your code here
  long long result = 0;
  sort(begin(a),end(a));
  sort(begin(b),end(b));
  for (size_t i = 0; i < a.size(); i++) {
    result += ((long long) a[i]) * b[i];
  }
  return result;
}

int main() {
  size_t n;
  std::cin >> n;
  vector<int> a(n), b(n);
  for (size_t i = 0; i < n; i++) {
    std::cin >> a[i];
  }
  for (size_t i = 0; i < n; i++) {
    std::cin >> b[i];
  }
  std::cout << max_dot_product(a, b) << std::endl;
}
