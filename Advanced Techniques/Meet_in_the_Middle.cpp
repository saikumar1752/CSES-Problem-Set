#include <iostream>
#include <string>
#include <algorithm>
#include <set>
#include <unordered_map>
#include <queue>
#include <chrono>
#include <functional>
#include <map>
#include <climits>
#include <cstring>
#include <vector>
#define int long long
 
using namespace std;
#define int long long
 
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
 
    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
 
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, b;
    cin>>n>>b;
    vector<int> arr(n);
    for(auto &x : arr){
        cin>>x;
    }
    vector<int> arr1, arr2;
    for(int i=0;i<n/2;i++){
        arr1.push_back(arr[i]);
    }
    for(int i=n/2;i<n;i++){
        arr2.push_back(arr[i]);
    }
   int n1=n/2;
   int n2=n-n1;
   unordered_map<int, int, custom_hash> mp1, mp2;
    for (int i = 0; i < (1<<n1); i++) {
        int x = 0, y = 0, st = i;
        while(st > 0) {
            if (st&1) x += arr1[y];
            y++; st>>=1;
        }
        mp1[x]++;
    }
    int ans=0;
    for (int i = 0; i < (1<<n2); i++) {
        int x = 0, y = 0, st = i;
        while(st > 0) {
            if (st&1) x+= arr2[y];
            y++; st>>=1;
        }
        if(mp1.count(b-x))ans+=mp1[b-x];
    }
    cout<<ans<<endl;
 
}