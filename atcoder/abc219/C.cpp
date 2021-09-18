#include "bits/stdc++.h"
using namespace std;
using ll = long long;

void solve() {
    string x;
    cin>>x;
    string back=x;
    char curr='a';
    for(int i=0; i<26; i++) {
        back[x[i]-'a']=curr;
        curr++;
    }
    int n;
    cin>>n;
    vector<string> a(n);
    for(auto &i : a) {
        cin>>i;
    }
    for(auto &i : a) {
        for(auto &j : i) {
            j=back[j-'a'];
        }
    }
    sort(a.begin(), a.end());
    for(auto &i : a) {
        for(auto &j : i) {
            j=x[j-'a'];
        }
        cout<<i<<endl;
    }
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
    //cin>>t;
    for(int i=0; i<t; i++) {
        //cout<<"Case #"<<i+1<<": ";
        solve();
    }
    return 0;
}

