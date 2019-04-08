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

int N;
map<int, map<string, int>> memo;
char C[4] = {'A', 'C', 'T', 'G' };

bool ok(string last4) {
    rep(i, 4) {
        string s = last4;
        // DEBUG(s);
        if (i >= 1) { // 交換なし、0,1,2の位置での交換
            s[i - 1] = last4[i];
            s[i] = last4[i - 1];
        }
        if (s.find("AGC") != string::npos) {
            return false;
        }
    }
    return true;
}

int dfs(int cur, string last3) {
    if (memo.count(cur) > 0 && memo.at(cur).count(last3) > 0) return memo.at(cur).at(last3);
    if (cur == N) return 1;
    int ret = 0;
    rep(i, 4) {
        // DEBUG(last3 + C[i]);
        // DEBUG(ok(last3 + C[i]));
        if (ok(last3 + C[i])){

            ret = (ret + dfs(cur + 1, last3.substr(1, 2) + C[i])) % MOD;
        }
    }
    if (memo.count(cur) == 0) {
        map<string, int> m;
        memo.insert(make_pair(cur, m));
    }
    memo.at(cur).insert(make_pair(last3, ret));
    return ret;
}

int main() {
    cin >> N;
    int result = dfs(0, "TTT");
    cout << result << endl;
}
