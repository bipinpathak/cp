#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<ll> store;

void solve() {
    int n, m;
    cin>>n>>m;
    vector<ll> count(10);
    while(n) {
        count[n%10]++;
        n/=10;
    }
    ll ans=0, p=1e9+7;
    for(int i=0; i<10; i++) {
        if(count[i]==0) {
            continue;
        }
        ll left=m, curr=i;
        if(curr+left>9) {
            left-=9-curr;
            curr=9;
        }
        if(curr<9) {
            ans=(ans+count[i])%p;
        } else {
            ans=(ans+count[i]*store[left])%p;
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
    cin >> t;
    int curr=1, high=2e5;
    ll p=1e9+7;
    store.push_back(1);
    while(curr<=high) {
        ll add=2;
        if(curr-10>0) {
            add=(add+store[curr-10]-1)%p;
        }
        if(curr-9>0) {
            add=(add+store[curr-9]-1)%p;
        }
        store.push_back(add);
        curr++;
    }
    for(int i=0; i<t; i++) {
        //cout<<"Case #"<<i+1<<": ";
        solve();
    }
    return 0;
}

