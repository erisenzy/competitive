#include <vector>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <set>

const double EPS = 1e-10;
const double INF = 1e+10;
const double PI = acos(-1);
#define equals(a,b) (fabs((a) - (b)) < EPS)

using namespace std;

struct Point{
	double x,y;
    //    Point operator + (const Point& p){ return Point(x+p.x,y+p.y);	}
	Point operator - (const Point& p){ return Point{x - p.x, y - p.y}; }
    //    Point operator * (double r){ return Point{x * r, y * r}; }
    //    Point operator / (double k){ return Point(x/k,y/k); }
};
typedef Point Vector;

double norm(Vector a){return a.x*a.x+a.y*a.y;}
double abs(Vector a){return sqrt(norm(a));}
double dot(Vector a, Vector b){return a.x * b.x + a.y * b.y;}//内積
double cross(Vector a, Vector b){return a.x*b.y - a.y*b.x;}//外積

struct Segment{
	Point p1,p2;
};

struct Circle{
	Point c;
	double r;
};

typedef Segment Line;
typedef vector<Point> Polygon;

double getArea(Polygon g){
	double ans = 0.0;
	int n = g.size();
	for(int i=0;i<n;i++){
		ans+=cross(Vector(g[i]), Vector(g[(i+1)%n]));
	}
	return fabs(ans)/2;
}

bool isOrthgonal(Vector a, Vector b){
	return equals(dot(a,b),0.0);
}

bool isOrthgonal(Point a1, Point a2, Point b1, Point b2){
	return isOrthgonal(a1-a2,b1-b2);
}

bool isOrthgonal(Segment s1, Segment s2){
	return equals(dot(s1.p2 - s1.p1, s2.p2 - s2.p1),0.0);
}

bool isParallel(Vector a,Vector b){
	return equals(cross(a,b),0.0);
}

bool isParallel(Point a1, Point a2, Point b1, Point b2){
	return isParallel(a1-a2,b1-b2);
}

bool isParallel(Segment s1, Segment s2){
	return equals(cross(s1.p2 - s1.p1,s2.p2-s2.p1),0.0);
}

Point project(Segment s,Point p){
	Vector base = s.p2 - s.p1;
	double r = dot(p-s.p1,base)/norm(base);
	return s.p1 + base * r;
}

Point reflect(Segment s, Point p){
	return p + (project(s,p) - p) * 2.0;
}



//時計周りチェック
static const int COUNTER_CLOCKWISE = 1;
static const int CLOCKWISE = -1;
static const int ONLINE_BACK = 2;
static const int ONLINE_FRONT = -2;
static const int ON_SEGMENT = 0;
int ccw(Vector a, Vector b){
	if(cross(a,b) > EPS)return COUNTER_CLOCKWISE;//1
	if(cross(a,b) < -EPS)return CLOCKWISE;//-1
	if(dot(a,b) < -EPS)return ONLINE_BACK;//2
	if(norm(a) < norm(b))return ONLINE_FRONT;//-2
	return ON_SEGMENT;//0
}

int ccw(Point p1,Point p2,Point p3){
	Vector a = p2 - p1;
	Vector b = p3 - p1;
	if(cross(a,b) > EPS)return COUNTER_CLOCKWISE;//1
	if(cross(a,b) < -EPS)return CLOCKWISE;//-1
	if(dot(a,b) < -EPS)return ONLINE_BACK;//2
	if(norm(a) < norm(b))return ONLINE_FRONT;//-2
	return ON_SEGMENT;//0
}

//線分交差判定
bool intersect(Point p1, Point p2, Point p3,Point p4){
	return ccw(p1,p2,p3)*ccw(p1,p2,p4) <= 0 && ccw(p3,p4,p1)*ccw(p3,p4,p2) <= 0;
}

//交点
Point getCsP(Segment s1, Segment s2){
	Vector base = s2.p2 - s2.p1;
	double d1 = abs(cross(base,s1.p1 - s2.p1));//約分で消去
	double d2 = abs(cross(base,s1.p2 - s2.p1));
	double t = d1 / (d1+d2);
	return s1.p1 + (s1.p2 - s1.p1)*t;
}

pair<Point, Point> getCsP(Circle c, Line l){
	//assert(intersect(c,l));
	Vector pr = project(l,c.c);
	Vector e = (l.p2 - l.p1)/abs(l.p2 - l.p1);
	double base = sqrt(c.r*c.r - norm(pr - c.c));
	return make_pair(pr + e*base, pr - e*base);
}


// x軸との角度を返す
double arg(Vector p){return atan2(p.y,p.x);}
// 角度0の直線をradian r 度回転(つまりわたすrは0 <= r < 2pi)
Vector polar(double a,double r){return Point(cos(r)*a,sin(r)*a);}

// 円同士の交点を返す
pair<Point, Point> getCsP(Circle c1, Circle c2){
	//assert(intersect(c1,c2))
	double d = abs(c1.c-c2.c);//円同士の距離
	double a = acos((c1.r * c1.r + d*d - c2.r*c2.r)/(2*d*c1.r));//余弦定理で交点と中心間線分のなす角を求める
	double t = arg(c2.c - c1.c);
	return make_pair(c1.c + polar(c1.r,t+a),c1.c + polar(c1.r,t-a));
}


//{点,直線,線分}^2の距離
double getDist(Point a,Point b){return abs(a-b);}
double getDistLP(Line l, Point p){ return abs(cross(l.p2 - l.p1, p-l.p1) / abs(l.p2 - l.p1));}
double getDistSP(Segment s,Point p){
	if(dot(s.p2 - s.p1, p-s.p1) < 0.0) return abs(p-s.p1);
	if(dot(s.p1 - s.p2, p-s.p2) < 0.0) return abs(p-s.p2);
	return getDistLP(s,p);
}

double getDist(Segment s1, Segment s2){
	if(intersect(s1.p1, s1.p2, s2.p1, s2.p2)) return 0.0;
	return min(min(getDistSP(s1, s2.p1), getDistSP(s1, s2.p2)),
						 min(getDistSP(s2, s1.p1), getDistSP(s2, s1.p2)));
}




/*
 * 凸性判定
 * 凸性は180度以下の条件なので、直線上は全て許される
 */
bool isConvex(Polygon g){
	int n = g.size();
	REP(i,n){
		int tmpccw = ccw(g[i],g[(i+1)%n],g[(i+2)%n]);
		if(tmpccw == CLOCKWISE)return false;
	}
	return true;
}

/*
 * 点の内包
 * IN 2, ON 1, OUT 0
 */
int contains(Polygon& g, Point p){
	int n = g.size();
	bool x = false;
	REP(i,n){
		Point a = g[i] - p, b = g[(i+1)%n] - p;
		if(abs(cross(a,b)) < EPS && dot(a,b) < EPS)return 1;
		if(a.y > b.y) swap(a,b);
		if(a.y < EPS && EPS < b.y && cross(a,b) > EPS) x = !x;
	}
	return x ? 2 : 0;
}

/*
 * y軸優先昇順
 */
bool compare(const Point& a,const Point& b){
	if(a.y == b.y)return a.x < b.x;
	return a.y < b.y;
}
/*
 * 凸包を求める(アンドリューのアルゴリズム)
 */
Polygon andrewScan(Polygon g){
	Polygon u,l;
	if(g.size() < 3) return g;
	sort(g.begin(),g.end(),compare);//compareなしでx軸優先昇順
	u.push_back(g[0]);
	u.push_back(g[1]);
	l.push_back(g[g.size() - 1]);
	l.push_back(g[g.size() - 2]);
	// 凸包の上部を生成
	for(int i =2;i < g.size();i++){
		for(int n = u.size();n>=2&&ccw(u[n-2],u[n-1],g[i]) == COUNTER_CLOCKWISE;n--){
			u.pop_back();
		}
		u.push_back(g[i]);
	}
	// 凸包の下部を生成
	for(int i = g.size() - 3;i >= 0;i--){
		for(int n = l.size();n>=2&&ccw(l[n-2],l[n-1],g[i])==COUNTER_CLOCKWISE;n--){
			l.pop_back();
		}
		l.push_back(g[i]);
	}
		reverse(l.begin(),l.end());
	for(int i = u.size() - 2;i>=1;i--)l.push_back(u[i]);
	return l;
}


// 端点の種類
#define BOTTOM 0
#define LEFT 1
#define RIGHT 2
#define TOP 3

class EndPoint{
public:
	Point p;
	int seg, st;
	EndPoint(){}
	EndPoint(Point p,int seg,int st):p(p),seg(seg),st(st){}

	bool operator < (const EndPoint &ep) const{
		// y座標が小さい順に整列
		if(p.y == ep.p.y){
			return st < ep.st;
		}else return p.y < ep.p.y;
	}
};

EndPoint EP[2 * 1000000]; //端点のリスト

//線分交差問題：マンハッタン幾何
int manhattanIntersection(vector<Segment> S){
	int n = S.size();

	for(int i = 0,k = 0;i < n;i++){
		// 端点のp1,p2が左下を基準に並ぶように調整
		if(S[i].p1.y == S[i].p2.y){
			if(S[i].p1.x > S[i].p2.x)swap(S[i].p1,S[i].p2);
		}else if(S[i].p1.y > S[i].p2.y)swap(S[i].p1,S[i].p2);

		if(S[i].p1.y == S[i].p2.y){
			EP[k++] = EndPoint(S[i].p1, i, LEFT);
			EP[k++] = EndPoint(S[i].p2, i, RIGHT);
		}else{
			EP[k++] = EndPoint(S[i].p1, i, BOTTOM);
			EP[k++] = EndPoint(S[i].p2, i, TOP);
		}
	}

	sort(EP,EP + 2*n); // 端点のy座標に関して昇順に整列

	set<int> BT; // 二分探索木
	BT.insert((int)1e9 + 1); //番兵を設置
	int cnt = 0;

	for(int i = 0;i < 2*n;i++){
		if(EP[i].st == TOP) BT.erase(EP[i].p.x); // 上端点を削除
		else if(EP[i].st == BOTTOM)BT.insert(EP[i].p.x); // 下端点を追加
		else if(EP[i].st == LEFT){
			set<int>::iterator b = lower_bound(BT.begin(), BT.end(), S[EP[i].seg].p1.x); // O(log n)
			set<int>::iterator e = upper_bound(BT.begin(), BT.end(), S[EP[i].seg].p2.x); // O(log n)
			cnt += distance(b,e); //bとeの距離（点の数）を加算,O(k)
		}
	}
	return cnt;
}

