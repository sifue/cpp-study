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

int main() {
    int len[5] = {0};
    int result = 0;
    int minRest = INF;
    rep(i, 5) {
        cin >> len[i];

        int mod = len[i] % 10;
        if (mod == 0) {
            result += len[i];
        } else {
            result += ((len[i] / 10) * 10) + 10;
            minRest = min(minRest, mod);
        }
    }

    if (minRest == INF) {
        cout << result << endl;
    } else {
        cout << (result - 10 + minRest) << endl;
    }
}
