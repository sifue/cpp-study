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

int main() {
    int N, K;
    cin >> N >> K;
    int H[100001] = {0};
    int mincost[100001] = {INF};
    rep(i, N) {
        int hi;
        cin >> hi;
        H[i] = hi;
    }

    mincost[0] = 0;
    for (int i = 1; i < N ; i++) {
        int localmin = INF;
        for (int j = 1; (0 <= (i - j) && j <= K); j++) {
            localmin = min(
                localmin,
                mincost[i-j] + abs(H[i] - H[i-j])
            );
        }
        mincost[i] = localmin;
        // DEBUG(i);
        // DEBUG(mincost[i]);
    }

    cout << mincost[N-1] << endl;
}