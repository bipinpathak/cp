#include <bits/stdc++.h>
using namespace std;
void solve() {
    int n, i, active=0;
    cin>>n;
    vector<int> a(n), open, close;
    for(int &i : a) cin>>i;
    for(i=0; i<n; i++) {
        while(a[i]<active) {
            close.push_back(i-1);
            active--;
        }
        while(a[i]>active) {
            open.push_back(i);
            active++;
        }
    }
    while(close.size()<open.size()) close.push_back(n-1);
    cout<<open.size()<<endl;
    for(i=0; i<(int) open.size(); i++) {
        cout<<open[i]+1<<" "<<close[i]+1<<endl;
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
    //cin>>t;
    while(t--) {
        solve();
    }
    return 0;
}

