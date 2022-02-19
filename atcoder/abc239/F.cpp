#include "bits/stdc++.h"
using namespace std;
using ll = long long;

int find_set(int v, vector<int> &parent) {
	if(parent[v]!=v) {
		parent[v]=find_set(parent[v], parent);
	}
    return parent[v];
}

void union_sets(int a, int b, vector<int> &parent, vector<int> &size) {
    a = find_set(a, parent);
    b = find_set(b, parent);
    if (a != b) {
        if (size[a] < size[b])
            swap(a, b);
        parent[b] = a;
        size[a] += size[b];
    }
	return;
}

void solve() {
    int n, m;
    cin>>n>>m;
    vector<int> d(n), parent(n), size(n, 1); 
    for(int i=0; i<n; i++) {
        cin>>d[i];
        parent[i]=i;
    }
    int build=n-1-m;
    while(m--) {
        int a, b;
        cin>>a>>b;
        a--, b--;
        union_sets(a, b, parent, size);
        d[a]--;
        d[b]--;
    }
    vector<vector<int>> orders(n);
    int want=0;
    for(int i=0; i<n; i++) {
        want+=d[i];
        if(d[i]<0 || want>2*build) {
            cout<< -1<<endl;
            return;
        }
        int p=find_set(i, parent);
        while(d[i]--) {
            orders[p].push_back(i);
        }
    }
    if(want!=2*build) {
        cout<< -1<<endl;
        return;
    }
    for(auto &i : orders) {
        i.push_back((int)i.size());
        reverse(i.begin(), i.end());
    }
    sort(orders.rbegin(), orders.rend());
    for(auto &i : orders) {
        reverse(i.begin(), i.end());
        i.pop_back();
    }
    vector<int> left=orders[0];
    vector<vector<int>> ans;
    for(int i=1; i<n && !orders[i].empty() && !left.empty(); i++) {
        ans.push_back({left.back(), orders[i].back()});
        left.pop_back();
        orders[i].pop_back();
        while(!orders[i].empty()) {
            left.push_back(orders[i].back());
            orders[i].pop_back();
        }
        union_sets(ans.back().front(), ans.back().back(), parent, size);
    }
    int count=0;
    for(int i=0; i<n; i++) {
        count+=parent[i]==i;
    }
    if(count!=1) {
        cout<< -1<<endl;
        return;
    }
    for(auto &i : ans) {
        for(auto &j : i) {
            cout<<j+1<<" ";
        }
        cout<<endl;
    }
    return;
}

int main() {
#ifdef bipinpathak
    (void)!freopen("input.txt", "r", stdin);
    (void)!freopen("output.txt", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    //cin>>t;
    for(int i=0; i<t; i++) {
        //cout<<"Case #"<<i+1<<": ";
        solve();
    }
    return 0;
}

