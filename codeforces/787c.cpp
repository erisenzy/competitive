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
enum res{WIN=1,LOSE=-1,LOOP=0};
res result[2][7001];
int n;
int k[2];
int s[2][7000];
int ct[2][7000];
void dp(int player,int x){
	result[player][x] = LOSE;
	REP(i,k[not player]){
		int nx=(x-s[not player][i]+n)%n;
		if(nx==0)continue;
		if(result[not player][nx]==WIN)continue;
		result[not player][nx] = WIN;
		REP(j,k[player]){
			int nnx=(nx-s[player][j]+n)%n;
			if(nnx==0)continue;
			if(not --ct[player][nnx])
				dp(player,nnx);
		}
	}
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
	cin>>n;
	REP(i,2){
		cin>>k[i];REP(j,k[i])cin>>s[i][j];
	}
	fill(result[0],result[2],LOOP);
	fill(ct[0],ct[1],k[0]);
	fill(ct[1],ct[2],k[1]);
	dp(0,0);
	dp(1,0);
	REP(i,2){
		REP(j,n-1){
			if(j)cout << ' ';
			switch(result[i][j+1]){
			case WIN:cout << "Win";break;
			case LOSE:cout << "Lose";break;
			case LOOP:cout << "Loop";break;
			}
		}
		cout << endl;
	}
  return 0;
}
