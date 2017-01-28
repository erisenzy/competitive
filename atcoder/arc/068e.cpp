/*
 *BIT
 *参考:http://hos.ac/slides/20140319_bit.pdf
 *調和級数1+1/2+1/3+ ... + 1/n ≒　logn + 41/71
 */
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <map>
#define REP(i,n) for (int i=0;i<(n);i++)
#define ll long long
#define ull unsigned long long
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

using namespace std;

//BIT
struct BIT{
	int N;
	int data[300010];
	void init(int n){
		N = n;
	}
void add(int a,int w){
	for(int x = a;x <= N;x += x & -x) data[x] +=w;
}
//bit[1] + ... + bit[a]
int sum(int a){
	int ret = 0;
	for(int x = a; x > 0; x -= x & -x) ret+= data[x];
	return ret;
}
};

/*BIT 0~n-1ver
void add(int a,int w){
	for(int x = a;x < N; x |= x + 1) bit[x] += w;
	}
}

int sum(int a){
	int ret = 0;
	for(int x = a-1;x >= 0; x = (x & (x+1)) - 1)ret += bit[x];
	return ret;
	}*/

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
	int n,m;
	cin >> n >> m;
	vector<vector<int> > souvenir(m+1,vector<int>());
	REP(i,n){
		int l,r;
		cin >> l >> r;
		souvenir[r-l+1].push_back(l);
	}
	BIT bittree;bittree.init(m+1);
	int absolutepass = n;
	for(int d = 1;d <=m;d++){
		for(auto a : souvenir[d-1]){//N*logM
			bittree.add(a,1);bittree.add(a+d-1,-1);
			absolutepass--;
		}
		int ans = absolutepass;
		for(int dd = d;dd <= m;dd+=d){//M*logM*logM
			ans += bittree.sum(dd);
		}
		cout << ans << endl;
	}
  return 0;
}
