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

int ctoi(char c) {
	switch (c) {
		case '0': return 0;
		case '1': return 1;
		case '2': return 2;
		case '3': return 3;
		case '4': return 4;
		case '5': return 5;
		case '6': return 6;
		case '7': return 7;
		case '8': return 8;
		case '9': return 9;
		default: return 0;
	}
}

int main() {
    string S;
    cin >> S;
    int target = 753;
    int len = S.length();
    int minDiff = INF;

    for (int i = 0; i < (len - 2); i++){
        int sum = 0;
        sum += 100 * ctoi(S[i]);
        sum += 10 * ctoi(S[i+1]);
        sum += ctoi(S[i+2]);
        // DEBUG(S[i]);
        // DEBUG(S[i+1]);
        // DEBUG(S[i+2]);
        // DEBUG(sum);
        minDiff = min(minDiff, abs(target - sum));
    }

    cout << minDiff << endl;
}
