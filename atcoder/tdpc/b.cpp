#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>
#define REP(i,n) for (int i=0;i<(n);i++)
#define ALL(a) (a).begin(),(a).end()
#define ll long long
#define ull unsigned long long
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

using namespace std;
const int INF = 1e9;
int A,B;
int dp[1003][1003] = {};
int carda[1003] = {},cardb[1003]={};
int solve(int i,int j,int k){
	int &res = dp[i][j];
	if(res != -INF)return res;
	if(k == 1){
		res = INF;
		if(j < B)res = min(res,solve(i,j+1,0));
		if(i < A)res = min(res,solve(i+1,j,0));
	}else{
		if(j < B)res = max(res,solve(i,j+1,1) + cardb[j]);
		if(i < A)res = max(res,solve(i+1,j,1) + carda[i]);
	}
	return res;
}


int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

	cin >> A >> B;
	REP(i,A)cin >> carda[i];REP(i,B)cin >> cardb[i];
	REP(i,1003)fill(dp[i],dp[i]+1003,-INF);
	dp[A][B] = 0;
	cout <<	solve(0,0,0) << endl;

  return 0;
}
