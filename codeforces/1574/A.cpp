#include "bits/stdc++.h"
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin>>n;
    string ans(n-1, '(');
    for(int i=0; i<n; i++) {
        ans.push_back(')');
    }
    string single="()";
    for(int i=0; i<n; i++) {
        for(int j=0; j<i; j++) {
            cout<<ans[j];
        }
        cout<<single;
        for(int j=i; j<2*n-2; j++) {
            cout<<ans[j];
        }
        cout<<endl;
    }
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

