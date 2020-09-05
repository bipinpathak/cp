#include <bits/stdc++.h>
using namespace std;
void solve() {
    int n, i, fmax, fmin;
    cin>>n;
    vector<vector<int>> adjacency(n);
    for(i=0; i<n-1; i++) {
        int x, y;
        cin>>x>>y;
        x--;
        y--;
        adjacency[x].push_back(y);
        adjacency[y].push_back(x);
    }
    fmax=n-1;
    set<int> next;
    for(i=0; i<n; i++) {
       if(adjacency[i].size()==1) {
            if(next.find(adjacency[i][0])!=next.end()) fmax--;
            else next.insert(adjacency[i][0]);
       }
    }
    fmin=1;
    queue<int> level;
    vector<int> color(n, -1);
    int parity=0;
    for(i=0; i<n; i++) if(adjacency[i].size()==1) level.push(i);
    while(level.size() && fmin==1) {
        int n=level.size();
        while(n-- && fmin==1) {
            int node=level.front();
            level.pop();
            if(color[node]==parity) fmin=3;
            else if(color[node]==-1) {
                color[node]=!parity;
                for(int next : adjacency[node]) {
                    if(color[next]==-1) level.push(next);
                    else if (color[next]!=parity){
                        fmin=3;
                        break;
                    }
                }
            }
        }
        parity=!parity;
    }
    cout<<fmin<<" "<<fmax<<endl;
    return;
}
int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t=1;
    //cin>>t;
    while(t--) {
        solve();
    }
    return 0;
}

