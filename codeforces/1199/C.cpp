#include "bits/stdc++.h"
using namespace std;
using ll = long long;

void solve() {
    int n, I;
    cin>>n>>I;
    I*=8;
    vector<int> a(n);
    set<int> have;
    for(auto &i : a) {
        cin>>i;
        have.insert(i);
    }
    int k=I/n, allowed=1, unique=(int)have.size();
    while(k--) {
        allowed*=2;
        if(allowed>=unique) {
            cout<<0<<endl;
            return;
        }
    }
    sort(a.begin(), a.end());
    vector<int> left(n+1, n+1), right(n+1, n+1);
    have.clear();
    for(int i=0; i<n; i++) {
        if(!have.count(a[i])) {
            left[(int)have.size()]=i;
            have.insert(a[i]);
        }
    }
    left[(int)have.size()]=n;
    have.clear();
    for(int i=n-1; i>=0; i--) {
        if(!have.count(a[i])) {
            right[(int)have.size()]=n-1-i;
            have.insert(a[i]);
        }
    }
    right[(int)have.size()]=n;
    int extra=unique-allowed, ans=n+1;
    for(int i=0; i<=extra; i++) {
        ans=min(ans, left[i]+right[extra-i]);
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

