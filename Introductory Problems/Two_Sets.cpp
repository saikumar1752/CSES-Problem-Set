#include <iostream>
#include <vector>
#include <algorithm>
#define int long long
using namespace std;
 
signed main(){
	int n;
	cin>>n;
	int total=(n*(n+1))/2;
	if (total&1){
        cout<<"NO"<<endl;
    }
    else{
        cout<<"YES"<<endl;
        vector<int> arr1, arr2;
        total/=2;
        while(n){
            if(total-n>=0){
                arr1.push_back(n);
                total-=n;
            }
            else{
                arr2.push_back(n);
            }
            n--;
        }
        cout<<arr1.size()<<endl;
        for (int ele : arr1){
            cout<<ele<<" ";
        }
        cout<<endl;
        cout<<arr2.size()<<endl;
        for(int ele : arr2){
            cout<<ele<<" ";
        }
    }
}
