#include "bits/stdc++.h"
using namespace std;
using ll = long long;

void fill(int i, int j, vector<vector<int>> &a, int target, int val) {
    a[i][j]=val;
    int n=4;
    if(i+1<n && a[i+1][j]==target) {
        fill(i+1, j, a, target, val);
    }
    if(i-1>=0 && a[i-1][j]==target) {
        fill(i-1, j, a, target, val);
    }
    if(j+1<n && a[i][j+1]==target) {
        fill(i, j+1, a, target, val);
    }
    if(j-1>=0 && a[i][j-1]==target) {
        fill(i, j-1, a, target, val);
    }
    return;
}   

bool check(vector<vector<int>> a) {
    int n=4;
    bool seen=false;
    for(int i=0; i<n; i++) {
        if(a[i][0]==0) {
            fill(i, 0, a, 0, 2);
        }
        if(a[i][n-1]==0) {
            fill(i, n-1, a, 0, 2);
        }
        if(a[0][i]==0) {
            fill(0, i, a, 0, 2);
        }
        if(a[n-1][i]==0) {
            fill(n-1, i, a, 0, 2);
        }
    }
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(a[i][j]==0) {
                return false;
            }
        }
    }
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(a[i][j]==1) {
                if(seen) {
                    return false;
                }
                seen=true;
                fill(i, j, a, 1, 0);
            }
        }
    }
    return true;
}

void go(int index, vector<vector<int>> &a, vector<vector<int>> &curr, ll &ans) {
    int n=4, i=index/n, j=index%n;
    if(index==n*n) {
        ans+=check(curr); 
    } else {
        curr[i][j]=1;
        go(index+1, a, curr, ans);
        if(a[i][j]==0) {
            curr[i][j]=0;
            go(index+1, a, curr, ans);
        }
    }
    return;
}   

void solve() {
    int n=4;
    vector<vector<int>> a(n, vector<int> (n));
    for(auto &i : a) {
        for(auto &j : i) {
            cin>>j;
        }
    }
    ll ans=0;
    vector<vector<int>> curr(n, vector<int> (n));
    go(0, a, curr, ans);
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
    //cin>>t;
    for(int i=0; i<t; i++) {
        //cout<<"Case #"<<i+1<<": ";
        solve();
    }
    return 0;
}

