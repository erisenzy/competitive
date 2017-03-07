//最初の行を定めれば後は一意に解を求められる
//最近やった類題だとarc069d　とか
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <map>
#include <bitset>
#define REP(i,n) for (int i=0;i<(n);i++)
#define FOR(i,a,b) for (int i=(a);i<(b);i++)
#define ll long long
#define ull unsigned long long
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

using namespace std;
int m,n;
int sq[15],cp_sq[15],ans[15];

void reverse(int i,int j){
	if(i != 0) cp_sq[i-1] ^= 1 << j;//up
	if(i != m-1) cp_sq[i+1] ^= 1 << j;//down
	if(j != 0) cp_sq[i] ^= 1 << (j-1);//left
	if(j != n-1) cp_sq[i] ^= 1 << (j+1);//right
	cp_sq[i] ^= 1 << j;//center
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
	cin >> m >> n;
	REP(i,m)REP(j,n){
		int a;
		cin >> a;
		sq[i] |= a << j;
	}
	REP(bit,1 << (n+1)){
		//init
		REP(i,m){
			cp_sq[i] = sq[i];
			ans[i] = 0;
		}
		ans[0] = bit;
		//line 0
		REP(j,n)if(1 & (ans[0] >> j))reverse(0,j);
		//line 1~m-2
		FOR(i,1,m-1){
			REP(j,n){
				if(1 & (cp_sq[i-1] >> j)){
					reverse(i,j);
					ans[i] |= 1 << j;
				}
			}
		}
		//line m-1
		REP(j,n){
			if((1 & (cp_sq[m-2] >> j))
				 && (j == 0 ||(1 & (cp_sq[m-1] >> (j-1))))){
				reverse(m-1,j);
				ans[m-1] |= 1 << j;
			}
		}
		bool isok = true;
		REP(i,m)if(cp_sq[i]){isok = false;break;}

		if(isok){
			REP(i,m){
				REP(j,n)cout << (1 & (ans[i] >> j)) << ' ';
				cout << '\n';
			}
			return 0;
		}
	}
	cout << "IMPOSSIBLE" << endl;
  return 0;
}
