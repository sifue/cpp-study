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

int search(int row, int column, int count, vector<vector<int>> V) {
  if (column == 4) return count;

  // 置く場合
  if (V[row][column] == 0 &&
      V[row][column + 1] == 0 &&
      V[row - 1][column] == 0 &&
      V[row - 1][column + 1] == 0)) {

      vector<vector<int>> nextV = V;
      

  }


  // 置かない場合
  int count1 =  search(row, column + 1, count, state);

  return max(count0, count1);
}

int main() {
  int H, N;
  cin >> H >> N;

  // Hを増やしながらDPしていく 0:なし、1:おけない 2: 荷物 

  int maxRowCount = 10000;
  vector<vector<int>> V;
  V.resize(maxRowCount);
  rep (i, maxRowCount) {
    V[i].resize(4);
    rep (j, maxRowCount){
      V[i][j] = 0;
    }
  }

  rep(i, N) {
    int x, y;
    cin >> x >> y;
    V[x][y] = 1;
  }

  int totalCount = 0;
  // i 行が増えたという形でループする
  for (int i = 2; i < H; i++) {


    // i行目が増えた時に最大数、countを増加


  }
  cout << maxPlayer << endl;
}
