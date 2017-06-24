#include <iomanip>
#include <iostream>
#include <queue>
#include <stack>
#include <vector>

using namespace std;

const int mf = 1000000007;

long long get_pattern(int rest, int select) {
  if (select == 0)
    return 1;
  long long pattern = (get_pattern(rest - 1, select - 1) * rest / select) % mf;
  //cout << "pattern:" << pattern << endl;
  return pattern;
}

int main() {
  int r, c, x, y, d, l;
  cin >> r >> c >> x >> y >> d >> l;

  // 1. まずは区画の置き方のパターンを計算する ps
  // 2. 区画内のデスクとラックの置き方を計算する pp
  // 3. ps * pp / 1000000007 が答えとなる
  int ps = (r - x + 1) * (c - y + 1); // 1 縦横の空き幅を掛け
  cout << "ps:" << ps << endl;

  // 2
  int space = x * y; // x y のスペースの数
  cout << "space:" << space << endl;
  //cout << "d:" << d << endl;
  //cout << "l:" << l << endl;
  long long desk_pattern = (get_pattern(space, d)) % mf;
  cout << "desk_pattern:" << desk_pattern << endl;
  long long lack_pattern = (get_pattern(space - d, l)) % mf;
  cout << "lack_pattern:" << lack_pattern << endl;
  long long result = (desk_pattern * lack_pattern) % mf;
  result = (result * ps) % mf;
  
  cout << result << endl;
}
