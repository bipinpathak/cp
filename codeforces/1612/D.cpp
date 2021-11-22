#include "bits/stdc++.h"
using namespace std;
using ll = long long;

void solve() {
    ll a, b, x;
    cin>>a>>b>>x;
    string ans="NO";
    if(a>b) {
        swap(a, b);
    }
    while(b>=x) {
        if((a && x%a==b%a) || (a==0 && b==x)) {
            ans="YES";
            break;
        }
        if(a==0) {
            break;
        }
        ll c=(b-1)/a;
        c=max(c, (ll)1);
        b-=a*c;
        swap(a, b);
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

