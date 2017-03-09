/*
	最大クリーク問題
	BITDPにも書き直せるらしい.
 */
#include <iostream>
#include <algorithm>
#define REP(i,n) for (int i=0;i<(n);i++)
#define FOR(i,a,b) for (int i=(a);i<(b);i++)
const int INF = 1e9;
const int MOD = 1e9 + 7;

using namespace std;

bool edge[13][13];
int n,m;
int dfs(int i,int relation){
	int res = -1;
	bool isok = true;
	int ct =0;
	REP(j,n){
		ct += relation >> j & 1;
	}
	if(ct == 0)return -1;
	REP(j,n){
		if(i!=j && (relation >> j)&1){
			REP(k,n){
				if(j == k || !((relation >> k)&1))continue;
				if(!edge[j][k]){
					relation ^= 1 << j;
					res = max(res,dfs(i,relation));
					isok = false;
					relation ^= 1 << j;
					break;
				}
			}
		}
	}
	if(isok)return ct;
	if(res != -1)return res;
	else return -1;
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
	cin >> n >> m;
	fill(edge[0],edge[13],false);
	REP(i,m){int a,b;
		cin >> a >> b;
		a--;b--;
		edge[a][b] = true;
		edge[b][a] = true;
	}
	int ans = 1;
	REP(i,n){
		int relation = 0;
		REP(j,n){
			if(edge[i][j])relation |= 1 << j;
		}
		int res = dfs(i,relation);
		if(res != -1){
			ans = max(res+1,ans);
		}
	}
	cout << ans << endl;
  return 0;
}
