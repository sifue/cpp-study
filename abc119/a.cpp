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

int ctoi(char c) {
    if (c >= '0' && c <= '9') {
        return c - '0';
    }
    return 0;
}

int main() {
    string s;
    cin >> s;

    int y, m, d;

    y = ctoi(s[0]) * 1000 + ctoi(s[1]) * 100 + ctoi(s[2]) * 10 + ctoi(s[3]);
    m = ctoi(s[5]) * 10 + ctoi(s[6]);
    d = ctoi(s[8]) * 10 + ctoi(s[9]);


    if (y > 2019) {
        cout << "TBD" << endl;
        return 0;
    } else if (y < 2019) {
        cout << "Heisei" << endl;
        return 0;
    }

    if (m > 4) {
        cout << "TBD" << endl;
        return 0;
    } else if (m < 4) {
        cout << "Heisei" << endl;
        return 0;
    }

    if (d <= 30) {
        cout << "Heisei" << endl;
        return 0;
    } else {
        cout << "TBD" << endl;
        return 0;
    }
}
