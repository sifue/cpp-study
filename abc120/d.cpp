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

// 素集合データ構造 UnionFind T(N); で構築
struct UnionFind
{
  // par[i]：データiが属する木の親の番号。i == par[i]のとき、データiは木の根ノードである
  vector<ll> par;
  // sizes[i]：根ノードiの木に含まれるデータの数。iが根ノードでない場合は無意味な値となる
  vector<ll> sizes;

  UnionFind(ll n) : par(n), sizes(n, 1) {
    // 最初は全てのデータiがグループiに存在するものとして初期化
    rep(i,n) par[i] = i;
  }

  // データxが属する木の根を得る
  ll find(ll x) {
    if (x == par[x]) return x;
    return par[x] = find(par[x]);  // 根を張り替えながら再帰的に根ノードを探す
  }

  // 2つのデータx, yが属する木をマージする
  void unite(ll x, ll y) {
    // データの根ノードを得る
    x = find(x);
    y = find(y);

    // 既に同じ木に属しているならマージしない
    if (x == y) return;

    // xの木がyの木より大きくなるようにする
    if (sizes[x] < sizes[y]) swap(x, y);

    // xがyの親になるように連結する
    par[y] = x;
    sizes[x] += sizes[y];
    // sizes[y] = 0;  // sizes[y]は無意味な値となるので0を入れておいてもよい
  }

  // 2つのデータx, yが属する木が同じならtrueを返す
  bool same(ll x, ll y) {
    return find(x) == find(y);
  }

  // データxが含まれる木の大きさを返す
  ll size(ll x) {
    return sizes[find(x)];
  }
};

int main() {
    ll N, M;
    cin >> N >> M;
    vector<P> path;
    rep(i, M) {
        ll A, B;
        cin >> A >> B;
        path.pb(make_pair(A, B));
    }

    reverse(all(path));
    vector<ll> results;
    UnionFind T(N);
    ll res = (N * (N -1) / 2);
    rep (i, M) {
        // 答えを追加
        results.pb(res);

        // 次の答えを作成
        P p = path[i];
        ll a = p._1 - 1;
        ll b = p._2 - 1;

        // パスの両端の連結成分が違うなら、その両端の数を掛けたものを前より引く
        if (T.find(a) != T.find(b)) {
            res = res - (T.size(a) * T.size(b));
        }

        // 結合する
        T.unite(a, b);
    }

    reverse(all(results));

    rep (i, M) {
        cout << results[i] << endl;
    }
}
