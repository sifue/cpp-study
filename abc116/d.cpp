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

__attribute__((constructor))
void initial() {
    cin.tie(0);
    ios::sync_with_stdio(false);
}

struct Sushi {
    int i;
    ll d;
    int typeCount;
    bool operator<( const Sushi& right ) const {
        return d == right.d ? typeCount < right.typeCount : d > right.d;
    }
};

ll t[100001] = {0};
ll d[100001] = {0};
ll typeCount[100001] = {0};
vector<Sushi> sushis;

int main() {
    int N, K;
    cin >> N >> K;
    rep(i, N) {
        int ti, di;
        cin >> ti >> di;
        t[i] = ti;
        d[i] = di;
        typeCount[ti]++;
    }

   rep(i, N) {
        Sushi s;
        s.i = i;
        s.d = d[i];
        s.typeCount = typeCount[t[i]];
        sushis.pb(s);
   }

   sort(all(sushis));

//   rep(i, sushis.size())  {
//       DEBUG("------");
//       DEBUG(sushis[i].i);
//       DEBUG(sushis[i].d);
//       DEBUG(sushis[i].typeCount);
//   }

    ll sum = 0;
    set<int> eaten;
    rep(i, K) {
        sum += sushis[i].d;
        eaten.insert(t[sushis[i].i]);
    }
    ll result = sum + eaten.size() * eaten.size();
    cout << result << endl;
}
