#include "bits/stdc++.h"
using namespace std;
using ll = long long;

ll mod=1e9+7;

void solve() {
    int n, x, y;
    cin>>n>>x>>y;
    vector<vector<ll>> a(n, vector<ll> (2));
    for(auto &i : a) {
        for(auto &j : i) {
            cin>>j;
        }
    }
    sort(a.begin(), a.end());
    priority_queue<ll> available;
    priority_queue<ll, vector<ll>, greater<ll>> due;
    ll ans=0;
    for(auto &i : a) {
        while(!due.empty() && due.top()<i[0]) {
            available.push(due.top());
            due.pop();
        }
        if(available.empty() || (i[0]-available.top())*y>x) {
            ans+=x;
        } else {
            ans+=(i[0]-available.top())*y;
            available.pop();
        }
        ans+=y*(i[1]-i[0]);
        ans%=mod;
        due.push(i[1]);
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

