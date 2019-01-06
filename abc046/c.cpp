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
    int minT = 0;
    int minA = 0;
    rep(i, N) {
        int Ti, Ai;
        cin >> Ti >> Ai;
        if (i == 0) {
            minT = Ti;
            minA = Ai;
        } else {
            bool isFinished = false;
            while (!isFinished) {
                double ratioT = (double)minT / (double)Ti;
                double ratioA = (double)minA / (double)Ai;
                //DEBUG(ratioT);
                //DEBUG(ratioA);
                if (ratioT == ratioA) {
                    isFinished = true;
                } else if (ratioT > ratioA) {
                    int addA = ceil(ratioA - ratioT);
                    if (addA < 1) addA = 1;
                    //DEBUG(addA);
                    minA += addA;
                } else if (ratioA > ratioT) {
                    int addT = ceil(ratioT - ratioA);
                    if (addT < 1) addT = 1;
                    //DEBUG(addT);
                    minT += addT;
                }
            }
        }
    }
    cout << (minT + minA) << endl;
}
