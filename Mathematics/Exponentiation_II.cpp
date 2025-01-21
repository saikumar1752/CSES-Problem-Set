#include <iostream>
#include <string>
#include <algorithm>
#include <set>
#include <unordered_map>
#include <bitset>
#include <queue>
#include <functional>
#include <map>
#include <climits>
#include <cstring>
#include <numeric>
#include <vector>
#define int long long
 
using namespace std;
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
signed main(){
    int t;
    cin>>t;
    while(t--){
        int a, b, c;
        cin>>a>>b>>c;
        int y=binpow(b, c, mod-1);
        cout<<binpow(a, y, mod)<<endl;
    }
}
