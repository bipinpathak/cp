#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll go(vector<vector<ll>> &cost, vector<vector<ll>> &dist, int x, int y, ll w) {
    ll ans=1e18;
    int n=(int)cost.size(), m=(int)cost[0].size();
    queue<vector<ll>> active;
    dist[x][y]=0;
    active.push({0, x, y});
    while(!active.empty()) {
        auto curr = active.front();
        active.pop();
        ll d=curr[0];
        x=curr[1], y=curr[2];
        if(cost[x][y]>0) {
            ans=min(ans, dist[x][y]+cost[x][y]);
        }   
        if(dist[x][y]<d) {
            continue;
        }
        d+=w;
        if(x+1<n && cost[x+1][y]!=-1 && d<dist[x+1][y]) {
            dist[x+1][y]=d;
            active.push({d, x+1, y});
        }
        if(x-1>=0 && cost[x-1][y]!=-1 && d<dist[x-1][y]) {
            dist[x-1][y]=d;
            active.push({d, x-1, y});
        }
        if(y+1<m && cost[x][y+1]!=-1 && d<dist[x][y+1]) {
            dist[x][y+1]=d;
            active.push({d, x, y+1});
        }
        if(y-1>=0 && cost[x][y-1]!=-1 && d<dist[x][y-1]) {
            dist[x][y-1]=d;
            active.push({d, x, y-1});
        }
        
    }
    return ans;
}

void solve() {
    int n, m;
    ll w;
    cin>>n>>m>>w;
    vector<vector<ll>> a(n, vector<ll> (m, 1e18)), u, v;
    v=u=a;
    for(auto &i : a) {
        for(auto &j : i) {
            cin>>j;
        }
    }
    ll ans=min(u[n-1][m-1], go(a, u, 0, 0, w)+go(a, v, n-1, m-1, w));
    if(ans>=1e18) {
        ans=-1;
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
    for(int i=0; i<t; i++) {
        //cout<<"Case #"<<i+1<<": ";
        solve();
    }
    double used= (double) (clock()-start);
    used=(used*1000)/CLOCKS_PER_SEC;
    cerr<<fixed<<setprecision(2)<<used<<" ms"<<endl;
    return 0;
}

