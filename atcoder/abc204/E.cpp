#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct road{
    ll c, d, v;
    road(ll ci, ll di, ll vi) : c(ci), d(di), v(vi) {}
};

double cost(ll t, ll c, ll d) {
    return t+c+(double)d/(double)(t+1);
}

ll calc(ll t, ll c, ll d) {
    ll low=t, high=1e18;
    while(high-low>2) {
        ll m1=low+(high-low)/3, m2=high-(high-low)/3;  
        double f1=cost(m1, c, d), f2=cost(m2, c, d);
        if(f1<=f2) {
            high=m2;
        } else {
            low=m1;
        }
    }
    double ans=1e18;
    while(low<high) {
        ans=min(ans, cost(low, c, d));
        low++;
    }
    return (ll)ans;
}

void solve() {
    int n, m;
    cin>>n>>m;
    vector<vector<road>> adjacency(n);
    while(m--) {
        ll a, b, c, d;
        cin>>a>>b>>c>>d;
        a--, b--;
        road add(c, d, b);
        adjacency[a].push_back(add);
        add.v=a;
        adjacency[b].push_back(add);
    }
    vector<ll> dist(n, 1e18);
    set<pair<ll, ll>> active;
    active.insert({0, 0});
    while(!active.empty()) {
        auto y=*active.begin();
        active.erase(active.begin());
        ll t=y.first, u=y.second;
        if(dist[u]<=t) {
            continue;
        }
        dist[u]=t;
        for(auto x: adjacency[u]) {
            ll c=x.c, d=x.d, v=x.v;
            ll offer=calc(t, c, d);
            if(dist[v]>offer) {
                active.insert({offer, v});
            }
        }
    }
    if(dist[n-1]==(ll)1e18) {
        dist[n-1]=-1;
    }
    cout<<dist[n-1]<<endl;
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
