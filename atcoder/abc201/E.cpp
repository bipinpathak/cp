#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll ans=0, p=1e9+7;

struct edge{
    int v;
    ll w;
    edge(int vi, ll wi) : v(vi), w(wi) {}
};

void handle(ll &w, int &count, vector<int> &one) {
    for(int i=0; i<60; i++) {
        if(w&((ll)1<<i)) {
            one[i]=count-one[i];
        }
    }
    return;
}   

void go(int parent, int u, int &count, vector<vector<edge>> &adjacency, vector<int> &one) {
    ll curr=1;
    for(int i=0; i<60; i++) {
        if(one[i]) {
            ans=(ans+one[i]*curr)%p;
        }
        curr=(curr*2)%p;
    }
    count++;
    for(auto v : adjacency[u]) {
        if(v.v==parent) {
            continue;
        }
        handle(v.w, count, one);
        go(u, v.v, count, adjacency, one);
        handle(v.w, count, one);
    }
    return;
}

void solve() {
    int n;
    cin>>n;
    vector<vector<edge>> adjacency(n);
    for(int i=1; i<n; i++) {
        int u, v;
        ll w;
        cin>>u>>v>>w;
        u--, v--;
        edge add(v, w);
        adjacency[u].push_back(add);
        add.v=u;
        adjacency[v].push_back(add);
    }
    vector<int> one(60);
    int count=0;
    go(-1, 0, count, adjacency, one);
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
    auto start=clock();
    int t = 1;
    //cin>>t;
    for(int i=0; i<t; i++) {
        //cout<<"Case #"<<i+1<<": ";
        solve();
    }
    double used= (double) (clock()-start);
    used=(used*1000)/CLOCKS_PER_SEC;
    cerr<<fixed<<setprecision(2)<<used<<" ms"<<endl;
    return 0;
}

