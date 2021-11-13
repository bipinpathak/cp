#include "bits/stdc++.h"
using namespace std;
using ll = long long;

void go(int p, int u, vector<vector<int>> &adjacency, vector<int> &height) {
    for(auto v : adjacency[u]) {
        if(v!=p) {
            height[v]=1+height[u];
            go(u, v,adjacency, height);
        }
    }
    return;
}   

void solve() {
    int n;
    cin>>n;
    vector<vector<int>> adjacency(n);
    for(int i=0; i<n-1; i++) {
        int u, v;
        cin>>u>>v;
        u--, v--;
        adjacency[u].push_back(v);
        adjacency[v].push_back(u);
    }
    vector<int> height(n);
    go(-1, 0, adjacency, height);
    vector<int> odd, even;
    for(int i=0; i<n; i++) {
        if(height[i]&1) {
            odd.push_back(i);
        } else {
            even.push_back(i);
        }
        height[i]=0;
    }
    if(odd.size()>even.size()) {
        swap(odd, even);
    }
    int target=(int)odd.size(), curr=1;
    for(int i=1; i<=n; i++) {
        if((curr&i)==0) {
            curr<<=1;
        }
        if(target&curr && !odd.empty()) {
            height[odd.back()]=i;
            odd.pop_back();
        } else {
            height[even.back()]=i;
            even.pop_back();
        }
    }
    for(auto i : height) {
        cout<<i<<" ";
    }
    cout<<endl;
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
    cin>>t;
    for(int i=0; i<t; i++) {
        //cout<<"Case #"<<i+1<<": ";
        solve();
    }
    return 0;
}

