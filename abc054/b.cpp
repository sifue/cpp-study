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
  int N, M;
  cin >> N >> M;
  vector<string> A;
  rep(i, N) {
    string ai;
    cin >> ai;
    A.pb(ai);
  }

  vector<string> B;
  rep(i, M) {
    string bi;
    cin >> bi;
    B.pb(bi);
  }

  
  // 合わせ位置の二重ループ
  bool isFound = false;
  repto (x, (N - M)) {
    if (isFound) break;

    repto (y, (N - M)) {
      bool isMatch = true;

      // 一つの画像の二重ループ
      rep (i, M) {
        if (!isMatch) break;
        rep (j, M) {
          if (A[x + i][y + j] != B[i][j]) {
            isMatch = false;
            break;
          } 
        }
      }

      if (isMatch) {
        isFound = true;
        break;
      }
    }
  }

  if(isFound) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }

}
