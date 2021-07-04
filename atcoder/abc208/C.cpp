#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n;
    ll k;
    cin>>n>>k;
    vector<vector<int>> people(n, vector<int> (2));
    for(int i=0; i<n; i++) {
        cin>>people[i][0];
        people[i][1]=i;
    }
    sort(people.begin(), people.end());
    vector<ll> ans(n);
    for(int i=0; i<n; i++) {
        ll curr=(k+n-i-1)/(n-i);
        ans[people[i][1]]=curr;
        k-=curr;
    }
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

