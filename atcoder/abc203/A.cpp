#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    vector<int> a(3);
    for(auto &i : a) {
        cin>>i;
    }
    sort(a.begin(), a.end());
    int ans=0;
    if(a[0]==a[1]) {
        ans=a[2];
    } else if(a[1]==a[2]) {
        ans=a[0];
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

