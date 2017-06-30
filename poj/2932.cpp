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

struct Point{
    double x,y;
    Point(){}
    Point(double x,double y):x(x),y(y){}
};

class Circle{
public:
	Point c;
	double r;
	Circle(Point c = Point(), double r = 0.0): c(c),r(r){}
	Circle(double x,double y, double r = 0.0): c(Point(x,y)),r(r){}
};

Circle cir[40004];
#define pdi pair<double,int>

bool isin(int i, int j){
    double dx = cir[i].c.x-cir[j].c.x;
    double dy = cir[i].c.y-cir[j].c.y;
    return dx*dx+dy*dy <= cir[j].r*cir[j].r;
}
int main(){
  int N;
  scanf("%d",&N);
  vector<pair<double,int> > events;
  REP(i,N){
      double a,b,r;
      scanf("%lf%lf%lf",&r,&a,&b);
      cir[i].c = Point(a,b);
      cir[i].r = r;
      events.push_back(make_pair(a-r,i));//L
      events.push_back(make_pair(a+r,i+N));//R
  }
  sort(events.begin(),events.end());
  set<pair<double, int> > outers;
  vector<int> ans;
  REP(i,2*N){
      pdi ev = events[i];
      if(events[i].second < N){//L
          set<pair<double,int> >::iterator itr = outers.lower_bound(pdi(cir[ev.second].c.y,0));
          bool inside = false;
          if(itr != outers.end()) inside |= isin(ev.second,itr->second);//↑
          if(itr != outers.begin()) itr--,inside |= isin(ev.second,itr->second);//↓
          if(!inside){
              ans.push_back(ev.second);
              outers.insert(pdi(cir[ev.second].c.y,ev.second));
          }
      }else{//R
          ev.second-=N;
          outers.erase(pdi(cir[ev.second].c.y,ev.second));
      }
  }
  sort(ans.begin(),ans.end());
  int s = ans.size();
  printf("%d\n",s);
  REP(i,s){
      printf("%d%c",ans[i]+1,i+1==ans.size()?'\n':' ');
  }
  return 0;
}
