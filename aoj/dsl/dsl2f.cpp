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
const int MAX_N = (1 << 17)+1;
struct Node{
	int mini,lazy;
	Node():mini(INT_MAX),lazy(INT_MAX){
	}
};
struct RUQ{
	int n;
	Node dat[MAX_N*2 - 1];
	//nが変わることに注意！！！
	void init(int n_){
		n = 1;
		while(n<n_)n*=2;//nが２のべき乗でないとupdateがバグる
	}
	//遅延値を子に反映
	inline void push(int k){
		if(dat[k].lazy == -1)return;
		dat[k].mini = dat[k].lazy;
		if(k<n-1){
			dat[2*k+1].lazy = dat[k].mini;
			dat[2*k+2].lazy = dat[k].mini;
		}
		dat[k].lazy = -1;
	}
	//子で小さい方を保存
	inline void update_node(int k){
		dat[k].mini = min(dat[2*k+1].mini,dat[2*k+2].mini);
	}
	//[a,b)の値をxに変更(c)
	inline void update(int a,int b,int x,int k,int l,int r){
		push(k);
		if(r <= a || b <= l)return;
		if(a <= l && b >= r){
			dat[k].lazy = x;
			push(k);return;
		}else{
			update(a,b,x,k*2+1,l,(l+r)/2);
			update(a,b,x,k*2+2,(l+r)/2,r);
			update_node(k);
		}
	}
	//[a,b)の最小値を返す
	int query(int a,int b,int k,int l,int r){
		push(k);
		if(r<=a||b<=l)return INT_MAX;
		if(a <=l&&b>=r)return dat[k].mini;
		int lb = query(a,b,k*2+1,l,(l+r)/2);
		int rb = query(a,b,k*2+2,(l+r)/2,r);
		update_node(k);
		return min(lb,rb);
	}
};


int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
	int n,q;
	cin >> n >> q;
	RUQ ruq;ruq.init(n);
	REP(i,q){
		int q;
		cin >> q;
		if(q){
			int a,b;cin >>a>>b;
			cout << ruq.query(a,b+1,0,0,ruq.n) << endl;
		}else{
			int a,b,x;
			cin >> a>>b>>x;
			ruq.update(a,b+1,x,0,0,ruq.n);
		}
	}
  return 0;
}
