#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool have(int &x, int &y, vector<string> &grid) {
    int n=(int)grid.size(), m=(int)grid[0].size();
    if(x+1<n && grid[x+1][y]=='.') {
        return true;
    }
    if(x-1>=0 && grid[x-1][y]=='.') {
        return true;
    }
    if(y+1<m && grid[x][y+1]=='.') {
        return true;
    }       
    if(y-1>=0 && grid[x][y-1]=='.') {
        return true;
    }
    return false;
}

void clean(queue<vector<int>> &a, vector<string> &grid) {
    int n=(int)a.size();
    while(n--) {
        auto curr=a.front();
        a.pop();
        if(have(curr[0], curr[1], grid)) {
            a.push(curr);
        }
    }
    return;
}

void expand(queue<vector<int>> &active, vector<string> &grid, int s, int p) {
    while(s-- && !active.empty()) {
        int n=(int)active.size();
        while(n--) {
            auto curr=active.front();
            active.pop();
            if(!have(curr[0], curr[1], grid)) {
                continue;
            }
            int row=(int)grid.size(), col=(int)grid[0].size(), i=curr[0], j=curr[1];
            if(i+1<row && grid[i+1][j]=='.') {
                grid[i+1][j]='1'+p; 
                active.push({i+1, j});
            }
            if(i-1>=0 && grid[i-1][j]=='.') {
                grid[i-1][j]='1'+p; 
                active.push({i-1, j});
            }
            if(j+1<col && grid[i][j+1]=='.') {
                grid[i][j+1]='1'+p; 
                active.push({i, j+1});
            }
            if(j-1>=0 && grid[i][j-1]=='.') {
                grid[i][j-1]='1'+p; 
                active.push({i, j-1});
            }
        }
    }
    return;
}

void solve() {
    int n, m, p;
    cin>>n>>m>>p;
    vector<int> speed(p);
    for(auto &i : speed) {
        cin>>i;
    }
    vector<string> grid(n);
    for(auto &i : grid) {
        cin>>i;
    }
    vector<queue<vector<int>>> active(p);
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(grid[i][j]=='.' || grid[i][j]=='#') {
                continue;
            }
            active[grid[i][j]-'1'].push({i, j});
        }
    }
    bool possible=false;
    for(int i=0; i<p; i++) {
        clean(active[i], grid);
        if(!active[i].empty()) {
            possible=true;
        }
    }
    while(possible) {
        possible=false;;
        for(int i=0; i<p; i++) {
            expand(active[i], grid, speed[i], i);
            clean(active[i], grid);
            if(!active[i].empty()) {
                possible=true;
            }
        }
    }
    vector<int> ans(p);
    for(auto i : grid) {
        for(auto j : i) {
            if(j=='.' || j=='#') {
                continue;
            }
            ans[j-'1']++;
        }
    }
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

