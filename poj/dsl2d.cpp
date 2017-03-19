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
const int MAX = (1LL << 31) - 1LL;
const int MAX_N = (1 << 17)+1;
struct RUQ{
	int n;
	int datx[MAX_N*2 - 1];
	int datc[MAX_N*2 - 1];
	//nが変わることに注意！！！
	void init(int n_){
		n = 1;
		while(n<n_)n*=2;//nが２のべき乗でないとupdateがバグる
		REP(i,2*n-1)datx[i] = MAX;
		REP(i,2*n-1)datc[i] = -1;
	}
	//[a,b)の値をxに変更(c)
	void update(int a,int b,int x,int c,int k,int l,int r){
		if(r <= a || b <= l)return;
		if(a <= l && b >= r){
			datx[k] = x;
			datc[k] = c;
		}else{
			update(a,b,x,c,k*2+1,l,(l+r)/2);
			update(a,b,x,c,k*2+2,(l+r)/2,r);
		}
	}
	//a[i]を返す
	int query(int i){
		i += n-1;
		int c = -1;
		int x = MAX;
		while(true){
			if(datc[i] > c){
				x = datx[i];
				c = datc[i];
			}
			if(i == 0)break;//最初のiとi==0を触るようにする
			i = (i-1)/2;
		}
		return x;
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
			int j;cin >>j;
			cout << ruq.query(j) << endl;
		}else{
			int a,b,x;
			cin >> a>>b>>x;
			b++;
			ruq.update(a,b,x,i,0,0,ruq.n);
		}
	}
  return 0;
}
