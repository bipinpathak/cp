#include "bits/stdc++.h"
using namespace std;
using ll = long long;

void solve() {
    int n, x;
    cin>>n>>x;
    vector<int> a(n);
    for(auto &i : a) {
        cin>>i;
    }
    string ans="Yes";
    if(n<2*x) {
        auto temp=a;
        sort(temp.begin(), temp.end());
        for(int i=0; i<n; i++) {
            if(i+x<n || i-x>=0) {
                continue;
            }
            if(a[i]!=temp[i]) {
                ans="No";
                break;
            }
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

