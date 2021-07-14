#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool good(int a, int b, int c) {
    return ((a<b && c<b) || (a>b && c>b));
}

void solve() {
    int n;
    cin>>n;
    vector<int> a(n);
    for(auto &i : a) {
        cin>>i;
    }
    int ans=2*n-1;
    for(int i=1; i+1<n; i++) {
        ans+=good(a[i-1], a[i], a[i+1]);
    }
    for(int i=0; i+3<n; i++) {
        int add=1;
        add*=good(a[i], a[i+1], a[i+2]);
        add*=good(a[i], a[i+1], a[i+3]);
        add*=good(a[i], a[i+2], a[i+3]);
        add*=good(a[i], a[i+1], a[i+2]);
        add*=good(a[i+1], a[i+2], a[i+3]);
        ans+=add;
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

