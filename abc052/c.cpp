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

void factrization(int n, map<int, int> &ret) {
  int target = n;
  int divider = 2;

  while (target != 1 && divider <= n) {
    if( target % divider == 0) {
      target = target / divider;
      if (ret.count(divider) > 0) {
        int current = ret.at(divider);
        ret.erase(divider);
        ret.insert(make_pair(divider, current + 1));
      } else {
        ret.insert(make_pair(divider, 1));
      }
    } else {
      divider++;
    }
  }
}


int main() {
  int N;
  cin >> N;

  map<int, int> ret;
  for(int i = 1; i <= N; i++) {
    factrization(i, ret);
  }

  ll result = 1;
  for(int i = 1; i <= N; i++) {
    if(ret.count(i) > 0) {
      result =  (result * (ret.at(i) + 1)) % MOD;
    }
  }

  cout << result << endl;
}
