 #include <iostream>
#include <string>
#include <cctype>
#include <vector>
using namespace std;
using State = string::const_iterator;

class ParseError{
};


int factor(State& begin);

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
	int ret = factor(begin);
	for(;;){
		if(*begin == '*'){
			begin++;
			ret *= factor(begin);
		}else if(*begin == '/'){
			begin++;
			ret /= factor(begin);
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

int factor(State& begin){
	if(*begin == '('){
		begin++;// '(' を飛ばす
		int ret = expression(begin);
		begin++;//')'を飛ばす
		return ret;
	}else{
		return number(begin);
	}
}

void consume(State &begin, char expected){
	if(*begin == expected){
		begin++;
	}else{
		cerr << "Expected '" << expected << "' but got '" << *begin << "'" << endl;
		cerr << "Rest string is '";
		while(*begin){
			cerr << *begin++;
		}
		cerr << "'" << endl;
		throw ParseError();
	}
}

void consume(State &begin, State &expected){
	if(begin == expected){
		begin++;
	}else{
		cerr << "Expected '" << *expected << "' but got '" << *begin << "'" << endl;
		cerr << "Rest string is '";
		while(*begin){
			cerr << *begin++;
		}
		cerr << "'" << endl;
		throw ParseError();
	}
}


int main(){
	int N;
	cin >> N;
	cin.ignore();
	vector<int> a(N);
	a[0] = 3;
	a[1] = 5;
	for (int i = 0; i < N; i++) {
		string s;
		getline(cin, s);
		State begin = s.begin();
		int ans = expression(begin);
		State end = s.end();
		consume(begin,end);
		cout << ans << endl;
	}
	return 0;
}
