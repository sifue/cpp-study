#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

#define DEBUG(x) cout << #x << ": " << x << endl;
#define MOD 1000000007

inline long long strHash(string str) {
  long long hashValue = 1;
  int length = str.size();
  for(int i = 0; i < length; i++) {
    hashValue = hashValue * 997 + str[i];
  }
  return hashValue;
}

int main() {

  set<long long> hashs;
  std::hash<std::string> hash_fn;
  string A;
  cin >> A;
  int length = A.size();
  hashs.insert(strHash(A));

  for(int i = 0; i < length; i++) {
    for(int j = 0; j < length; j++) {
      string tmp = A;
      tmp[i] = A[j];
      tmp[j] = A[i];
      // DEBUG(tmp);
      // DEBUG(hash_fn(tmp));
      // DEBUG(strHash(tmp));
      hashs.insert(strHash(tmp));
    }
  }

  cout << hashs.size() << endl;
}
