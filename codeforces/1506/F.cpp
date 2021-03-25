#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin>>n;
    vector<vector<ll>> a(n, vector<ll> (2));
    for(int i=0; i<n; i++) {
        cin>>a[i][0];
    }
    for(int i=0; i<n; i++) {
        cin>>a[i][1];
    }
    sort(a.begin(), a.end());
    ll ans=0, x=1, y=1;
    for(int i=0; i<n; i++) {
        if((x+y)%2==0) {
            if(a[i][0]==x+1) {
                if(a[i][1]!=y) {
                    ans++;
                }
            } else {
                if(y+a[i][0]-x==a[i][1]) {
                    ans+=a[i][0]-x;
                } else {
                    x++;
                    y+=a[i][0]-x;
                    ans+=(y-a[i][1]+1)/2;
                }
            }
        } else {
            y+=a[i][0]-x;
            ans+=(y-a[i][1]+1)/2;
        }
        x=a[i][0], y=a[i][1];
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
    cin >> t;
    for(int i=0; i<t; i++) {
        //cout<<"Case #"<<i+1<<": ";
        solve();
    }
    return 0;
}

