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

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
	int n,m;
	int a[100005],nums[100005];
	scanf("%d%d",&n,&m);
	int b = 1000;
	vector<vector<int> > backet(100005/b ,vector<int>());
	//	int nb = sqrt(n);
	//int nb = 1000;

	REP(i,n){
		scanf("%d",&a[i]);
		nums[i] = a[i];
		backet[i/b].push_back(a[i]);
	}
	sort(nums,nums+n);
	REP(i,n/b){
		sort(backet[i].begin(),backet[i].end());
	}
	REP(i,m){
		int qi,qj,qk;
		scanf("%d%d%d",&qi, &qj,&qk);
		qi--;
		int lb = -1,ub = n-1;
		while(ub-lb>1){
			int mib = (ub + lb)/2;
			int x = nums[mib],ct = 0;
			int l = qi,u = qj;
			while(l < u && l%b !=0)if(a[l++] <= x)ct++;
			while(l < u && u%b !=0)if(a[--u] <= x)ct++;//B- まで触らせる
			while(l < u){
				int bi = l/b;
				ct += upper_bound(backet[bi].begin(),backet[bi].end(),x) - backet[bi].begin();
				l+=b;
			}
			if(ct>=qk)ub = mib;
			else lb = mib;
		}
		printf("%d\n",nums[ub]);
	}
	/*	REP(i,n){
		cout << nums[i] << ' ' << a[i] << ' ' << backet[0][i] << endl;
		}*/
  return 0;
}
