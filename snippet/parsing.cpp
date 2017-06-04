#include <iostream>
#include <string>
#include <cctype>
using namespace std;
using State = string::const_iterator;

class ParseError{
};




//数字の列をパースしてその数を返す
int number(State& begin){
	int ret = 0;
	while(isdigit(*begin)){
		ret*=10;
		ret+=*begin-'0';
		begin++;
	}
	return ret;
}

int term(State& begin){
	int ret = number(begin);
	for(;;){
		if(*begin == '*'){
			begin++;
			ret *= number(begin);
		}else if(*begin == '/'){
			begin++;
			ret /= number(begin);
		}else break;
	}
	return ret;
}

int expression(State& begin){
	int ret = term(begin);
	for(;;){
		if(*begin == '+'){
			begin++;
			ret += term(begin);
		}else if(*begin == '-'){
			begin++;
			ret -= term(begin);
		}else break;
	}
	return ret;
}

int main(){
	int N;
	cin >> N;
	cin.ignore();//必須
	for (int i = 0; i < N; i++) {
		string s;

		getline(cin, s);
		cout << "input: " << s << endl;
		State begin = s.begin();
		int ans = expression(begin);
		cout << ans << endl;
	}
	return 0;
}
