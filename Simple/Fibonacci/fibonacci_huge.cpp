#include <iostream>
#include <vector>
using namespace std;
//Given n,m find Fn mod m. N could be huge!!!
int getPeriodNumber(long long m){
    //Pisano period pi(p^k)= p^(k-1) * pi(p)
    long long result = 2;
    for (long long fn2 = 1, fn1 = 2, fn = 3; fn1 != 1 || fn != 1;fn2 = fn1, fn1 = fn, fn = (fn1 + fn2) % m) 
    {
        result++;
    }
    return result;
}
long long get_fibonacci_huge_naive(long long n, long long m) {
    if (n <=1 )
        return n;
    int numberperiod = getPeriodNumber(m);
    int patternNum = n % numberperiod;
    vector<int> sum(patternNum+1);
    sum[0] = 0, sum[1] = 1;

    for(int i =2; i<=patternNum; i++){
        sum[i] = (sum[i-1] + sum[i-2])%m;
    }
    return sum[patternNum] ;
}

int main() {
    long long n, m;
    std::cin >> n >> m;
    std::cout << get_fibonacci_huge_naive(n, m) << '\n';
}
