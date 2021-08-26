#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n;
    string s;
    cin>>n>>s;
    int zero=-1;
    for(int i=0; i<n; i++) {
        if(s[i]=='0') {
            zero=i;
            break;
        }
    }
    int l1, r1, l2, r2;
    if(zero==-1) {
        l1=1, r1=n-1;
        l2=2, r2=n;
    } else if(zero>=n/2) {
        l1=l2=1;
        r1=zero+1;
        r2=zero;
    } else {
        l1=zero+1;
        l2=zero+2;
        r1=r2=n;
    }
    cout<<l1<<" "<<r1<<" "<<l2<<" "<<r2<<endl;
    return;
}

int main() {
#ifdef bipinpathak
    (void)!freopen("input.txt", "r", stdin);
    (void)!freopen("output.txt", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    auto start=clock();
    int t = 1;
    cin>>t;
    for(int i=0; i<t; i++) {
        //cout<<"Case #"<<i+1<<": ";
        solve();
    }
    double used= (double) (clock()-start);
    used=(used*1000)/CLOCKS_PER_SEC;
    cerr<<fixed<<setprecision(2)<<used<<" ms"<<endl;
    return 0;
}

