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
    rep(i, 4) {
        int ti, ni;
        cin >> ti >> ni;
        if (ti == 1) {
            cout << (6000 * ni) << endl;
        } else if (ti == 2) {
            cout << (4000 * ni) << endl;
        } else if (ti == 3) {
            cout << (3000 * ni) << endl;
        } else if (ti == 4) {
            cout << (2000 * ni) << endl;
        }
    }
}
