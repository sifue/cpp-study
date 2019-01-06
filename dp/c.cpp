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
    int N;
    cin >> N;
    int A[100001] = {0}; // 0
    int B[100001] = {0}; // 1
    int C[100001] = {0}; // 2

    int maxhappy[3][100001] = {0};

    rep(i, N) {
        int ai, bi, ci;
        cin >> ai >> bi >> ci;
        A[i] = ai;
        B[i] = bi;
        C[i] = ci;
    }

    maxhappy[0][0] = A[0];
    maxhappy[1][0] = B[0];
    maxhappy[2][0] = C[0];

    for (int i = 1; i < N ; i++) {
        maxhappy[0][i] = max (
            maxhappy[1][i-1] + A[i],
            maxhappy[2][i-1] + A[i]
        );
        maxhappy[1][i] = max (
            maxhappy[0][i-1] + B[i],
            maxhappy[2][i-1] + B[i]
        );
        maxhappy[2][i] = max (
            maxhappy[0][i-1] + C[i],
            maxhappy[1][i-1] + C[i]
        );
    }

    cout << max(maxhappy[0][N-1], max(maxhappy[1][N-1], maxhappy[2][N-1])) << endl;
}
