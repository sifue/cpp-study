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
    int N, M;
    cin >> N >> M;

    vector<vector<int>> yearRanks;
    rep(i, N) {
        vector<int> yearRank;
        yearRanks.pb(yearRank);
    }

    vector<P> input;
    rep(i, M) {
        int Pi, Yi;
        cin >> Pi >> Yi;
        input.pb(make_pair(Pi, Yi));
        yearRanks[Pi - 1].pb(Yi);
    }

    // sort and create map
    map<int, int> rankMap; //  key: year, value: rank
    rep(i, N) {
        sort(all(yearRanks[i]));
        int rank = 1;
        for(int year : yearRanks[i]) {
            rankMap.insert(make_pair(year, rank));
            rank++;
        }
    }

    rep(i, M) {
        int p = input[i]._1;
        int y = input[i]._2;
        int rank = rankMap.at(y);

        cout << setfill('0') << setw(6) << right << p;
        cout << setfill('0') << setw(6) << right << rank;
        cout << endl;
    }
}
