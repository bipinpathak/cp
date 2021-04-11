#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n, k;
    cin>>n>>k;
    vector<int> moves(n);
    for(auto &i : moves) {
        cin>>i;
    }
    vector<int> grundy(k+1);
    vector<set<int>> have(k+1);
    for(int i=0; i<=k; i++) {
        int mex=0;
        while(have[i].find(mex)!=have[i].end()) {
            mex++;
        }
        grundy[i]=mex;
        for(auto jump : moves) {
            if(i+jump>k) {
                break;
            }
            have[i+jump].insert(grundy[i]);
        }
    }
    string ans="Second";
    if(grundy[k]) {
        ans="First";
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

