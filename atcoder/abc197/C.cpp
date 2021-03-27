#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<ll> go(int index, vector<ll> &a) {
    vector<ll> ans;
    int n=(int)a.size();
    ll curr=0;
    while(index<n) {
        curr|=a[index];
        index++;
        vector<ll> next=go(index, a);
        for(auto i : next) {
            ans.push_back(curr^i);
        }
    }
    ans.push_back(curr);
    return ans;
}

void solve() {
    int n;
    cin>>n;
    vector<ll> a(n);
    for(auto &i : a) {
        cin>>i;
    }
    ll ans=1e18;
    vector<ll> options=go(0, a);
    for(auto i: options) {
        ans=min(ans, i);
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

