/*
	蟻本練習問題
	座標圧縮＋二次元imos＋幅優先探索
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define REP(i,n) for (int i=0;i<(n);i++)
#define FOR(i,a,b) for (int i=(a);i<(b);i++)
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

using namespace std;
int n;
int compress(int *x1,int *x2,int w){
	vector<int> xs;
	REP(i,n){
		FOR(d,-1,2){
			int tx1 = x1[i] + d,tx2 = x2[i] + d;
			if(tx1 >=0 && tx1 <= w)xs.push_back(tx1);
			if(tx2 >=0 && tx2 <= w)xs.push_back(tx2);
		}
	}
	sort(xs.begin(),xs.end());
	xs.erase(unique(xs.begin(),xs.end()),xs.end());
	REP(i,n){
		x1[i] = find(xs.begin(),xs.end(),x1[i])-xs.begin();
		x2[i] = find(xs.begin(),xs.end(),x2[i])-xs.begin();
	}
	return xs.size();
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
	int h,w;
	while(cin >> w >> h,w){
		cin >> n;
		int x1[1003],x2[1003],y1[1003],y2[1003];
		REP(i,n){
			cin >> x1[i] >> y1[i] >> x2[i] >> y2[i];
		}
		w = compress(x1,x2,w);
		h = compress(y1,y2,h);
		vector<vector<int> > fld(h,vector<int>(w,0));
		REP(i,n){
			fld[y1[i]][x1[i]]++;
			fld[y1[i]][x2[i]]--;
			fld[y2[i]][x1[i]]--;
			fld[y2[i]][x2[i]]++;
		}
		REP(i,h)REP(j,w-1)fld[i][j+1] += fld[i][j];
		REP(j,w)REP(i,h-1)fld[i+1][j] += fld[i][j];

		vector<vector<bool> > ispass(h,vector<bool>(w,false));
		queue<pair<int,int> > que;
		que.push(make_pair(0,0));
		int ct = 0;
		/*		REP(i,h){
			REP(j,w){
				cout << fld[i][j] << ' ';
			}
			cout << endl;
			}*/
		REP(i,h-1){
			REP(j,w-1){
				if(!ispass[i][j] && fld[i][j] == 0){
					ct++;
					ispass[i][j] = true;
					que.push(make_pair(i,j));
					while(!que.empty()){
						int y = que.front().first,x = que.front().second;
						que.pop();
						REP(k,4){
							int ny = y + dy[k];
							int nx = x + dx[k];
							if(nx >= 0 && nx <w-1 && ny>=0 && ny < h-1 && !ispass[ny][nx] && fld[ny][nx]==0){
								ispass[ny][nx] = true;
								que.push(make_pair(ny,nx));
							}
						}
					}
				}
			}
		}
		cout << ct << endl;
	}
  return 0;
}
