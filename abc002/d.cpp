#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
#include <cfenv>
#include <vector>
#include <cstdlib>

using namespace std;
/*
   1.まずは1人目(1)に注目
   2.その人と関係を集める(R-1,2,3)
   3.Rの人から1人選ぶ(r1つまり2)
   4.r1の関係から、Rに含まれる人の数をカウントする(R2-1,2,3)
   5.Rの人から1人選ぶ (r2つまり3)
   6.r2の関係から、Rに含まれる人を選ぶ(R3-1,2,3)
   7.関係の数のmaxを取得しておく
   これを全員に対して行い、最大数を取る
*/
int main() {
  int n, m;
  cin >> n >> m;

  int rels[n][n] = {{0}};
  for (int i = 0; i < n; i++) {
    rels[i][i] = 1;
  }

  for (int j = 0; j < m; j++) {
    int x, y;
    cin >> x >> y;
    rels[x - 1][y - 1] = 1;
    rels[y - 1][x - 1] = 1;
  }

  for (int i = 0; i < n; i++) { // 1
    vector<int> giins;
    for (int j = 0; j < n; j++) { // 2
      if (rels[i][j] == 1) {
        giins.push_back(j);
      }
    }
  }
}
