#include "bits/stdc++.h"
using namespace std;
using ll = long long;

void go(int p, int u, vector<vector<int>> &adjacency, vector<vector<ll>> &count, vector<vector<ll>> &weight) {
    weight[u][0]=1;
    weight[u][1]=adjacency[u].size();
    count[u][1]=1;
    for(auto &v : adjacency[u]) {
        if(v==p) {
            continue;
        }
        go(u, v, adjacency, count, weight);
        int choose=(count[v][1]>count[v][0] || (count[v][1]==count[v][0] && weight[v][1]<weight[v][0]));
        count[u][0]+=count[v][choose];
        weight[u][0]+=weight[v][choose];
        count[u][1]+=count[v][0];
        weight[u][1]+=weight[v][0];
    }
    return;
}

void build(int curr, int p, int u, vector<vector<int>> &adjacency, vector<vector<ll>> &count, vector<vector<ll>> &weight, vector<int> &ans) {
    ans[u]=curr;
    for(auto &v : adjacency[u]) {
        if(v==p) {
            continue;
        }
        int down=(curr==0 && (count[v][1]>count[v][0] || (count[v][1]==count[v][0] && weight[v][1]<weight[v][0])));
        build(down, u, v, adjacency, count, weight, ans);
    }
    return;
}

void solve() {
    int n;
    cin>>n;
    vector<vector<int>> adjacency(n);
    for(int i=0; i<n-1; i++) {
        int u, v;
        cin>>u>>v;
        u--, v--;
        adjacency[u].push_back(v);
        adjacency[v].push_back(u);
    }
    if(n==2) {
        cout<<"2 2"<<endl;
        cout<<"1 1"<<endl;
        return;
    }
    vector<vector<ll>> count(n, vector<ll> (2)), weight(n, vector<ll> (2));
    go(-1, 0, adjacency, count, weight);
    int choose=(count[0][1]>count[0][0] || (count[0][1]==count[0][0] && weight[0][1]<weight[0][0]));
    vector<int> ans(n);
    build(choose, -1, 0, adjacency, count, weight, ans);
    cout<<count[0][choose]<<" "<<weight[0][choose]<<endl;
    for(int i=0; i<n; i++) {
        if(ans[i]) {
            ans[i]=adjacency[i].size();
        } else {
            ans[i]=1;
        }
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return;
}

int main() {
#ifdef bipinpathak
    (void)!freopen("input.txt", "r", stdin);
    (void)!freopen("output.txt", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    for(int i=0; i<t; i++) {
        //cout<<"Case #"<<i+1<<": ";
        solve();
    }
    return 0;
}

