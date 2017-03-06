#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>
#include <iomanip>
#define REP(i,n) for (int i=0;i<(n);i++)
#define ALL(a) (a).begin(),(a).end()
#define ll long long
#define ull unsigned long long
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

using namespace std;

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
	int n,t,l,b;
	while(cin>>n>>t>>l>>b,n){
		vector<vector<double> > dp(t + 2,vector<double>(n + 1,0.0));
		vector<int> gammon(n + 1,0);
		REP(i,l){
			int tmp;
			cin >> tmp;
			gammon[tmp] = 1;
		}
		REP(i,b){
			int tmp;
			cin >> tmp;
			gammon[tmp] = 2;
		}
		dp[0][0] = 1;
		for(int i = 1;i <= t;i++){
			int max_mass = i*6 <= n ? i*6 : n;
			for(int j = 0;j <= max_mass;j++){
				if(gammon[j] == 0){//normal
				for(int roll = j-6 < 0 ? j : 6;roll > 0;roll--){
					dp[i][j] += dp[i-1][j-roll] * (1.0/6.0);
					}
				for(int backroll = j > n-6 && j != n ? j - n + 6 : 0;backroll > 0;backroll--){
					dp[i][j] += dp[i-1][n - backroll]* (1.0/6.0);
					}
				}else if(gammon[j] == 1){//lose turn
				for(int roll = j-6 < 0 ? j : 6;roll > 0;roll--){
					dp[i + 1][j] += dp[i-1][j-roll]* (1.0/6.0);
				}
				for(int backroll = j > n-6 && j != n ? j - n + 6 : 0;backroll > 0;backroll--){
					dp[i + 1][j] += dp[i-1][n - backroll]* (1.0/6.0);
					}
				}else{//back
				for(int roll = j-6 < 0 ? j : 6;roll > 0;roll--){
					dp[i][0] += dp[i-1][j-roll]* (1.0/6.0);
				}
				for(int backroll = j > n-6 && j != n ? j - n + 6 : 0;backroll > 0;backroll--){
					dp[i][0] += dp[i-1][n - backroll]* (1.0/6.0);
					}
				}
			}
		}
		double ans = 0.0;
		REP(i,t+2)ans += dp[i][n];
	cout << fixed << setprecision(5) << ans << endl;
	}
  return 0;
}
