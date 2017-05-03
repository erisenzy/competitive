/*
 *無限にバグらせた　ファースト集合を意識すると良いらしい
 */
#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;
#define REP(i,n)for(int i = 0;i<(n);i++)
const int INF = 1e9;
 
int H,W;
string s[50];
string order;
int ct;
 
vector<char> COND{'~','N','E','S','W','C','T'};
vector<char> MOVE{'^','v','<','>'};
map<char,int> mp;
int dy[4] = {-1,0,1,0},dx[4] = {0,1,0,-1};
 
int stepped[1000][50][50][4];
bool goaled;
int y,x,dir;
 
bool regionCheck(int y,int x){
  return 0<=x&&x<W&&0<=y&&y<H&&s[y][x]!='#';
}
 
bool goalCheck(int y,int x){
  return s[y][x]=='g';
}

int search(int order_i){
  int start_i = order_i;
  while(order_i < order.size()){//end check
    int condition = 1;
 
    //stepped?
    if(stepped[order_i][y][x][dir]==1){goaled = false;
      return INF;
    }else stepped[order_i][y][x][dir]++;
 
    //is condition?
    for(auto o:COND){
      if(order[order_i]==o){condition=-1;break;}
    }
 
    //condition check
    if(condition ==-1){
      bool reverse = false;
      if(order[order_i]=='~'){reverse=true;order_i++;}
 
      if(order[order_i] == 'C'){
				if(s[y + dy[dir]][x + dx[dir]] == '#')condition = 1;
				else condition = 0;
      }else if(order[order_i] == 'T')condition = 1;
      else if(mp[order[order_i]]==dir)condition = 1;
      else condition = 0;
       
      if(reverse)	{
				if(condition)condition = 0;
				else  condition= 1;//reverse
			}
      order_i++;
    }
     
		//execute move order
    if(condition==1){
      while(true){
				//is move order?
				bool canMove = false;
				for(auto m:MOVE)if(order[order_i]==m){canMove=true;break;}
				if(!canMove)break;
 
				//move
				ct++;
				if(order[order_i] == '^'){
					if(regionCheck(y+dy[dir],x+dx[dir])){
						y += dy[dir];x+=dx[dir];
					}
					if(goalCheck(y,x)){goaled = true;return INF;}
				}else if(order[order_i] == 'v'){
					if(regionCheck(y-dy[dir],x-dx[dir])){
						y -= dy[dir];x-=dx[dir];
					}
					if(goalCheck(y,x)){goaled = true;return INF;}
				}else if(order[order_i] == '<'){
					dir = (dir-1 + 4)%4;
				}else{
					dir = (dir+1 + 4)%4;
				}
 
				order_i++;
      }
    }else{
			//proceed index
			int bracket = 0,brace = 0;
			do{
				if(order[order_i] == '['){bracket++;
				}else	if(order[order_i] == ']'){bracket--;
				}else if(order[order_i] == '}'){brace--;
				}else if(order[order_i] == '{'){brace++;
				}
				if(bracket < 0 || brace < 0)break;
			}while(++order_i);
		}
    if(order[order_i] == '['||order[order_i]=='{'){
      order_i += search(order_i + 1);
		}
    else if(order[order_i] == '}'&&condition==1){
      order_i = start_i;
    }
    else if(order[order_i] == ']' || order[order_i] == '}'){
      return order_i - start_i + 2;
    }
  }
}
int main(){
  cin>>H>>W;
  REP(i,H)cin>>s[i];
  cin>>order;
  mp['N'] = 0;
  mp['E'] = 1;
  mp['S'] = 2;
  mp['W'] = 3;
  REP(i,H){
    REP(j,W){
      if(s[i][j]== 's'){
				y = i;x = j;
				s[i][j] = '.';
				break;
      }
    }
  }
  search(0);
  if(goaled) cout << ct << endl;
  else cout << -1 << endl;
}
