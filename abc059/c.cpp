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
  ll N;
  cin >> N;
  vector<ll> a;
  rep(i, N) {
    ll ai;
    cin >> ai;
    a.pb(ai);
  }

  ll changeCount = 0;
  ll sum = 0;
  bool nextSumPositive = true; // 最初の合計が正のパターン

  rep(i, N) {
    // DEBUG("---");
    // DEBUG(i);
    // DEBUG(nextSumPositive);
    // DEBUG(a[i]);

    sum += a[i];

    if (nextSumPositive) { // 合計が正である必要がある
      if(sum <= 0) { // だけど合計は負または0
        ll change = - sum + 1;  // sum を正にして + 1を変化させる
        // DEBUG(change);
        changeCount += abs(change); // 変更分をカウント
        sum += change; // 変化を sum に適用
      }
    } else { // 合計が負である必要がある
      if(sum >= 0) {// だけど合計は正または0
      ll change = - sum - 1; // sum を負 にして - 1を変化させる
      // DEBUG(change);
      changeCount += abs(change); // 変更分をカウント
      sum += change; // 変化を sum に適用
      }
    }
    // DEBUG(changeCount);
    // DEBUG(sum);

    nextSumPositive = !nextSumPositive;
  }


  // 最初が正、負で2パターン調べてみる 
  ll firstAns = changeCount;

  changeCount = 0;
  sum = 0;
  nextSumPositive = false; // 最初の合計が負のパターン
  rep(i, N) {
    // DEBUG("---");
    // DEBUG(i);
    // DEBUG(nextSumPositive);
    // DEBUG(a[i]);

    sum += a[i];

    if (nextSumPositive) { // 合計が正である必要がある
      if(sum <= 0) { // だけど合計は負または0
        ll change = - sum + 1;  // sum を正にして + 1を変化させる
        // DEBUG(change);
        changeCount += abs(change); // 変更分をカウント
        sum += change; // 変化を sum に適用
      }
    } else { // 合計が負である必要がある
      if(sum >= 0) {// だけど合計は正または0
      ll change = - sum - 1; // sum を負 にして - 1を変化させる
      // DEBUG(change);
      changeCount += abs(change); // 変更分をカウント
      sum += change; // 変化を sum に適用
      }
    }
    // DEBUG(changeCount);
    // DEBUG(sum);

    nextSumPositive = !nextSumPositive;
  }



  cout << min(firstAns, changeCount) << endl;
}
