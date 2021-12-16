#include "bits/stdc++.h"
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin>>n;
    int a, b, c;
    if(n&1) {
        c=1, b=2;
        while(__gcd(n-c-b, b)!=1) {
            b++;
        }
        a=n-b-c;
    } else {
        a=2, b=n-3, c=1;
    }
    cout<<a<<" "<<b<<" "<<c<<endl;
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

