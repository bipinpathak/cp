#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int last(int head, vector<vector<int>> &adjacency) {
    int n=(int)adjacency.size(); 
    vector<int> visited(n);
    queue<int> active;
    active.push(head);
    visited[head]=1;
    while(!active.empty()) {
        n=(int)active.size();
        while(n--) {
            int u=active.front();
            for(auto v : adjacency[u]) {
                if(!visited[v]) {
                    active.push(v);
                    visited[v]=1;
                }
            }
            head=u;
            active.pop();
        }
    }
    return head;
}

void calc(int p, int u, vector<vector<int>> &adjacency, vector<int> &dist) {
    for(auto v : adjacency[u]) {
        if(v!=p) {
            calc(u, v, adjacency, dist);
            dist[u]=max(dist[u], 1+dist[v]);
        }
    }
    return;
}

void go(int p, int u, vector<vector<int>> &adjacency, vector<int> &dist, vector<int> &ans, int &curr) {
    curr++;
    ans[u]=curr;
    map<int, vector<int>> options;
    for(auto v : adjacency[u]) {
        if(v!=p) {
            options[dist[v]].push_back(v);
        }
    }
    for(auto i : options) {
        for(auto v : i.second) {
            go(u, v, adjacency, dist, ans, curr);  
        }
    }
    curr++;
    return;
}

void solve() {
    int n;
    cin>>n;
    vector<vector<int>> adjacency(n);
    for(int i=0; i<n-1; i++) {
        int x, y;
        cin>>x>>y;
        x--, y--;
        adjacency[x].push_back(y);
        adjacency[y].push_back(x);
    }
    int head=0;
    head=last(head, adjacency);
    head=last(head, adjacency);
    vector<int> dist(n);
    calc(-1, head, adjacency, dist);
    vector<int> ans(n);
    int curr=0;
    go(-1, head, adjacency, dist, ans, curr);
    for(auto i : ans) {
        cout<<i<<" ";
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
    //cin >> t;
    for(int i=0; i<t; i++) {
        //cout<<"Case #"<<i+1<<": ";
        solve();
    }
    return 0;
}

