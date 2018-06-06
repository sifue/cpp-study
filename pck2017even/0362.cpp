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
  int N;
  cin >> N;
  vector<int> d;
  rep(i, N) {
    int di;
    cin >> di;
    d.pb(di);
  }

  int maxGo = 0;
  for (int i = 0; i < N; i++) {
    // DEBUG(i);
    // DEBUG(maxGo);
    if(maxGo < i) break;
    maxGo = max((d[i] / 10) + i, maxGo);
  }

  if (maxGo < (N - 1)) {
    cout << "no" << endl;
    return 0;
  }

  int minBack = N - 1;
  for(int i = N - 1; i > 0 ; i--) {
    // DEBUG(i);
    // DEBUG(minBack);
    if(i < minBack) break;
    minBack = min(minBack, i - (d[i] / 10));
  }

  if (minBack > 0) {
    cout << "no" << endl;
    return 0;
  }

  cout << "yes" << endl;
}
