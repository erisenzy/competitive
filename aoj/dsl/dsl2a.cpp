#include <iostream>
#include <algorithm>
#include <climits>
#define REP(i,n) for (int i=0;i<(n);i++)
#define FOR(i,a,b) for (int i=(a);i<(b);i++)
#define ll long long
#define ull unsigned long long
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
const int INF = 1e9;
const int MOD = 1e9 + 7;
using namespace std;


const int MAX_N = 2*1e5 + 1;
struct RMQ{
	int n;
	int dat[MAX_N*2 - 1];
	void init(int n_){
		n = 1;
		while(n<n_)n*=2;//nが２のべき乗でないとupdateがバグる
		REP(i,2*n-1)dat[i] = INT_MAX;
	}
	//インデックスiの値をxに変更
	void update(int i,int x){
		i += n-1;
		dat[i] = x;
		while(i > 0){
			i = (i-1)/2;
			dat[i] = min(dat[i*2+1],dat[i*2+2]);
		}
	}
	//[a,b)の最小値、ｌ、ｒにはノードｋに対応づく区間を与える
	//最初はquery(a,b,0,0,n)で呼び出し節点から始めて、潜ってくイメージ
	int query(int a,int b,int k,int l,int r){
		if(r <= a||b <= l)return INT_MAX;//交差しない
		if(a <= l && r <= b)return dat[k];//完全に含む
		else{
			int vl = query(a,b,k*2+1,l,l+(r-l)/2);
			int vr = query(a,b,k*2+2,l+(r-l)/2,r);
			return min(vl,vr);
		}
	}
};


int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
	int n,q;
	cin >> n >> q;
	RMQ rmq;
	rmq.init(n);
	REP(i,q){
		int com,x,y;
		cin >> com >> x >> y;
		//rmqの方のnを呼んでること,y+1に注意
		if(com)cout << rmq.query(x,y+1,0,0,rmq.n) << endl;
		else rmq.update(x,y);
	}
  return 0;
}
