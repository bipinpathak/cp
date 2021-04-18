#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int a, b;
    cin>>a>>b;
    vector<int> ans;
    if(a>b) {
        for(int i=1; i<=a; i++) {
            ans.push_back(i);
        }
        for(int i=1; i<b; i++) {
            ans.push_back(-i);
        }
        ans.push_back((b*(b-1))/2 - (a*(a+1))/2 );
    } else {
        for(int i=1; i<=b; i++) {
            ans.push_back(-i);
        }
        for(int i=1; i<a; i++) {
            ans.push_back(i);
        }
        ans.push_back((b*(b+1))/2 - (a*(a-1))/2 );
    }
    for(auto i: ans) {
        cout<<i<<" ";
    }   
    cout<<endl;
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
    //cin >> t;
    for(int i=0; i<t; i++) {
        //cout<<"Case #"<<i+1<<": ";
        solve();
    }
    return 0;
}

