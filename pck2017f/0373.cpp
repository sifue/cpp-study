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

int main(){
    int w, h;
    string s[1000];
    set<string> st;
    char c;
    cin >> w >> h;
    for(int i = 0; i < h; st.insert(s[i++]))
    for(int j = 0; j < w; j++) cin >> c, s[i]+=c;
    sort(s, s + h);
    bool ans = 1;
    int cnt = 0;
    for(int i = 0; i < w; i++){
        if (s[0][i] == '1') cnt++;
        if (s[h / 2 - 1][i] == s[(h + 1) / 2][i]) ans = 0;
    }
    if( (cnt != w / 2 && cnt != (w + 1) / 2) || st.size() != 2 ) ans = 0;
    cout << (ans ? "yes" : "no")  << endl;
    return 0;
}

