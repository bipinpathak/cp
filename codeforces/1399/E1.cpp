#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct edge{
    int v;
    ll w;
    edge(int vi, ll wi) : v(vi), w(wi) {}
};

void go(int u, int p, vector<vector<edge>> &adjacency, vector<int> &count, set<vector<ll>> &active, ll &total, int &key) {
    for(auto jump : adjacency[u]) {
        if(jump.v==p) {
            continue;
        }
        go(jump.v, u, adjacency, count, active, total, key);
        ll impact=((jump.w+1)/2)*count[jump.v];
        active.insert({impact, jump.w, count[jump.v], key});
        key++;
        total+=jump.w*count[jump.v];
        count[u]+=count[jump.v];
    }
    count[u]=max(count[u], 1);
    return;
}

void solve() {
    int n;
    ll s;
    cin>>n>>s;
    vector<vector<edge>> adjacency(n);
    for(int i=0; i<n-1; i++) {
        int u, v;
        ll w;
        cin>>u>>v>>w;
        u--, v--;
        edge add(v, w);
        adjacency[u].push_back(add);
        add.v=u;
        adjacency[v].push_back(add);
    }
    vector<int> count(n);
    set<vector<ll>> active;
    ll total=0;
    int key=0;
    go(0, -1, adjacency, count, active, total, key);
    total-=s;
    int ans=0;
    while(total>0) {
        auto best=*active.rbegin();     
        active.erase(best);
        total-=best[0];
        best[1]/=2;
        best[0]=((best[1]+1)/2)*best[2];
        ans++;
        if(best[0]) {
            active.insert(best);
        }
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
    auto start=clock();
    int t = 1;
    cin>>t;
    for(int i=0; i<t; i++) {
        //cout<<"Case #"<<i+1<<": ";
        solve();
    }
    double used= (double) (clock()-start);
    used=(used*1000)/CLOCKS_PER_SEC;
    cerr<<fixed<<setprecision(2)<<used<<" ms"<<endl;
    return 0;
}

