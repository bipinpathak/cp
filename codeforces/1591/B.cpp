#include "bits/stdc++.h"
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin>>n;
    vector<int> a(n);
    int m=0;
    for(auto &i : a) {
        cin>>i;
        m=max(m, i);
    }
    int ans=0, curr=0;
    while(!a.empty() && a.back()!=m) {
        if(a.back()>curr) {
            ans++;
            curr=a.back();
        }
        a.pop_back();
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

