#include "bits/stdc++.h"
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin>>n;
    vector<int> a(n);
    for(auto &i : a) {
        cin>>i;
    }
    map<int, vector<int>> index;
    for(int i=0; i<n; i++) {
        index[a[i]].push_back(i);
    }
    int ans=-1;
    for(auto &[key, order] : index) {
        int m=(int)order.size();
        for(int i=0; i+1<m; i++) {
            ans=max(ans, n+order[i] -order[i+1]);
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
    cin>>t;
    for(int i=0; i<t; i++) {
        //cout<<"Case #"<<i+1<<": ";
        solve();
    }
    return 0;
}

