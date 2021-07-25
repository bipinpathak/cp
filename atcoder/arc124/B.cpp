#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool go(ll target, vector<ll> &a, map<ll, int> count) {
    for(auto i : a) {
        if(count[target^i]==0) {
            return false;
        }
        count[target^i]--;
    }
    return true;
}

void solve() {
    int n;
    cin>>n;
    vector<ll> a(n);
    map<ll, int> count;
    for(auto &i : a) {
        cin>>i;
    }
    set<ll> options;
    for(int i=0; i<n; i++) {
        ll b;
        cin>>b;
        count[b]++;
        options.insert(a.front()^b);
    }
    vector<ll> ans;
    for(auto i : options) {
        if(go(i, a, count)) {
            ans.push_back(i);
        }
    }
    cout<<ans.size()<<endl;
    for(auto i : ans) {
        cout<<i<<endl;
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
    auto start=clock();
    int t = 1;
    //cin>>t;
    for(int i=0; i<t; i++) {
        //cout<<"Case #"<<i+1<<": ";
        solve();
    }
    double used= (double) (clock()-start);
    used=(used*1000)/CLOCKS_PER_SEC;
    cerr<<fixed<<setprecision(2)<<used<<" ms"<<endl;
    return 0;
}

