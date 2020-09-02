#include <bits/stdc++.h>
using namespace std;
void solve() {
    int n, i;
    string s;
    cin>>n>>s;
    vector<int> minimum(n), maximum(n);
    for(i=0; i<n; i++) {
        maximum[i]=i+1;
        minimum[i]=n-i;
    }
    int start=-1;
    for(i=0; i<n-1; i++) {
        if(s[i]=='>' && start==-1) {
            start=i;
        } else if(s[i]=='<' && start!=-1) {
            reverse(maximum.begin()+start, maximum.begin()+i+1);
            start=-1;
        }
    }
    if(start!=-1) {
        reverse(maximum.begin()+start, maximum.end());
    }
    start=-1;
    for(i=0; i<n-1; i++) {
        if(s[i]=='<' && start==-1) {
            start=i;
        } else if(s[i]=='>' && start!=-1) {
            reverse(minimum.begin()+start, minimum.begin()+i+1);
            start=-1;
        }
    }
    if(start!=-1) {
        reverse(minimum.begin()+start, minimum.end());
    }
    for(int i : minimum) {
        cout<<i<<" ";
    }
    cout<<endl;
    for(int i : maximum) {
        cout<<i<<" ";
    }
    cout<<endl;
    return;
}
int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t=1;
    cin>>t;
    while(t--) {
        solve();
    }
    return 0;
}

