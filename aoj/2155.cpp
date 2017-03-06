#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#define REP(i,n) for (int i=0;i<(n);i++)

using namespace std;
struct com{
	int t,s,d;
};

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
	int n,m;
	while(cin>>n>>m,n){
		vector<com> computer(m);
		vector<char> infected(n,0);
		infected[0] = 1;
		REP(i,m){
			int t,s,d;
			cin >> t >> s >> d;
			computer[i] = {--t,--s,--d};
		}
		sort(computer.begin(),computer.end(),[](com a,com b){
				return a.t < b.t;
			});
		REP(i,m){
			infected[computer[i].d] |= infected[computer[i].s];
		}
		cout << accumulate(infected.begin(),infected.end(),0) << endl;
	}
  return 0;
}
