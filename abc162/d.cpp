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

__attribute__((constructor))
void initial() {
    cin.tie(0);
    ios::sync_with_stdio(false);
}

int main() {
    int N;
    cin >> N;
    string S;
    cin >> S;

    ll cnt = 0;
    for (int i = 0; i < N - 2; i++) {
        set<char> s1;
        s1.insert(S[i]);
        for (int j = i + 1; j < N - 1; j++) {
            int diff = j - i;
            set<char> s2 = s1;
            s2.insert(S[j]);
            if(s2.size() != 2) continue;
            for (int k = j + 1; k < N ; k++) {
                set<char> s3 = s2;
                if(diff != k - j){
                    s3.insert(S[k]);
                    if(s3.size() == 3) cnt++;
                }
            }
        }
        s1.clear();
    }
    
    cout << cnt << endl;
}
