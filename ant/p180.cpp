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
#define RREP(i,n) for (int i=(n)-1;i>=0;i--)
#define RFOR(i,a,b) for (int i=(a)-1;i>=(b);i--)
#define ll long long
#define ull unsigned long long
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
const int INF = 1e9;
const int MOD = 1e9 + 7;

using namespace std;

typedef vector<vector<ll> > mat;
const int M = 1e5;
mat mul(const mat& A, const mat& B){
	mat C(A.size(),vector<ll>(B[0].size(),0));
	REP(i,A.size()){
		REP(j,B[0].size()){
			REP(k,B.size()){
				C[i][j] = (C[i][j] + A[i][k] * B[k][j])%M;
			}
		}
	}
	return C;
}

mat pow(mat A,ll n){
	ll res = 1;
	mat ans(A.size(),vector<ll>(A[0].size(),0));
	REP(i,A.size())ans[i][i] = 1;//ans = E
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
	ll n;
	cin >> n;
	mat A(2,vector<ll>(2,1));;
	A[1][1] = 0;
	A = pow(A,n);
	cout << A[1][0] << endl;
  return 0;
}
