#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int r, c, k;
    cin>>r>>c>>k;
    vector<string> farm(r);
    int rice=0;
    for(auto &i : farm) {
        cin>>i;
        for(auto j : i) {
            rice+=j=='R';
        }
    }
    vector<char> assign;
    for(int i=0; i<=9; i++) {
        assign.push_back('0'+i);
    }
    for(int i=0; i<26; i++) {
        assign.push_back('a'+i);
        assign.push_back('A'+i);
    }
    vector<vector<char>> ans(r, vector<char> (c, assign[0]));
    int left=0;
    for(int i=0; i<r && k; i++) {
        int start=0, diff=1;
        if(i%2) {
            start=c-1;
            diff=-1;
        }
        for(int j=start; j>=0 && j<c && k; j+=diff) {
            if(left==0) {
                left=rice/k;
                rice-=left;
                k--;
                //cout<<i<<" "<<j<<" "<<k<<endl;
            }
            ans[i][j]=assign[k];
            left-=farm[i][j]=='R';
        }
    }
    for(auto i : ans) {
        for(auto j : i) {
            cout<<j;
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
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}

