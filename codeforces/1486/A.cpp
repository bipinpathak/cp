#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin>>n;
    vector<ll> a(n);
    for(auto &i : a) {
        cin>>i;
    }
    ll extra=0, last=-1;
    for(auto i : a) {
        i+=extra;
        if(i<=last) {
            cout<<"NO"<<endl;
            return;
        }
        extra=i-(last+1);
        i-=extra;
        last=i;
    }
    cout<<"YES"<<endl;
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
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}

