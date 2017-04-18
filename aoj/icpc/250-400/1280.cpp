#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <map>
#include <set>
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
const int MOD = 1e9 + 7;

using namespace std;

struct UnionFind{
	int par[1000];
	int rank[1000];
	UnionFind(int n){
		init(n);
	}
	void init(int n){		REP(i,n){par[i] = i;rank[i] = 0;}}
	int find(int a){
		if(par[a] == a)return a;
		return par[a] = find(par[a]);
	}
	void unite(int x,int y){
		x = find(x);
		y = find(y);
		if(x==y)return;
		if(rank[x]<rank[y])par[x] = y;
		else {
			par[y] = x;
			if(rank[x]==rank[y])rank[x]++;
		}
	}
	bool same(int x,int y){return find(x)==find(y);}
};

struct Edge{
	int u,v,cost;
	Edge(){}
};
bool comp(const Edge& e1,const Edge& e2){
	return e1.cost < e2.cost;
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
	int n,m;
	while(cin>>n>>m,n){
		vector<Edge> edge(m);
		UnionFind uni(n);
		REP(i,m){
			cin >> edge[i].u >>edge[i].v >> edge[i].cost;
			edge[i].u--;edge[i].v--;
		}
		int ans = INF;
		sort(edge.begin(),edge.end(),comp);
		REP(i,m){
			uni.init(n);
			int maxc = -INF,minc = INF,ct = 0;
			FOR(j,i,m){
				Edge e = edge[j];
				if(!uni.same(e.u,e.v)){
					uni.unite(e.u,e.v);
					maxc = max(maxc,e.cost);
					minc = min(minc,e.cost);
					ct++;
				}
			}
			if(ct!=n-1)break;
			ans = min(ans,maxc-minc);
		}
		if(ans == INF)cout << -1 << endl;
		else cout << ans << endl;
	}
  return 0;
}
