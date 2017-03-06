#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <map>
#include <cstring>
#define REP(i,n) for (int i=0;i<(n);i++)
#define ll long long
#define ull unsigned long long
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

using namespace std;

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
	ll n;
	cin >> n;
	vector<ll> a(n);
	REP(i,n){
		cin >> a[i];
	}
	ll suma = accumulate(a.begin(),a.end(),(long long)0);
	ll sumope = (long long)n*(n+1)/2;
	if(suma % sumope != 0){
		cout << "NO" << endl;
		return 0;
	}else{
		vector<ll> b(n);
		REP(i,n-1)b[i] = a[i+1]-a[i];
		b[n-1] = a[0]-a[n-1];
		ll numope = suma / sumope;
		REP(i,n){
			b[i] -=numope;
			if(b[i] > 0 || (-b[i]) % n != 0){
				cout << "NO" << endl;
				return 0;
			}
		}
	}
	cout << "YES" << endl;
  return 0;
}
