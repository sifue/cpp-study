#include <bits/stdc++.h>

using namespace std;

#define P(s) cout << s << endl;
#define DEBUG(x) cout << #x << ": " << x << endl;
#define INF (1 << 29)

vector<int> rs; // 巡回必要なもの全てRs
int Cs[201][201] = {0}; // 全パスの距離

int main() {

  int N, M, R;
  cin >> N >> M >> R;
  
  for (int i = 0; i < R; i++) {
    int r;
    cin >> r;
    rs.push_back(r);
  }

  for (int i = 1; i <= N; i++) { 
    for (int j = 1; j <= N; j++) { 
      if (i != j) {
        Cs[i][j] = INF;
      }
    }
  } // fill

  for (int i = 0; i < M; i++) {
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
  sort(paths.begin(), paths.end()); // next_permutation は sortされている必要があった！
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
  } while (next_permutation(paths.begin(), paths.end()));

  cout << min << endl;
}
