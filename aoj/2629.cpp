#include <iostream>
#include <iomanip>
#include <cmath>
#include <algorithm>
#define REP(i,n) for (int i=0;i<(n);i++)

using namespace std;

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
	double d;
	cin >> d;
	cout << fixed << setprecision(9) << max(floor(d) + 1,sqrt(2) * d) << endl;
  return 0;
}
