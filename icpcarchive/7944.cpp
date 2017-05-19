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

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
	ll n,a,b,initn;
	//	while(cin>>n>>a>>b,a){
	cerr << "a,b is " << a << ' ' << b << endl;
	int ct = 0;
	vector<pair<ll,ll> > ans;
	for(a = 2;a<=36;a++){
		for(b = a;b<=36;b++){
			initn = n;
			while(n++){
				ll ans = 0;
				ll m = n;
				ll ta = a;
				while(m/ta){
					ans += m/ta*(a-1);
					ta *= a;
				}
				ll tb = b;
				while(m/tb){
					ans -= m/tb*(b-1);
					tb *= b;
				}
				if(ans == 0){
					if(++ct>10){
						ans.push_back(make_pair(a,b));
						break;
					}
					//					cout << m << endl;
				}
				if(n > initn + (ll)1e6){
					break;
				}
			}
		}
	}
	REP(i,ans.size()){
		cout << ans[i].first << ' ' << ans[i].second << endl;
	}
	return 0;
}
