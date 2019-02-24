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
    vector<int> l;
    vector<int> t;
    bool used[8] = {0};
    int current[3] = {0};
    int cost = 0;

    cin >> N;
    rep(i, 3) {
        int ti;
        cin >> ti;
        t.pb(ti);
    }

    rep(i, N) {
        int li;
        cin >> li;
        l.pb(li);
    }
    sort(all(l));
    reverse(all(l));
    sort(all(t));
    reverse(all(t));

    // 9以下で一番近いのから埋める、A, B, C順に
    rep(j, 3) {
        int diff = INF;
        int tIndex = -1;

        rep(i, N) {
            int tempDiff = abs(t[j] - l[i]);
            if (tempDiff < diff
                    && !used[i]) {
                diff  = tempDiff;
                tIndex = i;
            }
        }

        current[j] += l[tIndex];
        used[tIndex] = 1;

        DEBUG(j);
        DEBUG(tIndex);
        DEBUG(l[tIndex]);
    }

    // 残ったもので合成魔法でで最適化できるところまでやる
    int done = -1;
    while (done != 0) {
        done = 0;
        rep (j, 3) {
            int effect = -1;
            int tIndex = -1;
            rep (i, N) {
                if (!used[i]) {
                    // 足して目的との差分を見る
                    int currentDiff = abs(t[j] - current[j]);
                    int tempDiff = abs(t[j] - (current[j] + l[i]));
                    int tempEffect = currentDiff - tempDiff;

                    if (tempEffect > 10 // 結合して10以上近づいた
                           && tempEffect > effect
                           ) {
                       effect  = tempEffect;
                       tIndex = i;
                    }
               }
            }

            if (tIndex >= 0) {
                done++;
                current[j] += l[tIndex];
                used[tIndex] = 1;
                cost += 10;
            }
        }
    }

    // 最後に調整コスト
    rep (j, 3) {
        cost += abs(t[j] - current[j]);
    }

    cout << cost << endl;
}
