#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
 
int main(){
	string s;
	cin>>s;
	int ans=0;
	int n=s.length();
	for(int i=0;i<n;i++){
		int j=i;
		while(j+1<n and s[j+1]==s[i]){
			j++;
		}
		ans=max(ans, j-i+1);
		i=j;
	}
	cout<<ans<<endl;
 
}
