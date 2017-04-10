#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;
int dx[8] = {0,1,1,1,0,-1,-1,-1};
int dy[8] = {1,1,0,-1,-1,-1,0,1};
int main(){
  int h,w;
  while(cin>>h>>w,h){
    vector<string> s(h);
    for(int i = 0;i < h;i++){
      cin>>s[i];
    }
    map<string,int> mp;
    for(int i = 0;i < h;i++){
      for(int j = 0;j < w;j++){
	for(int d = 0;d < 8;d++){
	  int y = i, x = j;
	  string tmps = "";
	  tmps += s[i][j];
	  while(true){
	    int ny = (y+dy[d] + h)%h, nx = (x+dx[d] + w)%w;
	    if(ny == i && nx == j){
	      break;
	    }else{
	      tmps+=s[ny][nx];
	      mp[tmps]++;
	      x=nx,y=ny;
	    }
	  }
	}
      }
    }
    string ans;
    int maxsize = 0;
    for(auto itr = mp.begin();itr!=mp.end();itr++){
      if(itr->second >= 2 && itr->first.size() > maxsize){
	ans = itr->first;
	maxsize = itr->first.size();
      }
    }
    if(maxsize)cout << ans << endl;
    else cout << 0 << endl;
  }
  return 0;
}
