#include <iostream>
#include <vector>

#define DEBUG(x) cout << #x << ": " << x << endl;
#define MOD 1000000007

using namespace std;

int main() {
  string t, b;
  cin >> t >> b;

  int P[t.size() + 1][b.size() + 1] = {}; // [i][j]

  for (int i = 0; i < b.size() + 1; i++) { // 左端の初期化
    P[0][i] = 0; 
  }

  for (int i = 0; i < t.size() + 1; i++) { // 上端の初期化
    P[i][0] = 1; 
  }

  for (int i = 1; i < t.size() + 1; i++) {
    char ti = t.at(i - 1);
    for (int j = 1; j < b.size() + 1; j++) {
      char bj = b.at(j - 1);
      if (j <= i) {
        if (ti == bj) {
          P[i][j] = (P[i - 1][j - 1] + P[i - 1][j]) % MOD;
        } else {
          P[i][j] = P[i - 1][j];
        }
      } else {
        P[i][j] = 0;
      }
      // DEBUG(i);
      // DEBUG(j);
      // DEBUG(ti);
      // DEBUG(bj);
      // DEBUG(P[i][j]);
    }
  }
  cout << P[t.size()][b.size()] << endl;
}
