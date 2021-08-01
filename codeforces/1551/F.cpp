#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll mod=1e9+7;

struct edge{
    int u, v;
};

ll go(int root, vector<vector<int>> &adjacency, int k) {
    ll ans=0;
    queue<vector<edge>> active;
    edge add;
    add.u=root;
    for(auto v : adjacency[root]) {
        add.v=v;
        active.push({add});
    }
    while((int)active.size()>=k) {
        vector<ll> dp(k+1);
        dp[0]=1;
        int n=(int)active.size();
        while(n--) {
            auto leg=active.front();
            vector<edge> build;
            active.pop();
            int options=(int)leg.size();
            for(int i=k; i; i--) {
                dp[i]=(dp[i]+dp[i-1]*options)%mod;
            }
            for(auto i : leg) {
                int p=i.u, u=i.v;
                add.u=u;
                for(auto v : adjacency[u]) {
                    if(v==p) {
                        continue;
                    }
                    add.v=v;
                    build.push_back(add);
                }
            }
            if(!build.empty()) {
                active.push(build);
            }
        }
        ans=(ans+dp[k])%mod;
    }
    return ans;
}

void solve() {
    cin.ignore();
    int n, k;
    cin>>n>>k;
    vector<vector<int>> adjacency(n);
    for(int i=0; i<n-1; i++) {
        int u, v;
        cin>>u>>v;
        u--, v--;
        adjacency[u].push_back(v);
        adjacency[v].push_back(u);
    }   
    ll ans=0;
    if(k==2) {
        ans=(n*(n-1))/2;
    } else for(int i=0; i<n; i++) {
        ans=(ans+go(i, adjacency, k))%mod; 
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

