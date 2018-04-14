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

int result = 0;
int selectableRed[101][101] = {}; // i: 青, j: 赤

__attribute__((constructor))
void initial() {
  cin.tie(0);
  ios::sync_with_stdio(false);
}


void dfs(int bi, int N, int pairCount) {
  DEBUG(bi);
  if (bi == N) {
    // 終了、最大値更新
    result = max(pairCount, result);
    return;
  }

  // 未選択
  dfs(bi + 1, N, pairCount);

  rep(ri, N) {

    if(selectableRed[bi][ri] == 1) { // 選択可能なら選択
      dfs(bi + 1, N, pairCount + 1);
    }
  }
}

int main() {
  int N;
  cin >> N;

  vector<P> reds;
  vector<P> blues;

  // ソートして読み込み
  rep(i, N) {
    int ai, bi;
    cin >> ai >> bi;
    reds.pb(make_pair(ai, bi));
  }
  sort(reds.rbegin(), reds.rend());

  rep(i, N) {
    int ci, di;
    cin >> ci >> di;
    blues.pb(make_pair(ci, di));
  }
  sort(blues.rbegin(), blues.rend());

  // DEBUG("--RED--");
  // for_each(reds.begin(), reds.end(), [](P p) {
  //   cout << "(" << p._1 << ":"  << p._2 << ")" << endl;
  // });

  // DEBUG("--BLUE--");
  // for_each(blues.begin(), blues.end(), [](P p) {
  //   cout << "(" << p._1 << ":"  << p._2 << ")" << endl;
  // });

  // 青に対して選択可能な赤を作成
  for(int i = 0; i < blues.size(); i++) {
    for(int j = 0; j < reds.size(); j++) {
      P blue = blues[i];
      P red = reds[j];
      if (red._1 < blue._1 && red._2 < blue._2) { 
        selectableRed[i][j] = 1;
      }
    }
  }

  dfs(0, N, 0);

  cout << result << endl;
}
