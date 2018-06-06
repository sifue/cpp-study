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

int h, n;
vector<int> b;

int dp[10000][8];

int dfs(int i = 1, int bit = 0) {
  if (i == h) { // 最後まで来た場合
    return 0;
  }
  bit |= b[i]; // 置ける状況を取得

  int &ret = dp[i][bit]; // おける最大数、配列の中身を変えたいので参照取得
  if (~ret)
    return ret;  // 計算済みなら返す  retが-1だと~retは0となり計算するために次へ

  ret = 0;
  if (bit == 0) // 2つ置く場合
    ret = max(ret, dfs(i + 1, 0b111) + 2);
  if ((bit & (0b100)) == 0) // 左に置く場合
    ret = max(ret, dfs(i + 1, 0b110) + 1);
  if ((bit & (0b010)) == 0) // 中に置く場合
    ret = max(ret, dfs(i + 1, 0b111) + 1);
  if ((bit & (0b001)) == 0) // 右に置く場合
    ret = max(ret, dfs(i + 1, 0b011) + 1);
  ret = max(ret, dfs(i + 1, 0)); // 置かない場合

  // 5パターンの最大値がretに
  return ret;
}

int main() {
  memset(dp, -1, sizeof(dp));
  cin >> h >> n;

  // eiはそれぞれ x の値に対応するおけない箇所
  int ei[4] = {0b100, 0b110, 0b011, 0b001};
  b.assign(h + 1, 0);
  for (int i = 0; i < n; ++i) {
    int x, y;
    cin >> x >> y;
    // 置けなくなる箇所をパターンとして用意
    b[y + 1] |= ei[x];
    b[y] |= ei[x];
  }

  cout << dfs() << endl;
}