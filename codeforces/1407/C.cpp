#include <bits/stdc++.h>
using namespace std;
void solve() {
    int n;
    cin>>n;
    int maxn=0, i, a, b;
    vector<int> ans(n);
    for(i=1; i<n; i++) {
        cout<<"? "<<maxn+1<<" "<<i+1<<endl;
        cin>>a;
        cout<<"? "<<i+1<<" "<<maxn+1<<endl;
        cin>>b;
        if(a>b) {
            ans[maxn]=a;
            maxn=i;
        } else {
            ans[i]=b;
        }
    }
    ans[maxn]=n;
    cout<<"! ";
    for(int &i : ans) cout<<i<<" ";
    cout<<endl;
    return;
}
int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t=1;
    //cin>>t;
    while(t--) {
        solve();
    }
    return 0;
}

