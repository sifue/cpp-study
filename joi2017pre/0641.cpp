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
    int N, A, B, C, D;
    cin >> N >> A >> B >> C >> D;
    int resultX, resultY;

    resultX = (N / A) * B;
    if (N % A != 0) {
        resultX += B;
    }

    resultY = (N / C) * D;
    if (N % C != 0) {
        resultY += D;
    }

    cout << min(resultX, resultY) << endl;
}
