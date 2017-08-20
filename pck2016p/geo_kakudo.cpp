#include <iostream>
#include <algorithm>
#include <set>
using namespace std;
int main(){
  int N;
  cin >> N;
  int p[N][3];
  int i, j;
  for(i = 0; i < N; i++){
    for(j = 0; j < 3; j++){
      cin >> p[i][j];
    }
  }
  set< set<int> > Q;
  for(int k = 0; k < N; k++){
    set<int> S;
    for(int l = 0; l < 3; l++){
      S.insert(p[k][l]);
    }
    Q.insert(S);
  }
  cout << (N - Q.size()) << endl;
  return 0;
}