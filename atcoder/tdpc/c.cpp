/*
 *dp[i][j] = iラウンド目にj番目の人が生き残ってる確率
 *kラウンド目で戦う相手は、隣の部分木の全員が候補である。
 *なので、隣の部分木の人全員について、その人をk番目の人とすると、そこまで勝ち進んでくる確率*そのk番目の人と戦って勝利出来る確率を足し合わせる。
 *これを各ラウンドごとに行う。
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
	cout <<fixed << setprecision(9);
	int k;
	cin >> k;
	vector<int> a(1<<k);
	int p = 1 << k;
	REP(i,1 << k){
		cin>>a[i];
	}
	double dp[11][1030];
	fill(dp[0],dp[k+1],0.0);
	fill(dp[0],dp[0] + p,1.0);
	REP(i,k){
		REP(j,p){
			int tmpj = j;
			tmpj &= (INT_MAX << i);
			tmpj ^= 1 << i;
			int limitj = tmpj + (1<<i);
			FOR(k,tmpj,limitj){
				dp[i+1][j] += dp[i][j]*dp[i][k] / (1+pow(10,(double)(a[k]-a[j])/400));
			}
		}
	}
	REP(i,p){
		cout <<  dp[k][i] << endl;
	}
  return 0;
}
