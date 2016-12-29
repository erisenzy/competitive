#include <iostream>
#include <vector>
#define REP(i,n) for (int i=0;i<(n);i++)

using namespace std;

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
	int n,k,m;
	while(cin >> n >> k >> m,n){
		vector<bool> stone(n,true);
		int stone_ct = 0;
		int index = m - 1;
		int interval = 0;
		while(true){
			if(!stone[index]){
				index = index + 1 < n ? index + 1 : 0;
			}else if(interval == 0){
				stone[index] = false;
				stone_ct++;
				//							cout << index << endl;
				if(stone_ct == n - 1){
					break;
				}else{
					interval = (k % (n - stone_ct) - 1 + n - stone_ct)%(n-stone_ct);
					index = index + 1 < n ? index + 1 : 0;
				}
			}else{
				index = index + 1 < n ? index + 1 : 0;
				interval--;
			}
		}
		REP(i,n){
			if(stone[i]){
						cout << i + 1 << endl;
						break;
			}
		}
	}
  return 0;
}
