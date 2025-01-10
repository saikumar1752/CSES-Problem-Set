#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
#include <set>
#include <map>
 
#define int long long 
 
using namespace std;
int mod=1000000007;
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
	int n;
	cin>>n;
	while(n--){
		int a, b;
		cin>>a>>b;
		cout<<binpow(a, b, mod)<<endl;
	}
 
}