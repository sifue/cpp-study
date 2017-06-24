#include <iostream>
#include <cstdlib>

using namespace std;

int mf = 1000000007;

long long factorial(long long num) {
  long long result = 1;
  for (int i = 1; i <= num; i++) {
    result = (result * i) % mf;
  }
  return result;
}

int main() {
  int n, m;
  cin >> n >> m;
  int diff = n - m;

  //cout << "diff:" << diff << endl;
  //cout << "abs(diff):" << abs(diff) << endl;
  if (abs(diff) > 1) {
    cout << 0 << endl;
    exit(0);
  }

  int change_pattern;
  if ((n - m) == 0) {
    change_pattern = 2;
  } else {
    change_pattern = 1;
  }
  //cout << "change_pattern:" << change_pattern << endl;

  long long dog = factorial(n) % mf;
  //cout << "dog:" << dog << endl;
  long long  monkey = factorial(m) % mf;
  //cout << "monkey:" << monkey << endl;
  long long result = (dog * monkey) % mf ;
  //cout << "result:" << result << endl;
  result = (result * change_pattern) % mf;
  cout << result << endl;
}
