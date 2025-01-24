#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <functional>
#include <algorithm>
#include <climits>
#include <map>
 
#define int long long
 
using namespace std;
int arr[200005];
int seg[1000000];
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    function<void(int, int, int)> construct=[&](int i, int l, int r){
        if(l==r){
            seg[i]=1;
            return;
        }
        int mid=(l+r)/2;
        construct(2*i, l, mid);
        construct(2*i+1, mid+1, r);
        seg[i]=seg[2*i]+seg[2*i+1];
    };
    construct(1, 0, n-1);
    function<int(int, int, int, int, int)> get=[&](int v, int tl, int tr, int l, int r){
        if (l > r) 
            return 0ll;
        if (l == tl && r == tr) {
            return seg[v];
        }
        int tm = (tl + tr) / 2;
        return get(v*2, tl, tm, l, min(r, tm))
               + get(v*2+1, tm+1, tr, max(l, tm+1), r);
    };
    function<void(int, int, int, int)> update=[&](int i, int l, int r, int pos){
        if(l==r){
            seg[i]=0;
            return;
        }
        int mid=(l+r)/2;
        if(pos<=mid){
            update(2*i, l, mid, pos);
        }
        else{
            update(2*i+1, mid+1, r, pos);
        }
        seg[i]=seg[2*i]+seg[2*i+1];
    };
    function<int(int, int, int, int)> find_kth=[&](int v, int tl, int tr, int k) {
        if (k > seg[v])
            return -1ll;
        if (tl == tr)
            return tl;
        int tm = (tl + tr) / 2;
        if (seg[v*2] >= k)
            return find_kth(v*2, tl, tm, k);
        else 
            return find_kth(v*2+1, tm+1, tr, k - seg[v*2]);
    };
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        int ans=find_kth(1, 0, n-1, x);
        cout<<arr[ans]<<" ";
        update(1, 0, n-1, ans);
    }
    cout<<endl;
}