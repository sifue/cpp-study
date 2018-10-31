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
    int W, H, N;
    cin >> W >> H >> N;
    int minX = 0;
    int maxX = W;
    int minY = 0;
    int maxY = H;

    rep(i, N) {
        int xi, yi, ai;
        cin >> xi >> yi >> ai;

        if (ai == 1) {
            minX = max(minX, xi);
        } else if (ai == 2) {
            maxX = min(maxX, xi);
        } else if (ai == 3) {
            minY = max(minY, yi);
        } else if (ai == 4) {
            maxY = min(maxY, yi);
        }
    }

    int result = (maxX - minX) * (maxY - minY);
    if ((maxX - minX) <= 0  || (maxY - minY) <= 0) {
        cout << 0 << endl;
    } else {
        cout << result << endl;
    }
}
