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

int main() {
    int N;
    cin >> N;
    vector<int> h;
    int count = 0;
    int maxH = 0;
    rep(i, N) {
        int hi;
        cin >> hi;
        h.pb(hi);
        maxH = max(maxH, hi);
    }

    for(int limit = 1; limit <= maxH; limit++) {
        bool isWater = false;
        rep(i, N) {
            if (h[i] >= limit) {
                if (!isWater) count++;
                isWater = true;
            } else {
                isWater = false;
            }
        }
    }
    cout << count << endl;
}
