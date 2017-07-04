#include <iostream>
#include <iomanip>
#include <cmath>
#define REP(i,n) for(int i = 0;i < (n);i++)
#define FOR(i,a,n) for(int i = (a);i < (n);i++)
double PI = acos(-1);
const double EPS = 1e-10;
const double INF = 1e9;
using namespace std;

int N,M,L;

struct Point{
    double x,y;
    Point operator - (const Point& p){ return Point{x-p.x,y-p.y};}
};

struct Segment{
    Point p1,p2;
};

double norm(Point a){return a.x*a.x+a.y*a.y;}
double abs(Point a){return sqrt(norm(a));}
double dot(Point a, Point b){return a.x * b.x + a.y * b.y;}
double cross(Point a,Point b){return a.x*b.y - a.y*b.x;}

int ccw(Point p1,Point p2,Point p3){
    Point a = {p2.x-p1.x, p2.y - p1.y};
    Point b = {p3.x-p1.x, p3.y - p1.y};
    if(cross(a,b) > EPS) return 1;
    if(cross(a,b) < -EPS) return -1;
    if(dot(a,b) < -EPS) return 2;
    if(norm(a) < norm(b)) return -2;
    return 0;
}

bool intersect(Point p1, Point p2, Point p3, Point p4){
    return ccw(p1,p2,p3)*ccw(p1,p2,p4) <= 0 && ccw(p3,p4,p1)*ccw(p3,p4,p2) <= 0;
}

bool intersect(Segment s1, Segment s2){
    return intersect(s1.p1,s1.p2, s2.p1, s2.p2);
}

double getDistSP(Segment s, Point p){
    if(dot(s.p2 - s.p1, p - s.p1) < -EPS) return abs(p - s.p1);
    if(dot(s.p1 - s.p2, p - s.p2) < -EPS) return abs(p - s.p2);
    return abs(cross(s.p2 - s.p1, p - s.p1) / abs(s.p2 - s.p1));
}
    

Segment star[102][5];
double mindist[102][102];



double getdist(int u, int v){
    REP(i,5){
        REP(j,5){
            if(intersect(star[u][i],star[v][j])){
                    return 0;
            }
        }
    }
    double ans = INF;
    REP(k,2){
        if(k) swap(u,v);
        REP(i,5){
            REP(j,5){
                ans = min(getDistSP(star[u][i],star[v][j].p1),ans);
            }
        }
    }
    return ans;
}

int main(){
    while(cin>>N>>M>>L,N){
        REP(i,N){
            int x,y,a,r;
            cin>>x>>y>>a>>r;
            Point p[5];
            REP(j,5) p[j] = Point{x + r*sin((double)(72*j - a)/180*PI), y + r*cos((double)(72*j - a)/180*PI)};//star's vertex
            REP(j,5){
                star[i][j] = Segment{p[j], p[(j+2)%5]};
            }
        }

        //caluculate min distance
        REP(i,N){
            FOR(j,i,N){
                mindist[i][j] = mindist[j][i] = getdist(i,j);
            }
        }

        //WF        
        REP(k,N){
            REP(i,N){
                REP(j,N){
                    mindist[i][j] = min(mindist[i][j], mindist[i][k] + mindist[k][j]);
                }
            }
        }
        cout << fixed << setprecision(8) << mindist[M-1][L-1] << endl;
    }
}
