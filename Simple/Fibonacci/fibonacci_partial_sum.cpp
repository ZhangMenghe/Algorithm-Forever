#include <iostream>
#include <vector>
using std::vector;

long long get_fibonacci_partial_sum_naive(long long from, long long to) {
    if (to <= 1)
        return to;

    long long previous = 0;
    long long current  = 1;

    for (long long i = 0; i < from - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
    }

    long long sum = current;

    for (long long i = 0; i < to - from; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
        sum += current;
    }

    return sum % 10;
}
long long get_fibonacci_partial_sum(long long from, long long to) {
    if (to <= 1)
        return to;
    long long n = to - from + 1;

    int lastSum, sum;
    
    int fn0 = 0, fn1 =1, fn;
    int fpattern = from%60;
    for(int i=2; i<=fpattern; i++){
        fn  = (fn0+fn1) % 10;
        fn0 = fn1;
        fn1 = fn;
    }
    lastSum =sum= fn1; //from
    int pattern = n %60;//period
    for(int i = 1; i<pattern; i++){
        int fn  = (fn0+fn1)%10;
        sum = (lastSum + fn) % 10;
        lastSum = sum;
        fn0 = fn1;
        fn1 = fn;
    }
    return sum;
}

int main() {
    long long from, to;
    std::cin >> from >> to;
    //std::cout << get_fibonacci_partial_sum_naive(from, to) << '\n';
    std::cout << get_fibonacci_partial_sum(from, to) << '\n';
}
