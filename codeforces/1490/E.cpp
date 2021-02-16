#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin>>n;
    vector<vector<ll>> a(n, vector<ll> (2));
    for(int i=0; i<n; i++) {
        cin>>a[i][0];
        a[i][1]=i;
    }
    sort(a.begin(), a.end());
    vector<ll> cost(n);
    for(int i=n-1; i; i--) {
        if(i==n-1) {
            cost[i]=a[i][0];
        } else {
            cost[i]=max(a[i][0], cost[i+1]-a[i][0]);
        }
    }
    set<ll> winning;
    ll loot=0;
    for(int i=0; i<n; i++) {
        if(i==n-1 || a[i][0]+loot>=cost[i+1]) {
            winning.insert(a[i][0]);
        }
        loot+=a[i][0];
    }   
    vector<int> ans;
    for(auto i : a) {
        if(winning.find(i[0])!=winning.end()) {
            ans.push_back(i[1]+1);
        }
    }
    sort(ans.begin(), ans.end());
    cout<<ans.size()<<endl;
    for(auto i : ans) {
        cout<<i<<" ";
    }
    cout<<endl;
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

