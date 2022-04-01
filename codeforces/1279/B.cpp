#include "bits/stdc++.h"
using namespace std;
using ll = long long;

void solve() {
    int n, s;
    cin>>n>>s;
    vector<int> a(n);
    for(auto &i : a) {
        cin>>i;
    }
    ll ans=0, high=0, total=0;
    for(int i=0; i<n; i++) {
        total+=a[i];
        if(a[i]>a[high]) {
            high=i;
        }
        if(total>s) {
            if(total-a[high]>s) {
                break;
            }
            ans=high+1;
        }
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
    cin>>t;
    for(int i=0; i<t; i++) {
        //cout<<"Case #"<<i+1<<": ";
        solve();
    }
    return 0;
}

