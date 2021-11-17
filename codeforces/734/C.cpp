#include "bits/stdc++.h"
using namespace std;
using ll = long long;

void solve() {
    ll target, m, k;
    cin>>target>>m>>k;
    ll x, total;
    cin>>x>>total;
    vector<vector<ll>> firstSpell(m, vector<ll> (2)), secondSpell(k, vector<ll> (2));
    for(auto &i : firstSpell) {
        cin>>i[1];
    }
    for(auto &i : firstSpell) {
        cin>>i[0];
    }
    for(auto &i : secondSpell) {
        cin>>i[1];
    }
    for(auto &i : secondSpell) {
        cin>>i[0];
    }
    sort(firstSpell.begin(), firstSpell.end());
    sort(secondSpell.begin(),secondSpell.end());
    ll ans=target*x;
    for(int i=0; i<m; i++) {
        if(i) {
            firstSpell[i][1]=min(firstSpell[i][1], firstSpell[i-1][1]);
        }
        if(firstSpell[i][0]<=total) {
            ans=min(ans, target*firstSpell[i][1]);
        }
    }
    int i=m-1, best=0;
    for(int j=0; j<k; j++) {
        if(secondSpell[j][0]>total) {
            break;
        }
        if(secondSpell[j][1]>secondSpell[best][1]) {
            best=j;
        }
        ll left=total-secondSpell[best][0];
        while(i>=0 && firstSpell[i][0]>left) {
            i--;
        }
        ll discountedTime=x;
        if(i>=0) {
            discountedTime=firstSpell[i][1];
        }
        ll poitionsLeft=max(target-secondSpell[best][1], (ll)0);
        ans=min(ans, poitionsLeft*discountedTime);
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
    for(int i=0; i<t; i++) {
        //cout<<"Case #"<<i+1<<": ";
        solve();
    }
    return 0;
}

