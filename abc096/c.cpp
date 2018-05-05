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

int main() {
  int W, H;
  cin >> W >> H;
  int s[52][52] = {0}; // 0は白、1は黒にしたい、2は黒に塗り済み
  rep (pi, W) {
    int i = pi + 1;
    rep (pj, H) {
      int j = pj + 1;
      char sij;
      cin >> sij;
      // DEBUG(sij);
      if (sij == '#') {
        s[i][j] = 1;
      }
    }
  }

  int fixCount = 1;
  while (fixCount > 0) {
    fixCount = 0;

    rep (pi, W) {
      int i = pi + 1;
      rep (pj, H) { 
        int j = pj + 1;
        if (s[i][j] == 1) { // 該当箇所を黒にしたい場合 全部を2にしようとする

          if (s[i-1][j] == 1) { // 上 黒希望
            s[i-1][j] = 2;
            s[i][j] = 2;
            fixCount += 2;
          } else if (s[i-1][j] == 2) { // 上 黒済み
            s[i][j] = 2;
            fixCount += 1;
          } else if (s[i][j-1] == 1) { // 左 黒希望
            s[i][j-1] = 2;
            s[i][j] = 2;
            fixCount += 2;
          } else if (s[i][j-1] == 2) { // 左 黒済み
            s[i][j] = 2;
            fixCount += 1;
          } else if (s[i][j+1] == 1) { // 右 黒希望
            s[i][j+1] = 2;
            s[i][j] = 2;
            fixCount += 2;
          } else if (s[i][j+1] == 2) { // 右 黒済み
            s[i][j] = 2;
            fixCount += 1;
          } else if (s[i+1][j] == 1) { // 下 黒希望
            s[i+1][j] = 2;
            s[i][j] = 2;
            fixCount += 2;
          } else if (s[i+1][j] == 2) { // 下 黒済み
            s[i][j] = 2;
            fixCount += 1;
          }
        }

      }
    }


  }

  int blackNeedCount = 0;
  rep (pi, W) {
    int i = pi + 1;
    rep (pj, H) { 
      int j = pj + 1;
      if (s[i][j] == 1) { // 黒にしたいところがあればカウント
         blackNeedCount++;
      }
    }
  }

  if(blackNeedCount > 0) {
    cout << "No" << endl;
  } else {
    cout << "Yes" << endl;
  }
}
