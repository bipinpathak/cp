#include "bits/stdc++.h"
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin>>n;
    vector<vector<int>> a(n, vector<int> (2));
    vector<int> all;
    for(auto &i : a) {
        for(auto &j : i) {
            cin>>j;
        }
        i[1]+=i[0];
        all.push_back(i[0]);
        all.push_back(i[1]);
    }
    sort(all.begin(), all.end());
    all.erase(unique(all.begin(), all.end()), all.end());
    map<int, int> index;
    int m=(int)all.size();
    for(int i=0; i<m; i++) {
        index[all[i]]=i;
    }
    vector<int> change(m);
    for(auto &i : a) {
        change[index[i[0]]]++;
        change[index[i[1]]]--;
    }
    vector<int> ans(n+1);
    int active=0, prev=1;
    for(int i=0; i<m; i++) {
        ans[active]+=(all[i]-prev);
        prev=all[i];
        active+=change[i];
    }
    for(int j=1; j<=n; j++) {
        cout<<ans[j]<<" ";
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
    //cin>>t;
    for(int i=0; i<t; i++) {
        //cout<<"Case #"<<i+1<<": ";
        solve();
    }
    return 0;
}

