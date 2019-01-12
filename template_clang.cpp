#include <iostream> // clang++ -std=c++14 -o template template_clang.cpp
#include <vector>

using namespace std;

typedef pair<int, int> P;
typedef long long ll;

#define rep(i, n) for(int i = 0; i < (n); i++)
#define repto(i, n) for(int i = 0; i <= (n); i++)
#define all(c) (c).begin(), (c).end()
#define uniq(c) c.erase(unique(all(c)), (c).end()) // ユニークなvectorにする。連続した値を除去して切り出す。
#define _1 first
#define _2 second
#define pb push_back
#define INF 1145141919
#define MOD 1000000007
#define DEBUG(x) cout << #x << ": " << x << endl;

int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

bool isEnd(vector<int> sushis, vector<int> eatings) {
    int sum = 0;

    rep(i, sushis.size()) {
        sum += sushis[i];
    }

    rep(i, eatings.size()) {
        sum += eatings[i];
    }

    return sum == 0;
}

int main(void){

    int L, N, M;
    cin >> L >> N >> M;
   
    int MAX = 101;
    vector<int> humans(MAX);
    vector<int> sushis(MAX);
    vector<int> eatings(MAX);
    int t = 0;

    rep (i, MAX - 1) {
        humans[i] = 0;
    }

    rep (i, MAX - 1) {
        sushis[i] = 0;
    }

    rep (i, MAX - 1) {
        eatings[i] = 0;
    }
    
    rep (i, N) {
        int human;
        cin >> human;
        humans[human] = 1;
    }
    
    rep (i, M) {
        int sushi;
        cin >> sushi;
        sushis[sushi] = 1;
    }
    cout << t << endl;
    return 0;
}
