#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <map>
#define REP(i,n) for (int i=0;i<(n);i++)
#define ll long long
#define ull unsigned long long
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

using namespace std;

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
	string n;
	cin >> n;
	int nsize = n.size();
	int dp[11][2][11] = {}; // pos, less, number of has1
	dp[0][0][0] = 1;//0桁目は存在しないので1
	REP(i,nsize){
		REP(j,2){
			int lmax = j ? 9 : n[i] - '0';
			REP(k,11){
				REP(d,lmax + 1){
					dp[i + 1][j || d < lmax][k + (d == 1)] += dp[i][j][k];//()注意（演算子優先順位）
				}
			}
		}
	}
	int ans = 0;
	REP(i,11)ans += dp[nsize][0][i] * i + dp[nsize][1][i] * i;
	cout << ans << endl;
  return 0;
}
