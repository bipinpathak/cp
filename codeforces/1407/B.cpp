#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b) {
    if(a==0) return b;
    return gcd(b%a, a);
}
void solve() {
    int n, i, x=0;
    cin>>n;
    vector<int> a(n);
    for(int &i : a) cin>>i;
    vector<int> ans(n);
    vector<int> used(n, 0);
    for(i=0; i<n; i++) {
        int candidate=0, j, optimal=0;
        while(used[candidate]) candidate++;
        for(j=candidate; j<n; j++) {
            if(!used[j]) {
                int offer=gcd(x, a[j]);
                if(offer>optimal) {
                    optimal=offer;
                    candidate=j;
                }
            }
        }
        used[candidate]=1;
        ans[i]=a[candidate];
        x=gcd(x, ans[i]);
    }
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
    cin>>t;
    while(t--) {
        solve();
    }
    return 0;
}

