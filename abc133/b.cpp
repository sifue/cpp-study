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
    set<int> squares;
    for (int i = 1; i < 128; i++) {
        int square = i * i;
        // DEBUG(square);
        squares.insert(square);
    }

    int N, D;
    cin >> N >> D;
    int X[10][10] = {0};

    rep(i, N) {
        rep(j, D) {
            int xij;
            cin >> xij;
            X[i][j] = xij;
            // DEBUG(i);
            // DEBUG(j);
            // DEBUG(X[i][j]);
        }
    }

    // cout << "------------" << endl;
    int result = 0;
    rep(y, N) {
        rep(z, N) {
            int sum = 0;
            rep(j, D) {
                sum += (X[y][j] - X[z][j]) * (X[y][j] - X[z][j]);
            }
            // DEBUG(y);
            // DEBUG(z);
            // DEBUG(sum);
            if (squares.count(sum) > 0) result++;
        }
    }

    cout << (result / 2) << endl;
}
