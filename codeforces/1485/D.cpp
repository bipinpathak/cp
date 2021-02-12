#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n, m;
    cin>>n>>m;
    vector<vector<ll>> a(n, vector<ll> (m));
    for(auto &i : a) {
        for(auto &j : i) {
            cin>>j;
        }
    }
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if((i+j)%2==0) {
                a[i][j]=720720;
            } else {
                a[i][j]=720720+(a[i][j]*a[i][j]*a[i][j]*a[i][j]);
            }
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
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
    while(t--) {
        solve();
    }
    return 0;
}

