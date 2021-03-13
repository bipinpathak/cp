#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin>>n;
    vector<int> a(n);
    for(auto &i :a) {
        cin>>i;
    }
    vector<int> ans(n);
    int curr=0;
    for(int i=n-1; i>=0; i--) {
        curr=max(curr, a[i]); 
        if(curr) {
            ans[i]=1;
            curr--;
        }
    }
    for(auto &i : ans) {
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

