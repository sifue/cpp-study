#include <bits/stdc++.h>  // g++ -std=c++14 -o a a.cpp

using namespace std;

typedef pair<int, int> P;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (n); i++)
#define repto(i, n) for(int i = 0; i <= (n); i++)
#define all(c) (c).begin(), (c).end()
#define uniq(c) c.erase(unique(all(c)), (c).end()) // ユニークなvectorにする。連続した値を除去して切り出す。
#define _1 first
#define _2 second
#define pb push_back
#define INF 1145141919
#define MOD 1000000007
#define DEBUG(x) cout << #x << ": " << x << endl;

__attribute__((constructor))
void initial() {
  cin.tie(0);
  ios::sync_with_stdio(false);
}

int main() {
  int N;
  while (cin >> N, N) {
    vector<int> h;
    int corretDiff = -1;
    rep (i, N + 1) {
      int hi;
      cin >> hi;
      h.pb(hi);
    }

    rep (i, N + 1) {
      if (i == 2) { // 3個のときのみ特殊処理
        int diff1 = h[1] - h[0];
        int diff2 = h[2] - h[1];
        if (diff1 != diff2) { // 3個目までに雑草がある！

          int diff3 = h[3] - h[2];
          DEBUG(diff1);
          DEBUG(diff2);
          DEBUG(diff3);

          if (diff2 == diff3) { // 1つ目
             cout << h[0] << endl;
             break;
          }

          if ((h[2] - h[0]) == (h[3] - h[2])) { // 2つ目
             cout << h[1] << endl;
             break;
          }

          if (diff1 == (h[3] - h[1])) { // 3つ目
             cout << h[2] << endl;
             break;
          }

        } else { // 3つ目までにはなく、正しいdiffがわかった
          corretDiff = diff1;
        }
      } else if ( i > 2) { // 4つめより
        int newDiff = h[i] - h[i-1];
        if (corretDiff != newDiff) {
          cout << h[i] << endl;
          break;
        }
      }
    }
  }
}
