#include "bits/stdc++.h"
using namespace std;
using ll = long long;

void solve() {
    ll n, k;
    cin>>n>>k;
    ll d=0;
    while(d*d<8*(n+k+1)+1) {
        d++;
    }
    n=2*n+3;
    if(n>=d) {
        n-=d;
    } else {
        n+=d;
    }
    n/=2;
    cout<<n<<endl;
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
    for(int i=0; i<t; i++) {
        //cout<<"Case #"<<i+1<<": ";
        solve();
    }
    return 0;
}

