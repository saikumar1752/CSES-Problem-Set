#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#define int long long
 
using namespace std;
 
signed main(){
    int n, q;
    cin>>n>>q;
    vector<int> arr(n);
    for(auto &item : arr){
        cin>>item;
    }
    vector<int> prefix={0};
    for(auto item : arr){
        prefix.push_back(prefix.back()+item);
    }
    while(q--){
        int l, r;
        cin>>l>>r;
 
        cout<<prefix[r]-prefix[l-1]<<endl;
    }
 
}
