#include "bits/stdc++.h"
using namespace std;
using ll = long long;

void solve() {
    int n, m;
    cin>>n>>m;
    vector<vector<int>> a(m, vector<int> (2));
    vector<int> count(n), nearest(n, n-1);
    for(auto &i : a) {
        for(auto &j : i) {
            cin>>j;
            j--;
        }
        count[i[0]]++;
        int dist=i[1]-i[0];
        if(dist<0) {
            dist+=n;
        }
        nearest[i[0]]=min(nearest[i[0]], dist);
    }
    for(int i=0; i<n; i++) {
        int ans=0;
        for(int j=0; j<n; j++) {
            int curr=(i+j)%n;
            if(!count[curr]) {
                continue;
            }
            int offer=j+(count[curr]-1)*n+nearest[curr];
            ans=max(ans, offer);
        }
        cout<<ans<<" ";
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
    for(int i=0; i<t; i++) {
        //cout<<"Case #"<<i+1<<": ";
        solve();
    }
    return 0;
}

