#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <complex>
#define int long long
 
using namespace std;
vector<pair<int, int>> directions={
    {-1, 0},
    {1, 0},
    {0, -1},
    {0, 1}
};
bool visited[1001][1001];
vector<string> arr;
int n, m;
void dfs(int x, int y){
    visited[x][y]=true;
    for(auto d : directions){
        int new_x=d.first+x;
        int new_y=d.second+y;
        if(new_x>=0 and new_x<n and new_y>=0 and new_y<m and !visited[new_x][new_y] and arr[new_x][new_y]=='.'){
            dfs(new_x, new_y);
        }
    }
}
signed main(){
    cin>>n>>m;
    arr.resize(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int ans=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(!visited[i][j] and arr[i][j]=='.'){
                ans++;
                dfs(i, j);
            }
        }
    }
    cout<<ans<<endl;
