#include <bits/stdc++.h>  // g++ -std=c++14 -o a a.cpp

using namespace std;

typedef pair<int, int> P;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (n); i++)
#define repto(i, n) for(int i = 0; i <= (n); i++)
#define all(c) (c).begin(), (c).end()
#define uniq(c) c.erase(unique(all(c)), (c).end()) // ちゃんとユニークな配列にする。連続した値を除去して切り出す。
#define _1 first
#define _2 second
#define pb push_back
#define INF 1145141919
#define MOD 1000000007
#define DEBUG(x) cout << #x << ": " << x << endl;

int main() {
  int H, W;
  cin >> H >> W;
  ll C[10][10] = {0};
  int A[200][200] = {-1};
  rep(i, 10) {
    rep(j, 10) {
      cin >> C[i][j];
    }
  }
  rep(i, H) {
    rep(j, W) {
      cin >> A[i][j];
    }
  }

  // 同じならコスト0
  rep(i, 10) {
    C[i][i] == 0;
  }

  // ワーシャルフロイドでコストを最小化
  rep(i, 10) {
    rep(j, 10) {
      rep(k, 10) {
        C[i][j] = min(C[i][j], C[i][k] + C[k][j]);
      }
    }
  }

  // デバッグで表示
  // DEBUG("optimized");
  // rep(i, 10) {
  //   rep(j, 10) {
  //     cout << C[i][j] << " ";
  //   }
  //   cout << endl;
  // }

  ll sumCost = 0;
  rep(i, H) {
    rep(j, W) {
      int a = A[i][j];
      if (a != -1 && a != 1) {
        sumCost = sumCost + C[a][1];
      }
    }
  }

  cout << sumCost << endl;
}
