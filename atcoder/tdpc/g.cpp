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
const ll INF = 1e18+1;
const int MOD = 1e9 + 7;

using namespace std;
ll dp[(int)1e6 + 1];

int pos[26];
int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  string s;
  ll k;cin>>s>>k;
  int n = s.size();
  fill_n(pos,26,-1);
  for(int i = n-1;i>=0;i--){
      REP(j,26){
          if(pos[j]!=-1){
              //kの制約から10^18より大きい数は10^18+1と同値
              //またこの処理を行わないとoverflowが起きる
              if(dp[i] > INF - dp[pos[j]]){
                  dp[i] = INF;
                  break;
              }
              dp[i] += dp[pos[j]];
          }
      }
      pos[s[i]-'a'] = i;
      dp[i] += 1;
  }

  //復元
  int next[(int)1e6 + 1][26];
  fill(next[0],next[n+1],-1);
  for(int i = n-1;i>=0;i--)
      REP(j,26) next[i][j] = s[i] - 'a' == j ? i : next[i+1][j];
  //少なくともnext[i][j]でs[i]渡一致したらnext[i+1][j]は後辰砂れてる

  string ans;
  int nowpos = -1;
  while(k>0){
      int i = 0;
      for(;i<26;i++){
          int p = next[nowpos+1][i];
          if(p < 0)continue;
          if(k<=dp[p]){
              k--;
              nowpos = p;
              ans += 'a' + i;
              break;
          }else{
              k-=dp[p];
          }
      }
      if(i >= 26)break;
  }
  if(ans == "")cout << "Eel" << endl;
  else cout << ans << endl;

  return 0;
}
