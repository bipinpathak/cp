#include "bits/stdc++.h"
using namespace std;
using ll = long long;

void solve() {
    int n, a, b;
    cin>>n>>a>>b;
    a--, b--;
    vector<int> ans(n), used(n);
    ans[0]=a, ans[n-1]=b;
    used[a]=used[b]=1;
    int high=n-1;
    for(int i=1; i<n/2; i++) {
        while(used[high]) {
            high--;
        }
        ans[i]=high;
        used[high]=1;
    }
    int low=0;
    for(int i=n-2; i>=n/2; i--) {
        while(used[low]) {
            low++;
        }
        ans[i]=low;
        used[low]=1;
    }
    low=n-1, high=0;
    for(int i=0; i<n/2; i++) {
        low=min(low, ans[i]);
        high=max(high, ans[n-1-i]);
    }
    if(low!=a || high!=b) {
        ans={-2};
    }
    for(auto i : ans) {
        cout<<i+1<<" ";
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

