const int MAX_N = 100005;
struct UnionFind{
    int par[MAX_N];
    int rank[MAX_N];
    int N;
    UnionFind() : N(0) {}
    UnionFind(int N){
        Init(N);
    }
    ~UnionFind(){}

    void Init(int N_){
        N = N_;
        REP(i,N){
            par[i] = -1;
            rank[i] = 0;
        }
    }
    int Root(int child){
        if(par[child] < 0) return child;
        else return par[child] = Root(par[child]);
    }
    void Unite(int x, int y){
        x = Root(x);
        y = Root(y);
        if(x == y) return;
        if(rank[x] < rank[y]){
            par[y] += par[x];
            par[x] = y;
        }else{
            par[x] += par[y];
            par[y] = x;
            if(rank[x] == rank[y]) ++ rank[x];
        }
    }
    bool Same(int x, int y){
        return Root(x) == Root(y);
    }
    // その頂点から辿り着ける頂点の数（自身も含む）
    int Size(int x){
        return -par[Root(x)];
    }
};
