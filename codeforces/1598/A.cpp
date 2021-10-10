#include "bits/stdc++.h"
using namespace std;
using ll = long long;

void solve() {
    int n;
    string a, b;
    cin>>n>>a>>b;
    string ans="YES";
    for(int i=0; i<n; i++) {
        if(a[i]=='1' && b[i]=='1') {
            ans="NO";
            break;
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

