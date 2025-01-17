#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#define int long long
 
using namespace std;
int n, q;
int arr[1000000];
int t[1000000];
 
void build(int i, int l, int r){
    if(l==r){
        t[i]=arr[l];
        return;
    }
    int mid=(l+r)/2;
    build(2*i, l, mid);
    build(2*i+1, mid+1, r);
    t[i]=min(t[2*i], t[2*i+1]);
}
int mini(int i, int l, int r, int ql, int qr){
    if(l>r || l>qr || r<ql)return LONG_MAX;
    if(l>=ql and r<=qr)return t[i];
    int mid=(l+r)/2;
    return min(mini(2*i, l, mid, ql, qr), mini(2*i+1, mid+1, r, ql, qr));
}
 
signed main(){
    cin>>n>>q;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    build(1, 0, n-1);
    while(q--){
        int l, r;
        cin>>l>>r;
        l--;
        r--;
        cout<<mini(1, 0, n-1, l, r)<<endl;
    }
 
}