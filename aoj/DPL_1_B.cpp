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
    int N, W;
    cin >> N >> W;
    vector<P> items;
    int value[101] = {0};
    int weight[101] = {0};
    int vmax[101][10001] = {0};

    rep(i, N) {
        int vi, wi;
        cin >> vi >> wi;
        value[i] = vi;
        weight[i] = wi;
    }

    rep(j, W + 1) {
        if(j < weight[N-1]) {
            vmax[N-1][j] = 0;
        } else {
            vmax[N-1][j] = value[N-1];
        }
    }

    for (int i = N-2; i >= 0; i--) {
        for (int j = 0; j <= W; j ++) {
            if (j < weight[i]) {
                vmax[i][j] = vmax[i + 1][j];
            } else {
                vmax[i][j] = max(
                    vmax[i+1][j], 
                    value[i] + vmax[i+1][j - weight[i]]
                );
            }
        }
    }

    // rep(i, N) {
    //     rep(j, W + 1) {
    //         DEBUG(i);
    //         DEBUG(j);
    //         DEBUG(vmax[i][j]);
    //     }
    // }

    cout << vmax[0][W] << endl;
}
