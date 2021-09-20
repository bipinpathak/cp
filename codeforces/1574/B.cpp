#include "bits/stdc++.h"
using namespace std;
using ll = long long;

void solve() {
    vector<int> a(3);
    for(auto &i : a) {
        cin>>i;
    }
    int m, low, high;
    cin>>m;
    sort(a.rbegin(), a.rend());
    high=a[0]+a[1]+a[2]-3;
    low=a[0]-a[1]-a[2]-1;
    string ans="NO";
    if(low<=m && m<=high) {
        ans="YES";
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

