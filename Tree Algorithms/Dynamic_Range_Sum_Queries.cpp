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
    t[i]=t[2*i]+t[2*i+1];
}
void update(int v, int tl, int tr, int pos, int new_val){
    if (tl == tr) {
        t[v] = new_val;
    } else {
        int tm = (tl + tr) / 2;
        if (pos <= tm)
            update(v*2, tl, tm, pos, new_val);
        else
            update(v*2+1, tm+1, tr, pos, new_val);
        t[v] = t[v*2] + t[v*2+1];
    }
}
int sum(int v, int tl, int tr, int l, int r){
    if (l > r) 
        return 0;
    if (l == tl && r == tr) {
        return t[v];
    }
    int tm = (tl + tr) / 2;
    return sum(v*2, tl, tm, l, min(r, tm))
           + sum(v*2+1, tm+1, tr, max(l, tm+1), r);
}
 
signed main(){
    cin>>n>>q;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    build(1, 0, n-1);
    while(q--){
        int type;
        cin>>type;
        if(type==1){
            int k, u;
            cin>>k>>u;
            k--;
            update(1, 0, n-1, k, u);
        }
        else{
            int a, b;
            cin>>a>>b;
            a--;
            b--;
            cout<<sum(1, 0, n-1, a, b)<<endl;
        }
    }
 
}
