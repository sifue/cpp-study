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
  int c[4][4] = {};
  rep(j, 3) {
    rep(i, 3) {
      int cij;
      cin >> cij;
      c[i + 1][j + 1] = cij;
    }
  }

  int s11 = c[1][1] - c[2][1];
  int s12 = c[1][2] - c[2][2];
  int s13 = c[1][3] - c[2][3];
  // DEBUG(s11);
  // DEBUG(s12);
  // DEBUG(s13);

  int s21 = c[2][1] - c[3][1];
  int s22 = c[2][2] - c[3][2];
  int s23 = c[2][3] - c[3][3];
  // DEBUG(s21);
  // DEBUG(s22);
  // DEBUG(s23);

  int s31 = c[3][1] - c[1][1];
  int s32 = c[3][2] - c[1][2];
  int s33 = c[3][3] - c[1][3];
  // DEBUG(s31);
  // DEBUG(s32);
  // DEBUG(s33);

  if( (s11 == s12 && s12 == s13) &&
      (s21 == s22 && s22 == s23) &&
      (s31 == s32 && s32 == s33)
   ) {
     cout << "Yes" << endl;
   } else {
     cout << "No" << endl;
   }  
}
