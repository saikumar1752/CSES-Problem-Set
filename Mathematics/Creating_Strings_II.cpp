#include <iostream>
#include <string>
#include <algorithm>
#include <set>
#include <queue>
#include <functional>
#include <map>
#include <climits>
#include <cstring>
#include <vector>
#define int long long
 
using namespace std;
#define int long long
int mod=1e9+7;
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
int fact[2000001];
int nCr(int a, int b){
    return (fact[a]*((binpow(fact[b], mod-2, mod)*binpow(fact[a-b], mod-2, mod))%mod))%mod;
}
signed main(){
    fact[0]=fact[1]=1;
    for(int i=2;i<=2000000;i++){
        fact[i]=(fact[i-1]*i)%mod;
    }
    string s;
    cin>>s;
    map<char, int> mp;
    for(auto x : s){
        mp[x]++;
    }
    int ans=fact[s.length()];
    for(auto x : mp){
        ans=(ans*binpow(fact[x.second], mod-2, mod))%mod;
    }
    cout<<ans<<endl;
}