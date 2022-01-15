#include "bits/stdc++.h"
using namespace std;
using ll = long long;

int gcd(int a, int b) {
    if(b==0) {
        return a;
    }
    return gcd(b, a%b);
}

void solve() {
    int n;
    cin>>n;
    vector<int> a(n);
    for(auto &i : a) {
        cin>>i;
        n=max(n, i);
    }
    vector<int> have(n+1);
    for(auto &i : a) {
        have[i]=1;
    }
    int ans=0;
    for(int i=n; i; i--) {
        if(have[i]) {
            continue;
        }
        int g=1, count=0;
        for(int j=2; i*j<=n; j++) {
            if(have[i*j]) {
                if(count==0) {
                    g=j;
                }
                g=gcd(g, j);
                count++;
                if(count>=2 && g==1) {
                    have[i]=1;
                    break;
                }
            }
        }
        ans+=have[i];
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

