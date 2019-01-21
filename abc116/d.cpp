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
    bool operator<( const Sushi& right ) const {
        return d > right.d;
    }
};

struct SushiOut {
    int i;
    ll d;
    int t;
    bool operator<( const SushiOut& right ) const {
        return d > right.d;
    }
};

ll t[100001] = {0};
ll d[100001] = {0};
vector<Sushi> sushis;

ll getPoint(priority_queue<SushiOut> q) {
    ll sum = 0;
    set<int> eatenType;
    while (q.size() > 0) {
        sum += q.top().d;
        eatenType.insert(q.top().t);
        q.pop();
    }

    ll result = sum + eatenType.size() * eatenType.size();
    return result;
}

int main() {
    int N, K;
    cin >> N >> K;
    rep(i, N) {
        int ti, di;
        cin >> ti >> di;
        t[i] = ti;
        d[i] = di;
    }

   rep(i, N) {
        Sushi s;
        s.i = i;
        s.d = d[i];
        s.t = t[i];
        sushis.pb(s);
   }

   sort(all(sushis));

   rep(i, sushis.size())  {
       DEBUG("------");
       DEBUG(sushis[i].i);
       DEBUG(sushis[i].d);
       DEBUG(sushis[i].t);
   }

    int typeCount[100001] = {0};
    priority_queue<SushiOut> q;
    vector<SushiOut> notSelected;
    rep(i, N) {
        SushiOut so;
        so.i = sushis[i].i;
        so.d = sushis[i].d;
        so.t = sushis[i].t;
        if (i < K) {
            typeCount[so.t]++;
            q.push(so);
        } else {
            notSelected.pb(so);
        }
    }

    priority_queue<SushiOut> qp = q;
    while (qp.size() > 0) {
        DEBUG("------");
        DEBUG(qp.top().i);
        DEBUG(qp.top().d);
        DEBUG(qp.top().t);
        qp.pop();
    }

    DEBUG("---入れ替え処理---");

    ll currentMax = 0;
    ll nextMax = getPoint(q);
    do {
        currentMax = nextMax;
        nextMax = 0;
        priority_queue<SushiOut> newQ;
        int newTypeCount[100001] = {0};
        bool isFound = false;
        while (q.size() > 0) {
            DEBUG(q.top().i);
            DEBUG(q.top().d);
            DEBUG(q.top().t);
            DEBUG(typeCount[q.top().t]);
            if (typeCount[q.top().t] > 1 && !isFound) {
                DEBUG("---重複発見！---");
                DEBUG(q.top().t);
                isFound = true;
            } else {
                newQ.push(q.top());
                newTypeCount[q.top().t]++;
            }
            q.pop();
        }

        rep(i, notSelected.size())  {
            DEBUG("------");
            DEBUG(notSelected[i].i);
            DEBUG(notSelected[i].d);
            DEBUG(notSelected[i].t);
        }

        if (isFound) {
            rep (i, notSelected.size()) {
                if (newTypeCount[notSelected[i].t] == 0) {
                    newQ.push(notSelected[i]);
                    break;
                }
            }
        }
        nextMax = getPoint(newQ);
        DEBUG(newQ.size());
        DEBUG(currentMax);
        DEBUG(nextMax);
        q = newQ;
    } while (currentMax < nextMax);

    cout << currentMax << endl;
}
