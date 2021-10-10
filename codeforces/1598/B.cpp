#include "bits/stdc++.h"
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin>>n;
    int m=5;
    vector<vector<int>> a(n, vector<int> (m));
    for(auto &i : a) {
        for(auto &j : i) {
            cin>>j;
        }
    }
    string ans="NO";
    for(int first=0; first<m && ans=="NO"; first++) {
        for(int second=first+1; second<m && ans=="NO"; second++) {
            int left=0, right=0, both=0;
            for(auto i : a) {
                if(i[first] && i[second]) {
                    both++;
                } else if(i[first]) {
                    left++;
                } else if(i[second]) {
                    right++;
                }
            }
            if(left+right+both==n && left<=n/2 && right<=n/2) {
                ans="YES";
            }
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

