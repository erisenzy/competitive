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
	int s[100003],t[50003];
	int n,q;
	cin>>n;REP(i,n)cin>>s[i];
	cin>>q;REP(i,q)cin>>t[i];
	int ct = 0;
	REP(i,q){
		int l = 0;
		int r = n;
		while(abs(r-l) > 1){
			int mid = (r+l)/2;
			if(t[i]<s[mid])r = mid;
			else l = mid;
		}
		if(s[(r+l)/2]==t[i])ct++;
	}
	cout << ct << endl;
  return 0;
}
