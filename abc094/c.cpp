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
  vector<int> X;
  rep(i, N) {
    int xi;
    cin >> xi;
    X.pb(xi);
  }
  vector<int> sortedX = X;
  sort(all(sortedX));

  // rep(i, N) {
  //   DEBUG(sortedX[i]);
  // }

  int medianIndex = N / 2;
  int median1 = sortedX[medianIndex - 1];
  int median2 = sortedX[medianIndex];

  rep(i, N) {
    if (X[i] <= median1) {
      cout << median2 << endl;
    } else if (X[i] >= median2) {
      cout << median1 << endl;
    } else {
      cout << median1 << endl;
    }
  }
}
