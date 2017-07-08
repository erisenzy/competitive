#include <bits/stdc++.h>

#define REP(i,n) for(int i = 0;i < (n);i++)
const int INF = 1e+9;
using namespace std;

int N, K, S;

struct Point{
    int x, y, z;
};

Point p[2103];

bool used[2103];
vector<int> graph[2003];

int getS(int u, int v){
    Point a = p[u], b = p[v];
    if(a.x > b.x) swap(a.x, b.x);
    if(a.y > b.y) swap(a.y, b.y);
    if(a.z > b.z) swap(a.z, b.z);
    return (a.x + S - b.x) * (a.y + S - b.y) * 2
        +  (a.z + S - b.z) * (a.x + S - b.x) * 2
        +  (a.y + S - b.y) * (a.z + S - b.z) * 2;
}

bool connected(int a,int b){
    return (abs(p[a].x-p[b].x) <= S) && (abs(p[a].y-p[b].y) <= S) && (abs(p[a].z-p[b].z) <= S);
}

int main(){
    while(cin >> N >> K >> S, N){
        REP(i,N){
            int x, y, z;
            cin >> x >> y >> z;
            p[i] = Point{x, y, z};
            graph[i].clear();
        }

        if(K == 1){
            cout << S*S*6 << endl;
            continue;
        }

        REP(i,N){
            for(int j = i + 1;j < N;j++){
                if(connected(i, j)){
                    graph[i].push_back(j);
                    graph[j].push_back(i);
                }
            }     
        }
        
        int ans = INF;
        REP(firstv,N){
            for(int secondv : graph[firstv]){
                int res = S*S*6*K - getS(firstv, secondv);
                int endindex = -1;
                queue<int> que;
                que.push(secondv);
                fill_n(used, N, false);
                used[firstv] = true;
                used[secondv] = true;
                int ct = 2;
                while(!que.empty()){
                    if(ct == K) break;
                    int u = que.front();
                    que.pop();
                    for(int v : graph[u]){
                        if(used[v]) continue;
                        used[v] = true;
                        que.push(v);
                        endindex = v;
                        ct++;
                        res -= getS(u, v);
                        break;
                    }
                }
                if(connected(firstv,endindex) && K >= 3){
                    res -= getS(firstv, endindex);
                }
                if(ct == K) ans = min(res, ans);
            }
        }
        if(ans == INF) cout << -1 << endl;
        else cout << ans << endl;
    }
    return 0;
}
