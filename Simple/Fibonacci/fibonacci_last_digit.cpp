#include <iostream>
#include <vector>
using namespace std;
//Given n, find last digit of fibonacci
int get_fibonacci_last_digit(int n) {
    if (n <= 1)
        return n;
    vector<int> flast(n+1);
    flast[0] = 0, flast[1] = 1;
    for(int i = 2; i<=n; i++){
        flast[i] = (flast[i-1] + flast[i-2]) % 10;//store only last digit
    }
    return flast[n];
}

int main() {
    int n;
    std::cin >> n;
    int c = get_fibonacci_last_digit(n);
    std::cout << c << '\n';
    }
