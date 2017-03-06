/*
	ヨセフスの問題
	参考:
	https://ja.wikipedia.org/wiki/%E3%83%A8%E3%82%BB%E3%83%95%E3%82%B9%E3%81%AE%E5%95%8F%E9%A1%8C
	- wikipedia
	http://imulan.hatenablog.jp/entry/2015/06/01/175701
	- 裏紙
	漸化式は
	f(n,k) = (f(n-1,k) + k) % n
	f(1,k) = 0
	この問題がヨセフスの問題と違う点は
	・始点が0（最初の人）ではなくmになる
	・始点を取り除く
	この二点を踏まえて考えると、最初に呼び出す際のf(n,k)を
	f(n,k) = (f(n-1,k) + m) % n
	に変形すると上手く行く。
	解釈としては、
	・ヨセフスの問題より最初から一人人数が少ないと考えて、f(n-1,k)とする
	・始まりがm番目の人なので、f(n-1,k) + m

	注意としては出力が1から数えているので、 + 1 を忘れないこと
 */
#include <iostream>
#define REP(i,n) for (int i=0;i<(n);i++)

using namespace std;

int josephus(int n,int k){
	if(n == 1)return 0;
	else return (josephus(n-1,k) + k) % n;
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
	int n,k,m;
	while(cin >> n >> k >> m,n){
		cout <<  (josephus(n - 1,k) + m) % n + 1<< endl;
	}
  return 0;
}
