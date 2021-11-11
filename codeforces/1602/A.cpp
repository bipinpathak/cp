#include "bits/stdc++.h"
using namespace std;
using ll = long long;

void solve() {
    string s;
    cin>>s;
    char smallest='z';
    for(auto i : s) {
        smallest=min(smallest, i);
    }
    cout<<smallest<<" ";
    int n=(int)s.size();
    for(int i=0; i<n; i++) {
        if(s[i]==smallest) {
            s.erase(s.begin()+i, s.begin()+i+1);
            break;
        }
    }
    cout<<s<<endl;
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

