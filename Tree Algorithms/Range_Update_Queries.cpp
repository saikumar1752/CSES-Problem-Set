#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#define int long long
 
using namespace std;
int n, q;
int arr[1000000];
int t[1000000];
int lazy[1000000];
 void build(int v, int tl, int tr) {
    if (tl == tr) {
        t[v] = arr[tl];
    } else {
        int tm = (tl + tr) / 2;
        build(v*2, tl, tm);
        build(v*2+1, tm+1, tr);
        t[v] = 0;
    }
}
 
void update(int v, int tl, int tr, int l, int r, int add) {
    if (l > r)
        return;
    if (l == tl && r == tr) {
        t[v] += add;
    } else {
        int tm = (tl + tr) / 2;
        update(v*2, tl, tm, l, min(r, tm), add);
        update(v*2+1, tm+1, tr, max(l, tm+1), r, add);
    }
}
 
int get(int v, int tl, int tr, int pos) {
    if (tl == tr)
        return t[v];
    int tm = (tl + tr) / 2;
    if (pos <= tm)
        return t[v] + get(v*2, tl, tm, pos);
    else
        return t[v] + get(v*2+1, tm+1, tr, pos);
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
            int a, b, u;
            cin>>a>>b>>u;
            a--;
            b--;
            update(1, 0, n-1, a, b, u);
        }
        else{
            int k;
            cin>>k;
            k--;
            cout<<get(1, 0, n-1, k)<<endl;
        }
    }
}
