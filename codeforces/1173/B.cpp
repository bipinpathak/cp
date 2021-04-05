#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin>>n;
    int m=n/2 + 1;
    cout<<m<<endl;
    for(int i=1; i<=(n+1)/2; i++) {
        cout<<1<<" "<<i<<endl;
    }
    int temp=m-(n-(n+1)/2);
    for(int i=(n+1)/2 +1; i<=n; i++) {
        temp++;
        cout<<m<<" "<<temp<<endl;
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
    for(int i=0; i<t; i++) {
        //cout<<"Case #"<<i+1<<": ";
        solve();
    }
    return 0;
}

