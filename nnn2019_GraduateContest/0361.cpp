#include <bits/stdc++.h>  // g++ -std=c++14 -o a a.cpp

using namespace std;

typedef pair<int, int> P;
typedef long long ll;

#define rep(i, n) for(int i = 0; i < (n); i++)
#define repto(i, n) for(int i = 0; i <= (n); i++)
#define all(c) (c).begin(), (c).end()
#define uniq(c) c.erase(unique(all(c)), (c).end())
#define _1 first
#define _2 second
#define pb push_back
#define INF 1145141919
#define MOD 1000000007
#define DEBUG(x) cout << #x << ": " << x << endl;

int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

__attribute__((constructor))
void initial() {
    cin.tie(0);
    ios::sync_with_stdio(false);
}

// ユークリッド互除法の最大公約数の実装コピペ
int gcd(int m, int n) {
  if ( ( 0 == m ) || ( 0 == n ) )
    return 0;

  while( m != n )
  {
    if ( m > n ) m = m - n;
    else         n = n - m;
  }
  return m;
}

int main() {
  int x, y;
  cin >> x >> y;
  // 考察より x + y - gcd(x, y) + 1
  cout << (x + y - gcd(x, y) + 1) << endl;
}

