#include "bits/stdc++.h"
using namespace std;
using ll = long long;

void solve() {
    int n, k;
    cin>>n>>k;
    vector<int> a(n);
    for(auto &i : a) {
        cin>>i;
    }
    int ans=0, left=0;
    for(int i=0; i<n && k>0; i++) {
        ans++;
        left+=a[i];
        int curr=min(8, left);
        left-=curr;
        k-=curr;
    }
    if(k>0) {
        ans=-1;
    }
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
    for(int i=0; i<t; i++) {
        //cout<<"Case #"<<i+1<<": ";
        solve();
    }
    return 0;
}

