#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#define int long long
 
using namespace std;
 
signed main(){
    int n, q;
    cin>>n>>q;
    vector<vector<int>> store(n+10, vector<int>(n+10));
    vector<vector<int>> arr(n+10, vector<int>(n+10));
    function<int(int, int)> sum=[&](int x, int y){
        int ret=0;
        for (int i = x; i >= 0; i = (i & (i + 1)) - 1)
            for (int j = y; j >= 0; j = (j & (j + 1)) - 1)
                ret += arr[i][j];
        return ret;
    };
    function<void(int, int, int)> add=[&](int x, int y, int delta){
        for (int i = x; i < n; i = i | (i + 1))
            for (int j = y; j < n; j = j | (j + 1))
                arr[i][j] += delta;
    };
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            char c;
            cin>>c;
            if(c=='*'){
                add(i, j, 1);
                store[i][j]=1;
            }
        }
    }
    while(q--){
        int type;
        cin>>type;
        if(type==1){
            int y, x;
            cin>>x>>y;
            y--;
            x--;
            if(store[x][y]==1){
                store[x][y]=0;
                add(x, y, -1);
            }
            else{
                store[x][y]=1;
                add(x, y, 1);
            }
        }
        else{
            int y1, x1, y2, x2;
            cin>>x1>>y1>>x2>>y2;
            y1--;
            x1--;
            y2--;
            x2--;
            int ans=sum(x2, y2);
            if(x1-1>=0){
                ans-=sum(x1-1, y2);
            }
            if(y1-1>=0){
                ans-=sum(x2, y1-1);
            }
            if(x1-1>=0 and y1>=0){
                ans+=sum(x1-1, y1-1);
            }
            cout<<ans<<"\n";
        }
    }
}