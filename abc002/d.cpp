#include <iostream>
#include <set>
#include <vector>

using namespace std;

/*
   指定された人数の議員の全パターンを調べる
   */

int result = 0;
set<pair<int, int>> rels;

void dfs(int index, int rest, vector<int> giins) {
  if (rest == 0) {
    // チェック処理
    for (int ga : giins) {
      for (int gb : giins) {
        if (ga != gb && rels.count(make_pair(ga, gb)) == 0) {
          return; // 必要な関係がなかったりしたら終了
        }
      }
    }

    // 必要な関係が全部あるならばresultを更新
    int count = giins.size();
    if (count > result) {
      result = count;
    }
    return;
  }

  int next_index = index + 1;
  int next_rest = rest - 1;
  dfs(next_index, next_rest, giins); // index の議員を含めない場合
  giins.push_back(index);
  dfs(next_index, next_rest, giins); // index の議員を含める場合
}

int main() {
  int n, m;
  cin >> n >> m;

  if (m == 0) {
    cout << 1 << endl;
    exit(0);
  }

  // 関係の読み取り
  for (int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    rels.insert(make_pair(x - 1, y - 1));
    rels.insert(make_pair(y - 1, x - 1));
  }

  // 深さ優先探索で全部調べる
  vector<int> giins;
  dfs(0, n, giins);

  cout << result << endl;
}
