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

__attribute__((constructor)) void initial() {
    cin.tie(0);
    ios::sync_with_stdio(false);
}

int minN = INF;
int D, G;
vector<ll> p;
vector<ll> c;

void dfs(int i, int n, ll sum) {
    DEBUG(i);
    DEBUG(n);
    DEBUG(sum);
    cout << "------------" << endl;
  if (i == D && sum >= G) {
    minN = min(minN, n);
  }

  repto(j, p[i]) {
      ll lsum = sum + ((i+1) * 100) * j;
      if (j == p[i]) lsum += c[i];
      dfs(i+1, n+j, lsum);
  }
}

int main() {
    cin >> D >> G;
    rep(i, D) {
        int pi, ci;
        cin >> pi >> ci;
        p.pb(pi);
        c.pb(ci);
    }
    dfs(0, 0, 0);
    cout << minN << endl;
}
