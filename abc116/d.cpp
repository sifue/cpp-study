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
    int t;
    int typeCount;
    bool operator<( const Sushi& right ) const {
        return d > right.d;
    }
};

struct SushiOut {
    int i;
    ll d;
    int t;
    int typeCount;
    bool operator<( const SushiOut& right ) const {
        return typeCount == right.typeCount ? d < right.d : typeCount > right.typeCount;
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
        s.t = t[i];
        s.typeCount = typeCount[t[i]];
        sushis.pb(s);
   }

   sort(all(sushis));

   rep(i, sushis.size())  {
       DEBUG("------");
       DEBUG(sushis[i].i);
       DEBUG(sushis[i].d);
       DEBUG(sushis[i].typeCount);
   }

    set<int> eatenType;
    priority_queue<SushiOut> q;
    vector<Sushi> notSelected;
    rep(i, N) {
        if (i < K) {
            eatenType.insert(sushis[i].i);
            SushiOut so;
            so.i = sushis[i].i;
            so.d = sushis[i].d;
            so.t = sushis[i].t;
            so.typeCount = sushis[i].typeCount;
            q.push(so);
        } else {
            notSelected.pb(sushis[i]);
        }
    }

    while(q.top().typeCount > 1) {
        rep(i, notSelected.size()) {
            if (eatenType.count(notSelected[i].i) == 0) {
                DEBUG("Change!---");
                DEBUG(q.top().i);
                DEBUG(notSelected[i].i);
                eatenType.erase(q.top().i);
                q.pop();
                eatenType.insert(notSelected[i].i);
                SushiOut so;
                so.i = notSelected[i].i;
                so.d = notSelected[i].d;
                so.t = notSelected[i].t;
                so.typeCount = notSelected[i].typeCount;
                q.push(so);
                break;
            }
        }
    }

    ll sum = 0;
    while (q.size() > 0) {
        sum += q.top().d;
        q.pop();
    }

    ll result = sum + eatenType.size() * eatenType.size();
    cout << result << endl;
}
