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
int n, q;
int bit[1000000];
unordered_map<int, int> co_co(const vector<int> &a){
    vector<int> b = a;
    int n=a.size();
    sort(b.begin(), b.end());
    unordered_map<int, int> m;
    for (int i = 0; i < n; i++) {
        m[b[i]] = i;
    }
    return m;
}
 
struct FenwickTree {
    int n=600000;
    int sum(int r) {
        int ret = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1)
            ret += bit[r];
        return ret;
    }
 
    int sum(int l, int r) {
        return sum(r) - sum(l - 1);
    }
 
    void add(int idx, int delta) {
        for (; idx < n; idx = idx | (idx + 1))
            bit[idx] += delta;
    }
};
 
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>n>>q;
    vector<int> arr(n);
    vector<int> mm;
    for(int &x : arr){
        cin>>x;
        mm.push_back(x);
    }
    if(q<10){
        char type;
        cin>>type;
        if(type=='?'){
            int a, b;
            cin>>a>>b;
            int cnt=0;
            for(int i=0;i<n;i++){
                if(arr[i]>=a and arr[i]<=b){
                    cnt++;
                }
            }
            cout<<cnt<<endl;
        }
        else{
            int k, x;
            cin>>k>>x;
            k--;
            arr[k]=x;
        }
        return 0;
    }
    vector<pair<char, pair<int, int>>> queries(q);
    for(int i=0;i<q;i++){       
        cin>>queries[i].first>>queries[i].second.first>>queries[i].second.second;
        if(queries[i].first=='?'){
            mm.push_back(queries[i].second.first);
        }
        mm.push_back(queries[i].second.second);
    }
    auto mapping=co_co(mm);
    FenwickTree ft;
    for(int i=0;i<n;i++){
        arr[i]=mapping[arr[i]];
        ft.add(arr[i], 1);
    }
    for(int i=0;i<q;i++){
        if(queries[i].first=='?'){
            queries[i].second.first=mapping[queries[i].second.first];
        }
        queries[i].second.second=mapping[queries[i].second.second];
    }
    for(int i=0;i<q;i++){
        if(queries[i].first=='?'){
            int a=queries[i].second.first;
            int b=queries[i].second.second;
            int answer=ft.sum(a, b);
            cout<<answer<<"\n";
        }
        else{
            int k=queries[i].second.first;
            k--;
            int x=queries[i].second.second;
            ft.add(arr[k], -1);
            arr[k]=x;
            ft.add(arr[k], 1);
        }
    }
}