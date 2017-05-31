/*
 * dp[N][2] = N番目の駅で0連続で止まった状態or1~K-1連続で止まった状態
 * dp[N][K]の状態数を累積和を使って減らす。
 * その際、N番目のK-1連続の状態数はN-K+1番目の0番目の状態数に等しいことを利用する。
 * 参考:http://shindannin.hatenadiary.com/entry/2015/12/23/223251
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

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
	int n,k;cin>>n>>k;
	ll dp[n+1][2];
	dp[0][1] = dp[1][0] = 0;
	dp[0][0] = dp[1][1] = 1;
	FOR(i,2,n+1){
		dp[i][0] = (dp[i-1][0] + dp[i-1][1]) % MOD;
		dp[i][1] = (dp[i-1][0] + dp[i-1][1]) % MOD;
		if(i >= k){
			dp[i][1] = (dp[i][1] - dp[i-k][0] + MOD) % MOD;
		}
	}
	cout << dp[n][1] << endl;
	return 0;
}
