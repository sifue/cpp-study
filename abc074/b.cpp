#include <bits/stdc++.h>  // g++ -std=c++14 -o a a.cpp

using namespace std;

typedef pair<int, int> P;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (n); i++)
#define all(c) (c).begin(), (c).end()
#define uniq(c) c.erase(unique(all(c)), (c).end()) // ちゃんとユニークな配列にする。連続した値を除去して切り出す。
#define _1 first
#define _2 second
#define pb push_back
#define INF 1145141919
#define MOD 1000000007
#define DEBUG(x) cout << #x << ": " << x << endl;

int main() {
  int N, K;
  cin >> N >> K;
  int sum = 0;

  rep(i, N) {
    int x;
    cin >> x;
    int a = x * 2;
    int b = abs(x - K) * 2;
    int min_cost = min(a, b);
    sum += min_cost;
  }

  cout << sum << endl;
}
