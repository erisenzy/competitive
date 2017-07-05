#include <vector>

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
