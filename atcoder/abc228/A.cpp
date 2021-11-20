#include "bits/stdc++.h"
using namespace std;
using ll = long long;

void solve() {
    int s, t, x;
    cin>>s>>t>>x;
    string ans="No";
    if(s<t) {
        if(s<=x && x<t) {
            ans="Yes";
        }
    } else if(x<t || x>=s) {
        ans="Yes";
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
    //cin>>t;
    for(int i=0; i<t; i++) {
        //cout<<"Case #"<<i+1<<": ";
        solve();
    }
    return 0;
}

