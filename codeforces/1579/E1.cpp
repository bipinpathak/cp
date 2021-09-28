#include "bits/stdc++.h"
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin>>n;
    vector<int> a(n);
    vector<vector<int>> order;
    for(int i=0; i<n; i++) {
        cin>>a[i];
        a[i]--;
        order.push_back({a[i], i});
    }
    vector<int> done(n), ans;
    sort(order.begin(), order.end());
    int last=n;
    for(auto i : order) {
        int curr=i[1];
        if(curr<last) {
            last=curr;
            ans.push_back(a[last]);
            done[last]=1;
        }
    }
    for(int i=0; i<n; i++) {
        if(!done[i]) {
            ans.push_back(a[i]);
        }
    }
    for(auto i : ans) {
        cout<<i+1<<" ";
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
    cin>>t;
    for(int i=0; i<t; i++) {
        //cout<<"Case #"<<i+1<<": ";
        solve();
    }
    return 0;
}

