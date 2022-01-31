#include "bits/stdc++.h"
using namespace std;
using ll = long long;

void solve() {
    int n, m;
    cin>>n>>m;
    vector<vector<int>> a(n, vector<int> (m));
    ll ans=0;
    for(auto &i : a) {
        int offer=0;
        for(auto &j : i) {
            cin>>j;
            offer+=j;
        }
        if(offer) {
            ans+=((ll)1<<offer)-1;
        }
        offer=m-offer;
        if(offer) {
            ans+=((ll)1<<offer)-1;
        }
    }
    for(int j=0; j<m; j++) {
        int offer=0;
        for(int i=0; i<n; i++) {
            offer+=a[i][j];
        }
        if(offer) {
            ans+=((ll)1<<offer)-1;
        }
        offer=n-offer;
        if(offer) {
            ans+=((ll)1<<offer)-1;
        }
        
    }
    ans-=n*m;
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

