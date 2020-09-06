#include <bits/stdc++.h>
using namespace std;
void solve() {
    long long  n, ans=0, stock=0 ;
    cin>>n;
    vector<long long> a(n);
    for(auto &i :a) {
        cin>>i;
        if(i<0) {
            if(i+stock>=0) {
                stock+=i;
                i=0;
            } else {
                i+=stock;
                stock=0;
            }
            ans-=i;
        } else stock+=i;
    }
    cout<<ans<<endl;
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
    cin>>t;
    while(t--) {
        solve();
    }
    return 0;
}

