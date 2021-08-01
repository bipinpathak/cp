#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll mod=998244353;

void solve() {
    int n, m, k;
    cin>>n>>m>>k;
    vector<vector<int>> broken(n);
    while(m--) {
        int u, v;
        cin>>u>>v;
        u--, v--;
        broken[u].push_back(v);
        broken[v].push_back(u);
    }
    for(int i=0; i<n; i++) {
        broken[i].push_back(i);
    }
    vector<ll> up(n);
    up[0]=1;
    while(k--) {
        ll sum=0;
        for(auto &i : up) {
            sum=(sum+i)%mod;
        }
        vector<ll> update(n, sum);
        for(int i=0; i<n; i++) {
            for(auto j : broken[i]) {
                update[j]=(update[j]-up[i])%mod;
            }
        }
        up=update;
    }
    if(up[0]<0) {
        up[0]+=mod;
    }
    cout<<up[0]<<endl;
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

