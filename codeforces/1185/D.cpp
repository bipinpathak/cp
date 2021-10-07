#include "bits/stdc++.h"
using namespace std;
using ll = long long;

void solve() {
    ll n;
    cin>>n;
    vector<vector<ll>> a(n, vector<ll> (2));
    for(ll i=0; i<n; i++) {
        cin>>a[i][0];
        a[i][1]=i+1;
    }
    if(n<=3) {
        cout<<1<<endl;
        return;
    }
    sort(a.begin(), a.end());
    ll diff=a[2][0]-a[1][0];
    bool possible=true;
    for(ll i=3; i<n && possible; i++) {
        if(a[i][0]-a[i-1][0]!=diff) {
            possible=false;
        }
    }
    if(possible) {
        cout<<a[0][1]<<endl;
        return;
    }
    diff=a[n-2][0]-a[n-3][0];
    possible=true;
    for(ll i=n-3; i && possible; i--) {
        if(a[i][0]-a[i-1][0]!=diff) {
            possible=false;
        }
    }
    if(possible) {
        cout<<a[n-1][1]<<endl;
        return;
    }
    diff=a[n-1][0]-a[0][0];
    if(diff%(n-2)==0) {
        diff/=n-2;
        vector<ll> bad;
        ll curr=a[0][0];
        for(ll i=0; i<n; i++) {
            if(a[i][0]!=curr) {
                bad.push_back(a[i][1]);
            } else {
                curr+=diff;
            }
        }
        if((ll)bad.size()==1) {
            cout<<bad[0]<<endl;
            return;
        }
    }
    cout<<-1<<endl;
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

