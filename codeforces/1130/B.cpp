#include "bits/stdc++.h"
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin>>n;
    vector<int> a(2*n);
    vector<vector<int>> index(n);
    for(int i=0; i<2*n; i++) {
        cin>>a[i];
        a[i]--;
        index[a[i]].push_back(i);
    }
    ll ans=index[0][0]+index[0][1];
    for(int curr=1; curr<n; curr++) {
        int offer=1e9;
        for(int i=0; i<2; i++) {
            offer=min(offer, abs(index[curr][0]-index[curr-1][i]) + abs(index[curr][1]-index[curr-1][!i]));
        }
        ans+=offer;
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

