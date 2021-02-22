#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void go(int u, vector<vector<int>> &adjacency, vector<int> &total, vector<int> &high, vector<int> &type) {
    int smallest=1e6, sum=0, count=0;
    for(auto v : adjacency[u]) {
        go(v, adjacency, total, high, type);
        total[u]+=total[v];
        smallest=min(smallest, high[v]);
        sum+=high[v];
        count++;
    }
    if(total[u]) {
        high[u]=type[u]?smallest:(sum+count-1);
    } else {
        total[u]=1;
    }
    return;
}

void solve() {
    int n;
    cin>>n;
    vector<int> total(n), high(n), type(n);
    vector<vector<int>> adjacency(n);
    for(auto &i : type) {
        cin>>i;
    }
    for(int i=1; i<n; i++) {
        int p;
        cin>>p;
        p--;
        adjacency[p].push_back(i);
    }
    go(0, adjacency, total, high, type);
    cout<<total[0]-high[0]<<endl;
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
    while(t--) {
        solve();
    }
    return 0;
}

