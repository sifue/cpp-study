#include <bits/stdc++.h> // g++ -std=c++14 -o a a.cpp

using namespace std;

typedef pair<int, int> P;
typedef long long ll;

#define rep(i, n) for (int i = 0; i < (n); i++)
#define repto(i, n) for (int i = 0; i <= (n); i++)
#define all(c) (c).begin(), (c).end()
#define uniq(c) c.erase(unique(all(c)), (c).end())
#define _1 first
#define _2 second
#define pb push_back
#define INF 1145141919
#define MOD 1000000007
#define DEBUG(x) cout << #x << ": " << x << endl;

int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

template <typename A, size_t N, typename T>
void Fill(A (&array)[N], const T &val)
{
    std::fill((T *)array, (T *)(array + N), val);
}

__attribute__((constructor)) void initial()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
}

int N, X, Y;
int L[2001][2001];

void bfs(int start, int current, int l)
{
    queue<int> q;
    q.push(current);
    queue<int> nextQ;

    do
    {

        while (!q.empty())
        {
            int cur = q.front();
            q.pop();
            if (L[start][cur] != -1)
            { // 既に値があるパターンはパス
                continue;
            }
            L[start][cur] = l; // 最初のポジション埋め

            // 左へ
            if (cur > 1 && L[start][cur - 1] == -1)
            {
                nextQ.push(cur - 1);
            }

            // 右へ
            if (cur < N && L[start][cur + 1] == -1)
            {
                nextQ.push(cur + 1);
            }

            // X → Y へ
            if (cur == X && L[start][Y] == -1)
            {
                nextQ.push(Y);
            }

            // Y → X へ
            if (cur == Y && L[start][X] == -1)
            {
                nextQ.push(X);
            }
        }

        l++;
        q = nextQ;
        queue<int>().swap(nextQ);
    } while (!q.empty());
}

int main()
{
    // 配列初期化
    Fill(L, -1);
    // 全ての点から全ての点への最短距離を計算
    cin >> N >> X >> Y;

    // 全最短距離埋め
    for (int i = 1; i <= N; i++)
    {
        bfs(i, i, 0);
    }

    int cnt[2001] = {0};

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {

            cnt[L[i][j]]++;
        }
    }

    for (int i = 1; i <= N - 1; i++)
    {
        cout << (cnt[i] / 2) << endl;
    }
}
