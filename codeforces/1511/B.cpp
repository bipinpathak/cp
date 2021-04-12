#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int count(int a) {
    int ans=0;
    while(a) {
        ans++;
        a/=10;
    }
    return ans;
}

void solve() {
    int a, b, c;
    cin>>a>>b>>c;
    int g=1;
    c--;
    while(c--) {
        g=g*10;
    }
    int x=g, y=g;
    while(count(x)<a) {
        x*=2;
    }
    while(count(y)<b) {
        y*=3;
    }
    cout<<x<<" "<<y<<endl;
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
    cin >> t;
    for(int i=0; i<t; i++) {
        //cout<<"Case #"<<i+1<<": ";
        solve();
    }
    return 0;
}

