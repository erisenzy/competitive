#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <map>
#include <cstdio>
#define REP(i,n) for (int i=0;i<(n);i++)
#define ll long long
#define ull unsigned long long
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

using namespace std;

int main(){

	int n;
	cin >> n;
	vector<int> a(n),b(n),c(n),d(n);
	REP(i,n)scanf("%d%d%d%d",&a[i],&b[i],&c[i], &d[i]);
	vector<int> ab(n*n);
	REP(i,n){
		REP(j,n){
			ab[i*n+j] = a[i] + b[j];
		}
	}
	long long ans = 0;
	sort(ab.begin(),ab.end());
	REP(i,n){
		REP(j,n){
			vector<int>::iterator uitr =  upper_bound(ab.begin(),ab.end(),-(c[i] + d[j]));
			vector<int>::iterator litr =  lower_bound(ab.begin(),ab.end(),-(c[i] + d[j]));
			if(*uitr!=*litr)
				ans += distance(litr,uitr);
		}
	}
	printf("%lld\n",ans);
  return 0;
}
