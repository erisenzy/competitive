/*
 *概要:
 *挿入ソートの既に整列されている列なら高速化が期待できる性質を利用して、先にまばらなソートを行う
 */

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <map>
#include <set>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <bitset>
#include <climits>
#define REP(i,n) for (int i=0;i<(n);i++)
#define FOR(i,a,b) for (int i=(a);i<(b);i++)
#define RREP(i,n) for (int i=(n)-1;i>=0;i--)
#define RFOR(i,a,b) for (int i=(a)-1;i>=(b);i--)
#define ll long long
#define ull unsigned long long
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
const int INF = 1e9;
const int MOD = 1e9 + 7;

using namespace std;

int a[1000001];
//g =1 の時通常の挿入ソート
int insertionSort(int n,int g){
	int ct = 0;
	FOR(i,g,n){
		int v = a[i];
		int j = i-g;
		while(j>=0&&v<a[j]){
			a[j+g]=a[j];
			j-=g;
			ct++;
		}
		a[j+g] = v;
	}
	return ct;
}

int shellSort(int n){
	int G[100];
	int m = 0;
	for(int h = 1;;){
		if(h>n)break;
		G[m++] = h;
		h = 3*h+1;
	}
	int ct = 0;
	RREP(i,m)ct+=insertionSort(n,G[i]);

	cout << m << endl;
	REP(i,m){if(i)cout << ' ';cout << G[m-1-i];}
	cout << '\n';
	cout << ct << endl;
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
	int n;cin>>n;
	REP(i,n)cin>>a[i];
	shellSort(n);
	REP(i,n)cout << a[i] << endl;
  return 0;
}
