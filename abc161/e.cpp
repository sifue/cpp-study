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

int N, K, C;
string S;
vector<vector<int>> patterns;

void dfs(int dayIndex, int cntWorkDay, int lestYutoriDay, vector<int> pattern) {
    if (dayIndex >= N) {
        // 最終日でかつ指定日数労働ならパターン追加
        if (cntWorkDay == K) {
            patterns.pb(pattern);
        }
        return;
    } 

    if (cntWorkDay == K) {
        // 働き切ってるなら0埋めしてパターン追加
        int notWorkDays = N - dayIndex;
        vector<int> notWorkPattern = pattern;
        rep(i, notWorkDays) {
            notWorkPattern.pb(0);
        }
        patterns.pb(notWorkPattern);
        return;
    }

    bool canWork = (S[dayIndex] == 'o') && (lestYutoriDay <= 0);
    if (canWork) {
        // 働く
        vector<int> workPattern = pattern;
        workPattern.pb(1);
        dfs(dayIndex + 1,  cntWorkDay + 1, C, workPattern);
    }
    // 働かない
    vector<int> notWorkPattern = pattern;
    notWorkPattern.pb(0);
    dfs(dayIndex + 1,  cntWorkDay, lestYutoriDay - 1, notWorkPattern);
}

int main() {
    cin >> N >> K >> C;
    cin >> S;
    vector<int> pattern;
    dfs(0, 0, 0, pattern);

    rep(i, N) {
        bool isAllPattenWork = true;
        rep(j, patterns.size()) {
            if(patterns[j][i] != 1) {
                isAllPattenWork = false;
                break;
            }
        }

        if (isAllPattenWork) {
            cout << (i + 1) << endl;
        }
    }
}
