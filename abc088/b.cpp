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
  int N;
  cin >> N;
  vector<int> a;
  rep(i, N) {
    int ai;
    cin >> ai;
    a.pb(ai);
  }
  sort(a.rbegin(), a.rend());

  int A = 0;
  int B = 0;
  rep(i, N) {
    if (i % 2 == 0) {
      A = A + a[i];
    } else {
      B = B + a[i];
    }
  }

  cout << (A - B) << endl;
}
