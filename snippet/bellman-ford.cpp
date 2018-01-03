struct Edge{
  int from, to, cost;
};


const int MAXV = 1002;
const int MAXE = 2002;
Edge edges[MAXE];
bool is_pass[MAXV];
ll d[MAXV];
int V, E;

bool berm(){
  fill(d, d + V, -LL_INF);
  d[0] = 0;
  is_pass[0] = true;
  for(int ct=0;ct<V - 1;ct++){
    for(int i=0;i<E;i++){
      int v = edges[i].to;
      int u = edges[i].from;
      int c = edges[i].cost;
      is_pass[v] |= is_pass[u];
      if(d[u] + c > d[v]){
        d[v] = d[u] + c;
        /*        if(ct == V-1&&is_pass[u]){
          return false;
          }*/
        // ����ĺ��������ã��ǽ�ʹ�����ϩ����
        // ���󥳥��Ȥ������ct < V�Ȥ��뤳��
      }
    }
  }
  vector<ll> pd;
  copy(d, d + V, pd);
  for(int ct=0;ct<V;ct++){
    for(int i=0;i<E;i++){
      int v = edges[i].to;
      int u = edges[i].from;
      int c = edges[i].cost;
      is_pass[v] |= is_pass[u];
      if(d[u] + c > d[v]){
        d[v] = d[u] + c;
        if(ct == V-1&&is_pass[u]){
          return false;
        }
      }
    }
  }
  // ����ĺ��i�ޤǤκ�û��Υ����������Ƥ����������ĺ��i�ޤǤκ�û��Υ��˹�����ϩ��¸�ߤ��Ƥ���
  for(int i = 0; i < V; i++)
    if(pd[i] != d[i]) return false;
  return true;
}
