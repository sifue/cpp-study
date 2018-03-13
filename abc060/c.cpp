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
  int N, T;
  cin >> N >> T;
  vector<int> t;
  rep(i, N) {
    int ti;
    cin >> ti;
    t.pb(ti);
  }

  int sum = 0;
  int i = 0;

  while (i < (N - 1)) {
    if((t[i + 1] - t[i]) < T) {
      sum += (t[i + 1] - t[i]);
    } else {
      sum += T;
    }
    i++;
  }
  sum += T;

  cout << sum << endl;
}
