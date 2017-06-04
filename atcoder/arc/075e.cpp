#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <map>
#include <set>
#include <queue>
#include <stack>
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

//BIT
struct BIT{
	int N;
	int data[300010];
	void init(int n){
		N = n;
		fill(data,data+N+1,0);
	}
    void add(int a,int w){
        for(int x = a;x < N; x |= x + 1) data[x] += w;
	}
    int sum(int a){
        int ret = 0;
        for(int x = a-1;x >= 0; x = (x & (x+1)) - 1)ret += data[x];
        return ret;
	}
};

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  ll n,k;
  cin>>n>>k;
  vector<ll> a(n+1);
  BIT bit;
  bit.init(n + 2);
  ll ans = 0;
  a[0] = 0;
  FOR(i,1,n+1){
      cin>>a[i];
      a[i] -= k;
      a[i] += a[i-1];
  }
  //zip
  //重複を許し、同じindexで保持する圧縮
  vector<pair<ll,ll> > b(n+1);
  REP(i,n+1)b[i] = make_pair(a[i],i);
  sort(b.begin(),b.end());
  ll tmp = b[0].first, ct = 0;
  for(int i = 0;i < n+1;i++){
      if(tmp != b[i].first){
          tmp = b[i].first;
          ct++;
      }//重複を許し、別のindexで保持するときは消して毎回ct++
      a[b[i].second] = ct;
  }
  //  for(auto db:a)cout << db << endl;
  REP(i,n+1){
      ans += bit.sum(a[i]+1);
      bit.add(a[i],1);
  }
  
  cout << ans << endl;
  return 0;
}
