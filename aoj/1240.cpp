#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define REP(i,n) for (int i=0;i<(n);i++)

using namespace std;

string invJ(string s){//右へずらす
	rotate(s.rbegin(),s.rbegin() + 1,s.rend());
	return s;
}

string invC(string s){//leftへずらす
	rotate(s.begin(),s.begin() + 1,s.end());
	return s;
}

string invE(string s){//左部分と右部分を交換
	if((s.size() + 1) & 1)
		rotate(s.begin(),s.begin() + s.size()/2,s.end());
	else{
		string tmp;
		tmp = s;
		s.replace(0,s.size()/2,s.substr(s.size()/2 + 1,s.size()/2));
		s.replace(s.size()/2 + 1,s.size()/2,tmp.substr(0,s.size()/2));
	}
	return s;
}

string invA(string s){//反転
	reverse(s.begin(),s.end());
	return s;
}

string invP(string s){
	REP(i,s.size()){
		if(s[i] == '0')
			s[i] = '9';
		else if(s[i] > '0' && s[i] <= '9')
			s[i]--;
	}
	return s;
}

string invM(string s){
	REP(i,s.size()){
		if(s[i] == '9')
			s[i] = '0';
		else if(s[i] >= '0' && s[i] < '9')
			s[i]++;
	}
	return s;
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
	int n;
	cin >> n;
	while(n--){
		string command,s;
		cin >> command >> s;
		for(int i = command.size()-1;i>=0;i--){
			if(command[i] == 'J')s = invJ(s);
			else if(command[i] == 'C')s = invC(s);
			else if(command[i] == 'E')s = invE(s);
			else if(command[i] == 'A')s = invA(s);
			else if(command[i] == 'P')s = invP(s);
			else if(command[i] == 'M')s = invM(s);
		}
		cout << s << endl;
	}
  return 0;
}
