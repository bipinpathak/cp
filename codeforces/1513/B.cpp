#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    ll n;
    cin>>n;
    vector<ll> a(n);
    ll total=((ll)1<<31) -1;
    for(auto &i : a) {
        cin>>i;
        total&=i;
    }
    ll count=0;
    for(auto &i : a) {
        count+=(i==total);
    }
    ll p=1e9+7, ans=0;
    ans=(count*(count-1))%p;
    n-=2;
    while(n) {
        ans=(ans*n)%p;
        n--;
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
    cin >> t;
    for(int i=0; i<t; i++) {
        //cout<<"Case #"<<i+1<<": ";
        solve();
    }
    return 0;
}

