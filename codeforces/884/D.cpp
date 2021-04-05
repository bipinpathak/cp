#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin>>n;
    priority_queue<ll, vector<ll>, greater<ll>> active;
    vector<ll> a(n);
    if(n%2==0) {
        active.push(0);
    }
    for(auto &i :a) {
        cin>>i;
        active.push(i);
    }
    ll ans=0;
    while((int)active.size()>1) {
        ll curr=0;
        for(int i=0; i<3; i++) {
            curr+=active.top();
            active.pop();
        }
        ans+=curr;
        active.push(curr);
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
    for(int i=0; i<t; i++) {
        //cout<<"Case #"<<i+1<<": ";
        solve();
    }
    return 0;
}

