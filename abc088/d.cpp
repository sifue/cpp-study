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
  int H, W;
  cin >> H >> W;

  int s[52][52] = {};
  int blackCount = 0;
  rep(j, H) {
    rep(i, W) {
      char sij;
      cin >> sij;
      if(sij == '.') {
        s[i + 1][j + 1] = 1; // 白を1
      } else {
        s[i + 1][j + 1] = 0; // 黒を0
        blackCount++;
      }
    }
  }
  // 探索済みを -1
  // DEBUG(blackCount);

  // 幅優先探索でゴールできるか調べる
  // ゴールできないなら -1
  // ゴールできるなら、(W x H) - (W + H - 1) - 黒の数を出力
  queue<P> Q;
  queue<P> nextQ;
  Q.push(make_pair(1, 1));

  while(true) {
    if (Q.empty() && nextQ.empty()) { // たどり着けないなら -1
      cout << -1 << endl;
      exit;
    }

    if (!Q.empty()) {
      // DEBUG(Q.size());
      P p = Q.front();
      Q.pop();

      if(p._1 == H && p._2 == W) {
        break; // ゴール！
      } 
      s[p._1][p._2] = -1; // 居た場所を探索済みに

      int i, j, t;

      // 上
      i = p._1 - 1;
      j = p._2;
      if( i > 0 && j > 0 && i <= H && j <= W && s[i][j] == 1) {
        s[i][j] = -1;
        nextQ.push(make_pair(i, j));
      }

      // 下
      i = p._1 + 1;
      j = p._2;
      if( i > 0 && j > 0 && i <= H && j <= W && s[i][j] == 1) {
        s[i][j] = -1;
        nextQ.push(make_pair(i, j));
      }

      // 左
      i = p._1;
      j = p._2 - 1;
      if( i > 0 && j > 0 && i <= H && j <= W && s[i][j] == 1) {
        s[i][j] = -1;
        nextQ.push(make_pair(i, j));
      }

      // 右
      i = p._1;
      j = p._2 + 1;
      if( i > 0 && j > 0 && i <= H && j <= W && s[i][j] == 1) {
        s[i][j] = -1;
        nextQ.push(make_pair(i, j));
      }

    } else {
      Q = nextQ; // もし空ならnextQをQに
    }
  }
  
  cout << ((W * H) - (W + H - 1) - blackCount) << endl;  
}
