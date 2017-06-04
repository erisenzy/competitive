#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#define REP(i,n) for (int i=0;i<(n);i++)
#define FOR(i,a,b) for (int i=(a);i<(b);i++)
#define ll long long

using namespace std;

//元の値を容易に参照できる圧縮
//関数ではなくmain内で使う
//重複を許し、同値は同index
void compressAndRestoration(vector<int>& x, vector<int>& y){
    int N = x.size();
    map<int, int> mpx, mpy;
    map<int, int> rmpx, rmpy;//元の座標を呼び出す用
    
    REP(i, N) {
        mpx[x[i]] = 0;
        mpy[y[i]] = 0;
    }

    int numx = 0;
    for (auto p : mpx) {
        mpx[p.first] = numx;
        rmpx[numx] = p.first;
        numx++;
    }

    int numy = 0;
    for (auto p : mpy) {
        mpy[p.first] = numy;
        rmpy[numy] = p.first;
        numy++;
    }

    vector<int> X(N), Y(N);//圧縮された座標
    REP(i, N) {
        X[i] = mpx[x[i]];
        Y[i] = mpy[y[i]];
    }
}


//蟻本の座圧
//境界をはっきりさせたい時に有効
int compress(vector<int>& x1,vector<int>& x2,int w){
	vector<int> xs;
    int n = x1.size();
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

//重複を許し、同じindexで保持する圧縮
//O(2*10^5)程度でTLE。恐らくeraseかuniqueが悪さをしている
//O(10^3)程度なら大丈夫
//空間計算量に余裕があるなら↓↓の方がよい
void comp_uniq(vector<int> &a){
    int n = a.size();
    vector<ll> b(a.begin(),a.end());
    sort(b.begin(),b.end());
    b.erase(unique(b.begin(),b.end()), b.end());
    //0-indexed
    REP(i,n){
        a[i] = find(b.begin(),b.end(),a[i]) - b.begin();
    }
}

//重複を許し、同じindexで保持する圧縮
void comp(vector<int> &a){
    int n = a.size();
    vector<pair<ll,ll> > b(n);
    REP(i,n)b[i] = make_pair(a[i],i);
    sort(b.begin(),b.end());
    ll tmp = b[0].first;
    int ct = 0;//最小座標
    for(int i = 0;i < n+1;i++){
        if(tmp != b[i].first){
            tmp = b[i].first;
            ct++;
        }//重複を許し、別のindexで保持するときは消して毎回ct++
        a[b[i].second] = ct;
    }
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    vector<int> a = {5,10,8,2,1,10};
    for(auto b:a)cout << b << endl;
    comp_uniq(a);
    for(auto b:a)cout << b << endl;
    return 0;
}
