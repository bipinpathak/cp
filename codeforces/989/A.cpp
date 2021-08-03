#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    string s;
    cin>>s;
    int n=(int)s.size();
    string ans="No";
    for(int i=1; i+1<n; i++) {
        if(s[i-1]=='.' || s[i]=='.' || s[i+1]=='.') {
            continue;
        }
        if(s[i-1]==s[i] || s[i]==s[i+1] || s[i+1]==s[i-1]) {
            continue;
        }
        ans="Yes";
        break;
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

