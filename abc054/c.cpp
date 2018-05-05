#include <bits/stdc++.h>  // g++ -std=c++14 -o a a.cpp

using namespace std;

typedef pair<int, int> P;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (n); i++)
#define repto(i, n) for(int i = 0; i <= (n); i++)
#define all(c) (c).begin(), (c).end()
#define uniq(c) c.erase(unique(all(c)), (c).end()) // ユニークなvectorにする。連続した値を除去して切り出す。
#define _1 first
#define _2 second
#define pb push_back
#define INF 1145141919
#define MOD 1000000007
#define DEBUG(x) cout << #x << ": " << x << endl;

class Candidate {
  public:
      int p;
      set<P> edges;
      set<int> nexts;
};

__attribute__((constructor))
void initial() {
  cin.tie(0);
  ios::sync_with_stdio(false);
}

int main() {
  int N, M;
  cin >> N >> M;
  vector<P> edges;
  rep(i, M) {
    int ai, bi;
    cin >> ai >> bi;
    edges.pb(make_pair(ai, bi));
  }

  queue<Candidate> candidates;
  queue<Candidate> nextCandidates;
  vector<Candidate> results;
  
  Candidate c;
  c.p = 1;
  rep(i, M) {
    c.edges.insert(edges[i]);
  }
  for(int i = 1; i <= N; i++) {
    c.nexts.insert(i);
  }

  candidates.push(c);

  while(!candidates.empty()) {
    Candidate cc = candidates.front();
    candidates.pop();
    
    // DEBUG(cc.p);
    // DEBUG(cc.edges.size());
    // DEBUG(cc.nexts.size());

    if (cc.nexts.size() == 0) { // 最後まで到達しているものが合ったら結果に
      results.pb(cc);
      continue;
    } 

    vector<P> es(cc.edges.begin(), cc.edges.end());
    rep(i, es.size()) {
      P e =  es[i];

      if(cc.p == e._1 && cc.nexts.count(e._2) > 0) {
        Candidate nc;
        nc.p = e._2;
        set<P> nedges = cc.edges;
        nedges.erase(e);
        nc.edges = nedges;
        set<int> nnexts = cc.nexts;
        nnexts.erase(e._2);
        nextCandidates.push(nc);
      }

      if(cc.p == e._2 && cc.nexts.count(e._1) > 0) {
        Candidate nc;
        nc.p = e._1;
        set<P> nedges = cc.edges;
        nedges.erase(e);
        nc.edges = nedges;
        set<int> nnexts = cc.nexts;
        nnexts.erase(e._1);
        nextCandidates.push(nc);
      }
    }

    // 全部見終えたら次のに置き換える
    if(candidates.empty()) {
      candidates = nextCandidates;
    }
  }

  cout << results.size() << endl;
}
