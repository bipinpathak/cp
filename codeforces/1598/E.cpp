#include "bits/stdc++.h"
using namespace std;
using ll = long long;

void solve() {
    int n, m, q;
    cin>>n>>m>>q;
    vector<vector<int>> grid(n, vector<int> (m)), right, down;
    right=down=grid;
    ll ans=0, single=0;
    for(int i=n-1; i>=0; i--) {
        for(int j=m-1; j>=0; j--) {
            grid[i][j]=1;
            if(i+1<n) {
                down[i][j]=1+right[i+1][j];
            }
            if(j+1<m) {
                right[i][j]=1+down[i][j+1];
            }
            ans+=right[i][j]+down[i][j];
            single++;
        }
    }
    while(q--) {
        int x, y;
        cin>>x>>y;
        x--, y--;
        grid[x][y]=!grid[x][y];
        ll diff=0;
        if(grid[x][y]) {
            single++;
        } else {
            single--;
        }
        while(x>=0 && y>=0) {
            diff-=right[x][y]+down[x][y];
            right[x][y]=down[x][y]=0;
            if(grid[x][y] && x+1<n && grid[x+1][y]) {
                down[x][y]=1+right[x+1][y];
            }
            if(grid[x][y] && y+1<m && grid[x][y+1]) {
                right[x][y]=1+down[x][y+1];
            }
            diff+=right[x][y]+down[x][y];
            if(x-1>=0) {
                diff-=down[x-1][y];
                down[x-1][y]=0;
                if(grid[x-1][y] && grid[x][y]) {
                    down[x-1][y]=1+right[x][y];
                }
                diff+=down[x-1][y];
            }
            if(y-1>=0) {
                diff-=right[x][y-1];
                right[x][y-1]=0;
                if(grid[x][y-1] && grid[x][y]) {
                    right[x][y-1]=1+down[x][y];
                }
                diff+=right[x][y-1];
            }
            x--, y--;
        }
        ans+=diff;
        cout<<ans+single<<endl;
    }
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

