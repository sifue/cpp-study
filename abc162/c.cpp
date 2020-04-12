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

ll euclidean_gcd(ll a, ll b) {
    if(a < b) euclidean_gcd(b, a);
    ll r;
    while ((r = a % b)) {
        a = b;
        b = r;
    }
    return b;
}

int M[201][201] = {0};

int main() {
    int K;
    cin >> K;
    for (int i = 1; i <= 200; i++) {
        for (int j = 1; j <= 200; j++) {
            M[i][j] = euclidean_gcd(i, j);
        }
    }
    
    ll sum = 0;
    for (int a = 1; a <= K; a++) {
        for (int b = 1; b <= K; b++) {
            for (int c = 1; c <= K; c++) {
                int pgcd = M[a][b];
                int result = M[pgcd][c];
                sum += result; 
            }
        }
    }
    cout << sum << endl;
}
