#include <iostream>
//find greatest common divisor of(n,m)， 辗转相除法
int gcd_naive(int a, int b) {
  int current_gcd = 1;
  for (int d = 2; d <= a && d <= b; d++) {
    if (a % d == 0 && b % d == 0) {
      if (d > current_gcd) {
        current_gcd = d;
      }
    }
  }
  return current_gcd;
}
int gcd(int a, int b){
  if(a<b) return gcd(b,a);
  if(b == 0) return a;
  while(b!=0){
    int reminder = a%b;
    a = b;
    b = reminder;
  }
  return a;
}

int main() {
  int a, b;
  std::cin >> a >> b;
  //std::cout << gcd_naive(a, b) << std::endl;
  std::cout << gcd(a, b) << std::endl;
  return 0;
}
