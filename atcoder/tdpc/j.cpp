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

double dp[1 << 16];
int N;

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
	cin >> N;
	int ans = 0;
	REP(i,N){
		int x;
		cin >> x;
		ans |= 1 << x;
	}

	fill_n(dp + 1, (1 << 16) - 1,1e10);

	REP(i,1 << 16){
		FOR(j,1,16){// throw point
			double rhs = 1.0, lhs = 1.0;
			for(int d = -1; d <= 1; d++){
				if(i & (1 << (j + d))) rhs += dp[i ^ (1 << (j +d))] / 3;
				else lhs -= 1.0 / 3.0;
			}
			if(lhs < 1e-3)continue;
			dp[i] = min(rhs/lhs, dp[i]);
		}
	}
	cout << fixed << setprecision(8) << dp[ans] << endl;
  return 0;
}
