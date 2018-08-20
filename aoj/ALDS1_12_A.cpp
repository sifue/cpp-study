#include <bits/stdc++.h>  // g++ -std=c++14 -o a a.cpp

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

__attribute__((constructor))
void initial() {
  cin.tie(0);
  ios::sync_with_stdio(false);
}

int E[2001][2001] = {{0}};  
int T[2001] = {0};  
const int TAKEN = 1;

int main() {
  int N;
  cin >> N;
  
  rep(i, N) {
    rep(j, N) {
      int w;
      cin >> w;
      if (w == -1) {
         E[i][j] = INF;
      } else {
         E[i][j] = w;
      }
      // DEBUG(E[i][j]);	
	}
  }
 
  T[0] = TAKEN;
  int count = 1; 
  int sum = 0;

  while (count < N) {
    int minW = INF;
    int minI = -1;
    int minJ = -1;
    rep(i, N) {
       if (T[i] == TAKEN) {
          rep(j, N) {
			if(T[j] != TAKEN) {
              int w = E[i][j];
              if (w < minW) {
//                DEBUG(i);
//                DEBUG(j);
//                DEBUG(w);
                minW = w;
                minI = i;
                minJ = j;
              }
			}
          }
       }
    }
//    DEBUG("--------------------");
//    DEBUG(minI);
//    DEBUG(minJ);
//    DEBUG(minW);

	T[minJ] = TAKEN;
//	rep (i , N) {
//		DEBUG(i);
//		DEBUG(T[i]);
//	}

	count++;
	sum += minW;
  }

  cout << sum << endl; 
}
