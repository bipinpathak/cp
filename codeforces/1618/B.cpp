#include "bits/stdc++.h"
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin>>n;
    vector<string> a(n-2);
    for(auto &i : a) {
        cin>>i;
    }
    bool add=false;
    string ans="";
    for(auto &i : a) {
        if(ans.empty()) {
            ans=i;
        } else if(ans.back()!=i[0]) {
            add=true;
            ans+=i;
        } else {
            ans+=i[1];
        }
    }
    if(!add) {
        ans+='a';
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
    int t = 1;
    cin>>t;
    for(int i=0; i<t; i++) {
        //cout<<"Case #"<<i+1<<": ";
        solve();
    }
    return 0;
}

