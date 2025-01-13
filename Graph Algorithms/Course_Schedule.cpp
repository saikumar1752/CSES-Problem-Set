#include <iostream>
#include <vector>
#include <functional>
#include <queue>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> graph(n + 1);
    vector<int> in_degree(n+1);
    for (int i = 0; i < m; i++)
    {
        int course, pre_requisite_course;
        cin >> course >> pre_requisite_course;
        graph[course].push_back(pre_requisite_course);
        in_degree[pre_requisite_course]++;
    }
    vector<int> topo;
    queue<int> q;
    for(int i=1;i<=n;i++){
        if(in_degree[i]==0){
            q.push(i);
        }
    }
    while(q.size()>0){
        int course = q.front();
        topo.push_back(course);
        q.pop();
        for(auto next_course : graph[course]){
            in_degree[next_course]--;
            if(in_degree[next_course]==0){
                q.push(next_course);
            }
        }
    }
    for(int i=1;i<=n;i++){
        if(in_degree[i]!=0){
            cout<<"IMPOSSIBLE"<<endl;
            return 0;
        }
    }
    for(auto course : topo){
        cout<<course<<" ";
    }
    cout<<endl;
}