#include "bits/stdc++.h"
using namespace std;
using ll = long long;

void solve() {
    int n, h;
    cin>>n>>h;
    vector<int> a(n);
    for(auto &i : a) {
        cin>>i;
    }
    sort(a.rbegin(), a.rend());
    int ans=h/(a[0]+a[1]);
    h-=ans*(a[0]+a[1]); 
    ans*=2;
    if(h) {
        ans++;
        h-=a[0];
        if(h>0) {
            ans++;
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

