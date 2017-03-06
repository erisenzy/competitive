#include <iostream>
#include <vector>
#include <algorithm>
#define REP(i,n) for (int i=0;i<(n);i++)

using namespace std;

const int N = 1e7;
int p[N];
void Eratosthenes(){
	fill(p,p + N,1);
	p[0] = p[1] = 0;
	for(int i = 2; i*i <= N; i++)
		if(p[i] == 1)
			for(int j = i*i; j <= N; j+=i)
				p[j] = 0;
}



int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
	Eratosthenes();
	vector<int> realp;
	REP(i,N)if(p[i] == 1)realp.push_back(i);
	int a;
	while(cin >> a,a){
		auto itl = lower_bound(realp.begin(),realp.end(),a),
			itu = upper_bound(realp.begin(),realp.end(),a);
		cout << *itl - *(itu-1) << endl;
	}
  return 0;
}
