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
    int R, G, B, N;
    cin >> R >> G >> B >> N;

    vector<ll> rg;
    int rMax = N / R;
    int gMax = N / G;
    int bMax = N / B;

    repto(r, rMax) {
        repto(g, gMax) {
            int tmpRG = R * r + G * g;
            if (tmpRG <= N) rg.pb(tmpRG);
        }
    }

    sort(all(rg));
    ll result = 0;


    repto(b, bMax) {
        int target = N - b * B;
        decltype(rg)::iterator it = lower_bound(rg.begin(), rg.end(), target);
        if (it != rg.end()) {
            int pos = std::distance(rg.begin(), it);
            while (target == rg[pos]) {
                result++;
                pos++;
            }

        }
    }

    cout << result << endl;
}
