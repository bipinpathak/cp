#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n;
    string a, b;
    cin>>n>>a>>b;
    int ans=0;
    for(int i=0; i<n; i++) {
        if(b[i]=='0') {
            continue;
        }
        if(a[i]=='0') {
            ans++;
            continue;
        } 
        if(i-1>=0 && a[i-1]=='1') {
            a[i-1]='0';
            ans++;

        } else if(i+1<n && a[i+1]=='1') {
            a[i+1]='0';
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

