#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n, p, k;
    cin>>n>>p>>k;
    vector<int> a(n);
    for(auto &i : a) {
        cin>>i;
    }
    sort(a.begin(), a.end());
    vector<int> cost(n+1);
    int ans=0;
    for(int i=1; i<=n; i++) {
        cost[i]=a[i-1]+((i-k>=0)?cost[i-k]:cost[i-1]);
        if(cost[i]<=p) {
            ans=i;
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

