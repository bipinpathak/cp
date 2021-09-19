#include "bits/stdc++.h"
using namespace std;
using ll = long long;

void solve() {
    ll n2, n3, n4;
    cin>>n2>>n3>>n4;
    ll ans=0, curr=0;
    curr=min(n3/2, n4);
    ans+=curr;
    n3-=2*curr;
    n4-=curr;
    curr=min(n3/2, n2/2);
    ans+=curr;
    n3-=2*curr;
    n2-=2*curr;
    curr=min(n4/2, n2);
    ans+=curr;
    n4-=2*curr;
    n2-=curr;
    curr=min(n4, n2/3);
    ans+=curr;
    n4-=curr;
    n2-=3*curr;
    ans+=n2/5;
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

