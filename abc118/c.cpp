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

ll euclidean_gcd(ll a,  ll b) {
  if(a < b) euclidean_gcd(b, a);
  ll r;
  while ((r=a%b)) {
    a = b;
    b = r;
  }
  return b;
}

int main() {
    ll N;
    cin >> N;
    vector<ll> A;
    rep(i, N) {
        ll ai;
        cin >> ai;
        A.pb(ai); 
    }

    ll result = A[0];
    for (int i = 1; i < A.size(); i++){
        result = euclidean_gcd(result, A[i]);
    }
    cout << result << endl;
}
