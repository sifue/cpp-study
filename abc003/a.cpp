#include <iostream>

using namespace std;

int main() {
  int n;
  cin >> n;
  int sum = 0;

  for (int i = 1; i <= n; i++) {
    sum = sum + 10000 * i;
  }
  
  double result = (double)sum / n; 

  cout << result << endl;
}
