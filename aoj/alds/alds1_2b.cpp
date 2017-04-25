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
	int n;cin>>n;vector<int> a(n);REP(i,n)cin>>a[i];
	int ct = 0;
	REP(i,n){
		int mini = i;
		FOR(j,i,n){
			if(a[j] < a[mini])mini = j;
		}
		if(i!=mini){
			swap(a[i],a[mini]);
		ct++;
		}
	}
	REP(i,n){
		if(i)cout << ' ';
		cout << a[i];
	}
	cout << '\n';
	cout << ct << endl;
  return 0;
}
