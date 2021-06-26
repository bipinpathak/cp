#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin>>n;
    vector<vector<ll>> a(n, vector<ll> (2));
    for(auto &i : a) {
        int t;
        cin>>t>>i[0]>>i[1];
        i[0]*=2;
        i[1]*=2;
        if(t==2 || t==4) {
            i[1]--;
        }
        if(t==3 || t==4) {
            i[0]++;
        }
    }
    int ans=0;
    for(int i=0; i<n; i++) {
        for(int j=i+1; j<n; j++) {
            if(a[i][0]>a[j][1] || a[i][1]<a[j][0]) {
                continue;
            }
            ans++;
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

