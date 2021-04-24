#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n, q;
    string s;
    cin>>n>>s>>q;
    bool flip=false;
    while(q--) {
        int t, a, b;
        cin>>t>>a>>b;
        if(t==1) {
            a--, b--;
            if(flip) {
                a=(a+n)%(2*n);
                b=(b+n)%(2*n);
            }
            swap(s[a], s[b]);
        } else {
            flip=!flip;
        }
    }
    if(flip) {
        reverse(s.begin(), s.end());
        reverse(s.begin(), s.begin()+n);
        reverse(s.begin()+n, s.end());
    }
    cout<<s<<endl;
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
    for(int i=0; i<t; i++) {
        //cout<<"Case #"<<i+1<<": ";
        solve();
    }
    double used= (double) (clock()-start);
    used=(used*1000)/CLOCKS_PER_SEC;
    cerr<<fixed<<setprecision(2)<<used<<" ms"<<endl;
    return 0;
}

