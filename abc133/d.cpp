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
    int N;
    cin >> N;
    vector<int> dam;
    rep(i, N) {
        int di;
        cin >> di;
        dam.pb(di);
    }

    int firstD = dam[0];
    int lastD = dam[N-1];
    int minD = min(firstD, lastD);

    DEBUG(firstD);
    DEBUG(lastD);
    DEBUG(minD);

    queue<vector<int>> cands;
    for (int m = 0; m <= minD * 2; m = m + 2) {
        vector<int> mounts;
        mounts.pb(m);
        cands.push(mounts);
        DEBUG(m);
    }

    for (int i = 1; i < N - 1; i++) {
        DEBUG(i);
        queue<vector<int>> nextCands;
        while(!cands.empty()) {
            vector<int> mounts = cands.front();
            cout << "------------" << endl;
            rep(i, mounts.size()) DEBUG(mounts[i]);
            cands.pop();
            int lastM = mounts[i - 1];
            int nextM = (dam[i] - (lastM / 2)) * 2;
            DEBUG(lastM);
            DEBUG(nextM);
            if (nextM >= 0) {
                mounts.pb(nextM);
                nextCands.push(mounts);
            }
        }
        cands = nextCands;
        DEBUG(cands.size());
    }

    vector<int> result;

    while(!cands.empty()) {
       vector<int> mounts = cands.front();
       int lastM = mounts[N - 1];
       int nextM = (dam[N - 1] - (lastM / 2)) * 2;
       if (nextM == mounts[0]) result = mounts;
    }

    cout << result[0];
    for (int i = 1; i < result.size(); i++) {
        cout << " " << result[i];
    }
    cout << endl;
}
