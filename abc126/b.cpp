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
    string S;
    cin >> S;
    // DEBUG(S);
    int first = ctoi(S[0]) * 10 + ctoi(S[1]);
    int second = ctoi(S[2]) * 10 + ctoi(S[3]);

    bool isMMYY = false;
    bool isYYMM = false;

    // DEBUG(first);
    // DEBUG(second);

    if (1 <= first && first <= 12) {
        isMMYY = true;
    }
    if (1 <= second && second <= 12 ) {
        isYYMM = true;
    }
    // DEBUG(isMMYY);
    // DEBUG(isYYMM);

    if (isMMYY && isYYMM) {
        cout << "AMBIGUOUS" << endl;
    } else if (isMMYY) {
        cout << "MMYY" << endl;
    } else if (isYYMM) {
        cout << "YYMM" << endl;
    } else {
        cout << "NA" << endl;
    }
}
