#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
 
int main(){
	int n;
	cin>>n;
	set<int> s;
	for(int i=0;i<n-1;i++){
		int x;
		cin>>x;
		s.insert(x);
	}
	for(int i=1;i<=n;i++){
		if(!s.count(i)){
			cout<<i<<endl;
			return 0;
		}
	}
}