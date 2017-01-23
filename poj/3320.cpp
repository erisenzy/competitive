#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>
#include <map>
#include <set>
#include <cstdio>
#define REP(i,n) for (int i=0;i<(n);i++)
#define ALL(a) (a).begin(),(a).end()
#define ll long long
#define ull unsigned long long
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

using namespace std;
const int MAX_N = 1e6+1;
int a[(int)1e6+1];
int main(){
	int n;
	scanf("%d",&n);
	set<int> se;
	REP(i,n){
	scanf("%d",&a[i]);
		se.insert(a[i]);
	}
	int size = se.size();
	int s=0;
	int t=0,num=0,res=n;
	map<int,int> count;
	while(true){
		while(t < n && num < size){
			if(count[a[t++]]++ == 0){
				num++;
			}
		}
		if(num < size)break;//何故これでうまく行くのか
		res = min(res,t-s);
		if(--count[a[s++]] == 0){
			num--;
		}
	}
	printf("%d\n",res);
  return 0;
}
