#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    cin.ignore();
    vector<vector<int>> a(3, vector<int> (2));
    for(auto &i : a) {
        for(auto &j : i) {
            cin>>j;
        }
    }
    int ans=abs(a[0][0]-a[1][0])+abs(a[0][1]-a[1][1]);
    if((a[0][0]==a[1][0] && a[1][0]==a[2][0] && a[2][1]>min(a[0][1], a[1][1]) && a[2][1]<max(a[0][1], a[1][1])) || (a[0][1]==a[1][1] && a[1][1]==a[2][1] && a[2][0]>min(a[0][0], a[1][0]) && a[2][0]<max(a[0][0], a[1][0]))) {
        ans+=2;
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

