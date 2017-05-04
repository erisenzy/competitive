#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <map>
#include <set>
#include <queue>
#include <stack>
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

using State = string::const_iterator;

int formula(State& begin);

void consume(State &begin, char expected){
	if(*begin==expected)begin++;
	else{
		cerr << "expected '" << expected << "' but got '" << *begin << "'" << endl;
		cerr << "Rest string is'";
		while(*begin)cerr << *begin++;
		cerr << "'" << endl;
		exit(0);
	}
}


int reverse(int a){
	if(a==2)return 0;
	else if(a==0)return 2;
	else return 1;
}

int number(State& begin){
	int ret = (int)(*begin - '0');
	begin++;
	return ret;
}

int factor(State& begin){
	int ret = formula(begin);
	if(*begin == '+'){
		begin++;
		int ret2 = formula(begin);
		ret = max(ret,ret2);
	}else if(*begin == '*'){
		begin++;
		int ret2 = formula(begin);
		ret = min(ret,ret2);
	}
	return ret;
}

int formula(State& begin){
	if(*begin == '-'){
		begin++;
		return reverse(formula(begin));
	}else if(*begin == '('){
		consume(begin,'(');
		int ret = factor(begin);
		consume(begin,')');
		return ret;
	}else{
		return number(begin);
	}
}



int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
	string s;
	while(cin>>s,s[0]!='.'){
		int ct = 0;
		REP(P,3){
			REP(Q,3){
				REP(R,3){
					string tmps = s;
					replace(tmps.begin(),tmps.end(),'P',(char)('0' + P));
					replace(tmps.begin(),tmps.end(),'Q',(char)('0' + Q));
					replace(tmps.begin(),tmps.end(),'R',(char)('0' + R));
					State start = tmps.begin();
					if(formula(start) == 2)ct++;
				}
			}
		}
		cout << ct << endl;
	}
  return 0;
}
