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

int calc(int total, int count, int cost) {
  if(total % count == 0) {
    return (total / count) * cost;
  } else {
    return ((total / count) + 1) * cost;
  }
}

int main() {
  int N, A, B, C, D;
  cin >> N >> A >> B >> C >> D;
  int X = 0;
  int Y = 0;
  X = calc(N, A, B);
  Y = calc(N, C, D);
  cout << min(X, Y) << endl;
}

