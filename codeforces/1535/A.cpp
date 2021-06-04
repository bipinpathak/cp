#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    vector<vector<int>> a(4, vector<int> (2));
    for(int i=0; i<4; i++) {
        cin>>a[i][0];
        a[i][1]=i;
    }
    sort(a.rbegin(), a.rend());
    string ans="YES";
    if((a[0][1]==0 && a[1][1]==1) || (a[0][1]==1 && a[1][1]==0) || (a[0][1]==2 && a[1][1]==3) || (a[0][1]==3 && a[1][1]==2)) {
        ans="NO";
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

