/*
	それぞれの株について、当日と次の日を比べて、売却して購入すれば＋になるかだけ考えれば良い。
	dp[現在の所持金]=次の日の所持金
	一日ごとに最大化した所持金をmaxsizeに格納する。
	そして次のループではmaxsizeの長さまでdpテーブルを計算する。

	ハマった部分：
	ループ毎に予めmaxsizeの長さまでのdpテーブルに「取引しなかった時の金額」を入れて初期化する。
	for i range 0 to maxsize: dp[i] = i
	dp[現在の所持金] =次の日の所持金（取引しなかった場合）
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
	int n,d,x;
	cin >> n >> d >> x;
	vector<vector<int> > p(d,vector<int>(n));
	REP(i,d)REP(j,n)cin >> p[i][j];
	int maxsize = x;
	vector<int> dp(1e5 + 1,0);
	for(int i = 0;i < d - 1;i++){
		REP(l,maxsize+1)dp[l] = l;
		for(int j = 0;j < n;j++){
			for(int k = 0;k <= maxsize;k++){
					if(k-p[i][j] >= 0)dp[k] = max(dp[k - p[i][j]] + p[i+1][j], dp[k]);
				}
			}
			maxsize = *max_element(dp.begin(), dp.end());
	}
	cout << maxsize << endl;
  return 0;
}
