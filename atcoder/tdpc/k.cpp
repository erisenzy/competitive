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

int N;

vector<int> LIS(vector<int> &v){
	vector<int> dp(N,1 << 30);
	for(int i = 0;i < N;i++){
		dp[lower_bound(dp.begin(),dp.end(), v[i]) - dp.begin()] = v[i];
	}
	int size = 0;
	for(;size < N;size++){
		if(dp[size] == 1 << 30)break;
	}
	dp.resize(size);
	return dp;
}

bool EVAL(const pair<int,int>& a, const pair<int,int>& b){
	return a.first + a.second < b.first + b.second || (a.first + a.second == b.first + b.second && a.first - a.second < b.first - b.second);
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

	cin >> N;
	vector<pair<int,int > > x(N);
	REP(i,N){
		cin >> x[i].first >> x[i].second;
	}
	sort(x.begin(),x.end(),EVAL);
	vector<int> v(N);
	REP(i,N) v[i] = -(x[i].first - x[i].second);
	cout << LIS(v).size() << endl;
  return 0;
}
