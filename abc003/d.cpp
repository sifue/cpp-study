#include <vector>

using namespace std;

int get_pattern(int rest, int select) {
    if (select == 0) return 1;
    return rest * select * get_pattern(rest - 1, select - 1);
}

int fact(int n) {
    if (n == 1) {
        return 1;
    }
    return n * fact(n - 1);
}

int main() {
  int r, c, x, y, d, l;
  cin >> r >> c >> x >> y >> d >> l;

  // 1. まずは区画の置き方のパターンを計算する ps
  // 2. 区画内のデスクとラックの置き方を計算する pp
  // 3. ps * pp / 1000000007 が答えとなる

  int ps = (r - x + 1) * (c - y + 1); // 1 縦横の空き幅を掛け

  // 2
  int space = x * y; // スペースの数
  int desk_pattern = get_pattern(space, d) / fact(d);
  int lack_pattern = get_pattern(space - d, l) / fact(d);
  long long pp = (desk_pattern * lack_pattern);
  int result = pp  % 1000000007; 

  cout << result << endl; 
}
