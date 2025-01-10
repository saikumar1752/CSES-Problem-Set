#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
 
#define int long long 
 
using namespace std;
 
signed main(){
	int n;
	cin>>n;
	set<int> s;
	for(int i=0;i<n;i++){
		int x;
		cin>>x;
		s.insert(x);
	}
	cout<<s.size()<<endl;
}