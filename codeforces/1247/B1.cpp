#include "bits/stdc++.h"
using namespace std;
using ll = long long;

void solve() {
    int n, k, d;
    cin>>n>>k>>d;
    vector<int> a(n);
    for(auto &i : a) {
        cin>>i;
    }   
    map<int, int> active;
    int ans=d;
    for(int i=0; i<d-1; i++) {
        active[a[i]]++;
    }
    for(int i=d-1; i<n; i++) {
        active[a[i]]++;
        ans=min(ans, (int)active.size());
        active[a[i-d+1]]--;
        if(active[a[i-d+1]]==0) {
            active.erase(a[i-d+1]);
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

