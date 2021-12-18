#include "bits/stdc++.h"
using namespace std;
using ll = long long;

void solve() {
    int q;
    cin>>q;
    int m=5e5;
    vector<int> value(m+1);
    for(int i=0; i<=m; i++) {
        value[i]=i;
    }
    vector<int> ans;
    vector<vector<vector<int>>> a(q);
    while(q--) {
        int k;
        cin>>k;
        if(k==1) {
            int x;
            cin>>x;
            ans.push_back(x);
        } else {
            int x, y;
            cin>>x>>y;
            if(!ans.empty()) {
                a[(int)ans.size()-1].push_back({x, y});
            }
        }
    }
    q=(int)ans.size();
    for(int i=q-1; i>=0; i--) {
        while(!a[i].empty()) {
            auto curr=a[i].back();
            a[i].pop_back();
            value[curr[0]]=value[curr[1]];
        }
        ans[i]=value[ans[i]];
    }
    for(auto i : ans) {
        cout<<i<<" ";
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

