#include <iostream>
//find least common Multiple 最大公倍数 = m*n/gcd(m,n)
long long lcm_naive(int a, int b) {
  for (long l = 1; l <= (long long) a * b; ++l)
    if (l % a == 0 && l % b == 0)
      return l;

  return (long long) a * b;
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
long long lcm(int a, int b){
	int divisor = gcd(a,b);
	return (long long )a *b/divisor;
}

int main() {
  int a, b;
  std::cin >> a >> b;
  //std::cout << lcm_naive(a, b) << std::endl;
  std::cout << lcm(a, b) << std::endl;
  return 0;
}
