#include <bits/stdc++.h>  //  g++ -std=c++14 -o a a.cpp

using namespace std;
typedef pair<int, int> P;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (n); i++)
#define all(c) (c).begin(), (c).end()
#define uniq(c) c.erase(unique(all(c)), (c).end())
#define _1 first
#define _2 second
#define pb push_back
#define INF 1145141919
#define MOD 1000000007
#define DEBUG(x) cout << #x << ": " << x << endl;

vector<int> rs; // 巡回必要なもの全てRs
int Cs[201][201] = {0}; // 全パスの距離

int main() {

  int N, M, R;
  cin >> N >> M >> R;
  
  rep(i, R) {
    int r;
    cin >> r;
    rs.pb(r);
  }

  for (int i = 1; i <= N; i++) { 
    for (int j = 1; j <= N; j++) { 
      if (i != j) {
        Cs[i][j] = INF;
      }
    }
  } // fill

  rep(i, M) {
    int A, B, C;
    cin >> A >> B >> C;
    Cs[A][B] = C;
    Cs[B][A] = C;
  }

  // cout << "---------" << endl;
  // for (int i = 1; i <= N; i++) { 
  //   for (int j = 1; j <= N; j++) { 
  //     DEBUG(i);
  //     DEBUG(j);
  //     DEBUG(Cs[i][j]);
  //   }
  // }
  // cout << "---------" << endl;

  // 1. ワーシャルフロイドですべての頂点の対の最小距離を求める
  for (int k = 1; k <= N; k++) {
    for (int i = 1; i <= N; i++) { 
      for (int j = 1; j <= N; j++) { 
        if(Cs[i][k] != INF && Cs[k][j] != INF) { // オーバーフロー対策!!!!
          Cs[i][j] = min(Cs[i][j], Cs[i][k] + Cs[k][j]);
        }
      }
    }
  }

  // for (int i = 1; i <= N; i++) { 
  //   for (int j = 1; j <= N; j++) { 
  //     DEBUG(i);
  //     DEBUG(j);
  //     DEBUG(Cs[i][j]);
  //   }
  // }

  // 2. rsのすべての順列組み合わせを作り、最短距離を使ってそれぞれの全コストを求め、最短を出力
  vector<int> paths = rs;
  int min = INF;
  sort(all(paths)); // next_permutation は sortされている必要があった！
  do {
    int sum = 0;
    for (int i = 0; i < R - 1; i++) {
      int start = paths[i];
      int end = paths[i + 1];
      sum = sum + Cs[start][end];
      // cout << start << "->" << end << " ";
    }
    // cout << " : " << sum << endl;
    if (sum <= min) min = sum;
  } while (next_permutation(all(paths)));

  cout << min << endl;
}
