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
#define REP(i,n) for (int i=0;i<(n);i++)
#define FOR(i,a,b) for (int i=(a);i<(b);i++)
#define ll long long
#define ull unsigned long long
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
const int INF = 1e9;
const int MOD = 1e9 + 7;

using namespace std;

//BIT 1~nver
struct BIT{
    int N;
    int data[300010];
    void init(int n){
        N = n;
        fill(data,data+N+1,0);
    }
    void add(int a,int w){
        for(int x = a;x <= N;x += x & -x) data[x] +=w;
    }
    //bit[1] + ... + bit[a]
    //[1,a]
    int sum(int a){
        int ret = 0;
        for(int x = a; x > 0; x -= x & -x) ret+= data[x];
        return ret;
    }
};

//BIT 0~n-1ver
struct BIT{
    int N;
	int data[300010];
	void init(int n){
		N = n;
		fill(data,data+N,0);
	}
    void add(int a,int w){
        for(int x = a;x < N; x |= x + 1) data[x] += w;
	}
    //bit[0] + ... + bit[a-1]
    //[0,a) warning!!!!!!
    int sum(int a){
        int ret = 0;
        for(int x = a-1;x >= 0; x = (x & (x+1)) - 1)ret += data[x];
        return ret;
	}
};


int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
	BIT bit;
	int n,q;
	cin >> n >> q;
	bit.init(n);
	REP(i,q){
		int com,x,y;
		cin >> com >> x >> y;
		if(com) cout << bit.sum(y+1)-bit.sum(x) << endl;
		else bit.add(x,y);
	}
	
    return 0;
}
