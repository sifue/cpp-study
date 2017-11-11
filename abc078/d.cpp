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
  int N, X, Y;
  cin >> N >> X >> Y;
  vector<int> a;
  rep(i, N) {
    int ai;
    cin >> ai;
    a.pb(ai);
  }
  DEBUG(X);
  DEBUG(Y);

  int i = 0;
  bool isX = true;
  do {
    if(isX) {
      vector<ll> absFromY;
      for(int j = i; j < N; j++) {
        ll calcedAbs = (abs(a[j] - Y) * 10000) + j;
        DEBUG(calcedAbs);
        absFromY.pb(calcedAbs);
      }
      decltype(absFromY)::iterator maxIt = max_element(all(absFromY));
      size_t maxIndex = distance(absFromY.begin(), maxIt);
      int selectedIndex = maxIndex + i;
      X = a[selectedIndex];
      DEBUG(i);
      DEBUG(X);
      i = selectedIndex + 1;
      isX = false;
    } else {
      vector<ll> absFromX;
      for(int j = i; j < N; j++) {
        ll calcedAbs = (abs(a[j] - Y) * 10000) + j;
        DEBUG(calcedAbs);
        absFromX.pb(calcedAbs);
      }
      decltype(absFromX)::iterator minIt = min_element(all(absFromX));
      size_t minIndex = distance(absFromX.begin(), minIt);
      int selectedIndex = minIndex + i;
      Y = a[selectedIndex];
      DEBUG(i);
      DEBUG(Y);
      i = selectedIndex + 1;
      isX = true;
    }
  } while(i < N);

  cout << abs(X - Y) << endl;
}
