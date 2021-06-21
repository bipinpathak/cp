#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int calc(int n, int s) {
    return (n+s-1)/s + s;
}

void solve() {
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0; i<n; i++) {
        a[i]=i;
    }
    int s=0;
    while(s*s<=n) {
        s++;
    }
    s--;
    s+=(calc(n, s)>calc(n, s+1));
    reverse(a.begin(), a.end());
    for(int i=0; i<n; i+=s) {
        reverse(a.begin()+i, a.begin()+min(n, i+s));
    }
    for(auto i : a) {
        cout<<i+1<<" ";
    }
    cout<<endl;
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

