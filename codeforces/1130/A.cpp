#include "bits/stdc++.h"
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin>>n;
    vector<int> a(n);
    int p, z;
    p=n=z=0;
    for(auto &i : a) {
        cin>>i;
        if(i>0) {
            p++;
        } else if(i==0) {
            z++;
        } else {
            n++;
        }
    }
    int ans=0;
    if(p>=n+z) {
        ans=1;
    } else if(n>=p+z) {
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

