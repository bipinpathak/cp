#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n, m;
    cin>>n>>m;
    vector<int> ans(m+1, -1);
    ans[0]=0;
    ll k=1e5;
    for(int i=0; i<n; i++) {
        int t;
        ll x, y;
        cin>>t>>x>>y;
        ll jump=(x+k-1)/k;
        for(int j=m; j>=0; j--) {
            if(ans[j]==-1) {
                continue;
            }
            ll curr=j;
            for(int step=0; step<y; step++) {
                if(t==1) {
                    curr+=jump;
                } else {
                    curr=curr*x;
                    curr=(curr+k-1)/k;
                }
                if(curr>m || ans[curr]!=-1) {
                    break; 
                }
                ans[curr]=i;
            }
        }
    }
    for(int i=1; i<=m; i++) {
        if(ans[i]!=-1) {
            ans[i]++;
        }
        cout<<ans[i]<<" ";
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
    for(int i=0; i<t; i++) {
        //cout<<"Case #"<<i+1<<": ";
        solve();
    }
    return 0;
}

