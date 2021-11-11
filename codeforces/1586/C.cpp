#include "bits/stdc++.h"
using namespace std;
using ll = long long;

void solve() {
    int n, m;
    cin>>n>>m;
    vector<string> grid(n);
    for(auto &i : grid) {
        cin>>i;
    }
    vector<int> bad(m);
    for(int i=1; i<n; i++) {
        for(int j=1; j<m; j++) {
            if(grid[i-1][j]=='X' && grid[i][j-1]=='X') {
                bad[j]++;
            }
        }
    }
    for(int j=1; j<m; j++) {
        bad[j]+=bad[j-1];
    }
    int q;
    cin>>q;
    while(q--) {
        int l, r;
        cin>>l>>r;
        l--, r--;
        int left=bad[r]-bad[l];
        string ans=left?"No":"Yes";
        cout<<ans<<endl;
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

