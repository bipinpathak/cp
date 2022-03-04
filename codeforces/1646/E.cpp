#include "bits/stdc++.h"
using namespace std;
using ll = long long;

void solve() {
    int n, m;
    cin>>n>>m;
    int k=20;
    vector<int> have(m*k+1), total(k+1);
    for(int p=1; p<=k; p++) {
        total[p]=total[p-1];
        for(int j=1; j<=m; j++) {
            if(!have[p*j]) {
                have[p*j]=1;
                total[p]++;
            }
        }
    }
    vector<int> done(n+1);
    long long ans=1;
    for(int i=2; i<=n; i++) {
        if(done[i]) {
            continue;
        }
        int p=0;
        long long curr=i;
        while(curr<=n) {
            done[curr]=1;
            p++;
            curr*=i;
        }
        ans+=total[p];
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

