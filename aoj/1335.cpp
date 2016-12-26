#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#define REP(i,n) for (int i=0;i<(n);i++)
#define ll long long
#define ull unsigned long long
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

using namespace std;
int ct = 0;
int n,k,s;
void solve(int k_num,int min_n,int sum_set){
	for(int i = min_n + 1;i <= n;i++){
		if(k_num == k-1 && sum_set + i == s){
			ct++;
			return;
		}
		if(k_num + 1 < k)
			solve(k_num + 1,i,sum_set + i);
	}
	return;
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
	while(cin >> n >> k >> s,n){
		ct = 0;
		solve(0,0,0);
		cout << ct << endl;
		}
  return 0;
}
