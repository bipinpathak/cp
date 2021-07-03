#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    ll n, a, b;
    cin>>n>>a>>b;
    string ans="No";
    ll temp=1;
    while(temp<=n && ans=="No") {
        if((n-temp)%b==0) {
            ans="Yes";  
        }
        temp*=a;
        if(a==1) {
            break;
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

