#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <map>
#include <set>
#include <queue>
#include <stack>
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
  int dp[10003][2][101];
int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  int D;cin>>D;
  string S;cin>>S;
  int n = S.length();
  dp[0][0][0] = 1;
  REP(i,n){
      REP(j,2){
          REP(hasD,D){
          int lim = j ? 9 : S[i] - '0';
          REP(d,lim+1){
              (dp[i+1][j || d != lim][(hasD + d)%D] += dp[i][j][hasD]) %= MOD;
          }
          }
      }
  }
  int ans = 0;
  REP(j,2){
      REP(hasD,D){
          if(hasD==0){
              (ans+=dp[n][j][hasD]) %= MOD;
          }
      }
  }
  cout << (ans-1)%MOD << endl;
  return 0;
}
