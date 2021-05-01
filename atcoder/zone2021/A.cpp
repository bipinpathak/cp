#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    string s, t="ZONe";
    cin>>s;
    int n=s.length(), ans=0;
    for(int i=0; i+3<n; i++) {
        bool found=true;
        for(int j=0; j<4; j++) {
            if(s[i+j]!=t[j]) {
                found=false;
            }
        }
        ans+=found;
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
    for(int i=0; i<t; i++) {
        //cout<<"Case #"<<i+1<<": ";
        solve();
    }
    double used= (double) (clock()-start);
    used=(used*1000)/CLOCKS_PER_SEC;
    cerr<<fixed<<setprecision(2)<<used<<" ms"<<endl;
    return 0;
}

