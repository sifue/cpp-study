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

string S;
ll sum = 0;

int ctoi(char c) {
    if (c >= '0' && c <= '9') {
        return c - '0';
    }
    return 0;
}

void dfs(int i, vector<bool> plus) {
    if (i >= S.size() - 1) {
        // cout << "-----------------" << endl;
        // rep(i, plus.size()) DEBUG(plus[i]);
        ll lsum = 0;
        ll num = ctoi(S[0]);
        rep(j, S.size() - 1) {
            if (plus[j]) {
                lsum += num;
                num = ctoi(S[j+1]);
            } else {
                num *= 10;
                num += ctoi(S[j+1]);
            }
        }
        lsum += num;
        // DEBUG(lsum);
        sum += lsum;
        return;
    }

    vector<bool> hasPlus = plus;
    hasPlus.pb(true);
    dfs(i+1, hasPlus);

    vector<bool> noPlus = plus;
    noPlus.pb(false);
    dfs(i+1, noPlus);
}

int main() {
    cin >> S;
    vector<bool> plus;
    dfs(0, plus);
    cout << sum << endl;
}
