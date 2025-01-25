#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <map>
 
#define int long long 
 
using namespace std;
 
signed main(){
	int n, x;
	cin>>n>>x;
	map<int, vector<int>> mp;
	for(int i=1;i<=n;i++){
		int a;
		cin>>a;
		mp[a].push_back(i);
	}
	for(auto &y : mp){
		if(mp.find(abs(y.first-x))!=mp.end() and abs(y.first-x)+y.first==x){
			if(abs(y.first-x)==y.first){
				if(y.second.size()>1){
					cout<<y.second[0]<<" "<<y.second[1]<<endl;
					return 0;
				}
			}
			else{
				cout<<y.second[0]<<" "<<mp[abs(y.first-x)][0]<<endl;
				return 0;
			}
		}
	}
	cout<<"IMPOSSIBLE"<<endl;
}
