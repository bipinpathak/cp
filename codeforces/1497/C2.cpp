#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n, k;
    cin>>n>>k;
    k-=3;
    n-=k;
    while(k--) {
        cout<<1<<" ";
    }
    if(n&1) {
        cout<<1<<" ";
        n--;
    } else {
        if(n%4) {
            cout<<2<<" ";
            n-=2;
        } else {
            cout<<n/2<<endl;
            n/=2;
        }
    }
    cout<<n/2<<" "<<n/2<<endl;
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
    for(int i=0; i<t; i++) {
        //cout<<"Case #"<<i+1<<": ";
        solve();
    }
    return 0;
}

