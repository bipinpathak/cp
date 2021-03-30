#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n, m;
    cin>>n>>m;
    vector<vector<int>> a(n, vector<int> (m));
    for(auto &i : a) {
        for(auto &j : i) {
            cin>>j;
        }
    } 
    string ans="Ashish";
    for(int d=0; d<=n+m-2; d++) {
        int i=min(d, n-1), sum=0;
        for(int j=max(0, d-i); j<m && i>=0; j++) {
            sum^=a[i][j];
            i--;
        }
        if(sum) {
            cout<<ans<<endl;
            return;
        }
    }
    ans="Jeel";
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
    cin >> t;
    for(int i=0; i<t; i++) {
        //cout<<"Case #"<<i+1<<": ";
        solve();
    }
    return 0;
}

