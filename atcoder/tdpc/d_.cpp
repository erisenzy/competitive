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
	ll n,D;
	cin >> n >> D;
	double dp[202][101][101];//2,3,5
	fill(dp[0][0],dp[101][0],0.0);
	dp[0][0][0] = 1.0;
	int d2=0,d3=0,d5=0;
	while(D%2==0){D/=2;d2++;}
	while(D%3==0){D/=3;d3++;}
	while(D%5==0){D/=5;d5++;}
	if(D != 1){
		cout << 0 << endl;
		return 0;
	}
	FOR(i,1,n+1){
		RREP(j,i*2){
		RREP(k,i){
		RREP(l,i){
			dp[j+1][k][l] += dp[j][k][l]/6;//2
			dp[j][k+1][l] += dp[j][k][l]/6;//3
			dp[j+2][k][l] += dp[j][k][l]/6;//4
			dp[j][k][l+1] += dp[j][k][l]/6;//5
			dp[j+1][k+1][l] += dp[j][k][l]/6;//6
			dp[j][k][l] /= 6;//1
		}
		}
		}
	}
	double ans = 0.0;
	REP(i,2*(n+1))REP(j,n+1)REP(k,n+1){
		if( i >= d2 
			 && j >= d3 
			 && k >= d5)
			ans += dp[i][j][k];
	}
	cout << fixed << setprecision(9) << ans << endl;
  return 0;
}
