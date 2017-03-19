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

const int MAX_N = (1 << 17) + 1;

struct SegmentTree{
	int n;
	ll data[MAX_N*2 - 1],datb[MAX_N*2 - 1];;
	void init(int n_){
		n = 1;
		while(n<n_)n*=2;
		REP(i,2*n-1)data[i] = 0;
		REP(i,2*n-1)datb[i] = 0;
	}
	//[a,b)にxを加える
	void add(int a,int b,int x,int k,int l,int r){
		if(a <= l && r <= b){//加算区間が区間[l,r)を完全に含む場合
			data[k] += x;
		}else if(l<b && r>a){//交差してる場合
			datb[k] += (min(r,b) - max(l,a)) * x;
			add(a,b,x,k*2+1,l,(r+l)/2);
			add(a,b,x,k*2+2,(r+l)/2,r);
		}
	}
	//[a,b)の最小値、ｌ、ｒにはノードｋに対応づく区間を与える
	//最初はquery(a,b,0,0,n)で呼び出し節点から始めて、潜ってくイメージ
	ll sum(int a,int b,int k,int l,int r){
		if(r <= a||b <= l)return 0;//交差しない
		if(a <= l && r <= b)return datb[k] + data[k]*(r-l);//加算区間が区間[l,r)を完全に含む
		//部分的に含む
		ll res = data[k]*(min(r,b)-max(l,a));
		res += sum(a,b,k*2+1,l,l+(r-l)/2);
		res += sum(a,b,k*2+2,l+(r-l)/2,r);
		return res;
	}
};

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
	int n,q;
	cin >> n >> q;
	SegmentTree seg;
	seg.init(n);
	REP(i,q){
		int o;
		cin >> o;
		if(!o){
			int a,b,c;
			cin >> a >> b >> c;
			a--;
			seg.add(a,b,c,0,0,n);
		}else{
			int a,b;
			cin >> a >> b;a--;
			cout << seg.sum(a,b,0,0,n) << endl;
		}
	}
  return 0;
}
