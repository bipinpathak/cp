#include "bits/stdc++.h"
using namespace std;
using ll = long long;

void solve() {
    cin.ignore();
    int m, n;
    cin>>m>>n;
    vector<vector<int>> joy(m, vector<int> (n));
    for(auto &i : joy) {
        for(auto &j : i) {
            cin>>j;
        }
    }
    int ans=0;
    vector<int> best(n);
    for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++) {
            best[j]=max(best[j], joy[i][j]);
        }
    }
    for(int i=0; i<m; i++) {
        int first=0, second=1;
        if(joy[i][first]<joy[i][second]) {
            swap(first, second);
        }
        for(int j=2; j<n; j++) {
            if(joy[i][j]>joy[i][second]) {
                second=j;
            }
            if(joy[i][first]<joy[i][second]) {
                swap(first, second);
            }
        }
        int low=1e9;
        for(int j=0; j<n; j++) {
            if(j==first || j==second) {
                low=min(low, joy[i][j]);
            } else {
                low=min(low, best[j]);
            }
        }
        ans=max(ans, low);
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
    cin>>t;
    for(int i=0; i<t; i++) {
        //cout<<"Case #"<<i+1<<": ";
        solve();
    }
    return 0;
}

