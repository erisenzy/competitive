/*
 * 掛け算がandなので1が全ビット立ってることに注意
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

typedef vector<vector<ll> > mat;
int k,m;
mat mul(const mat& A, const mat& B){
	mat C(A.size(),vector<ll>(B[0].size(),0));
	REP(i,A.size()){
		REP(j,B[0].size()){
			REP(k,B.size()){
				C[i][j] = C[i][j] xor (A[i][k] bitand B[k][j]);
			}
		}
	}
	return C;
}

mat pow(mat A,ll n){
	ll res = 1;
	mat ans(A.size(),vector<ll>(A[0].size(),0));
	REP(i,A.size())ans[i][i] = __LONG_LONG_MAX__;//ans = E
	mat B = A;
	while(n>0){
		if(n&1)ans = mul(ans,B);
		B = mul(B,B);
		n >>= 1;
	}
	return ans;
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

	cin >> k >> m;
	long long a[103],c[103];
	REP(i,k)cin >> a[i];
	REP(i,k)cin >> c[i];
	if(m <= k){
		cout << a[m-1] << endl;
	}else{
		mat C(k,vector<ll>(k,0));
		REP(i,C.size()-1){
			C[i+1][i] = __LONG_LONG_MAX__;
		}
		REP(j,C[0].size())C[0][j] = c[j];
		mat ansC = pow(C,m-k);
		ll ans = 0;
		REP(i,k){
			ans xor_eq ansC[0][i] bitand a[k-1-i];
		}
		cout << ans << endl;
	}
  return 0;
}
