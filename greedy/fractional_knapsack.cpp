#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
//input: n,m as the number of items and capacity 
//       each line following: value[i], weight[i]
//output: maximum value
double get_optimal_value(int capacity, vector<int> weights, vector<int> values) {
  double value = 0.0;

  // write your code here
  vector<double> unitValue;
  vector<int> track;

  int n = weights.size();
  for (int i = 0; i<n; i++){
    unitValue.push_back((double)values[i] / weights[i]);
    track.push_back(i);
  }
  sort(begin(track), end(track), [&](int i1, int i2) { return unitValue[i1] < unitValue[i2]; });
  sort(begin(unitValue), end(unitValue));

  int packIndex = n-1;
  while (capacity > 0 && packIndex >-1){
    int index = track[packIndex];
    if (capacity >= weights[index]){//load all
      capacity -= weights[index];
      value += (double)values[index];
    }
    else{//last item load fractional
      value += (double)capacity * values[index]/ weights[index] ;
      capacity = 0;
    }
    packIndex--;
  }
  return value;
}

int main() {
  int n;
  int capacity;
  std::cin >> n >> capacity;
  vector<int> values(n);
  vector<int> weights(n);
  for (int i = 0; i < n; i++) {
    std::cin >> values[i] >> weights[i];
  }

  double optimal_value = get_optimal_value(capacity, weights, values);

  std::cout.precision(10);
  cout.setf(ios::fixed);
  std::cout << optimal_value << std::endl;
  return 0;
}
