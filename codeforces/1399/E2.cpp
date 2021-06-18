#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct edge{
    int c, v;
    ll w;
    edge(int ci, int vi, ll wi) : c(ci), v(vi), w(wi) {}
};

void go(int u, int p, vector<vector<edge>> &adjacency, vector<int> &count, vector<set<vector<ll>>> &active,  ll &total, int &key) {
    for(auto jump : adjacency[u]) {
        if(jump.v==p) {
            continue;
        }
        go(jump.v, u, adjacency, count, active, total, key);
        ll impact=((jump.w+1)/2)*count[jump.v];
        active[jump.c].insert({impact, jump.w, count[jump.v], key});
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
        int u, v, c;
        ll w;
        cin>>u>>v>>w>>c;
        u--, v--, c--;
        edge add(c, v, w);
        adjacency[u].push_back(add);
        add.v=u;
        adjacency[v].push_back(add);
    }
    vector<int> count(n);
    vector<set<vector<ll>>> active(2);
    ll total=0;
    int key=0;
    go(0, -1, adjacency, count, active, total, key);
    vector<vector<ll>> moves={{0}, {0}};
    for(int cost=0; cost<2; cost++) {
        ll last=0;
        while(!active[cost].empty()) {
            auto best=*active[cost].rbegin(); 
            active[cost].erase(best);
            moves[cost].push_back(best[0]+last);
            last=moves[cost].back();
            best[1]/=2;
            best[0]=((best[1]+1)/2)*best[2];
            if(best[0]) {
                active[cost].insert(best);
            }
        }
    }
    int i=(int)moves[0].size()-1, j=0, ans=1e9;
    total-=s;
    while(i>=0) {
        while(j<(int)moves[1].size() && moves[0][i]+moves[1][j]<total) {
            j++;
        }
        if(j<(int)moves[1].size() && moves[0][i]+moves[1][j]>=total) {
            ans=min(ans, i+2*j);
        }
        i--;
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

