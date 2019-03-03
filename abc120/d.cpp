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

int cnt[100001] = {0};
vector<ll> result;
vector<P> bridge;
ll maxInconv;

struct UnionFind {
    vector<int> par; // par[i]:iの親の番号　(例) par[3] = 2 : 3の親が2

    UnionFind(int N) : par(N) { //最初は全てが根であるとして初期化
        for(int i = 0; i < N; i++) par[i] = i;
    }

    int root(int x) { // データxが属する木の根を再帰で得る：root(x) = {xの木の根}
        if (par[x] == x) return x;
        return par[x] = root(par[x]);
    }

    void unite(int x, int y) { // xとyの木を併合
        int rx = root(x); //xの根をrx
        int ry = root(y); //yの根をry
        if (rx == ry) return; //xとyの根が同じ(=同じ木にある)時はそのまま
        par[rx] = ry; //xとyの根が同じでない(=同じ木にない)時：xの根rxをyの根ryにつける
    }

    bool same(int x, int y) { // 2つのデータx, yが属する木が同じならtrueを返す
        int rx = root(x);
        int ry = root(y);
        return rx == ry;
    }
};

int main() {
    int N, M;
    cin >> N >> M;
    rep(i, M) {
        int A, B;
        cin >> A >> B;
        bridge.pb(make_pair(A, B));
    }
    reverse(all(bridge));

    maxInconv = (N * (N - 1)) / 2;
    result.pb(maxInconv);

    UnionFind tree(N);
    // DEBUG(M);
    // DEBUG(bridge.size());
    rep(i, M-1) {
        P b = bridge[i];
        // DEBUG(b._1);
        // DEBUG(b._2);
        tree.unite(b._1 - 1, b._2 - 1);

        // cout << "------------" << endl;
        // DEBUG(i);

        rep(j, N) {
            cnt[j] = 0;
        }

        // rep(j, N) {
        //     DEBUG(cnt[j]);
        // }
        // cout << "------------" << endl;
        rep(j, N) {
            // DEBUG(tree.root(j));
            cnt[tree.root(j)] += 1;
        }

        // rep(j, N) {
        //     DEBUG(cnt[j]);
        // }

        ll conv = 0;

        rep(j, N) {
            if (cnt[j] > 1) {
                conv += (cnt[j] * (cnt[j] - 1)) / 2;
            }
        }

        // DEBUG(conv);
        result.pb(maxInconv - conv);
    }

    reverse(all(result));

    rep(i, M) {
        if (result[i] >= 0) {
            cout << result[i] << endl;
        } else {
            cout << 0 << endl;
        }
    }
}
