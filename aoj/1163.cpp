#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <map>
#define REP(i,n) for (int i=0;i<(n);i++)

using namespace std;

const int MAX_V = 1010;
vector<vector<int> > G(MAX_V); //グラフの隣接リスト表現
bool used[MAX_V]; //DFSで既に調べたかどうかのフラグ
int match[MAX_V]; //マッチングのペア

void init(int n){
	for(int i = 0;i < n;i++)G[i].clear();
}

void add_edge(int from, int to){
	G[from].push_back(to);
	G[to].push_back(from);
}

bool dfs(int v){
	used[v] = true;
	for(int i = 0; i < G[v].size(); i++){
		int u = G[v][i],w = match[u];
		if(w < 0 || (!used[w] && dfs(w))){
			match[v] = u;
			match[u] = v;
			return true;
		}
	}
	return false;
}

int bipartite_matching(int V){
	int res = 0;
	fill(match, match + V,-1);
	for(int v = 0;v < V;v++){
		if(match[v] < 0){
			fill(used, used + V, false);
			if(dfs(v))res++;
		}
	}
	/*
	//辺集合の出力
	REP(i,V){
		if(match[i] >= 0) cout << i << ' ' << match[i] << endl;
		}*/
	return res;
}


int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
	int m,n;
	while(cin >> m >> n,m){
		//		int s = m + n,t = s + 1;
		init(m+n);
		vector<int> b(m),r(n);
		REP(i,m){
			cin >> b[i];
			//			add_edge(s,i);//ついでに始点→ｂを結ぶ
		}
		REP(i,n){
			cin >> r[i];
			//			add_edge(i + m,t);//ついでにｒ→終点を結ぶ
		}
		REP(i,m){
			REP(j,n){
				if(__gcd(b[i],r[j]) != 1){
					add_edge(i,j + m);
				}
			}
		}
		cout << bipartite_matching(m+n) << endl;
	}
  return 0;
}
