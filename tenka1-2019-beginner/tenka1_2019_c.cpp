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
string S;

int dfs (int i, bool goBlack) {
    // if (i > 5) exit(0);
    // cout << "------------" << endl;
    // DEBUG(i);
    // DEBUG(N);
    // DEBUG(goBlack);
    if (i == N - 1) {
        if (goBlack) {
            if (S[i] == '#') return 0;
            if (S[i] == '.') return 1;
        } else {
            if (S[i] == '#') return 1;
            if (S[i] == '.') return 0;
        }
    }

    if (goBlack) {
        int cntB = 0;
        for (int j = i; j < N; j++) {
            if (S[j] == '.') cntB++;
        }
        return cntB;
    } else {
        // 黒があるところまで進める
        int j;
        bool getBlack = false;
        for (j = i; j < N - 1; j++) { // 最後一つ前まで進める
            if (S[j] == '#') {
                getBlack = true;
                break;
            }
        }
        // DEBUG(j);
        if (getBlack) {
          int goBlackResult = dfs(j + 1, true); // ここから全部黒くする
          // DEBUG(goBlackResult);
          int revBlackReslt = 1 + dfs(j + 1, false); // 黒を白に反転して進める
          // DEBUG(revBlackReslt);
          // return revBlackReslt;
          return min(goBlackResult, revBlackReslt);
        } else {
          return dfs(j, false);
        }

    }
}

int main() {
    cin >> N >> S;
    int result = dfs(0, false);
    cout << result << endl;
}
