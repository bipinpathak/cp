#include "bits/stdc++.h"
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin>>n;
    vector<int> a(n);
    for(auto &i : a) {
        cin>>i;
    }
    sort(a.begin(), a.end());
    map<int, int> have;
    int mex=0, index=0;
    ll curr=0;
    vector<ll> ans(n+1, -1);
    while(mex<=n) {
        int count=0;
        while(index<n && a[index]==mex) {
            have[a[index]]++;
            count++;
            index++;
        }
        ans[mex]=curr+count;
        if(have.empty()) {
            break;
        }
        int x=have.rbegin()->first;
        have[x]--;
        if(have[x]==0) {
            have.erase(x);
        }   
        curr+=mex-x;
        mex++;
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
    cin>>t;
    for(int i=0; i<t; i++) {
        //cout<<"Case #"<<i+1<<": ";
        solve();
    }
    return 0;
}

