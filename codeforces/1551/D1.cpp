#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n, m, k;
    cin>>n>>m>>k;
    string ans="NO";
    int total=(n*m)/2;
    if(n%2 || m%2) {
        if(n%2) {
            total-=m/2;
            k-=m/2;
        } else {
            total-=n/2;
        }
    }
    if(k%2==0 && k<=total && k>=0) {
        ans="YES";
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

