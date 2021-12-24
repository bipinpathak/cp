#include "bits/stdc++.h"
using namespace std;
using ll = long long;

vector<vector<int>> prefix(2e5+1, vector<int> (30));

void pre() {
    int l=1, r=2e5;
    while(l<=r) {
        prefix[l]=prefix[l-1];
        int x=l;
        for(int i=0; i<30 && x; i++, x>>=1) {
            if(x&1) {
                prefix[l][i]++;
            }
        }
        l++;
    }
    return;
}

void solve() {
    int l, r;
    cin>>l>>r;
    int ans=0;
    auto curr=prefix[r];
    for(int i=0; i<30; i++) {
        curr[i]-=prefix[l-1][i];
        ans=max(ans, curr[i]);
    }
    ans=r-l+1-ans;
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
    cin>>t;
    pre();
    for(int i=0; i<t; i++) {
        //cout<<"Case #"<<i+1<<": ";
        solve();
    }
    return 0;
}

