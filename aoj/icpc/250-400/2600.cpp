/*
	無線機は縦横に無線機を中心としたp×∞と∞×pの長方形二つ生成する。
	ある列を覆うためには、その列が∞×pの長方形に含まれている（ある列のｘ座標をｘとすると、x-p<x2<x+pを満たすx=x2、範囲pの無線機が存在する）か、
	p×∞の長方形により全ての行が長方形でおおわれている必要がある。
	これを全ての列について考えると、p×∞の長方形により全ての行がおおわれているか、∞×pの長方形により全ての列が長方形で覆われていれば良い。
	つまり、どちらかの時に全ての領域を覆うことができる。
	累積和は領域を含むか含まないかで用いる。
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

void add(vector<int>& r,int w,int x,int p){
	if(!p)return;
	int lx = x-p < 0?0:x-p;
	int rx = x+p >w?w:x+p;
	r[lx]++;r[rx]--;
}

bool check(vector<int>&r){
	int rsum = 0;
	REP(i,r.size()-1){
		rsum+=r[i];
		if(!rsum)return false;
	}
	return true;
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
	int n,w,h;
	cin>>n>>w>>h;
	vector<int> reach_w(w+1,0);
	vector<int> reach_h(h+1,0);
	REP(i,n){
		int x,y,p;
		cin>>x>>y>>p;
		add(reach_w,w,x,p);
		add(reach_h,h,y,p);
	}
	if(check(reach_w) || check(reach_h))cout << "Yes" << endl;
	else cout << "No" << endl;
  return 0;
}
