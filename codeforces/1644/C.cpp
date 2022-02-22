#include "bits/stdc++.h"
using namespace std;
using ll = long long;

void solve() {
    int n, x;
    cin>>n>>x;
    vector<int> a(n);
    for(auto &i : a) {
        cin>>i;
    }
    vector<int> best(n+1, -5e8);
    best[0]=0;
    int ans=0;
    for(int i=0; i<n; i++) {
        int curr=0, len=0;
        for(int j=i; j<n; j++) {
            curr+=a[j];
            len++;
            best[len]=max(best[len], curr);
            ans=max(ans, curr);
        }
    }
    for(int m=0; m<=n; m++) {
        cout<<ans<<" ";
        for(int i=m+1; i<=n; i++) {
            best[i]+=x;
            ans=max(ans, best[i]);
        }
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
    cin>>t;
    for(int i=0; i<t; i++) {
        //cout<<"Case #"<<i+1<<": ";
        solve();
    }
    return 0;
}

