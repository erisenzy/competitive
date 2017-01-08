/*
参考：http://imulan.hatenablog.jp/entry/2016/05/12/114314
 */

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>
#define REP(i,n) for (int i=0;i<(n);i++)

using namespace std;

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
	int n;
	cin >> n;
	vector<vector<int> > c(n,vector<int>(n));
	REP(i,n){
		REP(j,n){cin >> c[i][j];
		}
	}
	long long ans = 0;
	REP(i,n){
		REP(j,i){
			if(i == j)continue;
			ans += min(c[i][j],c[j][i]);
		}
	}
	cout << ans << endl;
  return 0;
}
