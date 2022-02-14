#include "bits/stdc++.h"
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin>>n;
    vector<int> a(n);
    vector<vector<int>> order(2);
    for(auto &i : a) {
        cin>>i;
        order[i&1].push_back(i);
    }
    string ans="Yes";
    for(auto &i : order) {
        int prev=0;
        for(auto &j : i) {
            if(j<prev) {
                ans="No";
                break;
            }
            prev=j;
        }
        if(ans=="No") {
            break;
        }
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

