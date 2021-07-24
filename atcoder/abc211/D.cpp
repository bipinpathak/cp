#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll mod=1e9+7;

void solve() {
    int n, m;
    cin>>n>>m;
    vector<vector<int>> adjacency(n);
    while(m--) {
        int a, b;
        cin>>a>>b;
        a--, b--;
        adjacency[a].push_back(b);
        adjacency[b].push_back(a);
    }
    vector<ll> count(n);
    vector<int> done(n), dist(n, n);
    queue<int> active;
    active.push(0);
    done[0]=1;
    count[0]=1;
    dist[0]=0;
    int temp=1;
    while(!active.empty()) {
        n=(int)active.size();
        while(n--) {
            int u=active.front();
            active.pop();
            for(auto v : adjacency[u]) {
                if(dist[v]<=dist[u]) {
                    continue;
                }
                dist[v]=temp;
                count[v]=(count[u]+count[v])%mod;
                if(done[v]==0) {
                    active.push(v);
                    done[v]=1;
                }
            }
        }
        temp++;
    }
    cout<<count.back()<<endl;
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

