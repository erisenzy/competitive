#include <iostream>
/*一回目のループでは重複を数えないために、
ｓｑが通過するタイミングでdp[0][sq]に１が代入されるため
sq以下の数との和の組み合わせの数だけ計算していく。
2回目以降は既に重複を除けているので、普通に計算すればよい
*/
using namespace std;

const int N = 32770;
int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
	int dp[4][N+1] = {};
	for(int i = 1;i*i <= N;i++){
		for(int j = 0;j < 3;j++){
			int sq = i*i;
			if(j == 0)dp[0][sq] = 1;
			for(int k = 1;k <= N;k++){
				if(k + sq >= N)continue;
				dp[j + 1][k + sq] += dp[j][k];
			}
		}
	}
	int n;
	while(cin >> n,n){
		cout << dp[0][n] + dp[1][n] + dp[2][n] + dp[3][n] << endl;
	}
  return 0;
}
