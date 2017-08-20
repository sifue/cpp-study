#include <iostream>
#include <vector>

using namespace std;

int main() {
  string t, b;
  cin >> t >> b;

  int P[t.size() + 1][b.size() + 1] = {}; // [i][j]

  for (int i = 0; i < t.size() + 1; i++) { // 上端の初期化
    P[i][0] = 1; 
  }

  for (int i = 1; i < t.size() + 1; i++) {
    char ti = t.at(i - 1);
    for (int j = 1; j < b.size() + 1; j++) {
      char bj = b.at(j - 1);

      if (ti == bj) {
        P[i][j] = P[i][j - 1] + P[i - 1][j];
      } else {
        P[i][j] = P[i - 1][j];
      }
    }
  }
  cout << P[t.size()][b.size()] << endl;
}
