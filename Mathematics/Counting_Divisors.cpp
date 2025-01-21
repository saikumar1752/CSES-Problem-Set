#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
#include <set>
#include <map>
 
#define int long long 
 
using namespace std;
int primes[1000001];
signed main(){
	for(int i=2;i<=1000000;i++){
		primes[i]=i;
	}
	for(int i=2;i*i<=1000000;i++){
		if(primes[i]==i){
			for(int j=2*i;j<=1000000;j+=i){
				primes[j]=min(primes[j], i);
			}
		}
	}
	int n;
	cin>>n;
	while(n--){
		int x;
		cin>>x;
		int ans=1;
		if(primes[x]==x){
			cout<<2<<endl;
			continue;
		}
		while(x>1){
			int g=primes[x];
			int cnt=0;
			while(x%g==0){
				cnt++;
				x/=g;
			}
			ans=ans*(cnt+1);
		}
		cout<<ans<<endl;
	}
}
