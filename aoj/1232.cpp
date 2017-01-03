#include <iostream>
#include <vector>
#define REP(i,n) for (int i=0;i<(n);i++)
const int N = 30000;
using namespace std;
bool a[N];
vector<int> prime;
void erast(){
	fill(a,a + N,true);
	a[0] = a[1] = false;
	for(int i = 2; i*i <= N;++i){
		if(a[i] == false)continue;
		for(int j = i*i; j<=N;j += i){
			a[j] = false;
		}
	}
	REP(i,N){
		if(a[i] == false)continue;
		prime.push_back(i);
	}
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
	erast();
	int m,a,b;
	while(cin>>m>>a>>b,m){
		int maxpq = 0,maxp = 0,maxq = 0;
		REP(i,prime.size()){
			if(prime[i] > m)break;
			for(int j = i;j < prime.size();j++){
				int p = prime[i],q = prime[j];
				if(p <= q && p * q <= m && a*q <= b*p){
					if(maxpq <= p*q){
					maxpq = p*q;
					maxp = p;
					maxq = q;
					}
				}else break;
			}
		}
		cout << maxp << ' ' << maxq << endl;
	}
  return 0;
}
