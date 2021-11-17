#include "bits/stdc++.h"
using namespace std;
using ll = long long;

int find_set(int v, vector<int> &parent) {
	if(parent[v]!=v) {
		parent[v]=find_set(parent[v], parent);
	}
    return parent[v];
}

void union_sets(int a, int b, vector<int> &parent, vector<int> &size) {
    a = find_set(a, parent);
    b = find_set(b, parent);
    if (a != b) {
        if (size[a] < size[b])
            swap(a, b);
        parent[b] = a;
        size[a] += size[b];
    }
	return;
}

int go(int &u, vector<vector<int>> &adjacency) {
    int n=(int)adjacency.size(), d=0;
    queue<int> active;
    active.push(u);
    vector<int> visited(n);
    visited[u]=1;
    while(!active.empty()) {
        d++;
        n=(int)active.size();
        while(n--) {
            u=active.front();
            active.pop();
            for(auto v : adjacency[u]) {
                if(!visited[v]) {
                    active.push(v);
                    visited[v]=1;
                }
            }
        }
    }
    return d;
}

void solve() {
    int n;
    cin>>n;
    vector<int> color(n), parent(n), size(n, 1);
    for(int i=0; i<n; i++) {
        cin>>color[i];
        parent[i]=i;
    }
    vector<vector<int>> edges;
    for(int i=0; i<n-1; i++) {
        int u, v;
        cin>>u>>v;
        u--, v--;
        if(color[u]==color[v]) {
            union_sets(u, v, parent, size);
        } else {
            edges.push_back({u, v});
        }
    }
    vector<vector<int>> adjacency(n);
    for(auto &i : edges) {
        i[0]=find_set(i[0], parent);
        i[1]=find_set(i[1], parent);
        adjacency[i[0]].push_back(i[1]);
        adjacency[i[1]].push_back(i[0]);
    }
    int u=find_set(0, parent), ans=0;
    go(u, adjacency);
    ans=go(u, adjacency)/2;
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
    int t = 1;
    for(int i=0; i<t; i++) {
        //cout<<"Case #"<<i+1<<": ";
        solve();
    }
    return 0;
}

