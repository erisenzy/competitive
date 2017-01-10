/*
	一つ目の条件に囚われてaかbが０の時思考停止でカウントしなかったのが敗因
	それ以外は特になし
 */
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>
#include <cmath>
#define REP(i,n) for (int i=0;i<(n);i++)
#define ALL(a) (a).begin(),(a).end()
#define ll long long
#define ull unsigned long long
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

using namespace std;

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
	int c,m,n;
	cin >> c;
	while(c--){
		cin >> m >> n;
		if(m*m + n*n <= 1){
			cout << 'C' << endl;
			continue;
		}
		int ct = 0;
		int size = m*m + n*n + 1;//20000でもよい
		for(int x = -sqrt(size) ;x*x <= size;++x){
			for(int y = -sqrt(size) ;y*y <= size;++y){
				if(x==y && x==0)continue;
				int sqsum = x*x + y*y;
				int a = x*m + y*n, b = x*n - y*m;
				if(a % sqsum == 0 && b % sqsum == 0){
					ct++;
					//					cout << "x:" << x << " y:" << y << endl;
				}
			}
		}
		if(ct == 8)cout << 'P' << endl;
		else cout << 'C' << endl;
	}
  return 0;
}
