#include <iostream>
#include <vector>
using namespace std;

int dp[21][11][156];

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
	int n,k,s;
	while(cin >> n >> k >> s,n){
		vector<vector<vector<int> > > dp(n+1,vector<vector<int> >(k+1,vector<int>(s+1,0)));
		for(int i = 0;i < n;i++)dp[i][0][0] = 1;
		for(int i = 1;i <= n;i++){
			for(int j = 1;j <= k;j++){
				for(int l = 1;l <= s;l++){
					if(l < i)dp[i][j][l] = dp[i-1][j][l];
					else dp[i][j][l] = dp[i-1][j][l] + dp[i-1][j-1][l-i];
				}
			}
		}
		cout << dp[n][k][s] << endl;
	}
  return 0;
}
