#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <bitset>
#include <climits>
#define REP(i,n) for (int i=0;i<(n);i++)
#define FOR(i,a,b) for (int i=(a);i<(b);i++)
#define RREP(i,n) for (int i=(n)-1;i>=0;i--)
#define RFOR(i,a,b) for (int i=(a)-1;i>=(b);i--)
#define ll long long
#define ull unsigned long long
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
const int INF = 1e9;
const ll LL_INF = 1e18;
const int MOD = 1e9 + 7;

using namespace std;
struct Node{
  ll v, cost;
};
struct Edge{
  ll v, cost;
};

ll A[100005];
/*void dijkstra(int start_i,int N, vector<vector<Edge> >& es, vector<ll>& dist){
  fill(dist.begin(), dist.end(), LL_INF);
  dist[start_i] = 0;
  auto cmp = [](Node& a, Node& b) { return a.cost < b.cost || a.cost == b.cost && a.v < b.v;};
  priority_queue<Node, vector<Node>, decltype(cmp) > que(cmp);
  que.push({start_i, 0});
  while(not que.empty()){
    Node from = que.top();
    que.pop();
    if(dist[from.v] < from.cost) continue;
    for(auto e : es[from.v]){
      if(dist[e.v] > e.cost + dist[from.v]){
        dist[e.v] = e.cost + dist[from.v];
        que.push({e.v, dist[e.v]});
      }
    }
  }
  }*/
void dijkstra(int start_i,int N, vector<vector<Edge> >& es, vector<ll>& dist){
  fill(dist.begin(), dist.end(), LL_INF);
  dist[start_i] = 0;
  priority_queue<pair<ll,int>> que; // -cost, vertex
  que.push({0, start_i});
  while(not que.empty()){
    ll cost = 0;
    int from;
    tie(cost,from) = que.top();
    que.pop();
    if(dist[from] < - cost) continue;
    for(auto e : es[from]){
      if(dist[e.v] > e.cost + dist[from]){
        dist[e.v] = e.cost + dist[from];
        que.push({- dist[e.v], e.v});
      }
    }
  }
}

int main(){
  ll N, M, T;
  cin >> N >> M >> T;
  REP(i,N){
    scanf("%lld", &A[i]);
  }
  vector<vector<Edge> > es;
  vector<vector<Edge> > res;
  vector<ll> dist(N);
  vector<ll> rdist(N);
  es.resize(N,vector<Edge>());
  res.resize(N,vector<Edge>());
  REP(i,M){
    ll a, b, c;
    scanf("%lld%lld%lld", &a, &b, &c);
    -- a;
    -- b;
    es[a].push_back({b,c});
    res[b].push_back({a,c});
  }
  dijkstra(0, N, es, dist);
  dijkstra(0, N, res, rdist);
  ll ans = 0;
  REP(i,N){
    ll t = T - (dist[i] + rdist[i]);
    if(t < 0) continue;
    ans = max(ans, t * A[i]);
  }
  cout << ans << endl;
  return 0;
}
