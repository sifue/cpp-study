#include <bits/stdc++.h>  // g++ -std=c++14 -o a a.cpp
#include <numeric>

using namespace std;

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
