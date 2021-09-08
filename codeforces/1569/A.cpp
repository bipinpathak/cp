#include "bits/stdc++.h"
using namespace std;
using ll = long long;

void solve() {
    int n;
    string s;
    cin>>n>>s;
    map<int, int> seen;
    int curr=0;
    seen[curr]=-1;
    for(int i=0; i<n; i++) {
        if(s[i]=='a') {
            curr++;
        } else {
            curr--;
        }
        if(seen.count(curr)) {
            cout<<seen[curr]+2<<" "<<i+1<<endl; 
            return;
        }
        seen[curr]=i;
    }
    cout<<"-1 -1"<<endl;
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

