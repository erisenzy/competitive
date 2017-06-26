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

const int MAXN = 500003;

pair<int,int> maxa(pair<int,int> a, int f,int s,pair<int,int> b){
	if(f)a.first++;
	a.second+=s;
	if(a.first > b.first)return a;
	else if(a.first == b.first){
		if(a.second < b.second)return a;
		else return b;
	}else return b;
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
	int n;
	while(cin>>n,n){
		vector<int> p(n);
		REP(i,n)cin>>p[i];
		pair<int,int> dp[2][MAXN + 503];
		fill(dp[0],dp[2],make_pair(0,INF));// num of 500 and imamade ni tukatta okane
		dp[1][0] = make_pair(0,0);
		REP(i,n){
			fill(dp[i&1],dp[i&1] + MAXN,make_pair(0,INF));// num of 500 and imamade ni tukatta okane
			for(int j = MAXN;j >= 0;j--){
				if(p[i] % 1000 <= 500 && p[i] % 1000 > 0 && (dp[(i+1)&1][j].second != INF || j==0) ){
					dp[i&1][j + (5000-p[i])%500] = maxa(dp[(i+1)&1][j],1,p[i],dp[i&1][j + (5000-p[i])%500]);
					//toriaezu 1000(+500)
				}else{
					if(p[i] %1000 > 0 &&  dp[(i+1)&1][j + p[i]%500].second != INF){
						dp[i&1][j] = maxa(dp[(i+1)&1][j + p[i]%500],1,p[i],dp[i&1][j]);
					}//1000n + iikanjino
					if(p[i] %1000 == 0 &&  dp[(i+1)&1][j + 500].second != INF){
						dp[i&1][j] = maxa(dp[(i+1)&1][j + 500],1,p[i],dp[i&1][j]);
					}// 1000n + 500
					if(dp[(i+1)&1][j].second != INF || j==0)//toriaezu 1000(not +500)
						dp[i&1][j + (5000-p[i])%500] = maxa(dp[(i+1)&1][j],0,p[i],dp[i&1][j + (5000-p[i])%500]);
				}
				dp[i&1][j] = maxa(dp[i&1][j],0,0,dp[(i+1)&1][j]);
			}
		}
		pair<int,int> ans = make_pair(0,0);
		for(int j = MAXN + 500;j >= 0;j--){
			ans = maxa(dp[(n-1)&1][j],0,0,ans);
		}
		cout << ans.first << ' ' << ans.second << endl;
	}
  return 0;
}
