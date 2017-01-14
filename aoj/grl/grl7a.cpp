#include <iostream>
#include <vector>
#include <algorithm>
#define REP(i,n) for (int i=0;i<(n);i++)

using namespace std;

const int INF = 1e9;
const int MAX_V = 210;
struct edge{
	int to, cap, rev;
	edge(int to,int cap, int rev):to(to),cap(cap),rev(rev){}
};
vector<vector<edge> > G(MAX_V); //グラフの隣接リスト表現
bool used[MAX_V]; //DFSで既に調べたかどうかのフラグ

void add_edge(int from, int to, int cap){
		G[from].push_back(edge(to,cap,G[to].size()));
		G[to].push_back(edge(from,0,G[from].size() - 1));
}

int dfs(int v, int t, int f){
	if(v == t) return f;
	used[v] = true;
	for(int i = 0; i < G[v].size(); i++){
		edge &e = G[v][i];
		if( !used[e.to] && e.cap > 0){
			int d = dfs(e.to,t,min(f,e.cap));
			if(d > 0){
				e.cap -=d;
				G[e.to][e.rev].cap += d;
				return d;
			}
		}
	}
	return 0;
}

int maxflow(int s, int t){
	int flow = 0;
	for(;;){
		fill(used,used + MAX_V,false);
		int f = dfs(s,t,INF);
		if(f == 0)return flow;
		flow += f;
	}
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
int x,y,e;
	cin >> x >> y >> e;
	int s = x+y, t = s+1;
	REP(i,e){
		int from,to;
		cin >> from >> to;
		add_edge(from,to + x,1);
	}
	REP(i,x){
		add_edge(s,i,1);//始点から終点への辺
	}
	REP(i,y){
		add_edge(x + i,t,1);//ｙから終点への辺
	}
	cout << maxflow(s,t) << endl;
  return 0;
}
