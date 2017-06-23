/*
 * dp[選んだ種類の数][2][現在の重さ]
 * 冷静に[2]なくても一時的な配列取れば解決する気がしてきた（ACなのでおわり）
 */
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

struct Nap{
    int w,v;
    Nap(int w,int v):w(w),v(v){}
    Nap(){}
};

bool compare(const Nap& a,const Nap& b){
    return a.w < b.w;
}

const int MAX_W = 10003;
int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  int N,W,C;
  cin>>N>>W>>C;
  vector<vector<Nap> > nap(50,vector<Nap>());
  int dp[51][2][MAX_W];
  fill(dp[0][0],dp[C][0],0);
  int ct = 1;map<int,int> mp;//色家運と用
  REP(i,N) {
      int w,v,c;cin>>w>>v>>c;
      if(mp[c] == 0)mp[c] = ct++;
      nap[mp[c]-1].push_back(Nap(w,v));
  }
  REP(i,50)sort(nap[i].begin(),nap[i].end(),compare);
  REP(i,ct-1){// 現在追加していく種類
      for(int j = min(i,C-1);j>=0;j--){// 何種類もっている集合をみる
          if(j){
              copy_n(dp[j-1][1],W+1,dp[j][0]);
          }else fill_n(dp[j][0],W+1,0);
          for(Nap p : nap[i]){
              for(int w = W-p.w;w>=0;w--){
                  if(w>0 && dp[j][0][w] == 0)continue;
                  dp[j][0][w+p.w] = max(dp[j][0][w] + p.v, dp[j][0][w+p.w]);
              }
          }
          for(int w=0;w<=W;w++)dp[j][1][w] = max(dp[j][1][w],dp[j][0][w]);
      }
  }
  int ans = 0;
  for(int w=0;w<=W;w++)ans = max(dp[C-1][1][w],ans);
  cout << ans << endl;
  return 0;
}
