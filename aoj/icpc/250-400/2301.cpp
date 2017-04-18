/*
	返り値を求める答えにするver
	先のバージョンと比べて、簡潔に書ける
	また、範囲内に[r、l]が含まれている場合を枝刈りしているが、これは先のバージョンでもtpを足すことで可能（本質はあまり変わらない）
 */

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <map>
#include <queue>
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
int k;
double r,l,t,e,p;
double solve(int tk,double tr,double tl){
	double h = (tr+tl)/2;
	tk--;
	if(tk==-1)
		if(h >= t-e && h <= t+e)return 1;
		else return 0;
	if(tr<=t-e&&tl <=t-e||tr>=t+e&&tl>=t+e)return 0;
	if(t-e<=tr&&tl<=t+e)return 1;
	double tmp_p = t <= h ? p : 1-p;
	double res = tmp_p*solve(tk,h,tl);
	res+=(1-tmp_p)*solve(tk,tr,h);
	return res;
} 
int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
	cin>>k>>r>>l>>p>>e>>t;
	cout.precision(10);
	cout << fixed << 	solve(k,r,l) << endl;
  return 0;
}
