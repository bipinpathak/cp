#include "bits/stdc++.h"
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin>>n;
    vector<int> a(n);
    set<int> have;
    for(auto &i : a) {
        cin>>i;
        have.insert(i);
    }
    sort(a.begin(), a.end());
    int count=0;
    for(int i=0; i<n && count<n/2; i++) {
        for(int j=i+1; j<n && count<n/2; j++) {
            if(!have.count(a[j]%a[i])) {
                count++;
                cout<<a[j]<<" "<<a[i]<<endl;
            }
        }
    }
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

