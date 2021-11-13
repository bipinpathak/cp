#include "bits/stdc++.h"
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin>>n;
    vector<int> s(n);
    for(auto &i : s) {
        cin>>i;
    }
    set<int> valid;
    for(int a=1; a<=1000; a++) {
        for(int b=1; b<=1000 && 4*a*b+3*a+3*b<=1000; b++) {
            valid.insert(4*a*b+3*a+3*b);
        }
    }
    int ans=n;
    for(auto i : s) {
        ans-=valid.count(i);
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

