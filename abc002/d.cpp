#include <iostream>
//#include <iomanip>
//#include <string>
#include <set>
#include <vector>
//#include <cstdlib>
//#include <cmath>
//#include <cfenv>
//#include <bits/stdc++.h>

using namespace std;
/*
   1.まずは1人目(1)に注目、その人の派閥の人数を出す
   2.その人と関係を集める(R-2,3)、この際最大派閥のsetを作る
   3.Rの人から1人選ぶ(r1つまり2)
   4.r1の関係から、Rに含まれる人取得(R2-2,3)
   5.Rの人から1人選ぶ (r2つまり3)
   6.r2の関係が存在しない者を派閥のsetから取り除く
   7.setのサイズを数えてその人の派閥の人数を取得
   8.関係の数のmaxを取得しておく
   9.これを全員に対して行い、最大数を取る
   */
int main() {
  int n, m;
  cin >> n >> m;
  int max = 1;

  if (m == 0) {
    cout << max << endl;
    exit(0);
  }
  // 初期化
  int rels[n][n];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (i != j) {
        rels[i][j] = 0;
      } else {
        rels[i][j] = 1;
      }
    }
  }

  // 関係の読み取り
  for (int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    rels[x - 1][y - 1] = 1;
    rels[y - 1][x - 1] = 1;
  }

  for (int i = 0; i < n; i++) { // 1
    vector<int> giins;
    set<int> habatsu;
    habatsu.insert(i);
    for (int j = 0; j < n; j++) { // 2
      if (rels[i][j] == 1) {
        giins.push_back(j);
        habatsu.insert(j); // 最大の可能性の派閥を作成
      }
    }

    for (int ga : giins) {   // 3  i で選んだ人の知り合い
      for (int gb : giins) { // 5  i の関係者の関係者として選んだ人
        if (ga != gb && rels[ga][gb] == 0) {
          // 6 もし関係がないなら派閥から取り除く
          habatsu.erase(gb);
        }
      }
    }
    int habatsuCount = habatsu.size(); // 7
    if (habatsuCount > max) {          // 8
      max = habatsuCount;
    }
    giins.clear();
    habatsu.clear();
  }
  cout << max << endl;
}
