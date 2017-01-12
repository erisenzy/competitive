#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <numeric>
#include <sstream>
#define REP(i,n) for (int i=0;i<(n);i++)
#define ALL(a) (a).begin(),(a).end()
#define ll long long
#define ull unsigned long long
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

using namespace std;

long long digitdp(string n){
	//	int dp[20][2][4][9]; //digit, letter, 4, 9
	long long dp[20][2] = {};
	dp[0][0] = 1;
	for(int i = 0;i < n.size();i++){
		for(int l = 0;l < 2;l++){
			int digit = l ? 9 : n[i] - '0';
			for(int d = 0;d <= digit;d++){
				if(d == 4 || d == 9)continue;
				dp[i + 1][l || (digit - d)] += dp[i][l];
			}
		}
	}
	stringstream ss;
	ss << n;
	long long a;
	ss >> a;
	return (a - (dp[n.size()][0] + dp[n.size()][1]));
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
	long long tmpa;
	string a,b;
	cin >> tmpa >> b;
	tmpa--;
	ostringstream sout;
	sout << tmpa;
	a = sout.str();
	cout << digitdp(b) - digitdp(a) << endl;
	
  return 0;
}
