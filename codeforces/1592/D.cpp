#include "bits/stdc++.h"
using namespace std;
using ll = long long;

int ask(int left, int right, vector<vector<int>> &edges) {
    int ans=0;
    set<int> all;
    while(left<=right) {
        for(auto i : edges[left]) {
            all.insert(i);
        }
        left++;
    }
    cout<<"? "<<all.size();
    for(auto i : all) {
        cout<<" "<<i;
    }
    cout<<endl;
    cin>>ans;
    return ans;
}

void go(vector<vector<int>> &adjacency, vector<vector<int>> &edges) {
    int n=(int)adjacency.size()-1;
    vector<int> done(n+1);
    queue<int> level;
    level.push(1);
    done[1]=1;
    while(!level.empty()) {
        int u=level.front();
        level.pop();
        for(auto v : adjacency[u]) { 
            if(done[v]) {
                continue; 
            }
            edges.push_back({u, v});
            level.push(v);
            done[v]=1;
        }
    }
    return;
}

void solve() {
    int n;
    cin>>n;
    vector<vector<int>> adjacency(n+1);
    for(int i=0; i<n-1; i++) {
        int a, b;
        cin>>a>>b;
        adjacency[a].push_back(b);
        adjacency[b].push_back(a);
    }
    vector<vector<int>> edges;
    go(adjacency, edges);
    int low=0, high=n-2, target=ask(low, high, edges);
    while(low<high) {
        int mid=low+(high-low)/2;
        int res=ask(low, mid, edges);
        if(res==target) {
            high=mid;
        } else {
            low=mid+1;
        }
    }
    cout<<"! "<<edges[low][0]<<" "<<edges[low][1]<<endl;
    return;
}

int main() {
#ifdef bipinpathak
    //(void)!freopen("input.txt", "r", stdin);
    //(void)!freopen("output.txt", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    //cin>>t;
    for(int i=0; i<t; i++) {
        //cout<<"Case #"<<i+1<<": ";
        solve();
    }
    return 0;
}

