#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int x, y, z;
    cin>>x>>y>>z;
    int total=x-y;
    char ans='0';
    if(z==0) {
        if(total>0) {
            ans='+';
        } else if(total<0) {
            ans='-';
        }
    } else {
        ans='?';
        if(total>0 && total-z>0) {
            ans='+';
        } else if(total<0 && total+z<0) {
            ans='-';
        }
    }
    cout<<ans<<endl;
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

