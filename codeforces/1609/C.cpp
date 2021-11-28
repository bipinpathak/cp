#include "bits/stdc++.h"
using namespace std;
using ll = long long;

int m=1e6;
vector<int> primes, lp(m+1, 0);

void pre() {
    for(int i=2; i<=m; i++) {
        if(lp[i]==0) {
            lp[i]=i;
            primes.push_back(i);
        }
        for(auto p : primes) {
            if(p>lp[i] || p*i>m) {
                break;
            }
            lp[p*i]=p;
        }
    }
    return;
}

void solve() {
    int n, e;
    cin>>n>>e;
    vector<int> a(n);
    for(auto &i : a) {
        cin>>i;
    }
    vector<int> next(n);
    ll ans=0;
    for(int i=0; i<n; i++) {
        if(lp[a[i]]!=a[i]) {
            continue;
        }
        ll left=1, right=1, j=i+e;
        while(j<n && a[j]==1) {
            right++;
            j+=e;
        }
        j=i-e;
        while(j>=0 && a[j]==1) {
            left++;
            j-=e;
        }
        ans+=left*right-1;
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
    pre();
    cin>>t;
    for(int i=0; i<t; i++) {
        //cout<<"Case #"<<i+1<<": ";
        solve();
    }
    return 0;
}

