#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    string s;
    cin>>s;
    ll ans=0, one=0, zero=0;
    for(auto i : s) {
        swap(one, zero);
        if(i=='1') {
            one++;
            zero=0;
            ans+=one;
        } else  if(i=='0') {
            zero++;
            one=0;
            ans+=zero;
        } else {
            one++;
            zero++;
            ans+=max(one, zero);
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

