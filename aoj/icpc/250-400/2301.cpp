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
double r,l,t,e,miss_p,suc_p;
double ans = 0.0;
void solve(int tk,double tr,double tl,double tp){
	double h = (tr+tl)/2;
	double n_suc_p = tp*suc_p;
	double n_miss_p = tp*miss_p;
	tk--;
	if(tk == -1){
		if((tr+tl)/2 >= t-e && (tr+tl)/2 <= t+e)ans+=tp;
	}else if(t+e<tr&&t+e<tl||t-e>tr&&t-e>tl)return;
	else if(h < t){
		solve(tk,h,tl,n_suc_p);
		solve(tk,tr,h,n_miss_p);
	}else{
		solve(tk,h,tl,n_miss_p);
		solve(tk,tr,h,n_suc_p);
	}
} 
int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
	cin>>k>>r>>l>>miss_p>>e>>t;
	suc_p = 1.0 - miss_p;
	double p = 1.0;
	solve(k,r,l,p);
	cout.precision(10);
	cout << fixed << ans << endl;
  return 0;
}
