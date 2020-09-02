#include <bits/stdc++.h>
using namespace std;
void solve() {
    int n, i;
    string s, t;
    cin>>n>>s>>t;
    vector<int> first, second;
    for(i=0; i<n; i++) {
        if(s[i]=='a' && t[i]=='b') {
            first.push_back(i+1);
        } else if(s[i]=='b' && t[i]=='a') {
            second.push_back(i+1);
        }
    }
    if(first.size()%2) {
        first.push_back(first.back());
        second.push_back(first.back());
    }
    if(first.size()%2==0 && second.size()%2==0) {
        cout<<(int)(first.size()+second.size())/2<<endl;
        for(i=0; i<(int)first.size(); i+=2) {
            cout<<first[i]<<" "<<first[i+1]<<endl;
        }
        for(i=0; i<(int)second.size(); i+=2) {
            cout<<second[i]<<" "<<second[i+1]<<endl;
        }
    } else {
        cout<<"-1"<<endl;
    }
    return;
}
int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t=1;
    //cin>>t;
    while(t--) {
        solve();
    }
    return 0;
}

