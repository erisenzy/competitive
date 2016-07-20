//	824K	110MS	
#include <iostream>
#include <vector>
#include <algorithm>
#define REP(i,n) for (int i=0;i<(n);i++)
using namespace std;

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
	int n,m;
	while(cin >> n >> m,n){
		vector<int> dragon(n),soldier(m);
		REP(i,n)cin >> dragon[i];
		REP(i,m)cin >> soldier[i];
		sort(dragon.begin(), dragon.end());
		sort(soldier.begin(), soldier.end());
		int ans = 0;
		int di = 0, si = 0;
		while(di != n && si != m){
			if(soldier[si] >= dragon[di]){
				ans += soldier[si];
				si++;
				di++;
			}else{
				si++;
			}
		}
		if(di == n)cout << ans << endl;
		else cout << "Loowater is doomed!" << endl;
	}
  return 0;
}
