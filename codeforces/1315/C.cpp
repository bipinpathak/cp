#include "bits/stdc++.h"
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin>>n;
    vector<int> b(n);
    for(auto &i : b) {
        cin>>i;
    }
    vector<int> a(2*n);
    set<int> left;
    for(int i=0; i<2*n; i++) {
        left.insert(i+1);
    }
    for(int i=0; i<2*n; i+=2) {
        a[i]=b[i/2];
        left.erase(a[i]);
    }
    for(int i=1; i<2*n; i+=2) {
        auto it=left.upper_bound(a[i-1]);
        if(it==left.end()) {
            a={-1};
            break;
        }
        a[i]=*it;
        left.erase(it);
    }
    for(auto i : a) {
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
    cin>>t;
    for(int i=0; i<t; i++) {
        //cout<<"Case #"<<i+1<<": ";
        solve();
    }
    return 0;
}

