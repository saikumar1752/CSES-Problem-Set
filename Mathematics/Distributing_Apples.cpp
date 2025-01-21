#include <iostream>
using namespace std;
#define int long long
int fact[2000001];
int MOD=1e9+7;
long long binpow(long long a, long long b, long long m) {
    a %= m;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}
signed main(){
    fact[0]=fact[1]=1;
    for(int i=2;i<=2000000;i++){
        fact[i]=(i*fact[i-1])%MOD;
    }
    int n, m;
    cin>>n>>m;
    int ans=fact[n+m-1];
    ans=(ans*binpow(fact[m], MOD-2, MOD))%MOD;
    ans=(ans*binpow(fact[n-1], MOD-2, MOD))%MOD;
    cout<<ans<<endl;
}