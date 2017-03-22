#include <algorithm>
#include <sstream>
#include <iostream>
#include <vector>
#include <string>
//give a series of number strings,
//find the largest number the strings could provide
using namespace std;

bool IsGreaterOrEqual(string a, string b){
  return a+b>=b+a;
}
string largest_number(vector<string> a) {
  //write your code here
  string result;
  string maxDigit;
  int pos;
  int n = a.size();
  if(n==0)return 0;
  while(!a.empty()){    
    pos = 0;
    maxDigit = a[0];
    for(int i=1;i<n;i++){
       if(IsGreaterOrEqual(a[i], maxDigit)){
          maxDigit = a[i];
          pos = i;
       }
    }
    result.append(maxDigit);
    a.erase (a.begin()+pos);
    n--;
  }
  if(result[0] == '0') result = "0";
  return result;
}

int main() {
  int n;
  std::cin >> n;
  vector<string> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  std::cout << largest_number(a);
}
