#include <iostream>
#include <vector>

using namespace std;

double result = 0.0;
vector<int> rates;

void dfs(int n, vector<int> taken_indexes, int k) {
  if (k >= 0) {
    // kが0以上ならチェックと計算
    double c = 0.0;
    for (int taken_index : taken_indexes) {
      c = (c + rates[taken_index]) / 2.0;
    }
    if (c > result) {
      result = c;
    }
  }

  // 上限まで取りきっているならもう終了
  if (k == 0) {
    return;
  }

  for (int i = 0; i < n; i++) {
    // すでに取得済みかチェック
    bool is_taken = false;
    for (int taken_index : taken_indexes) {
      if (taken_index == i) {
        is_taken = true;
      }
    }

    // すでに取得済みのものは無視
    if (is_taken) {
        continue;
    }

    vector<int> next_taken_indexes = taken_indexes;
    next_taken_indexes.push_back(i);
    int dec_k = k - 1;
    dfs(n, next_taken_indexes, dec_k); // 取る
  }

}

int main() {
  int n, k;
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    int rate;
    cin >> rate;
    rates.push_back(rate);
  }

  vector<int> taken_indexes;
  dfs(n, taken_indexes, k);
  cout << result << endl;
}
