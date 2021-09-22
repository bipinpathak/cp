#include "bits/stdc++.h"
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin>>n;
    vector<int> a(n);
    ll total=0, small=0;
    for(auto &i : a) {
        cin>>i;
        total+=i;
    }
    sort(a.begin(), a.end());
    for(int i=0; i<n/2; i++) {
        small+=a[i];
    }
    total-=small;
    cout<<small*small+total*total<<endl;
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

