#include <iostream>
 
#define int long long 
using namespace std;
 
int binpow(int a, int m, int mod){
	if(m==0)return 1ll;
	if(m==1)return a;
	int mid=binpow(a, m/2, mod);
	mid=(mid*mid)%mod;
	if(m%2)mid=(mid*a)%mod;
	return mid;
}
 
signed main(){
	int n;
	cin>>n;
	cout<<binpow(2, n, 1000000007)<<endl;
}
