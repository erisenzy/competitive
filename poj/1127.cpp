#include <iostream>

using namespace std;

const double EPS=1e-10;
struct Point{
  double x,y;Point(double x,double y):x(x),y(y){}
  Point(){}
};

typedef Point Vector;

double norm(Vector a){return a.x*a.x+a.y*a.y;}

double dot(Vector a,Vector b){
  return a.x*b.x+a.y*b.y;
}

double cross(Vector a, Vector b){
  return a.x*b.y - a.y*b.x;
}

int ccw(Point p1,Point p2,Point p3){
  Vector a = Vector(p2.x-p1.x,p2.y - p1.y);
  Vector b = Vector(p3.x-p1.x,p3.y - p1.y);
  if(cross(a,b) > EPS)return 1;
  if(cross(a,b) < -EPS)return -1;
  if(dot(a,b) < -EPS)return 2;
  if(norm(a) < norm(b))return -2;
  return 0;
}

bool intersect(Point a,Point b,Point c,Point d){
  return ccw(a,b,c)*ccw(a,b,d) <=0 && ccw(c,d,a)*ccw(c,d,b)<=0;
}

int n;
Point p[13][2];
bool oklist[13][13];

int main(){

  while(cin>>n,n){
    for(int i =1;i<=n;i++){
      int a,b,c,d;
      cin>>a>>b>>c>>d;
      p[i][0]=Vector(a,b);
      p[i][1]=Vector(c,d);
    }

    fill(oklist[0],oklist[13],false);

    for(int i =1;i<=n;i++){
        oklist[i][i]=true;
      for(int j =i+1;j<=n;j++){
	if(intersect(p[i][0],p[i][1],p[j][0],p[j][1])) oklist[i][j] = oklist[j][i] = true;
      else  oklist[i][j] = oklist[j][i] = false;
      }
    }


    for(int k =1;k<=n;k++){
        for(int i =1;i<=n;i++){
            for(int j =1;j<=n;j++){
                oklist[i][j] |= oklist[i][k] && oklist[k][j];
            }
        }
    }

    int a,b;
    while(cin>>a>>b,a){
      if(oklist[a][b] || oklist[b][a])cout << "CONNECTED" << endl;
      else cout << "NOT CONNECTED" << endl;
    }
  }
}
