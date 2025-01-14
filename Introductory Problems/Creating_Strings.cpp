#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
#include <climits>
#include <string>
#include <set>
#define int long long
 
using namespace std;
 
signed main(){
	string s;
	cin>>s;
	sort(s.begin(),s.end());
	set<string> ss;
	do{
		ss.insert(s);
	}while(next_permutation(s.begin(), s.end()));
	cout<<ss.size()<<endl;
	for(auto x : ss){
		cout<<x<<endl;
	}
}
