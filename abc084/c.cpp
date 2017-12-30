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
  int N;
  cin >> N;
  vector<int> C; // iは実際のiより1小さい
  vector<int> S;
  vector<int> F;
  rep(i, (N - 1)) {
    int ci, si, fi;
    cin >> ci >> si >> fi;
    C.pb(ci);
    S.pb(si);
    F.pb(fi);
  }

  // 500個ぐらいだし貪欲法
  rep(i, N) {
    int currentPos = i;
    int t = 0;
    while(currentPos < (N - 1)) {
      // DEBUG(currentPos);
      // DEBUG(t);
      if(S[currentPos] <= t 
         && (t % F[currentPos]) == 0)  {
        t = t + C[currentPos];
        currentPos++;
      } else {
        t++;
      }
    }
    cout << t << endl;
  }
}
