/*
 * 区間DP
 * IWIと違い二回DPしているので注意
 * IWIより1回目のDPは簡潔に書けるが、相変わらず添え字が圧倒的に間違えやすいので注意
 * 特にwidthは絶対値であり、閉区間を荒らしてくることに注意
 * rを宣言しとけば多少は間違えにくくなる
 * dp[i][i]　はi+1個目(0-indexeddならi)のダルマについてみていることに注意
 * 二回目のDPもi-1の扱いに注意、配列外参照の危険もある
 */

#include <iostream>
#include <vector>
#include <cstring>
#include <cmath>

#define REP(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,n) for(int i=(a);i<(n);i++)
using namespace std;

int main(){
  int n;
	bool dp[303][303];
	int ans[303];
  while(cin>>n,n){
    vector<int> w(n);
    REP(i,n)cin>>w[i];
    fill(dp[0],dp[n],false);
    fill(ans,ans+n,0);
    for(int i = 0;i <n;i++)dp[i][i+1] |= abs(w[i+1]-w[i])<=1;
    for(int width = 2;width <= n;width++){
      for(int l = 0;l + width <= n;l++){
				int r = l + width-1;
				for(int d = l;d < r;d++){//-1注意
					dp[l][r] |= dp[l][d]&&dp[d+1][r];
					dp[l][r] |= !(width&1) && dp[l+1][r-1] && abs(w[l]-w[r]) <=1;
				}
      }
    }
		/*		FOR(width,1,n+1){
			REP(l,n-width){
				cout << dp[l][l+width] << ' ';
				}
			cout << endl;
			}*/
    for(int i = 0;i<n;i++){
			//i-1までの遺産を使える
			//i以降を更新できなくても、iは無条件でi-1をもらえる。
			//ans[i]自体の更新はこれで最後（各divide地点から有効な分が既に更新されている
			if(i > 0)ans[i] = max(ans[i],ans[i-1]);
      for(int r = i+1;r<n;r++){
				//i-1までの遺産を使いつつ、iから始まる、消せるダルマ達を全て更新しておく
				//i-1のi=0の時に注意
				if(dp[i][r]) ans[r] = max(ans[r],(i>0?ans[i-1]:0) + (r-i+1));
      }
    }
    cout << ans[n-1] << endl;
  }
  return 0;
}
