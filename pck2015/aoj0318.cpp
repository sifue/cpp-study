#include <iostream>
#include <set>
#include <algorithm>

#define DEBUG(x) cout << #x << ": " << x << endl;
#define MOD 1000000007

using namespace std;

int main() {
  int n, an, bn, cn;
  cin >> n;
  set<int> A;
  set<int> B;
  set<int> C;

  cin >> an;
  for (int i = 0; i < an; i++) {
    int t;
    cin >> t;
    A.insert(t);
  }

  cin >> bn;
  for (int i = 0; i < bn; i++) {
    int t;
    cin >> t;
    B.insert(t);
  }

  cin >> cn;
  for (int i = 0; i < cn; i++) {
    int t;
    cin >> t;
    C.insert(t);
  }

  set<int> AiB;
  set_intersection(A.begin(), A.end(),
                  B.begin(), B.end(),
                  inserter(AiB, AiB.end()));
  set<int> AiBiC;
  set_intersection(AiB.begin(), AiB.end(),
                  C.begin(), C.end(),
                  inserter(AiBiC, AiBiC.end()));
  set<int> CdA;
  std::set_difference(C.begin(), C.end(),
                      A.begin(), A.end(),
                      inserter(CdA, CdA.end()));
  
  set<int> R;
  set_union(begin(AiBiC), end(AiBiC),
                 begin(CdA), end(CdA),
                 inserter(R, end(R)));


  cout << R.size() << endl;
}
