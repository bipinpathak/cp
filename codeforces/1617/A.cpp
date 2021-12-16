#include "bits/stdc++.h"
using namespace std;
using ll = long long;

void solve() {
    string s, t;
    cin>>s>>t;  
    string a, b, c, d;
    for(auto &i : s) {
        if(i=='a') {
            a.push_back(i);
        } else if(i=='b') {
            b.push_back(i);
        } else if(i=='c') {
            c.push_back(i);
        } else {
            d.push_back(i);
        }
    }
    string ans="";
    if(!a.empty() && !b.empty() && !c.empty() && t=="abc") {
        swap(c, b);
    }
    sort(d.begin(), d.end());
    ans=a+b+c+d;
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
    int t = 1;
    cin>>t;
    for(int i=0; i<t; i++) {
        //cout<<"Case #"<<i+1<<": ";
        solve();
    }
    return 0;
}

