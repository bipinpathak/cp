#include "bits/stdc++.h"
using namespace std;
using ll = long long;

void go(int p, int u, vector<vector<int>> &adjacnecy, vector<ll> &s) {
    ll high=1e9+1;
    for(auto v : adjacnecy[u]) {
        go(u, v, adjacnecy, s);
        if(s[u]==-1) {
            high=min(high, s[v]);
        }
    }
    if(s[u]==-1) {
        if(high==1e9+1) {
            high=s[p];
        }
        s[u]=high;
    }
    return;
}   

void build(int p, int u, vector<vector<int>> &adjacnecy, vector<ll> &s) {
    for(auto v : adjacnecy[u]) {
        build(u, v, adjacnecy, s);
    }
    if(p!=-1) {
        s[u]-=s[p];
    }
    return;
}

void solve() {
    int n;
    cin>>n;
    vector<vector<int>> adjacnecy(n);
    for(int i=1; i<n; i++) {
        int p;
        cin>>p;
        adjacnecy[--p].push_back(i);
    }   
    vector<ll> s(n);
    for(auto &i : s) {
        cin>>i;
    }
    go(-1, 0, adjacnecy, s);
    build(-1, 0, adjacnecy, s);
    ll ans=0;
    for(auto i : s) {
        if(i<0) {
            ans=-1;
            break;
        } 
        ans+=i;
    }
    cout<<ans<<endl;
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
    for(int i=0; i<t; i++) {
        //cout<<"Case #"<<i+1<<": ";
        solve();
    }
    return 0;
}

