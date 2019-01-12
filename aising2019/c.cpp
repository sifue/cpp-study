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

__attribute__((constructor))
void initial() {
    cin.tie(0);
    ios::sync_with_stdio(false);
}
 
string grid[401];
int H, W;
ll result = 0;

vector<P> path[401][401]; // 各マスから移動できる経路
ll col[401][401] = {0}; // そのマスがどの連結成分に属するか
ll cnts = 0; // 連結成分のID
ll B[160802] = {0}; // 各連結成分ごとの黒の数
ll WW[160802] = {0}; // 各連結成分ごとの白の数
 
void dfs(int x, int y) {
    if (col[x][y] > 0) return;
    col[x][y] = cnts;
    if (grid[x][y] == '.') WW[cnts]++;
    if (grid[x][y] == '#') B[cnts]++;
    rep(i, path[x][y].size()) {
        dfs(path[x][y][i]._1, path[x][y][i]._2);
    }
}
 
int main() {
    cin >> H >> W;
    rep(i, H) {
        string si;
        cin >> si;
        grid[i] = si;
    }

    // 各マスの経路作成
    rep(i, H) {
        rep(j, W) {
            char ci = grid[i][j];
            rep(d, 4) {
                int x = i + dx[d];
                int y = j + dy[d];
                if (x < 0 || x >= H || y < 0 || y >= W) continue;
                if (ci == '.' && grid[x][y] == '#') {
                    path[i][j].pb(make_pair(x, y));
                }
                if (ci == '#' && grid[x][y] == '.') {
                    path[i][j].pb(make_pair(x, y));
                }
            }
        }
    }

    // 深さ優先探索で連結成分作成しつつ、白黒の数を深さ優先でカウント
    rep(i, H) {
        rep(j, W) {
            if (col[i][j] != 0) continue;
            cnts++;
            dfs(i, j);
        }
    }

    // 全ての連結成分の個数分 白 * 黒を足し合わせる
    for (int i = 1; i <= cnts; i++) {
        result += 1LL * B[i] * WW[i];
    }
 
    cout << result << endl;
}