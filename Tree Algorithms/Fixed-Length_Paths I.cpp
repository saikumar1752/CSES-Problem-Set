#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <queue>
 
#define int long long
 
using namespace std;
 
vector<vector<int>> tree;
int n, k;
int first[200005], second[200005], third[500000];
 
int combine(deque<int> &a, deque<int> &b){
    if(a.size()<b.size())swap(a, b);
    int an=a.size();
    int bn=b.size();
    int res=0;
    for (int i = max(0ll, (k - bn) + 1); i < min(k + 1, an); ++i) {
        res += a[i] * b[k-i];
    }
    for(int i=0;i<bn;i++){
        a[i]+=b[i];
    }
    return res;
}
 
pair<int, deque<int>> solve(int i, int p){
    pair<int, deque<int>> res = {(k == 0), {1}};
    for (int t : tree[i]) {
        if (t == p) continue;
        auto sub = solve(t, i);
        sub.second.push_front(0);
        res.first += sub.first + combine(res.second, sub.second);
    }
    return res;
}
 
signed main(){
    cin>>n>>k;
    tree=vector<vector<int>>(n);
    for(int i=0;i<n-1;i++){
        int a, b;
        cin>>a>>b;
        a--;
        b--;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    auto ans=solve(0, 0);
    cout<<ans.first<<endl;
}