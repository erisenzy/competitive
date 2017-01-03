#include <bits/stdc++.h>
#define REP(i,n) for (int i=0;i<(n);i++)
const int N = 30000;
using namespace std;
bool a[N];
vector<int> prime;
vector<pair<int,double> > primepair;
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
	REP(i,prime.size()){
		for(int j = i;j < prime.size();j++){
			primepair.push_back(make_pair(prime[i]*prime[j],(double)prime[i] / prime[j]));
		}
	}
	sort(primepair.begin(),primepair.end());
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
	erast();
	int m,a,b;
	while(cin>>m>>a>>b,m){
		double suitable_p = (double)a/b;
		for(auto itr = lower_bound(primepair.begin(),primepair.end(),make_pair(m,5.0));;itr--){
			if(itr->first <= m && itr->second >= suitable_p){
				cout << ceil(sqrt(itr->first*itr->second)) << ' '<< ceil(sqrt(itr->first/itr->second))  << endl;
				break;
			}
			if(itr == primepair.begin())break;
		}
	}
  return 0;
}
