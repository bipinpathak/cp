#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin>>n;
    vector<vector<int>> a(n, vector<int> (n));
    for(int i=0; i<n; i++) {
        for(int j=i+1; j<n; j++) {
            if((i+j)%2) {
                a[i][j]=1;
            } else {
                a[i][j]=-1;
            }
        }
        if(n%2==0 && i%2==0) {
            for(int j=i+1; j<n; j++) {
                if(a[i][j]==1) {
                    a[i][j]=0;
                    break;
                }
            }
        }
    }
    for(int i=0; i<n; i++) {
        for(int j=i+1; j<n; j++) {
            cout<<a[i][j]<<" ";
        }
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
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}

