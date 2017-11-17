const int MAX_N = 1e5 * 2;
ll ifact[MAX_N];
ll fact[MAX_N];

ll comb(int n, int k){
  return fact[n] * ifact[k] % MOD * ifact[n-k] % MOD;
}
ll mod_pow(ll n, ll x){
  ll res = 1;
  while(n > 0){
    if(n & 1) res = res * x % MOD;
    x = x * x % MOD;
    n >>= 1;
  }
  return res;
}

void inv_fact(int M){
  fact[0] = ifact[0] = 1;
  for(int i = 1; i <= M; i++){
    fact[i] = fact[i-1] * i % MOD;
  }
  ifact[M] = mod_pow(MOD - 2, fact[M]);
  for(int i = M - 1; i >= 1; i--){
    ifact[i] = ifact[i + 1] * (i + 1) % MOD;
  }
}
