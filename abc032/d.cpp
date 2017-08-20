#include <iostream>
#include <vector>

using namespace std;

#define P(s) cout << s << endl;

int main() {
  int n, w;
  cin >> n >> w;
  vector<pair<int, int>> payloads;
  for (int i = 0; i < n; i++) {
    int vi, wi;
    cin >> vi >> wi;
    payloads.push_back(make_pair(vi, wi));
  }

  int values[200][INT_MAX] = {}; // [荷物の個数][重さ] => 価値

  for (pair<int, int> payload : payloads) {
    for (int i = 0; i < n; i++) {
      for (int w = 0; w < INT_MAX; w++) {
      

      
      }
    }
  }

  cout << payloads.size() << endl;
}
