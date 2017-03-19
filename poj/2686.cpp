/*
 *	792K	485MS	
 *  BitDP
 */
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

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
	int n,m,p,src,dist;
	while(cin>>n>>m>>p>>src>>dist,n){
		src--;dist--;
		int edge[30][30];
		fill(edge[0],edge[30],INF);
		double dp[1 << 8][32];//現在使ったチケット、位置
		fill(dp[0],dp[1<<8],INF);
		dp[0][src]=0;
		vector<int> t(n);
		REP(i,n)cin >> t[i];
		REP(i,p){
			int x,y;cin>>x>>y;
			x--;y--;
			cin>>edge[x][y];
			edge[y][x]=edge[x][y];
		}
		double ans = INF;

		REP(i,n){//使ったチケット枚数
			int comb = (1<<i)-1;
			while(comb<(1<<n)){
				REP(j,n){//使うチケットindex
					if(comb >> j & 1)continue;
					int nextcomb = comb | (1 << j);
					REP(src_i,m){
						REP(dist_i,m){
							if(edge[src_i][dist_i] ==INF || dp[comb][src_i] == INF)continue;
							double& nextdp = dp[nextcomb][dist_i];
							nextdp = min(dp[comb][src_i] + (double)edge[src_i][dist_i]/t[j],nextdp);
						}
					}
				}
				if(i == 0)break;//0除算を防ぐ
				int x = comb&-comb,y=comb+x;
				comb=((comb&~y)/x>>1)|y;
			}
		}
		REP(i,1<<n){
			ans = min(dp[i][dist],ans);
		}
		if(ans == INF)cout << "Impossible" << endl;
		else cout << fixed << setprecision(3) << ans << endl;
	}
  return 0;
}
