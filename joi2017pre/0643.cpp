#include <bits/stdc++.h>  // g++ -std=c++14 -o a a.cpp

using namespace std;

typedef pair<int, int> P;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (n); i++)
#define repto(i, n) for(int i = 0; i <= (n); i++)
#define all(c) (c).begin(), (c).end()
#define uniq(c) c.erase(unique(all(c)), (c).end()) // ちゃんとユニークな配列にする。連続した値を除去して切り出す。
#define _1 first
#define _2 second
#define pb push_back
#define INF 1145141919
#define MOD 1000000007
#define DEBUG(x) cout << #x << ": " << x << endl;

int main() {
  int H, W;
  cin >> H >> W;
  int A[26][26] = {};
  for(int i = 1; i <= H; i++) {
    for(int j = 1; j <= W; j++) {
      int a;
      cin >> a; 
      A[i][j] = a; 
    }
  }

  int minTotal = INF;
  for(int m = 1; m <= H; m++) {
    for(int n = 1; n <= W; n++) {
      int total = 0;
      for(int i = 1; i <= H; i++) {
        for(int j = 1; j <= W; j++) {
          int moyori = min(abs(i - m), abs(j - n));
          total = total + (moyori * A[i][j]);
        }
      }
      minTotal = min(total, minTotal);
    }
  }

  cout << minTotal << endl;
}
