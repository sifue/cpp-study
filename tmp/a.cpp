#include <algorithm>
#include <iostream>
#include <vector>
#define DEBUG(x) cout << #x << ": " << x << endl;
using namespace std;
int main(void) {
  int N, H;
  cin >> N >> H;
  vector<int> a, b;
  for (int i = 0; i < N; i++) {
    int ai, bi;
    cin >> ai >> bi;
    a.push_back(ai);
    b.push_back(bi);
  }
  int a_max = *max_element(a.begin(), a.end());
  sort(b.begin(), b.end());
  int answer = 0;
  int remain = H;
  int count = b.size() - 1;

  // DEBUG(a_max);
  while (1) {
    // DEBUG(remain);
    // DEBUG(b[count]);
    if (b[count] > a_max) {
      remain = remain - b[count];
      count--;
    } else {
      remain = remain - a_max;
    }
    answer++;
    if (remain <= 0) {
      break;
    }
  }
  cout << answer << endl;
  return 0;
}