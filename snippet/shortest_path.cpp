#include <tuple>
#include <queue>
#include <vector>
using namespace std;
const int LL_INF = 1e18;
using ll = long long;
struct Edge{
  int to;
  ll cost;
};

void dijkstra(int start_i,int N, vector<vector<Edge> >& es, vector<ll>& dist){
  fill(dist.begin(), dist.end(), LL_INF);
  dist[start_i] = 0;
  priority_queue<pair<ll,int>> que; // -cost, vertex
  que.push({0, start_i});
  while(not que.empty()){
    ll cost;
    int from;
    tie(cost,from) = que.top();
    que.pop();
    if(dist[from] < - cost) continue;
    for(auto e : es[from]){
      if(dist[e.to] > e.cost + dist[from]){
        dist[e.to] = e.cost + dist[from];
        que.push({- dist[e.to], e.to});
      }
    }
  }
}
