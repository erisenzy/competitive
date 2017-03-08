/*
	DPか二次元imos法どちらかを実装できれば通る.
	このコードは両方実装.
 */

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
	int n,q;
	int d[52][52];
	int dp[2502];
	cin >> n;
	REP(i,n){
		d[i][0] = 0;
		REP(j,n){
			cin >> d[i+1][j+1];
			d[0][j] = 0;
		}
	}
	fill(dp,dp+2502,0);
	int nsq = n*n;
	REP(i,n){
		REP(j,n){
			d[i+1][j+1] += d[i+1][j];
			}
	}
	REP(j,n){
		REP(i,n){
			d[i+1][j+1] += d[i][j+1];
			}
	}
	for(int dpct = 1;dpct <=nsq;dpct++){
		int ans = dpct == 1 ? 0 : dp[dpct-1];
		for(int index = 1;index <=dpct;index++){
			if(dpct % index!=0)continue;
			int H = index;
			int W = dpct / index;
			if(H > n || W > n)continue;
			int res = 0;
			REP(i,n-H+1){
				REP(j,n-W+1){
					res = d[i+H][j+W] - d[i][j+W] - d[i+H][j] + d[i][j];
					ans = max(res,ans);
				}
			}
		}
		dp[dpct] = ans;
	}
	cin >> q;
	REP(i,q){
		int p;
		cin >> p;
		cout << dp[p] <<endl;
	}

		return 0;
}
