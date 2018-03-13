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

int main() {
  int N, W;
  cin >> N >> W;
  vector<int> w;
  vector<int> v;
  rep(i, N) {
    int wi, vi;
    cin >> wi >> vi;
    w.pb(wi);
    w.pb(vi);
  }

  // wの総和になれるパターンは決まっている 
  // (w1 * n) + ((最大+3) * n) 
  // つまり n * (3*n) 分のパターンしか無い
  // 3 * 100 * 100 = 30000

  int MAX_N = 100;
  int MAX_W = 30000; // w1 の n 回 + (0 〜 3 * n)のパターン

  int dp[MAX_N][MAX_W] = {};

  // Wになれるパターンづくり
  vector<int> wpattern;
  int w1 = w[0];
  rep(i, N) {
    int w1n = w1 * i;
    rep(j, (3 * i) + 1) {
      wpattern.pb(w1n + j);
    }
  }

  rep(i, N) {
    rep(j, wpattern.size()) {
      // TODO DP
    }
  }

  cout << dp[N - 1][wpattern.size() -1] << endl;
}
