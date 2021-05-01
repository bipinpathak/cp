#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    cout<<fixed<<setprecision(3);
    int n, D, H;
    cin>>n>>D>>H;
    double ans=0;
    for(int i=0; i<n; i++) {
        int d, h;
        cin>>d>>h;
        double offer=(double)(D*h-d*H)/(double) (D-d);
        ans=max(ans, offer); 
    }
    ans=max(ans, (double)0);
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
    for(int i=0; i<t; i++) {
        //cout<<"Case #"<<i+1<<": ";
        solve();
    }
    double used= (double) (clock()-start);
    used=(used*1000)/CLOCKS_PER_SEC;
    cerr<<fixed<<setprecision(2)<<used<<" ms"<<endl;
    return 0;
}

