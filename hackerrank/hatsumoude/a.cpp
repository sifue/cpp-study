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

int c500 = 0, c100 = 0, c50 = 0, c10 = 0, c5 = 0, c1 = 0, total = 0;
bool result = false;

void rec(int s500, int s100, int s50, int s10, int s5, int s1, int index) {
    if (index == 0) {
        repto (i, c500) {
            rec(i, s100, s50, s10, s5, s1, index + 1);
        }
    } else if (index == 1) {
        repto (i, c100) {
            rec(s500, i, s50, s10, s5, s1, index + 1);
        }
    } else if (index == 2) {
        repto (i, c50) {
            rec(s500, s100, i, s10, s5, s1, index + 1);
        }
    } else if (index == 3) {
        repto (i, c10) {
            rec(s500, s100, s50, i, s5, s1, index + 1);
        }
    } else if (index == 4) {
        repto (i, c5) {
            rec(s500, s100, s50, s10, i, s1, index + 1);
        }
    } else if (index == 5) {
        repto (i, c1) {
            rec(s500, s100, s50, s10, s5, i, index + 1);
        }
    } else if (index == 6) {
        int sum = s500 * 500 + s100 * 100 + s50 * 50 + s10 * 10 + s5 * 5 + s1 * 1;
        if(sum == total) result = true;
        return;
    } 
}

int main() {
    cin >> c500 >> c100 >> c50 >> c10 >> c5 >> c1 >> total;
    rec(0, 0, 0, 0, 0, 0, 0);

    if(result) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    
}
