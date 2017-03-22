#include <iostream>
#include <vector>
using namespace std;
//Give n , find last digit of sum(Fn). Could be huge!
int fibonacci_sum(long long n) {
    if (n <= 1)
        return n;
    //int sum0 = 0, sum1 = 1;
    int fn0 = 0, fn1 =1;
    int lastSum = 1;
    int sum;
    int pattern = n %60;//period
    for(int i = 2; i<=pattern; i++){
        int fn  = (fn0+fn1)%10;
        sum = (lastSum + fn) % 10;
        lastSum = sum;
        fn0 = fn1;
        fn1 = fn;
    }
    return sum;
}

int main() {
    long long n = 0;
    std::cin >> n;
    std::cout << fibonacci_sum(n);
}
