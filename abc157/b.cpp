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
    int A[3][3] = { 0 };
    int X = -1;

    rep(i, 3) {
        rep(j, 3) {
            int aij;
            cin >> aij;
            A[i][j] = aij;
        }
    }

    int N;
    cin >> N;
    rep(k, N) {
      int b;
      cin >> b;
      rep(i, 3) {
          rep(j, 3) {
              if (A[i][j] == b) {
                  A[i][j] = X;
              }
          }
      }
    }


    if (
        (A[0][0] == X && A[0][1] == X && A[0][2] == X) ||
        (A[1][0] == X && A[1][1] == X && A[1][2] == X) ||
        (A[2][0] == X && A[2][1] == X && A[2][2] == X) ||
        (A[0][0] == X && A[1][0] == X && A[2][0] == X) ||
        (A[0][1] == X && A[1][1] == X && A[2][1] == X) ||
        (A[0][2] == X && A[1][2] == X && A[2][2] == X) ||
        (A[0][0] == X && A[1][1] == X && A[2][2] == X) ||
        (A[2][0] == X && A[1][1] == X && A[0][2] == X) 
       ) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}
