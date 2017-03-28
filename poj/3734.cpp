/*
 * a[0]=1,b[0]=0,c[0]=0であることに注意
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

const int M = 1e4 + 7;
mat mul(const mat& A, const mat& B){
	mat ans(A.size(),vector<ll>(A[0].size(),0));
	REP(i,A.size())REP(j,B[0].size()){
		REP(k,B.size()){
			ans[i][j] = (ans[i][j] + A[i][k]*B[k][j])%M;
		}
	}
	return ans;
}

mat pow(mat A,int n){
	mat ans(A.size(),vector<ll>(A[0].size(),0));
	REP(i,A.size())ans[i][i] = 1;
	while(n>0){
		if(n&1)ans=mul(ans,A);
		A = mul(A,A);
		n >>= 1;
	}
	return ans;
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
	int n;
	cin>>n;
	while(n--){
		int k;
		cin>>k;
		mat ans(3,vector<ll>(3,2));
		ans[0][2] = 0;
		ans[2][0] = 0;
		ans[0][1] = 1;
		ans[2][1] = 1;
		ans = pow(ans,k);
		cout << ans[0][0] << endl;
	}
  return 0;
}
