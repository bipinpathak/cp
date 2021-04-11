#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin>>n;
    while(n && n%10==0) {
        n/=10;
    }
    string s, t;
    while(n) {
        s.push_back('0'+n%10);
        n/=10;
    }
    t=s;
    reverse(t.begin(), t.end());
    if(s==t) {
        cout<<"Yes"<<endl;
    } else {
        cout<<"No"<<endl;
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
    //cin >> t;
    for(int i=0; i<t; i++) {
        //cout<<"Case #"<<i+1<<": ";
        solve();
    }
    return 0;
}

