#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <map>
#define REP(i,n) for (int i=0;i<(n);i++)
#define REP(i,n) for (int i=0;i<(n);i++)
#define ll long long
#define ull unsigned long long
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

using namespace std;
const int INF = 1e9;
const int MOD = 1e9 + 7;

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
	int n,a;
	cin >> n;
	int dp[30003];
	fill(dp,dp + n,INF);
	REP(i,n){
		cin >> a;
		*lower_bound(dp,dp+n,a) = a;
	}
	cout << n - (lower_bound(dp,dp+n,INF)-dp) << endl;
  return 0;
}
