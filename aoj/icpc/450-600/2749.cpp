#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#define REP(i,n) for(int i=0;i<(n);i++)
#define FOR(i,j,n) for(int i=(j);i<(n);i++)
const int INF = 1e9 + 3;
using namespace std;
 
int dp[102][1<<15];
int w[1<<15];
 
int main(){
  int n,m;
  while(cin>>n>>m,n){
    vector<int> s(n),d(m);
    REP(i,n)cin>>s[i];
    REP(i,m)cin>>d[i];
    sort(s.begin(),s.end());
    sort(d.begin(),d.end());
		fill(w,w+(1<<n),0);
    REP(bit,1<<n){
      REP(j,n){
        if(bit&(1<<j)){
          w[bit]+=s[j];
        }
      }
    }
		fill(dp[1],dp[102],INF);
    FOR(i,1,m+1){//position at demand
      REP(bit,1<<n){
        dp[i][bit] = min(dp[i][bit],dp[i-1][bit] + abs(w[bit]-d[i-1]));
        REP(k,n){
          if(bit&(1<<k)){
            dp[i][bit] = min(dp[i][bit],dp[i][bit^(1<<k)]);
          }
        }
      }
    }
    int ans = INF;
    REP(i,1<<n){
      ans = min(ans,dp[m][i]);
    }
    cout << ans << endl;
  }
  return 0;
}
