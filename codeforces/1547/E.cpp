#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    cin.ignore();
    int n, k;
    cin>>n>>k;
    vector<int> a(k);
    for(auto &i : a) {
        cin>>i;
        i--;
    }
    vector<ll> temp(n, 1e18);
    set<vector<ll>> active;
    for(int i=0; i<k; i++) {
        int t;
        cin>>t;
        temp[a[i]]=t;
        active.insert({t, a[i]});
    }
    while(!active.empty()) {
        auto curr=*active.begin();
        active.erase(active.begin());
        ll t=curr[0], index=curr[1];
        if(index-1>=0 && temp[index-1]>t+1) {
            temp[index-1]=t+1;
            active.insert({temp[index-1], index-1});
        }
        if(index+1<n && temp[index+1]>t+1) {
            temp[index+1]=t+1;
            active.insert({temp[index+1], index+1});
        }
    }
    for(auto i : temp) {
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

