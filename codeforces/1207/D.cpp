#include "bits/stdc++.h"
using namespace std;
using ll = long long;

ll mod=998244353;

void solve() {
    int n;
    cin>>n;
    vector<vector<int>> a(n, vector<int> (2));
    for(auto &i : a) {
        for(auto &j : i) {
            cin>>j;
        }
    }
    ll ans=1;
    for(int i=1; i<=n; i++) {
        ans=(ans*i)%mod;
    }
    for(int k=0; k<2; k++) {
        for(auto &i : a) {
            reverse(i.begin(), i.end());
        }
        sort(a.begin(), a.end());
        ll add=1;
        int count=0;
        for(int i=0; i<n; i++) {
            if(i && a[i][0]!=a[i-1][0]) {
                count=0;
            }
            count++;
            add=(add*count)%mod;
        }
        ans=(ans-add+mod)%mod;
    }
    ll add=1;
    int count=0;
    for(int i=0; i<n; i++) {
        if(i && a[i]!=a[i-1]) {
            count=0;
        }
        if(i && a[i-1][1]>a[i][1]) {
            add=0;
            break;
        }
        count++;
        add=(add*count)%mod;
    }
    ans=(ans+add)%mod;
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

