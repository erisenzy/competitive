#include <iostream>
#define REP(i,n) for (int i=1;i<(n);i++)

using namespace std;

#define N 256

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
	int a[300000] = { 0 };
	for(int i = 0;i < N;i++){
	for(int j = i;j < N;j++){
	for(int k = j;k < N;k++){
	for(int l = k;l < N;l++){
		++a[i*i + j*j + k*k + l*l];
	}
	}
	}
	}
	int n;
	while(cin >> n,n){
		cout << a[n] << endl;
	}
  return 0;

}
