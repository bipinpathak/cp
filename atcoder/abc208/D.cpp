#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n, m;
    cin>>n>>m;
    vector<vector<int>> dist(n, vector<int> (n, 1e9));
    while(m--) {
        int a, b, c;
        cin>>a>>b>>c;
        a--, b--;
        dist[a][b]=c;
    }
    for(int i=0; i<n; i++) {
        dist[i][i]=0;
    }
    ll ans=0;
    for(int add=0; add<n; add++) {
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                dist[i][j]=min(dist[i][j], dist[i][add]+dist[add][j]);
                if(dist[i][j]<1e9) {
                    ans+=dist[i][j];
                }
            }
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

