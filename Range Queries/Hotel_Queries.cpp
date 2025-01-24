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
pair<int, int> seg[1000000];
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m;
    cin>>n>>m;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    function<void(int, int, int)> construct=[&](int i, int l, int r){
        if(l==r){
            seg[i]={arr[l], l};
        }
        else{
            int mid=(l+r)/2;
            construct(2*i, l, mid);
            construct(2*i+1, mid+1, r);
            seg[i]=max(seg[2*i], seg[2*i+1]);
        }
 
    };
    construct(1, 0, n-1);
    function<pair<int, int>(int, int, int, int, int)> get=[&](int i, int l, int r, int ql, int qr){
        if(l>r or r<ql or l>qr)return make_pair((int)-1e12,  (int)(-1e12));
        if(l>=ql and r<=qr){
            return seg[i];
        }
        int mid=(l+r)/2;
        return max(get(i*2, l, mid, ql, min(qr, mid)), get(i*2+1, mid+1, r, max(ql, mid+1), qr));
    };
    function<void(int, int, int, int, int)> update=[&](int i, int l, int r, int pos, int val){
        if(l==r){
            seg[i].first+=val;
            return;
        }
        int mid=(l+r)/2;
        if(pos<=mid){
            update(2*i, l, mid, pos, val);
        }
        else{
            update(2*i+1, mid+1, r, pos, val);
        }
        seg[i]=max(seg[2*i], seg[2*i+1]);
    };
    function<pair<int, int>(int)> query=[&](int room){
        int low=0, high=n-1;
        while(low<high){
            int mid=(low+high)/2;
            auto xx=get(1, 0, n-1, low, mid);
            if(xx.first>=room){
                high=mid;
            }
            else{
                low=mid+1;
            }
        }
        return get(1, 0, n-1, low, high);
    };
    while(m--){
        int room;
        cin>>room;
        if(seg[1].first<room){
            cout<<0<<" ";
        } 
        else{
            auto g=query(room);
            cout<<g.second+1<<" ";
            update(1, 0, n-1, g.second, -room);
        }
    }
    cout<<endl;
}