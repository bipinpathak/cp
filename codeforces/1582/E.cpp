#include "bits/stdc++.h"
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin>>n;
    vector<ll> a(n);
    for(auto &i : a) {
        cin>>i;
    }
    vector<ll> dp(n+1, 1e9+1);
    ll k=1;
    while((k*(k+1))/2<=n) {
        vector<ll> update(n+1);
        ll sum=0;
        for(int i=n-1; i>=0; i--) {
            update[i]=update[i+1];
            sum+=a[i]; 
            if(i+k-1<n) {
                if(sum<dp[i+k]) {
                    update[i]=max(update[i], sum);
                }
                sum-=a[i+k-1];
            }
        }
        if(update[0]==0) {
            break;
        }
        dp=update;
        k++;
    }
    cout<<--k<<endl;
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

