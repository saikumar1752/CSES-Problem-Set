#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
 
#define int long long 
 
using namespace std;
 
signed main(){
	int n;
	cin>>n;
	int ans=0;
	while(n>0){
		ans+=n/5;
		n/=5;
	}
	cout<<ans<<endl;
}
