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
int dp[303][303];
int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
	string s;
	cin>>s;
	int n = s.size();
	REP(i,n-2){//初期処理
		if(s.substr(i,3) == "iwi")dp[i][i + 2] = 3;
	}
	for(int tar_l = 4;tar_l <= n;tar_l++){//区間の長さ
		for(int i = 0;i <= n - tar_l;i++){//開始位置
			for(int div_p = i;div_p < i+tar_l-1;div_p++){//分割位置([i][i]は一文字分)
				dp[i][i + tar_l-1] = max(dp[i][i + tar_l-1],dp[i][div_p] + dp[div_p+1][i+tar_l-1]);
			}
			//3の倍数の時は端に注意
			if((s.substr(i,2) == "iw" && dp[i+2][i+tar_l-2] == tar_l-3 && s[i+tar_l-1] == 'i'
					|| s[i] == 'i' && dp[i+1][i+tar_l-3] == tar_l-3 && s.substr(i+tar_l-2,2) == "wi") && tar_l%3 == 0)
				dp[i][i+tar_l-1] = tar_l;
		}
	}
	int ans = 0;
	REP(i,n)REP(j,n) ans = max(ans,dp[i][j]);
	cout << ans/3 << endl;
	return 0;
}
