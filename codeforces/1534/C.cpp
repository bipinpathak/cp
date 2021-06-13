#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin>>n;
    vector<vector<int>> a(2, vector<int> (n)), index;
    for(auto &i : a) {
        for(auto &j : i) {
            cin>>j;
        }
    }
    index=a;
    for(int j=0; j<2; j++) {
        for(int i=0; i<n; i++) {
            index[j][a[j][i]-1]=i;
        }
    }
    vector<int> done(n);
    ll ans=1, p=1e9+7;
    for(int i=0; i<n; i++) {
        if(done[i]) {
            continue;
        }
        ans=(ans*2)%p;
        int curr=i;
        while(!done[curr]) {
            done[curr]=1;
            int low=a[1][curr];
            curr=index[0][low-1];
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

