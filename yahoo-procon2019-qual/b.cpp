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

int arrived[5] = {0};
int path[5][5] = {0};

void dfs(int start) {
    if (start == 0) return;
    if (arrived[start] == 1) return;
    arrived[start] = 1;
    for (int t = 1; t < 5; t++) {
        if(path[start][t]) {
            path[start][t] = 0;
            path[t][start] = 0;
            dfs(t);
        }
    }
}

int main() {
    rep(i, 3) {
        int a, b;
        cin >> a >> b;
        path[a][b] = 1;
        path[b][a] = 1;
    }
    dfs(1);
    bool isAll = true;
    for (int i = 1; i <= 4; i++) {
        if (arrived[i] == 0) isAll = false;
    }
    cout << (isAll ? "YES" : "NO") << endl;
}
