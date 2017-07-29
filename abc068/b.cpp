#include <iostream>

using namespace std;

int search(int n) {
  int r, m, count;
  
  count = 0;
  m = n % 2;
  r = n / 2;
  
  while (r > 0 && m == 0) {
    count++;
    m = r % 2;
    r = r / 2;
  }

  return count;
}

int main() {
  int n, max, result;
  cin >> n;
  max = 0;
  result = 0;

  for (int i = n; i >= 1 ; i--) {
    int count = search(i);
    if (count >= max) {
      max = count;
      result = i;
    }
  }
  
  cout << result << endl;
}
