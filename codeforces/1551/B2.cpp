#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n, k;
    cin>>n>>k;
    vector<vector<int>> indexes(n);
    for(int i=0; i<n; i++) {
        int a;
        cin>>a;
        a--;
        indexes[a].push_back(i);
    }
    int useful=0;
    for(auto i: indexes) {
        useful+=min(k, (int)i.size());
    }
    useful=(useful/k)*k;
    vector<int> ans(n);
    int curr=0;
    for(auto i : indexes) {
        while((int)i.size()>k) {
            i.pop_back();
        }
        while(!i.empty() && useful) {
            ans[i.back()]=curr+1;
            curr=(curr+1)%k;
            i.pop_back();
            useful--;
        }
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
    auto start=clock();
    int t = 1;
    cin>>t;
    for(int i=0; i<t; i++) {
        //cout<<"Case #"<<i+1<<": ";
        solve();
    }
    double used= (double) (clock()-start);
    used=(used*1000)/CLOCKS_PER_SEC;
    cerr<<fixed<<setprecision(2)<<used<<" ms"<<endl;
    return 0;
}

