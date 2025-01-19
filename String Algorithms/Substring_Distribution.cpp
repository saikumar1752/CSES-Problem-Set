#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
#include <set>
#include <map>
 
#define int long long 
 
using namespace std;
 
vector<int> sort_cyclic_shifts(string const& s) {
    int n = s.size();
    const int alphabet = 256;
    vector<int> p(n), c(n), cnt(max(alphabet, n), 0);
    for (int i = 0; i < n; i++)
        cnt[s[i]]++;
    for (int i = 1; i < alphabet; i++)
        cnt[i] += cnt[i-1];
    for (int i = 0; i < n; i++)
        p[--cnt[s[i]]] = i;
    c[p[0]] = 0;
    int classes = 1;
    for (int i = 1; i < n; i++) {
        if (s[p[i]] != s[p[i-1]])
            classes++;
        c[p[i]] = classes - 1;
    }
        vector<int> pn(n), cn(n);
    for (int h = 0; (1 << h) < n; ++h) {
        for (int i = 0; i < n; i++) {
            pn[i] = p[i] - (1 << h);
            if (pn[i] < 0)
                pn[i] += n;
        }
        fill(cnt.begin(), cnt.begin() + classes, 0);
        for (int i = 0; i < n; i++)
            cnt[c[pn[i]]]++;
        for (int i = 1; i < classes; i++)
            cnt[i] += cnt[i-1];
        for (int i = n-1; i >= 0; i--)
            p[--cnt[c[pn[i]]]] = pn[i];
        cn[p[0]] = 0;
        classes = 1;
        for (int i = 1; i < n; i++) {
            pair<int, int> cur = {c[p[i]], c[(p[i] + (1 << h)) % n]};
            pair<int, int> prev = {c[p[i-1]], c[(p[i-1] + (1 << h)) % n]};
            if (cur != prev)
                ++classes;
            cn[p[i]] = classes - 1;
        }
        c.swap(cn);
    }
    return p;
}
vector<int> suffix_array_construction(string s) {
    s += "$";
    vector<int> sorted_shifts = sort_cyclic_shifts(s);
    sorted_shifts.erase(sorted_shifts.begin());
    return sorted_shifts;
}
 
vector<int> lcp_construction(string const& s, vector<int> const& p) {
    int n = s.size();
    vector<int> rank(n, 0);
    for (int i = 0; i < n; i++)
        rank[p[i]] = i;
 
    int k = 0;
    vector<int> lcp(n-1, 0);
    for (int i = 0; i < n; i++) {
        if (rank[i] == n - 1) {
            k = 0;
            continue;
        }
        int j = p[rank[i] + 1];
        while (i + k < n && j + k < n && s[i+k] == s[j+k])
            k++;
        lcp[rank[i]] = k;
        if (k)
            k--;
    }
    return lcp;
}
 
struct Segment_Tree{
	int n;
	vector<int> t;
	Segment_Tree(vector<int> arr){
		n=arr.size();
		t.resize(4*n);
		build(arr, 1, 0, n-1);
	}
	void build(vector<int> &arr, int v, int tl, int tr) {
	    if (tl == tr) {
	        t[v] = arr[tl];
	    } else {
	        int tm = (tl + tr) / 2;
	        build(arr, v*2, tl, tm);
	        build(arr, v*2+1, tm+1, tr);
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
};
 
signed main(){
	string s;
	cin>>s;
	auto suffix=suffix_array_construction(s);
	auto lcp=lcp_construction(s, suffix);
	Segment_Tree st(vector<int>(suffix.size()+1));
	int ans=s.length()-suffix[0];
	st.update(1, 0, st.n-1, 1, ans, 1);
 
	for(int i=1;i<suffix.size();i++){
		st.update(1, 0, st.n-1, lcp[i-1]+1, (s.length()-suffix[i]), 1);
	}
	for(int i=1;i<=s.length();i++){
		cout<<st.get(1, 0, st.n-1, i)<<" ";
	}
	cout<<endl;
}
