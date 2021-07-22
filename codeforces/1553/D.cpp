#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
void solve() {
    string s, t;
    cin>>s>>t;
    string ans="YES";
    while(!s.empty() && !t.empty()) {
        if(s.back()==t.back()) {
            t.pop_back();
            s.pop_back();
        } else if((int)s.size()>1) {
            s.pop_back();
            s.pop_back();
        } else {
            ans="NO";
            break;
        }
    }
    if(!t.empty()) {
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
