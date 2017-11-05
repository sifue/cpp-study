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
  string c1;
  string c2;
  cin >> c1 >> c2;
  bool result = true;
  for (int j = 0; j < 2 ; j++) {
    if (!result) break;
    if(c1[j] != c2[2 - j]) result = false;
    if(c2[j] != c1[2 - j]) result = false;
  }

  if (result) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
}
