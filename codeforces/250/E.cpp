#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void go(int r, int c, int d, vector<string> &grid, ll &ans) {
    int n=(int)grid.size(), m=(int)grid.front().size();
    if(r==n-1) {
        return;
    }
    int leftHole=-1, rightHole=m;
    for(int j=c; j>=0; j--) {
        if(grid[r][j]=='#') {
            break;
        }
        if(grid[r+1][j]=='.') {
            leftHole=j;
            break;
        }
    }
    for(int j=c; j<m; j++) {
        if(grid[r][j]=='#') {
            break;
        }
        if(grid[r+1][j]=='.') {
            rightHole=j;
            break;
        }
    }
    queue<int> leftWalls, rightWalls;
    int last=-1, count=2;
    for(int j=c-1; j>=0; j--) {
        if(grid[r][j]=='+') {
            leftWalls.push(j);   
        } else if(grid[r][j]=='#') {
            leftWalls.push(-j);
            last=j;
            break;
        }
    }
    if(leftHole==-1 || last>leftHole) {
        count--;
    }
    last=m;
    for(int j=c+1; j<m; j++) {
        if(grid[r][j]=='+') {
            rightWalls.push(j);   
        } else if(grid[r][j]=='#') {
            rightWalls.push(-j);
            last=j;
            break;
        }
    }
    if(rightHole==m || last<rightHole) {
        count--;
    }
    if(count==0) {
        ans=-1;
        return;
    }
    leftWalls.push(-m);
    rightWalls.push(-m);
    while(1) {
        if(d) {
            int maxRight=rightWalls.front(); 
            if(maxRight>=0) {
                rightWalls.pop();
            } else {
                maxRight*=-1;
            }
            maxRight--;
            ans+=(ll)min(rightHole,maxRight)-c;
            c=min(rightHole, maxRight);
        } else {
            int maxLeft=leftWalls.front();
            if(maxLeft>=0) {
                leftWalls.pop();
            } else {
                maxLeft*=-1;
                if(maxLeft==m) {
                    maxLeft=-1;
                }
            }
            maxLeft++;
            ans+=(ll)c-max(maxLeft, leftHole);
            c=max(maxLeft, leftHole);
        }
        ans++;
        if(c==rightHole || c==leftHole) {
            break;
        }
        if(d) {
            d=0;
        } else {
            d=1;
        }
    }
    go(r+1, c, d, grid, ans);
    return;
}

void solve() {
    int n, m;
    cin>>n>>m;
    vector<string> grid(n);
    for(auto &i : grid) {
        cin>>i;
    }
    ll ans=0;
    go(0, 0, 1, grid, ans);
    if(ans==-1) {
        cout<<"Never";
    } else {
        cout<<ans;
    }
    cout<<endl;
    return;
}

int main() {
#ifdef bipinpathak
    (void)!freopen("input.txt", "r", stdin);
   //(void)!freopen("output.txt", "w", stdout);
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
