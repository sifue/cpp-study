#include <bits/stdc++.h>  // g++ -std=c++14 -o a a.cpp

using namespace std;

typedef pair<int, int> P;
typedef long long ll;
#define mp(i, j) make_pair(i, j)
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

void exitIfAntilogy (bool isAntilogy) {
  if(isAntilogy) {
    cout << "No" << endl;
    exit(0);
  }
}

int main() {
  int N, M;
  cin >> N >> M;
  map<P, int> D;

  bool isAntilogy = false;

  vector<int> Li, Ri, Di;
  rep(i, M) {
    int l, r, d;
    cin >> l >> r >> d;
    Li.pb(l);
    Ri.pb(r);
    Di.pb(d);
  }

  rep(mIndex, M) {
    int l = Li[mIndex];
    int r = Ri[mIndex];
    int d = Di[mIndex];

    DEBUG(l);
    DEBUG(r);

    if(D.count(mp(l, r)) == 0 || D.at(mp(l, r)) == d) { // 未知 また 矛盾しない
      D.insert(mp(mp(l,r), d));
    } else { // 矛盾
      isAntilogy = true;
    }
    exitIfAntilogy(isAntilogy);

    if(D.count(mp(r, l)) == 0 || D.at(mp(r, l)) == -d) { // 未知 また 矛盾しない
      D.insert(mp(mp(r,l), -d));
    } else { // 矛盾
      isAntilogy = true;
    }
    exitIfAntilogy(isAntilogy);

    // rやlが先になる場合をすべて更新
    rep (i, N) {
      DEBUG(i);
      if(D.count(mp(i, r)) != 0) { // r が先になる既知のパターン
        int newDistance = D.at(mp(i, r)) + d;
        if(D.count(mp(i, l)) == 0) { // rを経由してlに至るパターン、未知なら更新
          D.insert(mp(mp(i,l), newDistance));
        } else { // 既知なら、矛盾チェック
          DEBUG("anti1");
          DEBUG(i);
          DEBUG(l);
          DEBUG(r);
          DEBUG(newDistance);
          if(D.at(mp(i, l)) != newDistance) isAntilogy = true;
        }
      }
      DEBUG(isAntilogy);
      exitIfAntilogy(isAntilogy);

      if(D.count(mp(i, l)) != 0) { // l が先になる既知のパターン
        int newDistance = D.at(mp(i, l)) - d;
        if(D.count(mp(i, r)) == 0) { // lを経由してrに至るパターン、未知なら更新
          D.insert(mp(mp(i,r), newDistance));
        } else { // 既知なら、矛盾チェック

          DEBUG("anti2");
          DEBUG(i);
          DEBUG(l);
          DEBUG(r);
          DEBUG(newDistance);
          if(D.at(mp(i, r)) != newDistance) isAntilogy = true;
        }
      }
      DEBUG(isAntilogy);
      exitIfAntilogy(isAntilogy);
    }

  }
  cout << "Yes" << endl;
}
