#include <iostream>
#include <vector>
#include <functional>
 
#define int long long
using namespace std;
void solve(int n){
	cout<<n<<" ";
	if(n==1)return ;
	if(n%2==1){
		solve(3*n+1);
	}
	else{
		solve(n/2);
	}
}
 
signed main(){
	int n;
	cin>>n;
	solve(n);
	cout<<endl;
}