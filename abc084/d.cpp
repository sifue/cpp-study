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
  int Q;
  cin >> Q;
  vector<int> l;
  vector<int> r;
  rep(i, Q) {
    int li, ri;
    cin >> li >> ri;
    l.pb(li);
    r.pb(ri);
  }

  // 全部作ってしまえ
  vector<int> primes;
  set<int> setPrime;
  vector<int> like2017s;

  primes.pb(2);
  setPrime.insert(2);
  for(int i = 3; i < 100001; i++)
  {
    bool prime = true;
    for(int j=0; j<primes.size() && primes[j]*primes[j] <= i ; j++)
    {
      if(i % primes[j] == 0)
      {
        prime = false;
        break;
      }
    }
    if(prime) 
    {
      primes.pb(i);
      setPrime.insert(i);

      if(setPrime.count((i + 1) / 2) > 0) {
        like2017s.pb(i);
      }
    }
  }

  // 数え上げるだけ
  rep(i, Q) {
    int count = 0;
    for(int like2017 : like2017s) {
      if(l[i] <= like2017 && like2017 <= r[i]) count++;
    }
    cout << count << endl;
  }

}
