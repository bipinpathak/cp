#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct node{
    int i0=-1, i1=-1, l0=0, l1=0, c=0, ans=-1;
};

void go(int p, int u, vector<vector<int>> &adjacency, vector<node> &dp) {
    node diff;
    diff.i0=dp[u].i0=u;
    for(auto v : adjacency[u]) {
        if(v==p) {
            continue;
        }
        go(u, v, adjacency, dp);
        if(dp[v].ans+1>dp[u].ans || (dp[v].ans+1==dp[u].ans && dp[v].l0+dp[v].c+1>dp[u].l0+dp[u].c)) {
            dp[u]=dp[v];
            dp[u].c++;
            dp[u].ans++;
        }
        if(dp[v].l0+dp[v].c+1>=diff.l1) {
            diff.l1=dp[v].l0+dp[v].c+1;
            diff.i1=dp[v].i0;
            if(diff.l1>diff.l0) {
                swap(diff.i0, diff.i1);
                swap(diff.l0, diff.l1);
            }   
            diff.ans=diff.l0+diff.l1;
        }       
    }
    if(diff.ans>dp[u].ans) {
        dp[u]=diff;
    }
    return;
}

int bfs(int u, vector<vector<int>> &adjacency) {
    int n=(int)adjacency.size();
    vector<int> visited(n);
    queue<int> active;
    active.push(u);
    visited[u]=1;
    while(!active.empty()) {
        u=active.front();
        active.pop();
        for(auto v : adjacency[u]) {
            if(!visited[v]) {
                visited[v]=1;
                active.push(v);
            }
        }
    }
    return u;
}

void solve() {
    int n;
    cin>>n;
    vector<vector<int>> adjacency(n);
    for(int i=0; i<n-1; i++) {
        int a, b;
        cin>>a>>b;
        a--, b--;
        adjacency[a].push_back(b);
        adjacency[b].push_back(a);
    }
    int root=bfs(bfs(0, adjacency), adjacency);
    vector<node> dp(n);
    go(-1, root, adjacency, dp);
    int best=0;
    for(int i=1; i<n; i++) {
        if(dp[i].ans>dp[best].ans) {
            best=i;
        }
    }
    cout<<dp[best].ans<<endl;
    cout<<best+1<<" "<<dp[best].i0+1<<" "<<dp[best].i1+1<<endl;
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

